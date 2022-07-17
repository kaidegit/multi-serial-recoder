/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-17     yekai       the first version
 */
#include "button.h"
#include "multi_button.h"
#include "database.h"

#define BTN_PIN    BSP_IO_PORT_01_PIN_05

struct button btn1;

uint8_t button_readbtn1() {
    return rt_pin_read(BTN_PIN);
}

void button_singleclick_cb() {
//    rt_kprintf("single click\r\n");
    rt_kprintf("start to read logs");
    DB_ReadAllLogs();
}

void button_doubleclick_cb() {
//    rt_kprintf("double click\r\n");
    rt_kprintf("start to clear logs\r\n");
    DB_ClearLogs();
}

void button_thread(void *para) {
    button_init(&btn1, button_readbtn1, 0);
    button_attach(&btn1, SINGLE_CLICK, button_singleclick_cb);
    button_attach(&btn1, DOUBLE_CLICK, button_doubleclick_cb);
    button_start(&btn1);
    while (1) {
        button_ticks();
        rt_thread_mdelay(5);
    }
}

