#ifndef S25FL216K
#define S25FL216K
    
#include "cytypes.h"
#include "project.h"
    
/* Flash organization */
/* Sizes in bytes */
#define       CHIP_SIZE             0x200000
#define       NUM_OF_BLOCKS         32
#define       NUM_OF_SECTORS        512
#define       NUM_OF_PAGES          8192
#define       BLOCK_SIZE            CHIP_SIZE/NUM_OF_BLOCKS
#define       SECTOR_SIZE           CHIP_SIZE/NUM_OF_SECTORS
#define       PAGE_SIZE             CHIP_SIZE/NUM_OF_PAGES

/* Command codes*/
#define       SHIFT_OUT             0x00
#define       WRITE_EN              0x06
#define       WRITE_DIS             0x04
#define       READ_STATUS_REG       0x05
#define       WRITE_STATUS_REG      0x01
#define       READ_DATA             0x03
#define       FAST_READ             0x0B
#define       FAST_READ_DUAL_OUT    0x3B
#define       PAGE_PROG             0x02
#define       BLK_ERASE             0xD8
#define       SECTOR_ERASE          0x20
#define       CHIP_ERASE_1          0xC7
#define       CHIP_ERASE_2          0x60
#define       PWR_DOWN              0xB9
#define       REL_PWR_DOWN_DEV_ID   0xAB
#define       MANF_DEV_ID           0x90
#define       JEDEC_ID              0x9F

/* Status register bits*/
#define   SRP_BIT   (1 << 8)
#define   REV_BIT   (1 << 7)
#define   BP3_BIT   (1 << 6)
#define   BP2_BIT   (1 << 5)
#define   BP1_BIT   (1 << 4)
#define   BP0_BIT   (1 << 3)
#define   WEL_BIT   (1 << 2)
#define   WIP_BIT    1

#define   READ_ONLY_BITS    0x43
#define   RW_BITS           0xBC

typedef uint8 BOOL;

typedef enum cmdStatusTypedef 
{
  OK,
  ERROR,
  INVALID_INPUT,
  BUSY,
  PROTECTED
}cmdStatusTypedef;

/* Function prototypes */
cmdStatusTypedef writeStatusReg(uint8);
cmdStatusTypedef readData(uint32, uint8*, uint32);
cmdStatusTypedef pageProgram(uint32, uint8*, uint32);
cmdStatusTypedef sectorErase(uint32);
cmdStatusTypedef blockErase(uint32);
cmdStatusTypedef chipErase();
cmdStatusTypedef deepPowerDown();
cmdStatusTypedef releaseDeepPowerDown();
uint8 releaseDeepPowerDownDevID();
cmdStatusTypedef readMnfctDevId(uint8*, uint8*);
cmdStatusTypedef readJEDECId(uint8*, uint8*, uint8*);

#endif

