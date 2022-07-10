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
#include "flashdb.h"
#include "sfud.h"
#include "spi_flash_sfud.h"
#include "finsh.h"

struct rt_spi_device sfud_dev;
struct fdb_tsdb log_db = {0};

static uint32_t counts;
static fdb_time_t get_count(void)
{
    return ++counts;
}

void DB_Init() {
    uint32_t cs_pin = BSP_IO_PORT_02_PIN_07;
    rt_hw_spi_device_attach(&sfud_dev, "sfspi", "spi0", (void *)cs_pin);
    rt_sfud_flash_probe("X25XXX", "sfspi");
//    fal_init();
    fdb_tsdb_init(&log_db, "log", "db", get_count, 255, NULL);
    fdb_tsdb_control(&log_db, FDB_TSDB_CTRL_GET_LAST_TIME, &counts);
}

void DB_InsertLog(char *log) {
    struct fdb_blob blob;
    fdb_tsl_append(&log_db, fdb_blob_make(&blob, log, 255));
}

static bool DB_query_cb(fdb_tsl_t tsl, void *arg) {
    struct fdb_blob blob;
    char log[256] = "";
    fdb_tsdb_t db = arg;

    fdb_blob_read((fdb_db_t) db, fdb_tsl_to_blob(tsl, fdb_blob_make(&blob, log, 255)));
    rt_kprintf("[query_cb] queried a TSL: time: %ld, state :%d, str:%s \r\n", tsl->time, tsl->status, log);

    return false;
}

static bool DB_delete_cb(fdb_tsl_t tsl, void *arg) {
    fdb_tsdb_t db = arg;

    rt_kprintf("set the TSL (time %ld) status from %d to %d\n", tsl->time, tsl->status, FDB_TSL_DELETED);
    fdb_tsl_set_status(db, tsl, FDB_TSL_DELETED);

    return false;
}

void DB_ReadAllLogs(void) {
    fdb_tsl_iter(&log_db, DB_query_cb, &log_db);
}

MSH_CMD_EXPORT(DB_ReadAllLogs, read_all_logs);

void DB_ClearLogs(void) {
    fal_partition_erase_all(fal_partition_find("db"));
    counts = 0;
    fdb_tsdb_init(&log_db, "log", "db", get_count, 255, NULL);
}

MSH_CMD_EXPORT(DB_ClearLogs, clear all logs);


