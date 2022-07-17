/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 * 2021-11-03     Sherman       Add icu_sample
 */

#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>
#include "usbd_cdc.h"
#include "serial_recv.h"
#include "database.h"
#include "button.h"

#define LED3_PIN    BSP_IO_PORT_01_PIN_06
#define USER_INPUT  "P105"

uint8_t usbd_cdc_stack[5120];
struct rt_thread usbd_cdc_handle;

uint8_t rx_stack[5120];
struct rt_thread rx_handle;

uint8_t rx_send_store_stack[5120];
struct rt_thread rx_send_store_handle;

uint8_t button_thread_stack[5120];
struct rt_thread button_thread_handle;

void hal_entry(void)
{
    rt_kprintf("\nHello RT-Thread!\n");

    // 优先级顺序 串口接收 > 串口数据存储发送 = 按键扫描 = USB CDC事件
    // 为保证按下按键时能使用CDC连续发送数据，优先级应相等

    rt_err_t result = rt_thread_init(&usbd_cdc_handle, "usbd_cdc", usbd_cdc, RT_NULL, usbd_cdc_stack, sizeof(usbd_cdc_stack), 20, 10);
    if (result == RT_EOK) rt_thread_startup(&usbd_cdc_handle);

    result = rt_thread_init(&rx_handle, "rx_recv", rx_recv, RT_NULL, rx_stack, sizeof(rx_stack), 10, 10);
    if (result == RT_EOK) rt_thread_startup(&rx_handle);

    result = rt_thread_init(&rx_send_store_handle, "rx_send_store", rx_send_store, RT_NULL, rx_send_store_stack, sizeof(rx_send_store_stack), 20, 10);
    if (result == RT_EOK) rt_thread_startup(&rx_send_store_handle);

    result = rt_thread_init(&button_thread_handle, "button_thread", button_thread, RT_NULL, button_thread_stack, sizeof(button_thread_stack), 20, 10);
    if (result == RT_EOK) rt_thread_startup(&button_thread_handle);

    DB_Init();

    while (1)
    {
        rt_pin_write(LED3_PIN, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED3_PIN, PIN_LOW);
        rt_thread_mdelay(500);
//        usbd_print("HelloCDC\r\n", strlen("HelloCDC\r\n"));
    }
}



void irq_callback_test(void *args)
{
    rt_kprintf("\n IRQ00 triggered \n");
}

void icu_sample(void)
{
    /* init */
    rt_uint32_t pin = rt_pin_get(USER_INPUT);
    rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, irq_callback_test, RT_NULL);
    if(RT_EOK != err)
    {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if(RT_EOK != err)
    {
        rt_kprintf("\n enable irq failed. \n");
    }
}
MSH_CMD_EXPORT(icu_sample, icu sample);
