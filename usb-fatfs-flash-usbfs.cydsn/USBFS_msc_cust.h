/*****************************************************************************
* File Name: USBFS_msc.h
* Version 2.19
*
* Description:
*  This file contains the function prototypes and constants used in
*  the USBFS_msc.c.
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
#if(!defined(USBFS_MSC_H))
#define USBFS_MSC_H
	
#include "cytypes.h"

#define ZERO									0x00
	
#define TRUE									0x01
#define FALSE									0x00
#define TRY_HOST_RESET							0x03

#define MSC_EP_IN								0x01
#define MSC_EP_OUT								0x02

#define UBSFS_MSC_EP_IN_PTR						USBFS_SIE_EP3_CR0_PTR
#define UBSFS_MSC_EP_OUT_PTR					USBFS_SIE_EP4_CR0_PTR

#define IN_EP_BUF_SIZE							64
#define OUT_EP_BUF_SIZE							64
	
#define USBFS_MSC_MASS_STORAGE_RESET			0xFF
#define USBFS_MSC_GET_MAX_LUN					0xFE

#define USBFS_MSC_MAX_LUN_NUMBER				0x00

#define CBWCB_MAX_SIZE							0x10
	
	
#define MSC_READY_STATE							0x00
#define MSC_COMMAND_TRANSPORT					0x01
#define MSC_DATA_OUT							0x02
#define MSC_DATA_IN								0x03
#define MSC_NO_DATA								0x04
#define MSC_STATUS_TRANSPORT					0x05
#define MSC_STALL_IN_ENDPOINT					0x06
#define MSC_STALL_OUT_ENDPOINT					0x07
#define MSC_WAIT_FOR_RESET						0x08

#define MSC_CBW_SIZE							0x1F
#define MSC_CSW_SIZE							0x0D

#define MSC_MAX_CBWCB_LEN						0x10

#define MSC_CBW_SIGNATURE						0x43425355
#define MSC_CSW_SIGNATURE						0x53425355
	
#define USBFS_MSC_CSW_PASS		                0x00
#define USBFS_MSC_CSW_FAIL      		        0x01
#define USBFS_MSC_CSW_PHASE_ERROR               0x02
	
#define MSC_CBWFLAG_DIRECTION_MASK				0x80
	
uint8 USBFS_MSC_InEPBuffer[IN_EP_BUF_SIZE];
uint8 USBFS_MSC_OutEPBuffer[OUT_EP_BUF_SIZE];

typedef struct
{
	uint32 dCBWSignature;
	uint32 dCBWTag;
	uint32 dCBWDataTransferLength;
	uint8 bmCBWFlags;
	uint8 bCBWLUN;
	uint8 bCBWCBLength;
	uint8 CBWCB[CBWCB_MAX_SIZE];
} CommandBlockWrapper;

typedef struct
{
	uint32 dCSWSignature;
	uint32 dCSWTag;
	uint32 dCSWDataResidue;
	uint8 bCSWStatus;
} CommandStatusWrapper;
	
void USBFS_HandleMassStorageInRequests(void);
void USBFS_HandleMassStorageOutRequests(void);

uint8 USBFS_DispatchMSCClassRqst(void);
void USBFS_InitializeMSC(void);

void USBFS_MSC_StallInEP(void);
void USBFS_MSC_StallOutEP(void);

#define USBFS_MSC_SRAM_END_LOC			30000//8000

#define USBFS_MSC_TOTAL_MEM_SIZE		600000
#define USBFS_MSC_BLOCKSIZE				512
#define USBFS_MSC_NUM_OF_BLOCKS			(USBFS_MSC_TOTAL_MEM_SIZE/USBFS_MSC_BLOCKSIZE)
#define USBFS_MSC_EM_IMAGE_SIZE 		0x00006400//0x00001000

#endif /* USBFS_MSC_H */

/* [] END OF FILE */


