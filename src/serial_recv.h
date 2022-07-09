/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-09     yekai       the first version
 */
#ifndef SRC_SERIAL_RECV_H_
#define SRC_SERIAL_RECV_H_

#include "hal_data.h"
#include "rtthread.h"
#include <rtdevice.h>

rt_err_t uart_irq_cb(rt_device_t serial_dev, rt_size_t size);

void rx_recv(void *para);

#endif /* SRC_SERIAL_RECV_H_ */
