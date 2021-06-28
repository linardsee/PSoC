/*****************************************************************************
* File Name: general.h
* Version 2.19
*
* Description:
*  This file contains the function prototypes and constants used in
*  main.c
*
* Owner:
*   Ivan Grytsyk, Applications Engineer Sr (gryt@cypress.com)
*   Vasyl Rodionov, Staff Systems Engr (rodi@cypress.com)
*
* Related Document:
* 	001-85925 - CY8CKIT-042 PSoC 4 Pioneer Kit IROS
*
* Hardware Dependency:
* 	CY8CKIT-042, 
*   CY3280-MBR3, 
*   CY8CKIT-193,
*   CY3679 Atlas EVK,
*   CY8CKIT-044,
*   CY8CKIT-046,
*   CY8CKIT-042 BLE,
*   CY3676  Hercules EVK,
*   CY3677  Hercules EVK
*
* Code Tested With:
* 	Creator 3.3 CP3(3.3.0.9604)
*	GCC 4.9-2015-q1-update(Cypress provided)
*	CY8CKIT-042 
*
* Note:
*
******************************************************************************
* Copyright (2016), Cypress Semiconductor Corporation.
******************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*****************************************************************************/
#if !defined(GENERAL_H) 
#define GENERAL_H 


#include "project.h"
#include "cyfitter.h"
//#include "DAP.h"

//#include "commandprocessor.h"
//#include "USBFS_commandinterface.h"
//#include "USBFS_HID_interface.h"
//#include "proc.h"
//#include "prog.h"
//#include "swd.h"
//#include "tc.h"
//#include "power.h"
//#include "USBUART.h"
//#include "version.h"
//#include "hex_signature.h"
#include "cyapicallbacks.h"
 

/* USB endpoint usage */
#define CMSIS_IN_EP						0x01
#define CMSIS_OUT_EP					0x02

#define HID_REPORT_INPUT			    0x01
#define HID_REPORT_FEATURE			    0x02
#define HID_REPORT_OUTPUT			    0x03
#define USBD_HID_REQ_EP_INT			    0x04
#define USBD_HID_REQ_EP_CTRL		    0x05
#define USBD_HID_REQ_PERIOD_UPDATE	    0x06
    

/*****************************************************************************
* MACRO Definition
*****************************************************************************/
#define FALSE                       0x00
#define TRUE                        0x01

#define IDLE                        0x00
#define BUSY                        0x02
#define ERROR                       0xFF
    
/* USB endpoint usage */
#define SWD_IN_EP                  	(0x01u)
#define SWD_OUT_EP                 	(0x02u)
#define HOST_IN_EP					(0x03u)
#define HOST_OUT_EP					(0x04u)
#define UART_INT_EP 				(0x05u)
#define UART_IN_EP	 				(0x06u)
#define UART_OUT_EP 				(0x07u)

#define RESET						(0x00u)
#define USB_WAIT_FOR_VBUS			(0x01u)
#define USB_START_COMPONENT			(0x02u)
#define USB_WAIT_FOR_CONFIG			(0x03u)
#define USB_CONFIGURED				(0x04u)
#define USB_MSC_READY				(0x06u)
#define USB_HALT					(0x07u)

#define RESET_ASSERTED				(0x00u)
#define RESET_RELEASED				(0x01u)

#define ONE_MS_DELAY				(0x01u)
#define MODE_SWITCHING_TIMEOUT		(600u)  /* in units of 5 ms */

#define STATUS_MSG_SIZE				(59u)
	
/*****************************************************************************
* Data Type Definition
*****************************************************************************/


/*****************************************************************************
* Enumerated Data Definition
*****************************************************************************/


/*****************************************************************************
* Data Struct Definition
*****************************************************************************/


/*****************************************************************************
* Global Variable Declaration
*****************************************************************************/
extern volatile uint8 USBResetDetected;
extern uint8 bOutEndpointData[64];
extern uint8 bInEndpointData[64];
extern uint8 bOutPacketIndex;
extern uint8 bInPacketIndex;
extern uint8 beginDataParsing;
extern uint8 forceOS;
extern uint8 statusFileTimer;
extern uint8 usbDapReadFlag;



extern uint32 currentSiliconId;
extern uint8 deviceHasImo48Step;
extern volatile uint8 modeChangeFlag;

/*****************************************************************************
* Function Prototypes
*****************************************************************************/
void SetStatus(const unsigned char *);
void InitMassStorage(void);





#endif /* GENERAL_H */


