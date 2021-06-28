#include "flash.h"
#include "project.h"
#include <stdio.h>

void _sendCmd(uint8 cmd)
{
  SPIM_1_WriteTxData(cmd);
  while( (SPIM_1_ReadTxStatus() & SPIM_1_STS_SPI_DONE) == 0){}
}

void _writeEnable()
{
  cs_Write(0);
  _sendCmd(WRITE_EN);
  cs_Write(1);
}

void _writeDisable()
{
  cs_Write(0);
  _sendCmd(WRITE_DIS);
  cs_Write(1);
}

uint8 _readStatusReg()
{
  uint8 reg = 0;
  
  SPIM_1_ClearRxBuffer();
  
  cs_Write(0);
  _sendCmd(READ_STATUS_REG);
  _sendCmd(SHIFT_OUT);
  cs_Write(1);
    
  SPIM_1_ReadRxData();
  reg = SPIM_1_ReadRxData();

  return reg;
}

BOOL _checkWIP()
{
  if((_readStatusReg() & WIP_BIT)) 
  {
    return 1;
  }
  else return 0;
}

BOOL _checkIfProtectedBitsSet()
{
  BOOL protected = 1;

  if(_readStatusReg() & 0x3C) protected = 1;
  else protected = 0;

  return protected;
}

BOOL _checkIfProtected(uint32 address)
{
  BOOL protected = 1;

  uint8 bpb = (_readStatusReg() & 0x3C) >> 2;

  switch(bpb)
  {
    case 0:
      protected = 0;
    break;
    case 1:
      if( (address >= 0x1F0000) && (address <= 0x1FFFFF) ) protected = 1;
      else protected = 0;
    break;
    case 2:
      if( (address >= 0x1E0000) && (address <= 0x1FFFFF) ) protected = 1;
      else protected = 0;
    break;
    case 3:
      if( (address >= 0x1C0000) && (address <= 0x1FFFFF) ) protected = 1;
      else protected = 0;
    break;
    case 4:
      if( (address >= 0x180000) && (address <= 0x1FFFFF) ) protected = 1;
      else protected = 0;
    break;
    case 5:
      if( (address >= 0x100000) && (address <= 0x1FFFFF) ) protected = 1;
      else protected = 0;
    break;
    case 6:
    case 9:
      protected = 1;
    break;
    case 10:
      if( (address >= 0x000000) && (address <= 0x0F0000) ) protected = 1;
      else protected = 0;
    break;
    case 11:
      if( (address >= 0x000000) && (address <= 0x170000) ) protected = 1;
      else protected = 0;
    break;
    case 12:
      if( (address >= 0x000000) && (address <= 0x1B0000) ) protected = 1;
      else protected = 0;
    break;
    case 13:
      if( (address >= 0x000000) && (address <= 0x1D0000) ) protected = 1;
      else protected = 0;
    break;
    case 14:
      if( (address >= 0x000000) && (address <= 0x1E0000) ) protected = 1;
      else protected = 0;
    break;
    case 15:
      protected = 1;
    break;

    default:
      return protected = 1;
    break;
  }

  return protected;
}

cmdStatusTypedef writeStatusReg(uint8 code)
{
  cmdStatusTypedef status = ERROR;

  if(code & READ_ONLY_BITS) return INVALID_INPUT;
  if(_checkWIP()) return BUSY;

  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(WRITE_STATUS_REG);
  _sendCmd(code);
  cs_Write(1);

  if( (_readStatusReg() & RW_BITS) == code)
  {
    status = OK;
  }
  else
  {
    status = ERROR;
  }

  return status;
}

cmdStatusTypedef readData(uint32 address, uint8* buff, uint32 size)
{
  cmdStatusTypedef status = ERROR;
  uint8 addr1 = (address & 0xFF0000) >> 16;
  uint8 addr2 = (address & 0xFF00) >> 8;
  uint8 addr3 = address & 0xFF;

  uint8 sendbuff[20];
  memset(sendbuff, 0, 20);

  if(_checkWIP()) return BUSY;

  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(READ_DATA);
  SPIM_1_ReadRxData();
  _sendCmd(addr1);
  SPIM_1_ReadRxData();
  _sendCmd(addr2);
  SPIM_1_ReadRxData();
  _sendCmd(addr3);
  SPIM_1_ReadRxData();

  for(uint32 i = 0; i < size; i++)
  {
    _sendCmd(SHIFT_OUT);
    buff[i] = SPIM_1_ReadRxData();
  }
  cs_Write(1);
  status = OK;
/*    
  buffSize = SPIM_1_GetRxBufferSize() - 4;

        sprintf((char*)sendbuff, "Buffsize: %d \r\n", buffSize);
        //sprintf((char*)sendbuff, "%d ", rand);
        USBUART_1_PutData(sendbuff, 20);
        memset(sendbuff, 0, 20);
        
        sprintf((char*)sendbuff, "size: %d \r\n", size);
        //sprintf((char*)sendbuff, "%d ", rand);
        USBUART_1_PutData(sendbuff, 20);
        memset(sendbuff, 0, 20);
        
  if( buffSize != size) return ERROR;
  else status = OK;
   
  // Dummy read
  for(uint8 i = 0; i < 4; i++)
  {
    SPIM_1_ReadRxData();
  }

  for(uint32 i = 0; i < buffSize; i++)
  {
    buff[i] = SPIM_1_ReadRxData();
  }
*/
  return status;
}
/* FAST READ */
//
//
//
//

