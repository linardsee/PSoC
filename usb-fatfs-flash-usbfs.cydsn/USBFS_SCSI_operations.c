/*****************************************************************************
* File Name: USBFS_SCSI_operations.c
*
* Version 2.19
*
* Description: This file provides routines to handle the SCSI requests from 
*   the host.
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*   Ivan Grytsyk, Applications Engineer Sr (gryt@cypress.com)
*   Vasyl Rodionov, Staff Systems Engr (rodi@cypress.com)
*
* Related Document:
* 	SCSI Command Reference Manual:
*	http://www.seagate.com/staticfiles/support/disc/manuals/scsi/100293068a.pdf
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
*	CY8CKIT-044, -046, -042, -042 BLE, BLE Dongle, -040, -042 BLE-A
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
//#include "version.h"
#include "project.h"
#include "USBFS_msc_cust.h"
#include "USBFS_SCSI_operations.h"


#define	VERSION_STRING      "0219"

/* Variable to keep track of when to send a Test Unit Ready
 * fail status to force a read from the host. */
uint8 forceOS = FALSE;

uint8 statusFileTimer = ZERO;

static uint8 mediaEjectedState = FALSE;

/* Variable to keep track of failed commands. */
static uint8 commandFailed = FALSE;

/* Should not exceet 8 characters. */
CYCODE unsigned char vendorIDT10[] = "ANKS ";

/* Should not exceet 16 characters. */
CYCODE unsigned char productID[] = "HIMA";

