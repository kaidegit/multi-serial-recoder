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

static struct rt_semaphore rx0_sem;
extern rt_device_t serial;

rt_err_t uart_irq_cb(rt_device_t serial_dev, rt_size_t size) {
    rt_sem_release(&rx0_sem);
    return RT_EOK;
}

void rx_recv(void *para) {
    char buffer[256];
    uint8_t len;
    char ch;
    char send[256];
    rt_sem_init(&rx0_sem, "rx0_sem", 0, RT_IPC_FLAG_FIFO);

    while (1) {
        while (rt_device_read(serial, -1, &ch, 1) != 1) {
            rt_sem_take(&rx0_sem, RT_WAITING_FOREVER);
        }
        if ((ch != '\n') && (len < 240)) {
            buffer[len++] = ch;
        } else {
            strcpy(send, "[uart0]");
            strcat(send, buffer);
            usbd_print(send, len - 1 + 7);
            len = 0;
            memset(buffer, 0, sizeof(buffer));
        }
    }
}
