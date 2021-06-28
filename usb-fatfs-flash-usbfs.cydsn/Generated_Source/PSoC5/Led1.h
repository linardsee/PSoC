/*******************************************************************************
* File Name: Led1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Led1_H) /* Pins Led1_H */
#define CY_PINS_Led1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Led1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Led1__PORT == 15 && ((Led1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Led1_Write(uint8 value);
void    Led1_SetDriveMode(uint8 mode);
uint8   Led1_ReadDataReg(void);
uint8   Led1_Read(void);
void    Led1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Led1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Led1_SetDriveMode() function.
     *  @{
     */
        #define Led1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Led1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Led1_DM_RES_UP          PIN_DM_RES_UP
        #define Led1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Led1_DM_OD_LO           PIN_DM_OD_LO
        #define Led1_DM_OD_HI           PIN_DM_OD_HI
        #define Led1_DM_STRONG          PIN_DM_STRONG
        #define Led1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Led1_MASK               Led1__MASK
#define Led1_SHIFT              Led1__SHIFT
#define Led1_WIDTH              1u

/* Interrupt constants */
#if defined(Led1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Led1_SetInterruptMode() function.
     *  @{
     */
        #define Led1_INTR_NONE      (uint16)(0x0000u)
        #define Led1_INTR_RISING    (uint16)(0x0001u)
        #define Led1_INTR_FALLING   (uint16)(0x0002u)
        #define Led1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Led1_INTR_MASK      (0x01u) 
#endif /* (Led1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Led1_PS                     (* (reg8 *) Led1__PS)
/* Data Register */
#define Led1_DR                     (* (reg8 *) Led1__DR)
/* Port Number */
#define Led1_PRT_NUM                (* (reg8 *) Led1__PRT) 
/* Connect to Analog Globals */                                                  
#define Led1_AG                     (* (reg8 *) Led1__AG)                       
/* Analog MUX bux enable */
#define Led1_AMUX                   (* (reg8 *) Led1__AMUX) 
/* Bidirectional Enable */                                                        
#define Led1_BIE                    (* (reg8 *) Led1__BIE)
/* Bit-mask for Aliased Register Access */
#define Led1_BIT_MASK               (* (reg8 *) Led1__BIT_MASK)
/* Bypass Enable */
#define Led1_BYP                    (* (reg8 *) Led1__BYP)
/* Port wide control signals */                                                   
#define Led1_CTL                    (* (reg8 *) Led1__CTL)
/* Drive Modes */
#define Led1_DM0                    (* (reg8 *) Led1__DM0) 
#define Led1_DM1                    (* (reg8 *) Led1__DM1)
#define Led1_DM2                    (* (reg8 *) Led1__DM2) 
/* Input Buffer Disable Override */
#define Led1_INP_DIS                (* (reg8 *) Led1__INP_DIS)
/* LCD Common or Segment Drive */
#define Led1_LCD_COM_SEG            (* (reg8 *) Led1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Led1_LCD_EN                 (* (reg8 *) Led1__LCD_EN)
/* Slew Rate Control */
#define Led1_SLW                    (* (reg8 *) Led1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Led1_PRTDSI__CAPS_SEL       (* (reg8 *) Led1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Led1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Led1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Led1_PRTDSI__OE_SEL0        (* (reg8 *) Led1__PRTDSI__OE_SEL0) 
#define Led1_PRTDSI__OE_SEL1        (* (reg8 *) Led1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Led1_PRTDSI__OUT_SEL0       (* (reg8 *) Led1__PRTDSI__OUT_SEL0) 
#define Led1_PRTDSI__OUT_SEL1       (* (reg8 *) Led1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Led1_PRTDSI__SYNC_OUT       (* (reg8 *) Led1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Led1__SIO_CFG)
    #define Led1_SIO_HYST_EN        (* (reg8 *) Led1__SIO_HYST_EN)
    #define Led1_SIO_REG_HIFREQ     (* (reg8 *) Led1__SIO_REG_HIFREQ)
    #define Led1_SIO_CFG            (* (reg8 *) Led1__SIO_CFG)
    #define Led1_SIO_DIFF           (* (reg8 *) Led1__SIO_DIFF)
#endif /* (Led1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Led1__INTSTAT)
    #define Led1_INTSTAT            (* (reg8 *) Led1__INTSTAT)
    #define Led1_SNAP               (* (reg8 *) Led1__SNAP)
    
	#define Led1_0_INTTYPE_REG 		(* (reg8 *) Led1__0__INTTYPE)
#endif /* (Led1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Led1_H */


/* [] END OF FILE */
