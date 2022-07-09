/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-10     yekai       the first version
 */
#include "database.h"
#include <drv_spi.h>
#include "fal.h"

struct rt_spi_device sfud_dev;

void DB_Init() {
    uint32_t cs_pin = BSP_IO_PORT_02_PIN_07;
    rt_hw_spi_device_attach(&sfud_dev, "sfspi", "spi0", (void *)cs_pin);
    rt_sfud_flash_probe("X25XXX", "sfspi");
    fal_init();
}
