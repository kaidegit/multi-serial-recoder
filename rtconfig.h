#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Generated by Kconfiglib (https://github.com/ulfalizer/Kconfiglib) */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_HOOK_USING_FUNC_PTR
#define RT_USING_IDLE_HOOK
#define RT_IDLE_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO 4
#define RT_TIMER_THREAD_STACK_SIZE 512

/* kservice optimization */

/* end of kservice optimization */
#define RT_DEBUG
#define RT_DEBUG_COLOR

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE
/* end of Inter-Thread communication */

/* Memory Management */

#define RT_USING_SMALL_MEM
#define RT_USING_SMALL_MEM_AS_HEAP
#define RT_USING_HEAP
/* end of Memory Management */

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 128
#define RT_CONSOLE_DEVICE_NAME "uart6"
/* end of Kernel Device Object */
#define RT_VER_NUM 0x40100
/* end of RT-Thread Kernel */
#define ARCH_ARM
#define RT_USING_CPU_FFS
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M4

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT
#define RT_USING_USER_MAIN
#define RT_MAIN_THREAD_STACK_SIZE 2048
#define RT_MAIN_THREAD_PRIORITY 10

/* C++ features */

/* end of C++ features */

/* Command shell */

#define RT_USING_FINSH
#define RT_USING_MSH
#define FINSH_USING_MSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_CMD_SIZE 80
#define MSH_USING_BUILT_IN_COMMANDS
#define FINSH_USING_DESCRIPTION
#define FINSH_ARG_MAX 10
/* end of Command shell */
#define RT_USING_FAL
#define FAL_DEBUG_CONFIG
#define FAL_DEBUG 1
#define FAL_PART_HAS_TABLE_CFG

/* Device virtual file system */

/* end of Device virtual file system */

/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_USING_SERIAL
#define RT_USING_SERIAL_V2
#define RT_SERIAL_USING_DMA
#define RT_USING_PIN
#define RT_USING_SPI
#define RT_USING_SFUD
#define RT_SFUD_USING_SFDP
#define RT_SFUD_USING_FLASH_INFO_TABLE
#define RT_SFUD_SPI_MAX_HZ 16000000
#define RT_DEBUG_SFUD

/* Using USB */

/* end of Using USB */
/* end of Device Drivers */

/* POSIX layer and C standard library */

#define RT_LIBC_DEFAULT_TIMEZONE 8

/* POSIX (Portable Operating System Interface) layer */


/* Interprocess Communication (IPC) */


/* Socket is in the 'Network' category */

/* end of Interprocess Communication (IPC) */
/* end of POSIX (Portable Operating System Interface) layer */
/* end of POSIX layer and C standard library */

/* Network */

/* end of Network */

/* VBUS(Virtual Software BUS) */

/* end of VBUS(Virtual Software BUS) */

/* Utilities */

/* end of Utilities */
/* end of RT-Thread Components */

/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */

/* end of Marvell WiFi */

/* Wiced WiFi */

/* end of Wiced WiFi */
/* end of Wi-Fi */

/* IoT Cloud */

/* end of IoT Cloud */
/* end of IoT - internet of things */

/* security packages */

/* end of security packages */

/* language packages */

/* JSON: JavaScript Object Notation, a lightweight data-interchange format */

/* end of JSON: JavaScript Object Notation, a lightweight data-interchange format */

/* XML: Extensible Markup Language */

/* end of XML: Extensible Markup Language */
/* end of language packages */

/* multimedia packages */

/* LVGL: powerful and easy-to-use embedded GUI library */

/* end of LVGL: powerful and easy-to-use embedded GUI library */

/* u8g2: a monochrome graphic library */

/* end of u8g2: a monochrome graphic library */

/* PainterEngine: A cross-platform graphics application framework written in C language */

/* end of PainterEngine: A cross-platform graphics application framework written in C language */
/* end of multimedia packages */

/* tools packages */

/* end of tools packages */

/* system packages */

/* enhanced kernel services */

/* end of enhanced kernel services */

/* acceleration: Assembly language or algorithmic acceleration packages */

/* end of acceleration: Assembly language or algorithmic acceleration packages */

/* CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */

/* end of CMSIS: ARM Cortex-M Microcontroller Software Interface Standard */

/* Micrium: Micrium software products porting for RT-Thread */

/* end of Micrium: Micrium software products porting for RT-Thread */
#define PKG_USING_FLASHDB
#define FDB_USING_KVDB
#define FDB_USING_TSDB
#define FDB_USING_FAL_MODE
#define FDB_WRITE_GRAN_1BIT
#define FDB_WRITE_GRAN 1
#define FDB_NOT_USING_FILE_MODE
#define FDB_DEBUG_ENABLE
#define PKG_USING_FLASHDB_V10102
#define PKG_FLASHDB_VER_NUM 0x10102
/* end of system packages */

/* peripheral libraries and drivers */

/* end of peripheral libraries and drivers */

/* AI packages */

/* end of AI packages */

/* miscellaneous packages */

/* project laboratory */

/* end of project laboratory */

/* samples: kernel and components samples */

/* end of samples: kernel and components samples */

/* entertainment: terminal games and other interesting software packages */

/* end of entertainment: terminal games and other interesting software packages */
/* end of miscellaneous packages */
/* end of RT-Thread online packages */
#define SOC_FAMILY_RENESAS
#define SOC_SERIES_R7FA6M4

/* Hardware Drivers Config */

#define SOC_R7FA6M4AF

/* Onboard Peripheral Drivers */

/* On-chip Peripheral Drivers */

#define BSP_USING_GPIO
#define BSP_USING_UART
#define BSP_USING_UART0
#define BSP_UART0_RX_USING_DMA
#define BSP_UART0_RX_BUFSIZE 256
#define BSP_UART0_TX_BUFSIZE 0
#define BSP_USING_UART1
#define BSP_UART1_RX_USING_DMA
#define BSP_UART1_RX_BUFSIZE 256
#define BSP_UART1_TX_BUFSIZE 0
#define BSP_USING_UART2
#define BSP_UART2_RX_USING_DMA
#define BSP_UART2_RX_BUFSIZE 256
#define BSP_UART2_TX_BUFSIZE 0
#define BSP_USING_UART3
#define BSP_UART3_RX_USING_DMA
#define BSP_UART3_RX_BUFSIZE 256
#define BSP_UART3_TX_BUFSIZE 0
#define BSP_USING_UART4
#define BSP_UART4_RX_USING_DMA
#define BSP_UART4_RX_BUFSIZE 256
#define BSP_UART4_TX_BUFSIZE 0
#define BSP_USING_UART6
#define BSP_UART6_RX_BUFSIZE 256
#define BSP_UART6_TX_BUFSIZE 0
#define BSP_USING_SPI
#define BSP_USING_SPI0
/* end of On-chip Peripheral Drivers */

/* Board extended module Drivers */

/* end of Board extended module Drivers */
/* end of Hardware Drivers Config */

#endif
