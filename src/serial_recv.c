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

static rt_mq_t uart_queue_handle = RT_NULL;

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
            rt_mq_send(uart_queue_handle, &i, 1);
            return RT_EOK;
        }
    }
    return RT_ERROR;
}

void rx_recv(void *para) {
    char ch;
    char send[256];
    uint8_t serial_index;

    uart_queue_handle = rt_mq_create("uart_queue", 1, 20, RT_IPC_FLAG_FIFO);

    for (uint8_t i = 0; i < 5; i++) {
        rx_serial[i] = rt_device_find(serial_list[i]);
        rt_device_open(rx_serial[i], RT_DEVICE_FLAG_INT_RX);
        rt_device_set_rx_indicate(rx_serial[i], uart_irq_cb);
    }

    while (1) {
        if (rt_mq_recv(uart_queue_handle, &serial_index, 1, RT_WAITING_FOREVER) == RT_EOK) {
            rt_device_t serial = rx_serial[serial_index];
            char *buffer = rx_buffer[serial_index];
            uint8_t *len = &rx_len[serial_index];
            const char *tag = serial_list[serial_index];

            rt_device_read(serial, -1, &ch, 1);
            if ((ch != '\n') && (*len < 240)) {
                buffer[(*len)++] = ch;
            } else {
                sprintf(send, "[%s]%.*s",
                        tag, *len, buffer);
                usbd_print(send, *len - 1 + 7);
                *len = 0;
                memset(buffer, 0, 256 * sizeof(char));
            }
        }
    }
}
