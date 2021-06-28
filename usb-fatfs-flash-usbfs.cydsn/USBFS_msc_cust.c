/*****************************************************************************
* File Name: USBFS_msc.c
*
* Version 2.19
*
* Description: This file provides routines to handle the USB mass storage
*   class requests.
*
* Owner:
*	Ranjith M, Applications Engineer (rnjt@cypress.com)
*   Ivan Grytsyk, Applications Engineer Sr (gryt@cypress.com)
*   Vasyl Rodionov, Staff Systems Engr (rodi@cypress.com)
*
* Related Document:
* 	USB Mass Storage Class Specification: 
*   http://www.usb.org/developers/docs/devclass_docs/usbmassbulk_10.pdf
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
#include "project.h"
#include "diskio.h"
#include "USBFS_msc_cust.h"
#include "USBFS_SCSI_operations.h"
//#include "hexParser.h"
#include "general.h"

static CommandBlockWrapper USBFS_MSC_CBW;
static CommandStatusWrapper USBFS_MSC_CSW;

static uint8 currState = MSC_READY_STATE;
static uint32 USBFS_MSC_BytesToTransfer = ZERO;
static uint32 USBFS_MSC_StartLocation = ZERO;

static uint8 resetRecovery = FALSE;

//extern uint8 beginDataParsing;

/*******************************************************************************
* Function Name: USBFS_DispatchMSCClassRqst()
********************************************************************************
* Summary:
*  Class request handler for MSC. 
*  Ref: Page 7, http://www.usb.org/developers/docs/devclass_docs/usbmassbulk_10.pdf
*
* Parameters:
*  void
*
* Return:
*  uint8: requestHandled
*
*******************************************************************************/
uint8 USBFS_DispatchMSCClassRqst(void) 
{
	uint8 requestHandled = USBFS_FALSE;

    if ((CY_GET_REG8(USBFS_bmRequestType) & USBFS_RQST_DIR_MASK) == USBFS_RQST_DIR_D2H)
    {   /* Control Read */
        switch (CY_GET_REG8(USBFS_bRequest))
        {
            case USBFS_MSC_GET_MAX_LUN:
				USBFS_currentTD.count = 0x01;
                USBFS_currentTD.pData = 0x00;
                requestHandled  = USBFS_InitControlRead();
//                requestHandled = USBFS_InitZeroLengthControlTransfer();
                break;

            /* `#START MSC_READ_REQUESTS` Place other request handler here */

            /* `#END` */

            default:    /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    else if ((CY_GET_REG8(USBFS_bmRequestType) & USBFS_RQST_DIR_MASK) == \
                                                                            USBFS_RQST_DIR_H2D)
    {   /* Control Write */
        switch (CY_GET_REG8(USBFS_bRequest))
        {
            case USBFS_MSC_MASS_STORAGE_RESET:
				resetRecovery = TRUE;
                requestHandled = USBFS_InitNoDataControlTransfer();
                break;

            /* `#START MSC_WRITE_REQUESTS` Place other request handler here */

            /* `#END` */

            default:    /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    else
    {   
		/* requestHandled is initialized as FALSE by default */
    }

    return(requestHandled);	
}

/*******************************************************************************
* Function Name: USBFS_MSC_ReadOutEP
********************************************************************************
*
* Summary:
*  Read data from an endpoint.  This is copied from the generated files of USBFS
*  and modified to remove the automatic re-arming of the endpoint from within 
*  the API.
*
* Parameters:
*  epNumber: Contains the data endpoint number.
*            Valid values are between 1 and 8.
*  pData: A pointer to a data array from which the data for the endpoint space
*         is loaded.
*  length: The number of bytes to transfer from the USB Out endpoint and loads
*          it into data array. Valid values are between 0 and 1023. The function
*          moves fewer than the requested number of bytes if the host sends
*          fewer bytes than requested.
*
* Returns:
*  None.
*******************************************************************************/
static void USBFS_MSC_ReadOutEP(uint8 epNumber, uint8 pData[], uint16 length)
{
    uint8 ri;
    reg8 *p;
    uint16 index;

    ri = ((epNumber - USBFS_EP1) << USBFS_EPX_CNTX_ADDR_SHIFT);
    p = (reg8 *)(USBFS_ARB_RW1_DR_IND + ri);

    /* Copy the data using the arbiter data register */
    for (index = 0u; index < length; index++)
    {
        pData[index] = CY_GET_REG8(p);
    }
}

/*******************************************************************************
* Function Name: USBFS_InitializeMSC()
********************************************************************************
* Summary:
*  Initializes the CSW signature with the default value.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void USBFS_InitializeMSC(void) 
{
	USBFS_MSC_CSW.dCSWSignature = MSC_CSW_SIGNATURE;
}

/*******************************************************************************
* Function Name: USBFS_MSC_StallInEP()
********************************************************************************
* Summary:
*  Stalls the Bulk IN endpoint.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void USBFS_MSC_StallInEP(void)
{
	CY_SET_REG8(UBSFS_MSC_EP_IN_PTR, USBFS_MODE_STALL_DATA_EP);
}

/*******************************************************************************
* Function Name: USBFS_MSC_StallOutEP()
********************************************************************************
* Summary:
*  Stalls the Bulk OUT endpoint.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void USBFS_MSC_StallOutEP(void)
{
	CY_SET_REG8(UBSFS_MSC_EP_OUT_PTR, USBFS_MODE_STALL_DATA_EP);
}

/*******************************************************************************
* Function Name: USBFS_IsCommandBlockWrapperValid()
********************************************************************************
* Summary:
*  Check for validity of CBW.
*
* Parameters:
*  None.
*
* Return:
*  uint8: If the CBW is valid or not.
*
*******************************************************************************/
uint8 USBFS_IsCommandBlockWrapperValid(void)
{
	uint8 validStatus = CYRET_BAD_DATA;	
	uint8 index = ZERO;
	
	for(index = ZERO; index < MSC_CBW_SIZE; index++)
	{
		/* Copy all contents from EP buffer to structure. May replace with DMA, 
		 * need to validate if efficiency can be increased in that way. */
		*((uint8 *)&USBFS_MSC_CBW + index) = USBFS_MSC_OutEPBuffer[index]; 
	}
	
	if(USBFS_MSC_CBW.dCBWSignature == MSC_CBW_SIGNATURE)
	{
		if(USBFS_MSC_CBW.bCBWLUN <= USBFS_MSC_MAX_LUN_NUMBER)
		{
			if((USBFS_MSC_CBW.bCBWCBLength > ZERO) && (USBFS_MSC_CBW.bCBWCBLength <= MSC_MAX_CBWCB_LEN)) 
			{
				/* Validate all conditons of section 6.6.1 of MSC spec. */
				validStatus = CYRET_SUCCESS; 
			}
		}
	}
	return(validStatus);
}

/*******************************************************************************
* Function Name: HandleSCSIInRequests()
********************************************************************************
* Summary:
*  Interprets the SCSI IN commands and implements a non-blocking statemachine 
*  to service the requests. 
*
* Parameters:
*  None.
*
* Return:
*  cystatus: PASS: If the routines handling SCSI is successful.
*
*******************************************************************************/
cystatus HandleSCSIInRequests(void)
{
	cystatus commandStatus = CYRET_INVALID_STATE;
	static uint8 currPacketSize = ZERO;
	static uint8 toggle = ZERO;
	uint32 index = ZERO;
	uint8 epIndex = ZERO;
    uint8 recvBuff[512];
	
	switch(USBFS_MSC_CBW.CBWCB[0])
	{
		case USBFS_MSC_SCSI_READ10:
			if(toggle == ZERO)
			{
				if(USBFS_MSC_BytesToTransfer > IN_EP_BUF_SIZE)
				{
					currPacketSize = IN_EP_BUF_SIZE;
				}
				else
				{
					currPacketSize = USBFS_MSC_BytesToTransfer;
				}
				
				if((USBFS_MSC_StartLocation + currPacketSize) > USBFS_MSC_TOTAL_MEM_SIZE)
				{
					currPacketSize = USBFS_MSC_TOTAL_MEM_SIZE - USBFS_MSC_StartLocation;
				}
                
				if(USBFS_MSC_StartLocation > USBFS_MSC_SRAM_END_LOC)
				{
					/* Return spaces if host tries to read memory locations outside emulated memory in SRAM. */
					for(epIndex = ZERO, index = USBFS_MSC_StartLocation; epIndex < currPacketSize; epIndex++, index++)
					{
						USBFS_MSC_InEPBuffer[epIndex] = 0x20;
					}
					toggle = ~ZERO;
				}
				else
				{
					/* Allow reads from emulated memory if the requested location is within the SRAM. */
					while(disk_read(0, recvBuff, USBFS_MSC_StartLocation/512, 1) == BUSY){}
                    for(epIndex = ZERO, index = USBFS_MSC_StartLocation; epIndex < currPacketSize; epIndex++, index++)
					{
						USBFS_MSC_InEPBuffer[epIndex] = recvBuff[epIndex];
					}
				}
			}
            
			if((USBFS_MSC_StartLocation + currPacketSize) > USBFS_MSC_TOTAL_MEM_SIZE)
			{
				currState = MSC_STATUS_TRANSPORT;
			}
			commandStatus = USBFS_MSC_CSW_PASS;
			toggle = ZERO;
            
			break;
			
		case USBFS_MSC_SCSI_REQUEST_SENSE:
			commandStatus = USBFS_MSC_SCSI_RequestSense(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_INQUIRY:
			commandStatus = USBFS_MSC_SCSI_Inquiry(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_MODE_SENSE6:
			commandStatus = USBFS_MSC_SCSI_ModeSense6(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_MODE_SENSE10:
			commandStatus = USBFS_MSC_SCSI_ModeSense10(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_READ_CAPACITY:
			commandStatus = USBFS_MSC_SCSI_ReadCapacity(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_READ_FORMAT_CAPACITIES:
			commandStatus = USBFS_MSC_SCSI_ReadFormatCapacities(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_FORMAT_UNIT:
			commandStatus = USBFS_MSC_SCSI_FormatUnit(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_MODE_SELECT6:
			commandStatus = USBFS_MSC_SCSI_ModeSelect6(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		case USBFS_MSC_SCSI_MODE_SELECT10:
			commandStatus = USBFS_MSC_SCSI_ModeSelect10(&currPacketSize);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		default:
			break;
	}
	
	if(commandStatus == USBFS_MSC_CSW_PASS)
	{
		USBFS_LoadInEP(MSC_EP_IN, USBFS_MSC_InEPBuffer, currPacketSize);
		USBFS_MSC_CSW.dCSWDataResidue -= currPacketSize;
		if(USBFS_MSC_CBW.CBWCB[0] == USBFS_MSC_SCSI_READ10)
		{
			USBFS_MSC_StartLocation += currPacketSize;
			USBFS_MSC_BytesToTransfer -= currPacketSize;
			
			if(USBFS_MSC_BytesToTransfer == ZERO)
			{
				currState = MSC_STATUS_TRANSPORT;
			}
			
			if(currState != MSC_DATA_IN)
			{
				USBFS_MSC_CSW.bCSWStatus = USBFS_MSC_CSW_PASS;
			}
		}
	}
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: HandleSCSIOutRequests()
********************************************************************************
* Summary:
*  Interprets the SCSI OUT commands and implements a non-blocking statemachine 
*  to service the requests.
*
* Parameters:
*  None.
*
* Return:
*  cystatus: PASS: If the routines handling SCSI is successful.
*
*******************************************************************************/
cystatus HandleSCSIOutRequests(void)
{
	cystatus commandStatus = CYRET_INVALID_STATE;
	static uint8 currPacketSize = ZERO;
	static uint8 toggle = ZERO;
	uint8 index = ZERO;
	
	uint8 parseStatus = TRUE;
	
	switch(USBFS_MSC_CBW.CBWCB[0])
	{
		case USBFS_MSC_SCSI_WRITE10:
			if(toggle == ZERO)
			{
				currPacketSize = USBFS_GetEPCount(MSC_EP_OUT);
				USBFS_MSC_ReadOutEP(MSC_EP_OUT, USBFS_MSC_OutEPBuffer, currPacketSize);
				
			  	if ((USBFS_MSC_StartLocation + currPacketSize) > USBFS_MSC_TOTAL_MEM_SIZE) 
				{
			    	currPacketSize = USBFS_MSC_TOTAL_MEM_SIZE - USBFS_MSC_StartLocation;
			    	currState = MSC_STATUS_TRANSPORT;
			  	}
                
				/* Check if the incoming data is already being parsed. */
//                if (beginDataParsing == FALSE)
//				{
//					for(index = ZERO; index < currPacketSize; index++)
//					{
//						if(USBFS_MSC_OutEPBuffer[index] == ':')
//						{
//							/* A valide hex file will always begin with ':'. Wait for 
//							 * the stream to hit this condition to begin parsing. */
//							beginDataParsing = TRUE;
//                            
//                            //STATUS_LED_BREATHING_ON;
//                            
//							break;
//						}
//					}
//				}
			}
			
//            if (beginDataParsing == TRUE)
//			{
//				/* Parse incoming data stream if ':' is detected.
//				 * Additional checks implemented inside this routine. */
//				//parseStatus = ParseIncomingData(currPacketSize);
//				toggle = ~ZERO;
//			}
				
			if (parseStatus == TRUE)
			{
				/* Rearm the EP if parsing of the current packet is complete and data is written to the F-RAM. */
				USBFS_EnableOutEP(MSC_EP_OUT);
				
				USBFS_MSC_StartLocation += currPacketSize;
			  	USBFS_MSC_BytesToTransfer -= currPacketSize;

			  	USBFS_MSC_CSW.dCSWDataResidue -= currPacketSize;

				/* Retrun the status to host if all the packets sent by host has been parsed. */
			  	if ((USBFS_MSC_BytesToTransfer == 0) || (currState == MSC_STATUS_TRANSPORT)) 
				{
			    	USBFS_MSC_CSW.bCSWStatus = USBFS_MSC_CSW_PASS;
			    	currState = MSC_STATUS_TRANSPORT;
				}
				toggle = ZERO;
			}
			break;
			
		case USBFS_MSC_SCSI_VERIFY10:
			if(USBFS_GetEPAckState(MSC_EP_OUT) != FALSE)
			{
				currPacketSize = USBFS_GetEPCount(MSC_EP_OUT);
				USBFS_MSC_ReadOutEP(MSC_EP_OUT, USBFS_MSC_OutEPBuffer, currPacketSize);
			  	
				if ((USBFS_MSC_StartLocation + currPacketSize) > USBFS_MSC_TOTAL_MEM_SIZE) 
				{
			    	currPacketSize = USBFS_MSC_TOTAL_MEM_SIZE - USBFS_MSC_StartLocation;
			    	currState = MSC_STATUS_TRANSPORT;
			  	}
				
				/* Write the memory verification routine here. None implemented as of now. */		
				
				USBFS_MSC_StartLocation += currPacketSize;
			  	USBFS_MSC_BytesToTransfer -= currPacketSize;

			  	USBFS_MSC_CSW.dCSWDataResidue -= currPacketSize;

			  	if ((USBFS_MSC_BytesToTransfer == ZERO) || (currState == MSC_STATUS_TRANSPORT)) 
				{
			    	USBFS_MSC_CSW.bCSWStatus = USBFS_MSC_CSW_PASS;
			    	currState = MSC_STATUS_TRANSPORT;
				}
			}
			
			USBFS_EnableOutEP(MSC_EP_OUT);
			break;
	}
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: HandleSCSINoDataRequests()
********************************************************************************
* Summary:
*  Interprets the SCSI No Data commands and implements a non-blocking statemachine 
*  to service the requests.
*
* Parameters:
*  None.
*
* Return:
*  cystatus: PASS: If the routines handling SCSI is successful.
*
*******************************************************************************/
cystatus HandleSCSINoDataRequests(void)
{
	cystatus commandStatus = CYRET_INVALID_STATE;
	
	switch(USBFS_MSC_CBW.CBWCB[0])
	{
		case USBFS_MSC_SCSI_TEST_UNIT_READY:
			commandStatus = USBFS_MSC_SCSI_TestUnitReady();
			break;
			
		case USBFS_MSC_SCSI_MEDIA_REMOVAL:
			commandStatus = USBFS_MSC_SCSI_PreventMediaRemoval(USBFS_MSC_CBW.CBWCB[4]);
			break;
			
		case USBFS_MSC_SCSI_START_STOP_UNIT:
			commandStatus = USBFS_MSC_SCSI_StartStopUnit(USBFS_MSC_CBW.CBWCB[4]);
			currState = MSC_STATUS_TRANSPORT;
			break;
			
		default:
			break;
	}
	
	return(commandStatus);
}

/*******************************************************************************
* Function Name: USBFS_HandleMassStorageInRequests()
********************************************************************************
* Summary:
*  Handles the IN part of the common state machine implemented together with 
*  USBFS_HandleMassStorageOutRequests() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void USBFS_HandleMassStorageInRequests(void)
{
	cystatus requestStatus = CYRET_INVALID_STATE;
	switch(currState)
	{
		case MSC_DATA_IN:
			/* Interpret command. This is a SCSI command. */
			requestStatus = HandleSCSIInRequests();  
			USBFS_MSC_CSW.bCSWStatus = requestStatus;
			break;
			
		case MSC_NO_DATA:
			/* Interpret command. This is a SCSI command. */
			requestStatus = HandleSCSINoDataRequests();  
			USBFS_MSC_CSW.bCSWStatus = requestStatus;
			currState = MSC_STATUS_TRANSPORT;
			break;
	
		case MSC_STALL_IN_ENDPOINT:
			CY_SET_REG8(MSC_EP_IN, USBFS_MODE_STALL_DATA_EP);
			currState = MSC_READY_STATE;
			break;
			
		case MSC_STATUS_TRANSPORT:
			/* Send the status using CSW to the host. */
			USBFS_LoadInEP(MSC_EP_IN, (uint8 *)&USBFS_MSC_CSW, MSC_CSW_SIZE);
			currState = MSC_READY_STATE;
			break;
	}
}

/*******************************************************************************
* Function Name: USBFS_HandleMassStorageOutRequests()
********************************************************************************
* Summary:
*  Handles the OUT part of the common state machine implemented together with 
*  USBFS_HandleMassStorageInRequests() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void USBFS_HandleMassStorageOutRequests(void)
{
	uint32 tempVar = ZERO;
	uint8 epCount = ZERO;
	
	switch(currState)
	{
		case MSC_READY_STATE: 
			/* Number of bytes received now should be exactly 31 as per spec. */
			if(USBFS_GetEPAckState(MSC_EP_OUT) != FALSE)
			{
				epCount = USBFS_GetEPCount(MSC_EP_OUT);	
				if(epCount == MSC_CBW_SIZE)
				{
					USBFS_MSC_ReadOutEP(MSC_EP_OUT, USBFS_MSC_OutEPBuffer, epCount);
					currState = MSC_COMMAND_TRANSPORT;
				}
				else
				{
					currState = MSC_STALL_OUT_ENDPOINT;
				}
			}
			break;
			
		case MSC_COMMAND_TRANSPORT: 
			/* Validate CBW and check the direction of data transfer expected by host. */
			if(USBFS_IsCommandBlockWrapperValid() == CYRET_SUCCESS)
			{
				if(USBFS_MSC_CBW.dCBWDataTransferLength != ZERO)
				{
					/* Bulk In Transfer. */
					if((USBFS_MSC_CBW.bmCBWFlags & MSC_CBWFLAG_DIRECTION_MASK) == USBFS_DIR_IN)
					{
						currState = MSC_DATA_IN;
						
						if((USBFS_MSC_CBW.CBWCB[0]) == USBFS_MSC_SCSI_READ10)
						{
							tempVar = ((USBFS_MSC_CBW.CBWCB[2] << 24) | (USBFS_MSC_CBW.CBWCB[3] << 16) | (USBFS_MSC_CBW.CBWCB[4] << 8) | USBFS_MSC_CBW.CBWCB[5]);
							USBFS_MSC_StartLocation = tempVar * USBFS_MSC_BLOCKSIZE; 
							
							tempVar = ((USBFS_MSC_CBW.CBWCB[7] << 8) | USBFS_MSC_CBW.CBWCB[8]);
							USBFS_MSC_BytesToTransfer = tempVar * USBFS_MSC_BLOCKSIZE;
							
							if(USBFS_MSC_CBW.dCBWDataTransferLength != USBFS_MSC_BytesToTransfer)
							{
								USBFS_MSC_CSW.bCSWStatus = USBFS_MSC_CSW_PHASE_ERROR;
								currState = MSC_STALL_OUT_ENDPOINT;
							}
						}						
					}
					else
					{
						/* Bulk Out Transfer. */
						currState = MSC_DATA_OUT;
						
						if(((USBFS_MSC_CBW.CBWCB[0]) == USBFS_MSC_SCSI_WRITE10) || ((USBFS_MSC_CBW.CBWCB[0]) == USBFS_MSC_SCSI_VERIFY10))
						{
							tempVar = ((USBFS_MSC_CBW.CBWCB[2] << 24) | (USBFS_MSC_CBW.CBWCB[3] << 16) | (USBFS_MSC_CBW.CBWCB[4] << 8) | USBFS_MSC_CBW.CBWCB[5]);
							USBFS_MSC_StartLocation = tempVar * USBFS_MSC_BLOCKSIZE;
							
                           // if (USBFS_MSC_StartLocation == 0x0A00) //ResetProgrammingParameters();
                            
							tempVar = ((USBFS_MSC_CBW.CBWCB[7] << 8) | USBFS_MSC_CBW.CBWCB[8]);
							USBFS_MSC_BytesToTransfer = tempVar * USBFS_MSC_BLOCKSIZE;
							
							if(USBFS_MSC_CBW.dCBWDataTransferLength != USBFS_MSC_BytesToTransfer)
							{
								USBFS_MSC_CSW.bCSWStatus = USBFS_MSC_CSW_PHASE_ERROR;
								currState = MSC_STALL_OUT_ENDPOINT;
							}
						}
					}
				}
				else
				{
					/* No data transfer expected by the host. */
					currState = MSC_NO_DATA;
				}
				
				/* Echo the tag. */
				USBFS_MSC_CSW.dCSWTag = USBFS_MSC_CBW.dCBWTag; 
				
				/* Inform the residue. */
				USBFS_MSC_CSW.dCSWDataResidue = USBFS_MSC_CBW.dCBWDataTransferLength;
				
				/* Re-arm the endpoint for next OUT transfer. */
				USBFS_EnableOutEP(MSC_EP_OUT);
			}
			else
			{
				/* Invalid CBW. Wait for reset recovery. */
				currState = MSC_WAIT_FOR_RESET; 
			}
			break;

		case MSC_DATA_OUT:
			/* Interpret command. This is a SCSI command. */
			HandleSCSIOutRequests();  
			break;

		case MSC_STALL_OUT_ENDPOINT:
			CY_SET_REG8(MSC_EP_OUT, USBFS_MODE_STALL_DATA_EP);
			currState = MSC_READY_STATE;
			break;
			
		case MSC_WAIT_FOR_RESET:
			USBFS_MSC_StallInEP();
			USBFS_MSC_StallOutEP();
			if(resetRecovery == TRUE)
			{
				resetRecovery = FALSE;
				currState = MSC_READY_STATE;
			}
			break;
	}
}

/* [] END OF FILE */


