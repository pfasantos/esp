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
#define REC_TIME_US        5000000

//tags
#define MAIN_TAG "main"
#define I2S_TAG  "i2s"

extern FILE* audio_file;
extern char rx_buffer[BUF_SIZE];
extern char tx_buffer[BUF_SIZE];
extern int block_count;

#endif // _MAIN_H_