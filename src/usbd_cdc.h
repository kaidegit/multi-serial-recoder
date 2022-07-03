#pragma once

#include "hal_data.h"
#include <rtthread.h>

void usbd_cdc(void* para);

fsp_err_t usbd_print(char *p_data, uint16_t len);