/* Match this with VER_MAJOR, VER_MINOR defined in version.h */
CYCODE unsigned char productRev[] = VERSION_STRING;

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_TestUnitReady()
********************************************************************************
* Summary:
*  Responds to the periodic Test Unit Ready Command from host. Send PASS by default.
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS/FAIL.
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_PreventMediaRemoval(uint8 prevent)
{
	cystatus commandStatus = USBFS_MSC_CSW_FAIL;

	if(prevent == FALSE)
	{
		/* Send pass if prevent is not enabled. */
		commandStatus = USBFS_MSC_CSW_PASS;
	}
	else
	{
		/* Send a fail response for command to force
		 * the OS to initiate a Request Sense. */
		commandStatus = USBFS_MSC_CSW_FAIL;
		commandFailed = TRUE;
	}
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_TestUnitReady()
********************************************************************************
* Summary:
*  Responds to the periodic Test Unit Ready Command from host. Send PASS by default.
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS/FAIL.
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_TestUnitReady(void)
{
	cystatus commandStatus = USBFS_MSC_CSW_FAIL;
	
	if(mediaEjectedState == TRUE)
	{
		/* Send a fail response for Test Unit Ready command 
		 * since the media is in ejected state. */
		commandStatus = USBFS_MSC_CSW_FAIL;
	}
	else
	{
		if(forceOS == FALSE)
		{
			/*Send pass by default. */
			commandStatus = USBFS_MSC_CSW_PASS;
		}
		else
		{
			if(statusFileTimer >= STATUS_FILE_TIMEOUT)
			{
				statusFileTimer = ZERO;
				
				/* Send a fail response for Test Unit Ready command to force
				 * the OS to initiate a Request Sense. */
				commandStatus = USBFS_MSC_CSW_FAIL;
			}
			else
			{
				/*Send pass for one more request before failing. */
				commandStatus = USBFS_MSC_CSW_PASS;
			}
		}
	}
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_RequestSense()
********************************************************************************
* Summary:
*  
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_RequestSense(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	memset(USBFS_MSC_InEPBuffer, ZERO, *numOfBytes);
	
	USBFS_MSC_InEPBuffer[ 0] = SENSE_RESPONSE_CODE;

	USBFS_MSC_InEPBuffer[ 7] = SENSE_ADDITIONAL_LENGTH;
	
	if((forceOS == FALSE) && (commandFailed == FALSE) && (mediaEjectedState == FALSE))
	{
		USBFS_MSC_InEPBuffer[ 2] = SENSE_KEY_NO_SENSE;
		
		USBFS_MSC_InEPBuffer[12] = SENSE_ASC_NO_SENSE;  
		USBFS_MSC_InEPBuffer[13] = SENSE_ASCQ_NO_SENSE; 
	}
	else
	{
		if(commandFailed == TRUE)
		{
			USBFS_MSC_InEPBuffer[ 2] = SENSE_KEY_ILLEGAL_REQUEST;
			
			USBFS_MSC_InEPBuffer[12] = SENSE_ASC_INVALID_FIELD_IN_CDB;
			USBFS_MSC_InEPBuffer[13] = SENSE_ASCQ_NO_SENSE;    
			commandFailed = FALSE;
		}
		
		if(forceOS == TRUE)
		{
			USBFS_MSC_InEPBuffer[ 2] = SENSE_KEY_UNIT_ATTENTION;
			
			USBFS_MSC_InEPBuffer[12] = SENSE_ASC_MEDIA_REMOVAL;
			USBFS_MSC_InEPBuffer[13] = SENSE_ASCQ_NO_SENSE;    
			forceOS = FALSE;
			statusFileTimer = ZERO;
		}
		
		/* If the host has sent a command to eject the drive,
		 * send not ready until re-mounted. */
		if(mediaEjectedState == TRUE)
		{
			USBFS_MSC_InEPBuffer[ 2] = SENSE_KEY_NOT_READY;
			
			USBFS_MSC_InEPBuffer[12] = SENSE_ASC_MEDIA_REMOVAL;
			USBFS_MSC_InEPBuffer[13] = SENSE_ASCQ_NO_SENSE;    
		}
	}
	
	*numOfBytes = 18;
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_FormatUnit()
********************************************************************************
* Summary:
*  Function returns fail as the file system does not support formatting.
*
* Parameters:
*  void
*
* Return:
*  cystatus: FAIL
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_FormatUnit(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_FAIL;
	
	commandFailed = TRUE;
	
	*numOfBytes = ZERO;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_Inquiry()
********************************************************************************
* Summary:
*  Sends the details about the Mass Storage device to host. 
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_Inquiry(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	uint8 index = ZERO;
	
	USBFS_MSC_InEPBuffer[ 0] = INQUIRY_PERIPHERAL_TYPE; 
	USBFS_MSC_InEPBuffer[ 1] = INQUIRY_REMOVABLE;        
	USBFS_MSC_InEPBuffer[ 2] = INQUIRY_NO_STANDARD;      
	USBFS_MSC_InEPBuffer[ 3] = INQUIRY_RESPONSE_DATA_FORMAT;

	USBFS_MSC_InEPBuffer[ 4] = INQUIRY_ADDITIONAL_LENGTH; 
	USBFS_MSC_InEPBuffer[ 5] = INQUIRY_SCSI_STORAGE_CONTROLLER_PRESENT; 
	USBFS_MSC_InEPBuffer[ 6] = INQUIRY_MEDIUM_CHANGER_DEVICE;
	USBFS_MSC_InEPBuffer[ 7] = ZERO;

	/* T10 Vendor Identification. */
	for(index = ZERO; index < sizeof(vendorIDT10); index++)
	{
		USBFS_MSC_InEPBuffer[8 + index] = vendorIDT10[index];
	}

	/* Product Identification */
	for(index = ZERO; index < sizeof(productID); index++)
	{
		USBFS_MSC_InEPBuffer[16 + index] = productID[index];
	}

	/* Product Revision Level */
	for(index = ZERO; index < sizeof(productRev); index++)
	{
		USBFS_MSC_InEPBuffer[32 + index] = productRev[index];
	}

	*numOfBytes = 36;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ModeSelect6()
********************************************************************************
* Summary:
*  This command is not supported as of now.
*
* Parameters:
*  void
*
* Return:
*  cystatus: FAIL
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ModeSelect6(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_FAIL;
	
	commandFailed = TRUE;
	
	*numOfBytes = ZERO;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ModeSense6()
********************************************************************************
* Summary:
*  Responds to the SCSI Mode Sense6 command. (Ref: Section 4.3 of SCSI Manual)
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ModeSense6(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	USBFS_MSC_InEPBuffer[ 0] = MODE_SENSE6_BLOCK_LENGTH;
	USBFS_MSC_InEPBuffer[ 1] = DEFAULT_MEDIUM_TYPE;
	USBFS_MSC_InEPBuffer[ 2] = ZERO;
	USBFS_MSC_InEPBuffer[ 3] = ZERO;

	*numOfBytes = 4;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ModeSense10()
********************************************************************************
* Summary:
*  Polls the status of the programmer 
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ModeSense10(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	memset(USBFS_MSC_InEPBuffer, ZERO, *numOfBytes);
	
	USBFS_MSC_InEPBuffer[ 1] = MODE_SENSE10_BLOCK_LENGTH;
	USBFS_MSC_InEPBuffer[ 2] = DEFAULT_MEDIUM_TYPE;

	*numOfBytes = 8;
	return(commandStatus);
}
	
/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_StartStopUnit()
********************************************************************************
* Summary:
*  This command responds to the eject/mount requests from the host.
*
* Parameters:
*  void
*
* Return:
*  cystatus: FAIL
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_StartStopUnit(uint8 ejectIndicator)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	if((ejectIndicator & LOEJ_BIT_FIELD) != ZERO)
	{
		if((ejectIndicator & START_BIT_FIELD) == TRUE)
		{
			mediaEjectedState = FALSE;
		}
		else
		{
			mediaEjectedState = TRUE;
		}
	}
	
	return(commandStatus);	
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ReadFormatCapacities()
********************************************************************************
* Summary:
*  Supported since required by Windows. 
*  Ref: ftp://www.t10.org/t10/t10r/2003/r0310162.htm
*  http://janaxelson.com/mass_storage_faq.htm
*  http://www.13thmonkey.org/documentation/SCSI/mmc2r11a.pdf
* 
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ReadFormatCapacities(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	USBFS_MSC_InEPBuffer[ 0] = 0x00;
	USBFS_MSC_InEPBuffer[ 1] = 0x00;
	USBFS_MSC_InEPBuffer[ 2] = 0x00;
	USBFS_MSC_InEPBuffer[ 3] = FORMAT_CAP_LIST_LENGTH;

	/* Number of Blocks */
	USBFS_MSC_InEPBuffer[ 4] = HI8(HI16(USBFS_MSC_NUM_OF_BLOCKS)); 
	USBFS_MSC_InEPBuffer[ 5] = LO8(HI16(USBFS_MSC_NUM_OF_BLOCKS)); 
	USBFS_MSC_InEPBuffer[ 6] = HI8(LO16(USBFS_MSC_NUM_OF_BLOCKS)); 
	USBFS_MSC_InEPBuffer[ 7] = LO8(LO16(USBFS_MSC_NUM_OF_BLOCKS)); 

	/* Block Length */
	USBFS_MSC_InEPBuffer[ 8] = FORMAT_CAP_FORMATTED_MEDIA;        
	USBFS_MSC_InEPBuffer[ 9] = LO8(HI16(USBFS_MSC_BLOCKSIZE)); 
	USBFS_MSC_InEPBuffer[10] = HI8(LO16(USBFS_MSC_BLOCKSIZE)); 
	USBFS_MSC_InEPBuffer[11] = LO8(LO16(USBFS_MSC_BLOCKSIZE)); 

	*numOfBytes = 12;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ReadCapacity()
********************************************************************************
* Summary:
*  Polls the status of the programmer 
*
* Parameters:
*  void
*
* Return:
*  cystatus: PASS
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ReadCapacity(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_PASS;
	
	/* Returned Logical Block Address of Last Block */
	USBFS_MSC_InEPBuffer[ 0] = HI8(HI16(USBFS_MSC_TOTAL_MEM_SIZE)); 
	USBFS_MSC_InEPBuffer[ 1] = LO8(HI16(USBFS_MSC_TOTAL_MEM_SIZE)); 
	USBFS_MSC_InEPBuffer[ 2] = HI8(LO16(USBFS_MSC_TOTAL_MEM_SIZE)); 
	USBFS_MSC_InEPBuffer[ 3] = LO8(LO16(USBFS_MSC_TOTAL_MEM_SIZE)); 

	/* Block Length */
	USBFS_MSC_InEPBuffer[ 4] = HI8(HI16(USBFS_MSC_BLOCKSIZE)); 
	USBFS_MSC_InEPBuffer[ 5] = LO8(HI16(USBFS_MSC_BLOCKSIZE)); 
	USBFS_MSC_InEPBuffer[ 6] = HI8(LO16(USBFS_MSC_BLOCKSIZE)); 
	USBFS_MSC_InEPBuffer[ 7] = LO8(LO16(USBFS_MSC_BLOCKSIZE)); 

	*numOfBytes = 8;
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_MSC_SCSI_ModeSelect10()
********************************************************************************
* Summary:
*  This command is not supported as of now.
*
* Parameters:
*  void
*
* Return:
*  cystatus: FAIL
*
*******************************************************************************/
cystatus USBFS_MSC_SCSI_ModeSelect10(uint8 *numOfBytes)
{
	cystatus commandStatus = USBFS_MSC_CSW_FAIL;
	
	commandFailed = TRUE;
	
	*numOfBytes = ZERO;
	
	return(commandStatus);
}


/* [] END OF FILE */


