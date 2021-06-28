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
#include "project.h"

uint8 randomBuff[5] = {'a', 'b', 'c', 'd', 'e'};

void copyBuffer(uint8* buff, uint8 size)
{
    for(int i = 0; i < size; i++)
    {
        *buff = randomBuff[i];
        buff++;
    }
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    uint8 copyBuff[5] = {0, 0, 0, 0, 0};
    
    copyBuffer(copyBuff, 5);
    
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
