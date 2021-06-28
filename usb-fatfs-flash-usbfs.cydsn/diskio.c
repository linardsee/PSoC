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
#include "diskio.h"
#include "flash.h"

#include <project.h>
#include <cytypes.h>

static DSTATUS Stat = STA_NOINIT;


DSTATUS disk_status(BYTE drv)
{
    if (drv) return STA_NOINIT;

	return Stat;
}

DSTATUS disk_initialize(BYTE drv)
{
    DSTATUS s;
    
    if (drv) return RES_NOTRDY;
    s = 0;
    Stat = s;
    
    return s;
}

DRESULT disk_read(BYTE drv, BYTE* buff, DWORD sector, UINT count)
{
    if (disk_status(drv) & STA_NOINIT) return RES_NOTRDY;
    uint32 address = sector * 512;
    uint8 disk_status = ERROR;
   
    do
    {
        disk_status = readData(address, buff, 512 * count);
    }while(disk_status == BUSY);
    
    return disk_status ? RES_ERROR : RES_OK;
}

DRESULT disk_write(BYTE drv, const BYTE* buff, DWORD sector, UINT count)
{
    if (disk_status(drv) & STA_NOINIT) return RES_NOTRDY;

    uint32 address = sector * 512;
    uint8 writeCnt = 2 * count;
    uint8 disk_status = ERROR;
    
    uint8 recvBuff[512];
    memset(recvBuff, 0, 512);
    uint8 sendbuff[6];
    memset(sendbuff, 0, 6);
    uint8 cr = 13;
    uint8 nl = 10;
    
    do
    {
        do
        {
            disk_status = pageProgram(address, buff, 256);
        }while(disk_status == BUSY);
        address += 256;
        buff += 256;
    }while(--writeCnt);
    
    while(disk_read(0, recvBuff, 0, 1) == 3){}
/*
    for(int i = 0; i < 512; i++)
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
    return writeCnt ? RES_ERROR : RES_OK;
}

DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void* buff)
{ 
    DRESULT res;
    DWORD blockCnt = NUM_OF_PAGES / 2;
    
    switch(cmd)
    {
        case CTRL_SYNC:
        break;
        
        case GET_SECTOR_COUNT:
            *(DWORD*)buff = blockCnt;
            res = RES_OK;
        break;
        
        case GET_BLOCK_SIZE:
        break;
        
        default:
            res = RES_PARERR;
    }
    
    return res;
}

void disk_timerproc(void)
{
}



/* [] END OF FILE */

