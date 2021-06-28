/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdio.h>

#include "project.h"
#include "diskio.h"
#include "ff.h"
#include "USBFS_msc_cust.h"
#include "USBFS_SCSI_operations.h"
#include "general.h"

extern void USBFS_HandleMassStorageInRequests(void);
void USBFS_HandleMassStorageOutRequests(void);

uint8 cr = 13;
uint8 nl = 10;

int main(void)
{
    uint8 recvBuff[1024];
    uint8 sendbuff[6];
    
    memset(sendbuff, 0, 6);
    memset(recvBuff, 0, sizeof(recvBuff));
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPIM_1_Start();
    
    USBFS_Start(0,USBFS_3V_OPERATION);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    if(USBFS_GetConfiguration())
	{
		/* Re-enable the OUT EP */
		USBFS_EnableOutEP(2);
    } 
   
    CyDelay(10000);
  
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  
    //FATFS fatFs;
    FATFS fs;
    FIL fileO;
    //DIR directoryO;
    //FILINFO fileInfo;
    uint8 resultF;
    //FATFS *fatFsPtr;
    
    resultF = f_mount(&fs, "", 0);
    resultF = f_mkfs("", 1, 0);
    
    while(disk_read(0, recvBuff, 0, 2) == 3){}
 /*   
    for(int i = 0; i < 1024; i++)
    {
        if( !(i % 15) ) 
        {
            USBUART_1_PutData(&nl, 1);
            CyDelay(10);
            USBUART_1_PutData(&cr, 1);
            CyDelay(10);
        }  
        sprintf((char*)sendbuff, "%x ", recvBuff[i]);
        //sprintf((char*)sendbuff, "%d ", rand);
        USBUART_1_PutData(sendbuff, 6);
        memset(sendbuff, 0, 6);
        CyDelay(10); 
    }
 */   
    USBFS_InitializeMSC();
    
    for(;;)
    {
        /* Place your application code here. */
        if(USBFS_GetConfiguration())
	    {
    		/* Check for the Configuration to Change, if so then re-enable the OUT EP */
    		if(USBFS_IsConfigurationChanged())
    		{
    			USBFS_EnableOutEP(2);
    		}
        }
        
        /* Check buffer status and handle mass storage events. Execute SCSI commands in the next level. */
		if(USBFS_GetEPState(MSC_EP_IN) == USBFS_IN_BUFFER_EMPTY)
		{
			USBFS_HandleMassStorageInRequests();
		}
		if(USBFS_GetEPState(MSC_EP_OUT) == USBFS_EVENT_PENDING)
		{
			USBFS_HandleMassStorageOutRequests(); 
		}
    }
}

/* [] END OF FILE */
