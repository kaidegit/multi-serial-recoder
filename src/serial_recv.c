/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-09     yekai       the first version
 */
#include "serial_recv.h"
#include "usbd_cdc.h"
#include "string.h"
#include "stdio.h"
#include "database.h"

static rt_mq_t uart_queue_handle = RT_NULL;
static rt_mq_t log_queue_handle = RT_NULL;

rt_device_t rx_serial[5];

const char serial_list[][6] = {
        "uart0",
        "uart1",
        "uart2",
        "uart3",
        "uart4"
};

char rx_buffer0[256] = "";
char rx_buffer1[256] = "";
char rx_buffer2[256] = "";
char rx_buffer3[256] = "";
char rx_buffer4[256] = "";
char *rx_buffer[5] = {
        rx_buffer0,
        rx_buffer1,
        rx_buffer2,
        rx_buffer3,
        rx_buffer4
};
uint8_t rx_len[5];


rt_err_t uart_irq_cb(rt_device_t serial_dev, rt_size_t size) {
    for (uint8_t i = 0; i < 5; i++){
        if (serial_dev == rx_serial[i]) {
            rt_mq_send(uart_queue_handle, &i, sizeof(i));
            return RT_EOK;
        }
    }
    return RT_ERROR;
}

void rx_recv(void *para) {
    char ch;
    char send[256];
    uint8_t serial_index;

    uart_queue_handle = rt_mq_create("uart_queue", sizeof(serial_index), 255, RT_IPC_FLAG_FIFO);
    log_queue_handle = rt_mq_create("log_queue", 256 * sizeof(char), 20, RT_IPC_FLAG_FIFO);

    for (uint8_t i = 0; i < 5; i++) {
        rx_serial[i] = rt_device_find(serial_list[i]);
        rt_device_open(rx_serial[i], RT_DEVICE_FLAG_RX_NON_BLOCKING);
        rt_device_set_rx_indicate(rx_serial[i], uart_irq_cb);
    }
    while (1) {
        if (rt_mq_recv(uart_queue_handle, &serial_index, sizeof(serial_index), RT_WAITING_FOREVER) == RT_EOK) {
            rt_device_t serial = rx_serial[serial_index];
            char *buffer = rx_buffer[serial_index];
            uint8_t *len = &rx_len[serial_index];
            const char *tag = serial_list[serial_index];

            rt_device_read(serial, 0, &ch, 1);
            if ((ch != '\n') && (*len < 240)) {
                buffer[(*len)++] = ch;
            } else {
                sprintf(send, "[%s]%.*s\r\n", tag, *len, buffer);
                rt_kprintf("%.*s\r\n", *len - 1 + 7, send);
                rt_mq_send(log_queue_handle, send, 256 * sizeof(char));
                *len = 0;
                memset(buffer, 0, 256 * sizeof(char));
                memset(send, 0, sizeof(send));
            }
        }
    }
}

void rx_send_store(void *para) {
    char log[256] = "";
    while (1) {
        if (rt_mq_recv(log_queue_handle, log, 256 * sizeof(char), RT_WAITING_FOREVER) == RT_EOK) {
            usbd_print(log, strlen(log));
            DB_InsertLog(log);
        }
    }
}