/* FAST READ DUAL OUTPUT */
//
//
//
//

cmdStatusTypedef pageProgram(uint32 address, uint8* buff, uint32 size)
{
  cmdStatusTypedef status = ERROR;

  if((size - 1) > 255) return INVALID_INPUT;
  if(_checkWIP()) return BUSY;
  if(_checkIfProtected(address)) return PROTECTED;

  uint8 addr1 = (address & 0xFF0000) >> 16;
  uint8 addr2 = (address & 0xFF00) >> 8;
  uint8 addr3 = address & 0xFF;

  _writeEnable();
  cs_Write(0);
  _sendCmd(PAGE_PROG);
  _sendCmd(addr1);
  _sendCmd(addr2);
  _sendCmd(addr3);
  for(uint32 i = 0; i < size; i++)
  {
    _sendCmd(*buff);
    buff++;
  }
  cs_Write(1);

  status = OK;

  return status;
}

cmdStatusTypedef sectorErase(uint32 address)
{
  cmdStatusTypedef status = ERROR;

  if(_checkWIP()) return BUSY;
  if(_checkIfProtected(address)) return PROTECTED;

  uint8 addr1 = (address & 0xFF0000) >> 16;
  uint8 addr2 = (address & 0xFF00) >> 8;
  uint8 addr3 = address & 0xFF;

  _writeEnable();
  cs_Write(0);
  _sendCmd(SECTOR_ERASE);
  _sendCmd(addr1);
  _sendCmd(addr2);
  _sendCmd(addr3);
  cs_Write(1);

  status = OK;

  return status;
}

cmdStatusTypedef blockErase(uint32 address)
{
  cmdStatusTypedef status = ERROR;

  if(_checkWIP()) return BUSY;
  if(_checkIfProtected(address)) return PROTECTED;

  uint8 addr1 = (address & 0xFF0000) >> 16;
  uint8 addr2 = (address & 0xFF00) >> 8;
  uint8 addr3 = address & 0xFF;

  _writeEnable();
  cs_Write(0);
  _sendCmd(BLK_ERASE);
  _sendCmd(addr1);
  _sendCmd(addr2);
  _sendCmd(addr3);
  cs_Write(1);

  status = OK;

  return status;
}

cmdStatusTypedef chipErase()
{
  cmdStatusTypedef status = ERROR;

  if(_checkWIP()) return BUSY;
  if(_checkIfProtectedBitsSet()) return PROTECTED;

  SPIM_1_ClearRxBuffer();

  _writeEnable();
  cs_Write(0);
  _sendCmd(CHIP_ERASE_1);
  cs_Write(1);

  status = OK;

  return status;
}

cmdStatusTypedef deepPowerDown()
{
  cmdStatusTypedef status = ERROR;

  if(_checkWIP()) return BUSY;

  SPIM_1_ClearRxBuffer();

  _writeEnable();
  cs_Write(0);
  _sendCmd(PWR_DOWN);
  cs_Write(1);

  status = OK;

  return status;
}

cmdStatusTypedef releaseDeepPowerDown()
{
  cmdStatusTypedef status = ERROR;
    
  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(REL_PWR_DOWN_DEV_ID);
  cs_Write(1);

  status = OK;

  return status;
}

uint8 releaseDeepPowerDownDevID()
{
  uint8 devId = 0;
    
  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(REL_PWR_DOWN_DEV_ID);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  cs_Write(1);

  devId = SPIM_1_ReadRxData();

  return devId;
}

cmdStatusTypedef readMnfctDevId(uint8* mnfct, uint8* devId)
{
  cmdStatusTypedef status = ERROR;
    
  if(_checkWIP()) return BUSY;
    
  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(MANF_DEV_ID);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  cs_Write(1);
    
  while(SPIM_1_GetRxBufferSize() > 0)
  {
    if(SPIM_1_GetRxBufferSize() == 2) *mnfct = SPIM_1_ReadRxData();
    else if(SPIM_1_GetRxBufferSize() == 1) *devId = SPIM_1_ReadRxData();
    else SPIM_1_ReadRxData();
  }

  status = OK;

  return status;
}

cmdStatusTypedef readJEDECId(uint8* mnfct, uint8* type, uint8* capacity)
{
  cmdStatusTypedef status = ERROR;

  if(_checkWIP()) return BUSY;

  SPIM_1_ClearRxBuffer();

  cs_Write(0);
  _sendCmd(JEDEC_ID);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  _sendCmd(SHIFT_OUT);
  cs_Write(1);

  while(SPIM_1_GetRxBufferSize() > 0)
  {
    if(SPIM_1_GetRxBufferSize() == 3) *mnfct = SPIM_1_ReadRxData();
    else if(SPIM_1_GetRxBufferSize() == 2) *type = SPIM_1_ReadRxData();
    else if(SPIM_1_GetRxBufferSize() == 1) *capacity = SPIM_1_ReadRxData();
    else SPIM_1_ReadRxData();
  }

  status = OK;

  return status;
}
