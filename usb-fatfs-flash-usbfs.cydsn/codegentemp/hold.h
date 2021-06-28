/*******************************************************************************
* File Name: hold.h  
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

#if !defined(CY_PINS_hold_H) /* Pins hold_H */
#define CY_PINS_hold_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "hold_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 hold__PORT == 15 && ((hold__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    hold_Write(uint8 value);
void    hold_SetDriveMode(uint8 mode);
uint8   hold_ReadDataReg(void);
uint8   hold_Read(void);
void    hold_SetInterruptMode(uint16 position, uint16 mode);
uint8   hold_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the hold_SetDriveMode() function.
     *  @{
     */
        #define hold_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define hold_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define hold_DM_RES_UP          PIN_DM_RES_UP
        #define hold_DM_RES_DWN         PIN_DM_RES_DWN
        #define hold_DM_OD_LO           PIN_DM_OD_LO
        #define hold_DM_OD_HI           PIN_DM_OD_HI
        #define hold_DM_STRONG          PIN_DM_STRONG
        #define hold_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define hold_MASK               hold__MASK
#define hold_SHIFT              hold__SHIFT
#define hold_WIDTH              1u

/* Interrupt constants */
#if defined(hold__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in hold_SetInterruptMode() function.
     *  @{
     */
        #define hold_INTR_NONE      (uint16)(0x0000u)
        #define hold_INTR_RISING    (uint16)(0x0001u)
        #define hold_INTR_FALLING   (uint16)(0x0002u)
        #define hold_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define hold_INTR_MASK      (0x01u) 
#endif /* (hold__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define hold_PS                     (* (reg8 *) hold__PS)
/* Data Register */
#define hold_DR                     (* (reg8 *) hold__DR)
/* Port Number */
#define hold_PRT_NUM                (* (reg8 *) hold__PRT) 
/* Connect to Analog Globals */                                                  
#define hold_AG                     (* (reg8 *) hold__AG)                       
/* Analog MUX bux enable */
#define hold_AMUX                   (* (reg8 *) hold__AMUX) 
/* Bidirectional Enable */                                                        
#define hold_BIE                    (* (reg8 *) hold__BIE)
/* Bit-mask for Aliased Register Access */
#define hold_BIT_MASK               (* (reg8 *) hold__BIT_MASK)
/* Bypass Enable */
#define hold_BYP                    (* (reg8 *) hold__BYP)
/* Port wide control signals */                                                   
#define hold_CTL                    (* (reg8 *) hold__CTL)
/* Drive Modes */
#define hold_DM0                    (* (reg8 *) hold__DM0) 
#define hold_DM1                    (* (reg8 *) hold__DM1)
#define hold_DM2                    (* (reg8 *) hold__DM2) 
/* Input Buffer Disable Override */
#define hold_INP_DIS                (* (reg8 *) hold__INP_DIS)
/* LCD Common or Segment Drive */
#define hold_LCD_COM_SEG            (* (reg8 *) hold__LCD_COM_SEG)
/* Enable Segment LCD */
#define hold_LCD_EN                 (* (reg8 *) hold__LCD_EN)
/* Slew Rate Control */
#define hold_SLW                    (* (reg8 *) hold__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define hold_PRTDSI__CAPS_SEL       (* (reg8 *) hold__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define hold_PRTDSI__DBL_SYNC_IN    (* (reg8 *) hold__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define hold_PRTDSI__OE_SEL0        (* (reg8 *) hold__PRTDSI__OE_SEL0) 
#define hold_PRTDSI__OE_SEL1        (* (reg8 *) hold__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define hold_PRTDSI__OUT_SEL0       (* (reg8 *) hold__PRTDSI__OUT_SEL0) 
#define hold_PRTDSI__OUT_SEL1       (* (reg8 *) hold__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define hold_PRTDSI__SYNC_OUT       (* (reg8 *) hold__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(hold__SIO_CFG)
    #define hold_SIO_HYST_EN        (* (reg8 *) hold__SIO_HYST_EN)
    #define hold_SIO_REG_HIFREQ     (* (reg8 *) hold__SIO_REG_HIFREQ)
    #define hold_SIO_CFG            (* (reg8 *) hold__SIO_CFG)
    #define hold_SIO_DIFF           (* (reg8 *) hold__SIO_DIFF)
#endif /* (hold__SIO_CFG) */

/* Interrupt Registers */
#if defined(hold__INTSTAT)
    #define hold_INTSTAT            (* (reg8 *) hold__INTSTAT)
    #define hold_SNAP               (* (reg8 *) hold__SNAP)
    
	#define hold_0_INTTYPE_REG 		(* (reg8 *) hold__0__INTTYPE)
#endif /* (hold__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_hold_H */


/* [] END OF FILE */
