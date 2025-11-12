#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <sys/param.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"
#include <errno.h>

#include "driver/i2s_std.h"
#include "driver/i2s_pdm.h"
#include "driver/gpio.h"

#define FSYNC_DELAY_BLOCKS 8
#define REC_TIME_MS        5000

//tags
#define MAIN_TAG "main"
#define I2S_TAG  "i2s"

FILE* audio_file = NULL;

char rx_buffer[BUF_SIZE];
char tx_buffer[BUF_SIZE];
int block_count = 0; //contagem de blocos para fsync

//handlers freertos
QueueHandle_t xQueueData;
TaskHandle_t xTaskReadDataHandle;
TaskHandle_t xTaskStoreDataHandle;

//definicao das funcoes
static void vTaskReadData(void *pvParameters);
static void vTaskStoreData(void *pvParameters);
#endif // _MAIN_H_