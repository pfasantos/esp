#ifndef _I2S_DRIVER_H_
#define _I2S_DRIVER_H_

#include "driver/i2s_std.h"
#include "esp_err.h"
#include "esp_log.h"

#include "driver/i2s_pdm.h"
#include "driver/gpio.h"

#define I2S_DRIVER_TAG "i2s_driver"

#define DMA_BUF_NUM  16 // quantidade de buffers do DMA
#define DMA_BUF_SIZE 511 // tamanho [em amostras] dos buffers do DMA
#define BUF_SIZE     4088 // tamanho [em bytes] dos buffers de entrada/transmissao

extern i2s_chan_handle_t rx_handle;

void i2s_pdm_init();
void i2s_pdm_stop();

#endif // _I2S_DRIVER_H_