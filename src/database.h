/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-10     yekai       the first version
 */
#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_

#include "hal_data.h"
#include "rtthread.h"
#include <rtdevice.h>

void DB_Init();

void DB_InsertLog(char *log);

void DB_ReadAllLogs();

#endif /* SRC_DATABASE_H_ */
