/*******************************************************************************
* File Name: wp.h  
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

#if !defined(CY_PINS_wp_H) /* Pins wp_H */
#define CY_PINS_wp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "wp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 wp__PORT == 15 && ((wp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    wp_Write(uint8 value);
void    wp_SetDriveMode(uint8 mode);
uint8   wp_ReadDataReg(void);
uint8   wp_Read(void);
void    wp_SetInterruptMode(uint16 position, uint16 mode);
uint8   wp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the wp_SetDriveMode() function.
     *  @{
     */
        #define wp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define wp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define wp_DM_RES_UP          PIN_DM_RES_UP
        #define wp_DM_RES_DWN         PIN_DM_RES_DWN
        #define wp_DM_OD_LO           PIN_DM_OD_LO
        #define wp_DM_OD_HI           PIN_DM_OD_HI
        #define wp_DM_STRONG          PIN_DM_STRONG
        #define wp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define wp_MASK               wp__MASK
#define wp_SHIFT              wp__SHIFT
#define wp_WIDTH              1u

/* Interrupt constants */
#if defined(wp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in wp_SetInterruptMode() function.
     *  @{
     */
        #define wp_INTR_NONE      (uint16)(0x0000u)
        #define wp_INTR_RISING    (uint16)(0x0001u)
        #define wp_INTR_FALLING   (uint16)(0x0002u)
        #define wp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define wp_INTR_MASK      (0x01u) 
#endif /* (wp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define wp_PS                     (* (reg8 *) wp__PS)
/* Data Register */
#define wp_DR                     (* (reg8 *) wp__DR)
/* Port Number */
#define wp_PRT_NUM                (* (reg8 *) wp__PRT) 
/* Connect to Analog Globals */                                                  
#define wp_AG                     (* (reg8 *) wp__AG)                       
/* Analog MUX bux enable */
#define wp_AMUX                   (* (reg8 *) wp__AMUX) 
/* Bidirectional Enable */                                                        
#define wp_BIE                    (* (reg8 *) wp__BIE)
/* Bit-mask for Aliased Register Access */
#define wp_BIT_MASK               (* (reg8 *) wp__BIT_MASK)
/* Bypass Enable */
#define wp_BYP                    (* (reg8 *) wp__BYP)
/* Port wide control signals */                                                   
#define wp_CTL                    (* (reg8 *) wp__CTL)
/* Drive Modes */
#define wp_DM0                    (* (reg8 *) wp__DM0) 
#define wp_DM1                    (* (reg8 *) wp__DM1)
#define wp_DM2                    (* (reg8 *) wp__DM2) 
/* Input Buffer Disable Override */
#define wp_INP_DIS                (* (reg8 *) wp__INP_DIS)
/* LCD Common or Segment Drive */
#define wp_LCD_COM_SEG            (* (reg8 *) wp__LCD_COM_SEG)
/* Enable Segment LCD */
#define wp_LCD_EN                 (* (reg8 *) wp__LCD_EN)
/* Slew Rate Control */
#define wp_SLW                    (* (reg8 *) wp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define wp_PRTDSI__CAPS_SEL       (* (reg8 *) wp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define wp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) wp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define wp_PRTDSI__OE_SEL0        (* (reg8 *) wp__PRTDSI__OE_SEL0) 
#define wp_PRTDSI__OE_SEL1        (* (reg8 *) wp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define wp_PRTDSI__OUT_SEL0       (* (reg8 *) wp__PRTDSI__OUT_SEL0) 
#define wp_PRTDSI__OUT_SEL1       (* (reg8 *) wp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define wp_PRTDSI__SYNC_OUT       (* (reg8 *) wp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(wp__SIO_CFG)
    #define wp_SIO_HYST_EN        (* (reg8 *) wp__SIO_HYST_EN)
    #define wp_SIO_REG_HIFREQ     (* (reg8 *) wp__SIO_REG_HIFREQ)
    #define wp_SIO_CFG            (* (reg8 *) wp__SIO_CFG)
    #define wp_SIO_DIFF           (* (reg8 *) wp__SIO_DIFF)
#endif /* (wp__SIO_CFG) */

/* Interrupt Registers */
#if defined(wp__INTSTAT)
    #define wp_INTSTAT            (* (reg8 *) wp__INTSTAT)
    #define wp_SNAP               (* (reg8 *) wp__SNAP)
    
	#define wp_0_INTTYPE_REG 		(* (reg8 *) wp__0__INTTYPE)
#endif /* (wp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_wp_H */


/* [] END OF FILE */
