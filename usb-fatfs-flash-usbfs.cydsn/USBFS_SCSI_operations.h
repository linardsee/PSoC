/*****************************************************************************
* File Name: USBFS_SCSI_operations.h
* Version 2.19
*
* Description:
*  This file contains the function prototypes and constants used in
*  the USBFS_SCSI_operations.c.
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
#if(!defined(USBFS_SCSI_OPERATIONS_H))
#define USBFS_SCSI_OPERATIONS_H
	
#include "cytypes.h"

#define USBFS_MSC_SCSI_TEST_UNIT_READY				0x00
#define USBFS_MSC_SCSI_REQUEST_SENSE              	0x03
#define USBFS_MSC_SCSI_FORMAT_UNIT                	0x04
#define USBFS_MSC_SCSI_INQUIRY                    	0x12
#define USBFS_MSC_SCSI_MODE_SELECT6               	0x15
#define USBFS_MSC_SCSI_MODE_SENSE6                	0x1A
#define USBFS_MSC_SCSI_START_STOP_UNIT            	0x1B
#define USBFS_MSC_SCSI_MEDIA_REMOVAL              	0x1E
#define USBFS_MSC_SCSI_READ_FORMAT_CAPACITIES     	0x23
#define USBFS_MSC_SCSI_READ_CAPACITY              	0x25
#define USBFS_MSC_SCSI_READ10                     	0x28
#define USBFS_MSC_SCSI_WRITE10                    	0x2A
#define USBFS_MSC_SCSI_VERIFY10                   	0x2F
#define USBFS_MSC_SCSI_MODE_SELECT10              	0x55
#define USBFS_MSC_SCSI_MODE_SENSE10               	0x5A
	
/* Request Sense */
#define SENSE_RESPONSE_CODE							0x70
#define SENSE_KEY_NO_SENSE							0x00
#define SENSE_KEY_NOT_READY							0x02
#define SENSE_KEY_ILLEGAL_REQUEST					0x05
#define SENSE_KEY_UNIT_ATTENTION					0x06
#define SENSE_ADDITIONAL_LENGTH						0x0A
#define SENSE_ASC_NO_SENSE							0x00
#define SENSE_ASC_MEDIA_REMOVAL						0x3A
#define SENSE_ASC_INVALID_FIELD_IN_CDB				0x24
#define SENSE_ASCQ_NO_SENSE							0x00
	
/* Inquiry */
#define DIRECT_ACCESS_DEVICE						0x00
	
#define INQUIRY_PERIPHERAL_TYPE						DIRECT_ACCESS_DEVICE
#define INQUIRY_REMOVABLE							0x80
#define INQUIRY_NO_STANDARD							0x00
#define INQUIRY_RESPONSE_DATA_FORMAT				0x01
#define INQUIRY_ADDITIONAL_LENGTH					0x20
#define INQUIRY_SCSI_STORAGE_CONTROLLER_PRESENT		0x80
#define INQUIRY_MEDIUM_CHANGER_DEVICE				0x08

/* Mode Sense 6 */
#define DEFAULT_MEDIUM_TYPE							0x00
#define MODE_SENSE6_BLOCK_LENGTH					0x03
	
/* Mode Sense 10 */
#define MODE_SENSE10_BLOCK_LENGTH					0x06
	
/* Read fromat capacity */
#define FORMAT_CAP_LIST_LENGTH						0x08
#define FORMAT_CAP_FORMATTED_MEDIA					0x02
	
/* Start Stop Unit */
#define LOEJ_BIT_FIELD								0x02
#define START_BIT_FIELD								0x01
	
#define STATUS_FILE_TIMEOUT							200
	
	
cystatus USBFS_MSC_SCSI_TestUnitReady(void);
cystatus USBFS_MSC_SCSI_RequestSense(uint8 *);
cystatus USBFS_MSC_SCSI_FormatUnit(uint8 *);
cystatus USBFS_MSC_SCSI_Inquiry(uint8 *);
cystatus USBFS_MSC_SCSI_ModeSelect6(uint8 *);
cystatus USBFS_MSC_SCSI_ModeSense6(uint8 *);
cystatus USBFS_MSC_SCSI_StartStopUnit(uint8);
cystatus USBFS_MSC_SCSI_ReadFormatCapacities(uint8 *);
cystatus USBFS_MSC_SCSI_ReadCapacity(uint8 *);
cystatus USBFS_MSC_SCSI_ModeSelect10(uint8 *);
cystatus USBFS_MSC_SCSI_ModeSense10(uint8 *);
cystatus USBFS_MSC_SCSI_PreventMediaRemoval(uint8);
	
#endif	/* USBFS_SCSI_OPERATIONS_H */

/* [] END OF FILE */


