#include "i2s_std.h"
#include "sd_driver.h"
#include "main.h"
#include "esp_timer.h"

FILE* audio_file = NULL;
char rx_buffer[BUF_SIZE];
char tx_buffer[BUF_SIZE];
int block_count = 0;

void app_main(void)
{   //iniciando i2s e sdcard
    i2s_std_init();
    sdcard_init();
    
    audio_file = fopen(MOUNT_POINT "/semrtos.raw", "wb");
    if (audio_file == NULL) {
        ESP_LOGE(MAIN_TAG, "Falha ao abrir o arquivo");
        return;
    }    
    size_t bytes_to_read = BUF_SIZE;
    size_t bytes_read;

    //inicia canal i2s
    i2s_channel_enable(rx_handle);

    int64_t start_time = esp_timer_get_time();
    int64_t now = start_time;

    ESP_LOGI(I2S_TAG, "Aquisição iniciada");
    while ((now - start_time)< REC_TIME_US)
    {
        if (i2s_channel_read(rx_handle, (void *)rx_buffer, bytes_to_read, &bytes_read, portMAX_DELAY) == ESP_OK)
        {
            if (audio_file) {
                fwrite(rx_buffer, 1, bytes_read, audio_file);
                block_count++;

                if (block_count >= FSYNC_DELAY_BLOCKS) {
                    fflush(audio_file);
                    fsync(fileno(audio_file));
                    block_count = 0;
                }
            }
        }
        now = esp_timer_get_time();
    }

    fclose(audio_file);
    i2s_std_stop();
    ESP_LOGI(I2S_TAG, "Aquisição encerrada");
}