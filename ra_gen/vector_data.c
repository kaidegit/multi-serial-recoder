/* generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI6 RXI (Received data full) */
            [1] = sci_uart_txi_isr, /* SCI6 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI6 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI6 ERI (Receive error) */
            [4] = r_icu_isr, /* ICU IRQ0 (External pin interrupt 0) */
            [5] = usbfs_interrupt_handler, /* USBFS INT (USBFS interrupt) */
            [6] = usbfs_resume_handler, /* USBFS RESUME (USBFS resume interrupt) */
            [7] = usbfs_d0fifo_handler, /* USBFS FIFO 0 (DMA transfer request 0) */
            [8] = usbfs_d1fifo_handler, /* USBFS FIFO 1 (DMA transfer request 1) */
            [9] = spi_rxi_isr, /* SPI0 RXI (Receive buffer full) */
            [10] = spi_txi_isr, /* SPI0 TXI (Transmit buffer empty) */
            [11] = spi_tei_isr, /* SPI0 TEI (Transmission complete event) */
            [12] = spi_eri_isr, /* SPI0 ERI (Error) */
            [13] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [14] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [15] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [16] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [17] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [18] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [19] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [20] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
            [21] = sci_uart_rxi_isr, /* SCI2 RXI (Received data full) */
            [22] = sci_uart_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [23] = sci_uart_tei_isr, /* SCI2 TEI (Transmit end) */
            [24] = sci_uart_eri_isr, /* SCI2 ERI (Receive error) */
            [25] = sci_uart_rxi_isr, /* SCI3 RXI (Received data full) */
            [26] = sci_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [27] = sci_uart_tei_isr, /* SCI3 TEI (Transmit end) */
            [28] = sci_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [29] = sci_uart_rxi_isr, /* SCI4 RXI (Received data full) */
            [30] = sci_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [31] = sci_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [32] = sci_uart_eri_isr, /* SCI4 ERI (Receive error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI6_RXI), /* SCI6 RXI (Received data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI6_TXI), /* SCI6 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI6_TEI), /* SCI6 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI6_ERI), /* SCI6 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ0), /* ICU IRQ0 (External pin interrupt 0) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_USBFS_INT), /* USBFS INT (USBFS interrupt) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_USBFS_RESUME), /* USBFS RESUME (USBFS resume interrupt) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_0), /* USBFS FIFO 0 (DMA transfer request 0) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_USBFS_FIFO_1), /* USBFS FIFO 1 (DMA transfer request 1) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SPI0_RXI), /* SPI0 RXI (Receive buffer full) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TXI), /* SPI0 TXI (Transmit buffer empty) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TEI), /* SPI0 TEI (Transmission complete event) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SPI0_ERI), /* SPI0 ERI (Error) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_SCI2_RXI), /* SCI2 RXI (Received data full) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TXI), /* SCI2 TXI (Transmit data empty) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TEI), /* SCI2 TEI (Transmit end) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_SCI2_ERI), /* SCI2 ERI (Receive error) */
            [25] = BSP_PRV_IELS_ENUM(EVENT_SCI3_RXI), /* SCI3 RXI (Received data full) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TXI), /* SCI3 TXI (Transmit data empty) */
            [27] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TEI), /* SCI3 TEI (Transmit end) */
            [28] = BSP_PRV_IELS_ENUM(EVENT_SCI3_ERI), /* SCI3 ERI (Receive error) */
            [29] = BSP_PRV_IELS_ENUM(EVENT_SCI4_RXI), /* SCI4 RXI (Received data full) */
            [30] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TXI), /* SCI4 TXI (Transmit data empty) */
            [31] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TEI), /* SCI4 TEI (Transmit end) */
            [32] = BSP_PRV_IELS_ENUM(EVENT_SCI4_ERI), /* SCI4 ERI (Receive error) */
        };
        #endif