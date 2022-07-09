#include "usbd_cdc.h"

#include "hal_data.h"
#include "r_usb_basic.h"

#define LINE_CODING_LENGTH 0x07
#define READ_BUF_SIZE 8

usb_status_t usb_event;
usb_setup_t usb_setup;
uint8_t g_usb_module_number = 0x00;
usb_class_t g_usb_class_type = 0x00;
static usb_pcdc_linecoding_t g_line_coding;
fsp_err_t err = FSP_SUCCESS;
uint8_t g_buf[READ_BUF_SIZE] = {0};
static bool b_usb_attach = false;

extern uint8_t g_apl_device[];
extern uint8_t g_apl_configuration[];
extern uint8_t g_apl_hs_configuration[];
extern uint8_t g_apl_qualifier_descriptor[];
extern uint8_t *g_apl_string_table[];

const usb_descriptor_t g_usb_descriptor = {g_apl_device,               /* Pointer to the device descriptor */
                                         g_apl_configuration,        /* Pointer to the configuration descriptor for Full-speed */
                                         g_apl_hs_configuration,     /* Pointer to the configuration descriptor for Hi-speed */
                                         g_apl_qualifier_descriptor, /* Pointer to the qualifier descriptor */
                                         g_apl_string_table,         /* Pointer to the string descriptor table */
                                         7U};

void usbd_cdc(void *para) {
    R_USB_Open(&g_basic0_ctrl, &g_basic0_cfg);
    R_USB_ClassTypeGet(&g_basic0_ctrl, &g_usb_class_type);
    R_USB_ModuleNumberGet(&g_basic0_ctrl, &g_usb_module_number);
    while (1) {
        R_USB_EventGet(&g_basic0_ctrl, &usb_event);
        switch (usb_event) {
            case USB_STATUS_CONFIGURED: {
                err = R_USB_Read(&g_basic0_ctrl, g_buf, READ_BUF_SIZE, (uint8_t)g_usb_class_type);
                break;
            }

            case USB_STATUS_READ_COMPLETE: {
                if (b_usb_attach) {
                    err = R_USB_Read(&g_basic0_ctrl, g_buf, 1, (uint8_t)g_usb_class_type);
                }
                break;
            }

            case USB_STATUS_REQUEST: /* Receive Class Request */
            {
                R_USB_SetupGet(&g_basic0_ctrl, &usb_setup);

                /* Check for the specific CDC class request IDs */
                if (USB_PCDC_SET_LINE_CODING == (usb_setup.request_type & USB_BREQUEST)) {
                    err = R_USB_PeriControlDataGet(&g_basic0_ctrl, (uint8_t *)&g_line_coding, LINE_CODING_LENGTH);
                } else if (USB_PCDC_GET_LINE_CODING == (usb_setup.request_type & USB_BREQUEST)) {
                    err = R_USB_PeriControlDataSet(&g_basic0_ctrl, (uint8_t *)&g_line_coding, LINE_CODING_LENGTH);
                } else if (USB_PCDC_SET_CONTROL_LINE_STATE == (usb_setup.request_type & USB_BREQUEST)) {
                    err = R_USB_PeriControlStatusSet(&g_basic0_ctrl, USB_SETUP_STATUS_ACK);
                } else {
                }

                break;
            }

            case USB_STATUS_DETACH:
            case USB_STATUS_SUSPEND: {
                b_usb_attach = false;
                memset(g_buf, 0, sizeof(g_buf));
                break;
            }
            case USB_STATUS_RESUME: {
                b_usb_attach = true;
                break;
            }
            default: {
                break;
            }
        }
        // rt_thread_mdelay(1);
    }
}

//static fsp_err_t check_for_write_complete(void) {
//    usb_status_t usb_write_event = USB_STATUS_NONE;
//    int32_t timeout_count = 200;  // about 200ms
//    fsp_err_t err = FSP_SUCCESS;
//
//    do {
//        err = R_USB_EventGet(&g_basic0_ctrl, &usb_write_event);
//        if (FSP_SUCCESS != err) {
//            return err;
//        }
//
//        --timeout_count;
//
//        if (0 > timeout_count) {
//            timeout_count = 0;
//            err = (fsp_err_t)USB_STATUS_NONE;
//            break;
//        }
//        rt_thread_mdelay(1);
//    } while (USB_STATUS_WRITE_COMPLETE != usb_write_event);
//
//    return err;
//}

fsp_err_t usbd_print(char *p_data, uint16_t len) {
    fsp_err_t err = FSP_SUCCESS;

    err = R_USB_Write(&g_basic0_ctrl, (uint8_t *)p_data, len, (uint8_t)g_usb_class_type);
//    /* Handle error */
//    if (FSP_SUCCESS != err) {
//        return err;
//    }
//
//    err = check_for_write_complete();
//    if (FSP_SUCCESS != err) {
//        /* Did not get the event hence returning error */
//        return FSP_ERR_USB_FAILED;
//    }
    return err;
}
