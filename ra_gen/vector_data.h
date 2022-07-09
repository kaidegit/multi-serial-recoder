/* generated vector header file - do not edit */
        #ifndef VECTOR_DATA_H
        #define VECTOR_DATA_H
                /* Number of interrupts allocated */
        #ifndef VECTOR_DATA_IRQ_COUNT
        #define VECTOR_DATA_IRQ_COUNT    (17)
        #endif
        /* ISR prototypes */
        void sci_uart_rxi_isr(void);
        void sci_uart_txi_isr(void);
        void sci_uart_tei_isr(void);
        void sci_uart_eri_isr(void);
        void r_icu_isr(void);
        void usbfs_interrupt_handler(void);
        void usbfs_resume_handler(void);
        void usbfs_d0fifo_handler(void);
        void usbfs_d1fifo_handler(void);
        void spi_rxi_isr(void);
        void spi_txi_isr(void);
        void spi_tei_isr(void);
        void spi_eri_isr(void);

        /* Vector table allocations */
        #define VECTOR_NUMBER_SCI6_RXI ((IRQn_Type) 0) /* SCI6 RXI (Received data full) */
        #define SCI6_RXI_IRQn          ((IRQn_Type) 0) /* SCI6 RXI (Received data full) */
        #define VECTOR_NUMBER_SCI6_TXI ((IRQn_Type) 1) /* SCI6 TXI (Transmit data empty) */
        #define SCI6_TXI_IRQn          ((IRQn_Type) 1) /* SCI6 TXI (Transmit data empty) */
        #define VECTOR_NUMBER_SCI6_TEI ((IRQn_Type) 2) /* SCI6 TEI (Transmit end) */
        #define SCI6_TEI_IRQn          ((IRQn_Type) 2) /* SCI6 TEI (Transmit end) */
        #define VECTOR_NUMBER_SCI6_ERI ((IRQn_Type) 3) /* SCI6 ERI (Receive error) */
        #define SCI6_ERI_IRQn          ((IRQn_Type) 3) /* SCI6 ERI (Receive error) */
        #define VECTOR_NUMBER_ICU_IRQ0 ((IRQn_Type) 4) /* ICU IRQ0 (External pin interrupt 0) */
        #define ICU_IRQ0_IRQn          ((IRQn_Type) 4) /* ICU IRQ0 (External pin interrupt 0) */
        #define VECTOR_NUMBER_USBFS_INT ((IRQn_Type) 5) /* USBFS INT (USBFS interrupt) */
        #define USBFS_INT_IRQn          ((IRQn_Type) 5) /* USBFS INT (USBFS interrupt) */
        #define VECTOR_NUMBER_USBFS_RESUME ((IRQn_Type) 6) /* USBFS RESUME (USBFS resume interrupt) */
        #define USBFS_RESUME_IRQn          ((IRQn_Type) 6) /* USBFS RESUME (USBFS resume interrupt) */
        #define VECTOR_NUMBER_USBFS_FIFO_0 ((IRQn_Type) 7) /* USBFS FIFO 0 (DMA transfer request 0) */
        #define USBFS_FIFO_0_IRQn          ((IRQn_Type) 7) /* USBFS FIFO 0 (DMA transfer request 0) */
        #define VECTOR_NUMBER_USBFS_FIFO_1 ((IRQn_Type) 8) /* USBFS FIFO 1 (DMA transfer request 1) */
        #define USBFS_FIFO_1_IRQn          ((IRQn_Type) 8) /* USBFS FIFO 1 (DMA transfer request 1) */
        #define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 9) /* SPI0 RXI (Receive buffer full) */
        #define SPI0_RXI_IRQn          ((IRQn_Type) 9) /* SPI0 RXI (Receive buffer full) */
        #define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 10) /* SPI0 TXI (Transmit buffer empty) */
        #define SPI0_TXI_IRQn          ((IRQn_Type) 10) /* SPI0 TXI (Transmit buffer empty) */
        #define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 11) /* SPI0 TEI (Transmission complete event) */
        #define SPI0_TEI_IRQn          ((IRQn_Type) 11) /* SPI0 TEI (Transmission complete event) */
        #define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 12) /* SPI0 ERI (Error) */
        #define SPI0_ERI_IRQn          ((IRQn_Type) 12) /* SPI0 ERI (Error) */
        #define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 13) /* SCI0 RXI (Receive data full) */
        #define SCI0_RXI_IRQn          ((IRQn_Type) 13) /* SCI0 RXI (Receive data full) */
        #define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 14) /* SCI0 TXI (Transmit data empty) */
        #define SCI0_TXI_IRQn          ((IRQn_Type) 14) /* SCI0 TXI (Transmit data empty) */
        #define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 15) /* SCI0 TEI (Transmit end) */
        #define SCI0_TEI_IRQn          ((IRQn_Type) 15) /* SCI0 TEI (Transmit end) */
        #define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 16) /* SCI0 ERI (Receive error) */
        #define SCI0_ERI_IRQn          ((IRQn_Type) 16) /* SCI0 ERI (Receive error) */
        #endif /* VECTOR_DATA_H */