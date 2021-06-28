;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.4
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; cs
cs__0__INTTYPE EQU CYREG_PICU1_INTTYPE2
cs__0__MASK EQU 0x04
cs__0__PC EQU CYREG_PRT1_PC2
cs__0__PORT EQU 1
cs__0__SHIFT EQU 2
cs__AG EQU CYREG_PRT1_AG
cs__AMUX EQU CYREG_PRT1_AMUX
cs__BIE EQU CYREG_PRT1_BIE
cs__BIT_MASK EQU CYREG_PRT1_BIT_MASK
cs__BYP EQU CYREG_PRT1_BYP
cs__CTL EQU CYREG_PRT1_CTL
cs__DM0 EQU CYREG_PRT1_DM0
cs__DM1 EQU CYREG_PRT1_DM1
cs__DM2 EQU CYREG_PRT1_DM2
cs__DR EQU CYREG_PRT1_DR
cs__INP_DIS EQU CYREG_PRT1_INP_DIS
cs__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
cs__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
cs__LCD_EN EQU CYREG_PRT1_LCD_EN
cs__MASK EQU 0x04
cs__PORT EQU 1
cs__PRT EQU CYREG_PRT1_PRT
cs__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
cs__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
cs__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
cs__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
cs__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
cs__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
cs__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
cs__PS EQU CYREG_PRT1_PS
cs__SHIFT EQU 2
cs__SLW EQU CYREG_PRT1_SLW

; wp
wp__0__INTTYPE EQU CYREG_PICU1_INTTYPE5
wp__0__MASK EQU 0x20
wp__0__PC EQU CYREG_PRT1_PC5
wp__0__PORT EQU 1
wp__0__SHIFT EQU 5
wp__AG EQU CYREG_PRT1_AG
wp__AMUX EQU CYREG_PRT1_AMUX
wp__BIE EQU CYREG_PRT1_BIE
wp__BIT_MASK EQU CYREG_PRT1_BIT_MASK
wp__BYP EQU CYREG_PRT1_BYP
wp__CTL EQU CYREG_PRT1_CTL
wp__DM0 EQU CYREG_PRT1_DM0
wp__DM1 EQU CYREG_PRT1_DM1
wp__DM2 EQU CYREG_PRT1_DM2
wp__DR EQU CYREG_PRT1_DR
wp__INP_DIS EQU CYREG_PRT1_INP_DIS
wp__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
wp__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
wp__LCD_EN EQU CYREG_PRT1_LCD_EN
wp__MASK EQU 0x20
wp__PORT EQU 1
wp__PRT EQU CYREG_PRT1_PRT
wp__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
wp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
wp__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
wp__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
wp__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
wp__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
wp__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
wp__PS EQU CYREG_PRT1_PS
wp__SHIFT EQU 5
wp__SLW EQU CYREG_PRT1_SLW

; hold
hold__0__INTTYPE EQU CYREG_PICU3_INTTYPE7
hold__0__MASK EQU 0x80
hold__0__PC EQU CYREG_PRT3_PC7
hold__0__PORT EQU 3
hold__0__SHIFT EQU 7
hold__AG EQU CYREG_PRT3_AG
hold__AMUX EQU CYREG_PRT3_AMUX
hold__BIE EQU CYREG_PRT3_BIE
hold__BIT_MASK EQU CYREG_PRT3_BIT_MASK
hold__BYP EQU CYREG_PRT3_BYP
hold__CTL EQU CYREG_PRT3_CTL
hold__DM0 EQU CYREG_PRT3_DM0
hold__DM1 EQU CYREG_PRT3_DM1
hold__DM2 EQU CYREG_PRT3_DM2
hold__DR EQU CYREG_PRT3_DR
hold__INP_DIS EQU CYREG_PRT3_INP_DIS
hold__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
hold__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
hold__LCD_EN EQU CYREG_PRT3_LCD_EN
hold__MASK EQU 0x80
hold__PORT EQU 3
hold__PRT EQU CYREG_PRT3_PRT
hold__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
hold__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
hold__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
hold__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
hold__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
hold__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
hold__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
hold__PS EQU CYREG_PRT3_PS
hold__SHIFT EQU 7
hold__SLW EQU CYREG_PRT3_SLW

; miso
miso__0__INTTYPE EQU CYREG_PICU1_INTTYPE4
miso__0__MASK EQU 0x10
miso__0__PC EQU CYREG_PRT1_PC4
miso__0__PORT EQU 1
miso__0__SHIFT EQU 4
miso__AG EQU CYREG_PRT1_AG
miso__AMUX EQU CYREG_PRT1_AMUX
miso__BIE EQU CYREG_PRT1_BIE
miso__BIT_MASK EQU CYREG_PRT1_BIT_MASK
miso__BYP EQU CYREG_PRT1_BYP
miso__CTL EQU CYREG_PRT1_CTL
miso__DM0 EQU CYREG_PRT1_DM0
miso__DM1 EQU CYREG_PRT1_DM1
miso__DM2 EQU CYREG_PRT1_DM2
miso__DR EQU CYREG_PRT1_DR
miso__INP_DIS EQU CYREG_PRT1_INP_DIS
miso__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU1_BASE
miso__LCD_COM_SEG EQU CYREG_PRT1_LCD_COM_SEG
miso__LCD_EN EQU CYREG_PRT1_LCD_EN
miso__MASK EQU 0x10
miso__PORT EQU 1
miso__PRT EQU CYREG_PRT1_PRT
miso__PRTDSI__CAPS_SEL EQU CYREG_PRT1_CAPS_SEL
miso__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT1_DBL_SYNC_IN
miso__PRTDSI__OE_SEL0 EQU CYREG_PRT1_OE_SEL0
miso__PRTDSI__OE_SEL1 EQU CYREG_PRT1_OE_SEL1
miso__PRTDSI__OUT_SEL0 EQU CYREG_PRT1_OUT_SEL0
miso__PRTDSI__OUT_SEL1 EQU CYREG_PRT1_OUT_SEL1
miso__PRTDSI__SYNC_OUT EQU CYREG_PRT1_SYNC_OUT
miso__PS EQU CYREG_PRT1_PS
miso__SHIFT EQU 4
miso__SLW EQU CYREG_PRT1_SLW

; mosi
mosi__0__INTTYPE EQU CYREG_PICU5_INTTYPE3
mosi__0__MASK EQU 0x08
mosi__0__PC EQU CYREG_PRT5_PC3
mosi__0__PORT EQU 5
mosi__0__SHIFT EQU 3
mosi__AG EQU CYREG_PRT5_AG
mosi__AMUX EQU CYREG_PRT5_AMUX
mosi__BIE EQU CYREG_PRT5_BIE
mosi__BIT_MASK EQU CYREG_PRT5_BIT_MASK
mosi__BYP EQU CYREG_PRT5_BYP
mosi__CTL EQU CYREG_PRT5_CTL
mosi__DM0 EQU CYREG_PRT5_DM0
mosi__DM1 EQU CYREG_PRT5_DM1
mosi__DM2 EQU CYREG_PRT5_DM2
mosi__DR EQU CYREG_PRT5_DR
mosi__INP_DIS EQU CYREG_PRT5_INP_DIS
mosi__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU5_BASE
mosi__LCD_COM_SEG EQU CYREG_PRT5_LCD_COM_SEG
mosi__LCD_EN EQU CYREG_PRT5_LCD_EN
mosi__MASK EQU 0x08
mosi__PORT EQU 5
mosi__PRT EQU CYREG_PRT5_PRT
mosi__PRTDSI__CAPS_SEL EQU CYREG_PRT5_CAPS_SEL
mosi__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT5_DBL_SYNC_IN
mosi__PRTDSI__OE_SEL0 EQU CYREG_PRT5_OE_SEL0
mosi__PRTDSI__OE_SEL1 EQU CYREG_PRT5_OE_SEL1
mosi__PRTDSI__OUT_SEL0 EQU CYREG_PRT5_OUT_SEL0
mosi__PRTDSI__OUT_SEL1 EQU CYREG_PRT5_OUT_SEL1
mosi__PRTDSI__SYNC_OUT EQU CYREG_PRT5_SYNC_OUT
mosi__PS EQU CYREG_PRT5_PS
mosi__SHIFT EQU 3
mosi__SLW EQU CYREG_PRT5_SLW

; sclk
sclk__0__INTTYPE EQU CYREG_PICU3_INTTYPE6
sclk__0__MASK EQU 0x40
sclk__0__PC EQU CYREG_PRT3_PC6
sclk__0__PORT EQU 3
sclk__0__SHIFT EQU 6
sclk__AG EQU CYREG_PRT3_AG
sclk__AMUX EQU CYREG_PRT3_AMUX
sclk__BIE EQU CYREG_PRT3_BIE
sclk__BIT_MASK EQU CYREG_PRT3_BIT_MASK
sclk__BYP EQU CYREG_PRT3_BYP
sclk__CTL EQU CYREG_PRT3_CTL
sclk__DM0 EQU CYREG_PRT3_DM0
sclk__DM1 EQU CYREG_PRT3_DM1
sclk__DM2 EQU CYREG_PRT3_DM2
sclk__DR EQU CYREG_PRT3_DR
sclk__INP_DIS EQU CYREG_PRT3_INP_DIS
sclk__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
sclk__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
sclk__LCD_EN EQU CYREG_PRT3_LCD_EN
sclk__MASK EQU 0x40
sclk__PORT EQU 3
sclk__PRT EQU CYREG_PRT3_PRT
sclk__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
sclk__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
sclk__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
sclk__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
sclk__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
sclk__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
sclk__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
sclk__PS EQU CYREG_PRT3_PS
sclk__SHIFT EQU 6
sclk__SLW EQU CYREG_PRT3_SLW

; USBFS
USBFS_arb_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_arb_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_arb_int__INTC_MASK EQU 0x400000
USBFS_arb_int__INTC_NUMBER EQU 22
USBFS_arb_int__INTC_PRIOR_NUM EQU 7
USBFS_arb_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_22
USBFS_arb_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_arb_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_bus_reset__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_bus_reset__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_bus_reset__INTC_MASK EQU 0x800000
USBFS_bus_reset__INTC_NUMBER EQU 23
USBFS_bus_reset__INTC_PRIOR_NUM EQU 7
USBFS_bus_reset__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_23
USBFS_bus_reset__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_bus_reset__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_Dm__0__INTTYPE EQU CYREG_PICU15_INTTYPE7
USBFS_Dm__0__MASK EQU 0x80
USBFS_Dm__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC1
USBFS_Dm__0__PORT EQU 15
USBFS_Dm__0__SHIFT EQU 7
USBFS_Dm__AG EQU CYREG_PRT15_AG
USBFS_Dm__AMUX EQU CYREG_PRT15_AMUX
USBFS_Dm__BIE EQU CYREG_PRT15_BIE
USBFS_Dm__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USBFS_Dm__BYP EQU CYREG_PRT15_BYP
USBFS_Dm__CTL EQU CYREG_PRT15_CTL
USBFS_Dm__DM0 EQU CYREG_PRT15_DM0
USBFS_Dm__DM1 EQU CYREG_PRT15_DM1
USBFS_Dm__DM2 EQU CYREG_PRT15_DM2
USBFS_Dm__DR EQU CYREG_PRT15_DR
USBFS_Dm__INP_DIS EQU CYREG_PRT15_INP_DIS
USBFS_Dm__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU15_BASE
USBFS_Dm__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USBFS_Dm__LCD_EN EQU CYREG_PRT15_LCD_EN
USBFS_Dm__MASK EQU 0x80
USBFS_Dm__PORT EQU 15
USBFS_Dm__PRT EQU CYREG_PRT15_PRT
USBFS_Dm__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USBFS_Dm__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USBFS_Dm__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USBFS_Dm__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USBFS_Dm__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USBFS_Dm__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USBFS_Dm__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USBFS_Dm__PS EQU CYREG_PRT15_PS
USBFS_Dm__SHIFT EQU 7
USBFS_Dm__SLW EQU CYREG_PRT15_SLW
USBFS_Dp__0__INTTYPE EQU CYREG_PICU15_INTTYPE6
USBFS_Dp__0__MASK EQU 0x40
USBFS_Dp__0__PC EQU CYREG_IO_PC_PRT15_7_6_PC0
USBFS_Dp__0__PORT EQU 15
USBFS_Dp__0__SHIFT EQU 6
USBFS_Dp__AG EQU CYREG_PRT15_AG
USBFS_Dp__AMUX EQU CYREG_PRT15_AMUX
USBFS_Dp__BIE EQU CYREG_PRT15_BIE
USBFS_Dp__BIT_MASK EQU CYREG_PRT15_BIT_MASK
USBFS_Dp__BYP EQU CYREG_PRT15_BYP
USBFS_Dp__CTL EQU CYREG_PRT15_CTL
USBFS_Dp__DM0 EQU CYREG_PRT15_DM0
USBFS_Dp__DM1 EQU CYREG_PRT15_DM1
USBFS_Dp__DM2 EQU CYREG_PRT15_DM2
USBFS_Dp__DR EQU CYREG_PRT15_DR
USBFS_Dp__INP_DIS EQU CYREG_PRT15_INP_DIS
USBFS_Dp__INTSTAT EQU CYREG_PICU15_INTSTAT
USBFS_Dp__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU15_BASE
USBFS_Dp__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
USBFS_Dp__LCD_EN EQU CYREG_PRT15_LCD_EN
USBFS_Dp__MASK EQU 0x40
USBFS_Dp__PORT EQU 15
USBFS_Dp__PRT EQU CYREG_PRT15_PRT
USBFS_Dp__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
USBFS_Dp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
USBFS_Dp__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
USBFS_Dp__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
USBFS_Dp__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
USBFS_Dp__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
USBFS_Dp__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
USBFS_Dp__PS EQU CYREG_PRT15_PS
USBFS_Dp__SHIFT EQU 6
USBFS_Dp__SLW EQU CYREG_PRT15_SLW
USBFS_Dp__SNAP EQU CYREG_PICU_15_SNAP_15
USBFS_dp_int__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_dp_int__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_dp_int__INTC_MASK EQU 0x1000
USBFS_dp_int__INTC_NUMBER EQU 12
USBFS_dp_int__INTC_PRIOR_NUM EQU 7
USBFS_dp_int__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_12
USBFS_dp_int__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_dp_int__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_ep_0__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_ep_0__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_ep_0__INTC_MASK EQU 0x1000000
USBFS_ep_0__INTC_NUMBER EQU 24
USBFS_ep_0__INTC_PRIOR_NUM EQU 7
USBFS_ep_0__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_24
USBFS_ep_0__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_ep_0__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_ep_1__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_ep_1__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_ep_1__INTC_MASK EQU 0x04
USBFS_ep_1__INTC_NUMBER EQU 2
USBFS_ep_1__INTC_PRIOR_NUM EQU 7
USBFS_ep_1__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
USBFS_ep_1__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_ep_1__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_ep_2__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
USBFS_ep_2__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
USBFS_ep_2__INTC_MASK EQU 0x08
USBFS_ep_2__INTC_NUMBER EQU 3
USBFS_ep_2__INTC_PRIOR_NUM EQU 7
USBFS_ep_2__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
USBFS_ep_2__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
USBFS_ep_2__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
USBFS_USB__ARB_CFG EQU CYREG_USB_ARB_CFG
USBFS_USB__ARB_EP1_CFG EQU CYREG_USB_ARB_EP1_CFG
USBFS_USB__ARB_EP1_INT_EN EQU CYREG_USB_ARB_EP1_INT_EN
USBFS_USB__ARB_EP1_SR EQU CYREG_USB_ARB_EP1_SR
USBFS_USB__ARB_EP2_CFG EQU CYREG_USB_ARB_EP2_CFG
USBFS_USB__ARB_EP2_INT_EN EQU CYREG_USB_ARB_EP2_INT_EN
USBFS_USB__ARB_EP2_SR EQU CYREG_USB_ARB_EP2_SR
USBFS_USB__ARB_EP3_CFG EQU CYREG_USB_ARB_EP3_CFG
USBFS_USB__ARB_EP3_INT_EN EQU CYREG_USB_ARB_EP3_INT_EN
USBFS_USB__ARB_EP3_SR EQU CYREG_USB_ARB_EP3_SR
USBFS_USB__ARB_EP4_CFG EQU CYREG_USB_ARB_EP4_CFG
USBFS_USB__ARB_EP4_INT_EN EQU CYREG_USB_ARB_EP4_INT_EN
USBFS_USB__ARB_EP4_SR EQU CYREG_USB_ARB_EP4_SR
USBFS_USB__ARB_EP5_CFG EQU CYREG_USB_ARB_EP5_CFG
USBFS_USB__ARB_EP5_INT_EN EQU CYREG_USB_ARB_EP5_INT_EN
USBFS_USB__ARB_EP5_SR EQU CYREG_USB_ARB_EP5_SR
USBFS_USB__ARB_EP6_CFG EQU CYREG_USB_ARB_EP6_CFG
USBFS_USB__ARB_EP6_INT_EN EQU CYREG_USB_ARB_EP6_INT_EN
USBFS_USB__ARB_EP6_SR EQU CYREG_USB_ARB_EP6_SR
USBFS_USB__ARB_EP7_CFG EQU CYREG_USB_ARB_EP7_CFG
USBFS_USB__ARB_EP7_INT_EN EQU CYREG_USB_ARB_EP7_INT_EN
USBFS_USB__ARB_EP7_SR EQU CYREG_USB_ARB_EP7_SR
USBFS_USB__ARB_EP8_CFG EQU CYREG_USB_ARB_EP8_CFG
USBFS_USB__ARB_EP8_INT_EN EQU CYREG_USB_ARB_EP8_INT_EN
USBFS_USB__ARB_EP8_SR EQU CYREG_USB_ARB_EP8_SR
USBFS_USB__ARB_INT_EN EQU CYREG_USB_ARB_INT_EN
USBFS_USB__ARB_INT_SR EQU CYREG_USB_ARB_INT_SR
USBFS_USB__ARB_RW1_DR EQU CYREG_USB_ARB_RW1_DR
USBFS_USB__ARB_RW1_RA EQU CYREG_USB_ARB_RW1_RA
USBFS_USB__ARB_RW1_RA_MSB EQU CYREG_USB_ARB_RW1_RA_MSB
USBFS_USB__ARB_RW1_WA EQU CYREG_USB_ARB_RW1_WA
USBFS_USB__ARB_RW1_WA_MSB EQU CYREG_USB_ARB_RW1_WA_MSB
USBFS_USB__ARB_RW2_DR EQU CYREG_USB_ARB_RW2_DR
USBFS_USB__ARB_RW2_RA EQU CYREG_USB_ARB_RW2_RA
USBFS_USB__ARB_RW2_RA_MSB EQU CYREG_USB_ARB_RW2_RA_MSB
USBFS_USB__ARB_RW2_WA EQU CYREG_USB_ARB_RW2_WA
USBFS_USB__ARB_RW2_WA_MSB EQU CYREG_USB_ARB_RW2_WA_MSB
USBFS_USB__ARB_RW3_DR EQU CYREG_USB_ARB_RW3_DR
USBFS_USB__ARB_RW3_RA EQU CYREG_USB_ARB_RW3_RA
USBFS_USB__ARB_RW3_RA_MSB EQU CYREG_USB_ARB_RW3_RA_MSB
USBFS_USB__ARB_RW3_WA EQU CYREG_USB_ARB_RW3_WA
USBFS_USB__ARB_RW3_WA_MSB EQU CYREG_USB_ARB_RW3_WA_MSB
USBFS_USB__ARB_RW4_DR EQU CYREG_USB_ARB_RW4_DR
USBFS_USB__ARB_RW4_RA EQU CYREG_USB_ARB_RW4_RA
USBFS_USB__ARB_RW4_RA_MSB EQU CYREG_USB_ARB_RW4_RA_MSB
USBFS_USB__ARB_RW4_WA EQU CYREG_USB_ARB_RW4_WA
USBFS_USB__ARB_RW4_WA_MSB EQU CYREG_USB_ARB_RW4_WA_MSB
USBFS_USB__ARB_RW5_DR EQU CYREG_USB_ARB_RW5_DR
USBFS_USB__ARB_RW5_RA EQU CYREG_USB_ARB_RW5_RA
USBFS_USB__ARB_RW5_RA_MSB EQU CYREG_USB_ARB_RW5_RA_MSB
USBFS_USB__ARB_RW5_WA EQU CYREG_USB_ARB_RW5_WA
USBFS_USB__ARB_RW5_WA_MSB EQU CYREG_USB_ARB_RW5_WA_MSB
USBFS_USB__ARB_RW6_DR EQU CYREG_USB_ARB_RW6_DR
USBFS_USB__ARB_RW6_RA EQU CYREG_USB_ARB_RW6_RA
USBFS_USB__ARB_RW6_RA_MSB EQU CYREG_USB_ARB_RW6_RA_MSB
USBFS_USB__ARB_RW6_WA EQU CYREG_USB_ARB_RW6_WA
USBFS_USB__ARB_RW6_WA_MSB EQU CYREG_USB_ARB_RW6_WA_MSB
USBFS_USB__ARB_RW7_DR EQU CYREG_USB_ARB_RW7_DR
USBFS_USB__ARB_RW7_RA EQU CYREG_USB_ARB_RW7_RA
USBFS_USB__ARB_RW7_RA_MSB EQU CYREG_USB_ARB_RW7_RA_MSB
USBFS_USB__ARB_RW7_WA EQU CYREG_USB_ARB_RW7_WA
USBFS_USB__ARB_RW7_WA_MSB EQU CYREG_USB_ARB_RW7_WA_MSB
USBFS_USB__ARB_RW8_DR EQU CYREG_USB_ARB_RW8_DR
USBFS_USB__ARB_RW8_RA EQU CYREG_USB_ARB_RW8_RA
USBFS_USB__ARB_RW8_RA_MSB EQU CYREG_USB_ARB_RW8_RA_MSB
USBFS_USB__ARB_RW8_WA EQU CYREG_USB_ARB_RW8_WA
USBFS_USB__ARB_RW8_WA_MSB EQU CYREG_USB_ARB_RW8_WA_MSB
USBFS_USB__BUF_SIZE EQU CYREG_USB_BUF_SIZE
USBFS_USB__BUS_RST_CNT EQU CYREG_USB_BUS_RST_CNT
USBFS_USB__CR0 EQU CYREG_USB_CR0
USBFS_USB__CR1 EQU CYREG_USB_CR1
USBFS_USB__CWA EQU CYREG_USB_CWA
USBFS_USB__CWA_MSB EQU CYREG_USB_CWA_MSB
USBFS_USB__DMA_THRES EQU CYREG_USB_DMA_THRES
USBFS_USB__DMA_THRES_MSB EQU CYREG_USB_DMA_THRES_MSB
USBFS_USB__DYN_RECONFIG EQU CYREG_USB_DYN_RECONFIG
USBFS_USB__EP_ACTIVE EQU CYREG_USB_EP_ACTIVE
USBFS_USB__EP_TYPE EQU CYREG_USB_EP_TYPE
USBFS_USB__EP0_CNT EQU CYREG_USB_EP0_CNT
USBFS_USB__EP0_CR EQU CYREG_USB_EP0_CR
USBFS_USB__EP0_DR0 EQU CYREG_USB_EP0_DR0
USBFS_USB__EP0_DR1 EQU CYREG_USB_EP0_DR1
USBFS_USB__EP0_DR2 EQU CYREG_USB_EP0_DR2
USBFS_USB__EP0_DR3 EQU CYREG_USB_EP0_DR3
USBFS_USB__EP0_DR4 EQU CYREG_USB_EP0_DR4
USBFS_USB__EP0_DR5 EQU CYREG_USB_EP0_DR5
USBFS_USB__EP0_DR6 EQU CYREG_USB_EP0_DR6
USBFS_USB__EP0_DR7 EQU CYREG_USB_EP0_DR7
USBFS_USB__MEM_DATA EQU CYREG_USB_MEM_DATA_MBASE
USBFS_USB__PM_ACT_CFG EQU CYREG_PM_ACT_CFG5
USBFS_USB__PM_ACT_MSK EQU 0x01
USBFS_USB__PM_STBY_CFG EQU CYREG_PM_STBY_CFG5
USBFS_USB__PM_STBY_MSK EQU 0x01
USBFS_USB__SIE_EP_INT_EN EQU CYREG_USB_SIE_EP_INT_EN
USBFS_USB__SIE_EP_INT_SR EQU CYREG_USB_SIE_EP_INT_SR
USBFS_USB__SIE_EP1_CNT0 EQU CYREG_USB_SIE_EP1_CNT0
USBFS_USB__SIE_EP1_CNT1 EQU CYREG_USB_SIE_EP1_CNT1
USBFS_USB__SIE_EP1_CR0 EQU CYREG_USB_SIE_EP1_CR0
USBFS_USB__SIE_EP2_CNT0 EQU CYREG_USB_SIE_EP2_CNT0
USBFS_USB__SIE_EP2_CNT1 EQU CYREG_USB_SIE_EP2_CNT1
USBFS_USB__SIE_EP2_CR0 EQU CYREG_USB_SIE_EP2_CR0
USBFS_USB__SIE_EP3_CNT0 EQU CYREG_USB_SIE_EP3_CNT0
USBFS_USB__SIE_EP3_CNT1 EQU CYREG_USB_SIE_EP3_CNT1
USBFS_USB__SIE_EP3_CR0 EQU CYREG_USB_SIE_EP3_CR0
USBFS_USB__SIE_EP4_CNT0 EQU CYREG_USB_SIE_EP4_CNT0
USBFS_USB__SIE_EP4_CNT1 EQU CYREG_USB_SIE_EP4_CNT1
USBFS_USB__SIE_EP4_CR0 EQU CYREG_USB_SIE_EP4_CR0
USBFS_USB__SIE_EP5_CNT0 EQU CYREG_USB_SIE_EP5_CNT0
USBFS_USB__SIE_EP5_CNT1 EQU CYREG_USB_SIE_EP5_CNT1
USBFS_USB__SIE_EP5_CR0 EQU CYREG_USB_SIE_EP5_CR0
USBFS_USB__SIE_EP6_CNT0 EQU CYREG_USB_SIE_EP6_CNT0
USBFS_USB__SIE_EP6_CNT1 EQU CYREG_USB_SIE_EP6_CNT1
USBFS_USB__SIE_EP6_CR0 EQU CYREG_USB_SIE_EP6_CR0
USBFS_USB__SIE_EP7_CNT0 EQU CYREG_USB_SIE_EP7_CNT0
USBFS_USB__SIE_EP7_CNT1 EQU CYREG_USB_SIE_EP7_CNT1
USBFS_USB__SIE_EP7_CR0 EQU CYREG_USB_SIE_EP7_CR0
USBFS_USB__SIE_EP8_CNT0 EQU CYREG_USB_SIE_EP8_CNT0
USBFS_USB__SIE_EP8_CNT1 EQU CYREG_USB_SIE_EP8_CNT1
USBFS_USB__SIE_EP8_CR0 EQU CYREG_USB_SIE_EP8_CR0
USBFS_USB__SOF0 EQU CYREG_USB_SOF0
USBFS_USB__SOF1 EQU CYREG_USB_SOF1
USBFS_USB__USB_CLK_EN EQU CYREG_USB_USB_CLK_EN
USBFS_USB__USBIO_CR0 EQU CYREG_USB_USBIO_CR0
USBFS_USB__USBIO_CR1 EQU CYREG_USB_USBIO_CR1

; SPIM_1
SPIM_1_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
SPIM_1_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB08_09_CTL
SPIM_1_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB08_09_CTL
SPIM_1_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB08_09_CTL
SPIM_1_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB08_09_CTL
SPIM_1_BSPIM_BitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB08_09_MSK
SPIM_1_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB08_09_MSK
SPIM_1_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB08_09_MSK
SPIM_1_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB08_09_MSK
SPIM_1_BSPIM_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
SPIM_1_BSPIM_BitCounter__CONTROL_REG EQU CYREG_B1_UDB08_CTL
SPIM_1_BSPIM_BitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB08_ST_CTL
SPIM_1_BSPIM_BitCounter__COUNT_REG EQU CYREG_B1_UDB08_CTL
SPIM_1_BSPIM_BitCounter__COUNT_ST_REG EQU CYREG_B1_UDB08_ST_CTL
SPIM_1_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_BitCounter__PERIOD_REG EQU CYREG_B1_UDB08_MSK
SPIM_1_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
SPIM_1_BSPIM_BitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB08_09_ST
SPIM_1_BSPIM_BitCounter_ST__MASK_REG EQU CYREG_B1_UDB08_MSK
SPIM_1_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB08_ST_CTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB08_ST_CTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_REG EQU CYREG_B1_UDB08_ST
SPIM_1_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_11_ACTL
SPIM_1_BSPIM_RxStsReg__16BIT_STATUS_REG EQU CYREG_B1_UDB10_11_ST
SPIM_1_BSPIM_RxStsReg__4__MASK EQU 0x10
SPIM_1_BSPIM_RxStsReg__4__POS EQU 4
SPIM_1_BSPIM_RxStsReg__5__MASK EQU 0x20
SPIM_1_BSPIM_RxStsReg__5__POS EQU 5
SPIM_1_BSPIM_RxStsReg__6__MASK EQU 0x40
SPIM_1_BSPIM_RxStsReg__6__POS EQU 6
SPIM_1_BSPIM_RxStsReg__MASK EQU 0x70
SPIM_1_BSPIM_RxStsReg__MASK_REG EQU CYREG_B1_UDB10_MSK
SPIM_1_BSPIM_RxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB10_ACTL
SPIM_1_BSPIM_RxStsReg__STATUS_REG EQU CYREG_B1_UDB10_ST
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_A0_REG EQU CYREG_B1_UDB08_09_A0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_A1_REG EQU CYREG_B1_UDB08_09_A1
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_D0_REG EQU CYREG_B1_UDB08_09_D0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_D1_REG EQU CYREG_B1_UDB08_09_D1
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB08_09_ACTL
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_F0_REG EQU CYREG_B1_UDB08_09_F0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_F1_REG EQU CYREG_B1_UDB08_09_F1
SPIM_1_BSPIM_sR8_Dp_u0__A0_A1_REG EQU CYREG_B1_UDB08_A0_A1
SPIM_1_BSPIM_sR8_Dp_u0__A0_REG EQU CYREG_B1_UDB08_A0
SPIM_1_BSPIM_sR8_Dp_u0__A1_REG EQU CYREG_B1_UDB08_A1
SPIM_1_BSPIM_sR8_Dp_u0__D0_D1_REG EQU CYREG_B1_UDB08_D0_D1
SPIM_1_BSPIM_sR8_Dp_u0__D0_REG EQU CYREG_B1_UDB08_D0
SPIM_1_BSPIM_sR8_Dp_u0__D1_REG EQU CYREG_B1_UDB08_D1
SPIM_1_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB08_ACTL
SPIM_1_BSPIM_sR8_Dp_u0__F0_F1_REG EQU CYREG_B1_UDB08_F0_F1
SPIM_1_BSPIM_sR8_Dp_u0__F0_REG EQU CYREG_B1_UDB08_F0
SPIM_1_BSPIM_sR8_Dp_u0__F1_REG EQU CYREG_B1_UDB08_F1
SPIM_1_BSPIM_sR8_Dp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_sR8_Dp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB08_MSK_ACTL
SPIM_1_BSPIM_TxStsReg__0__MASK EQU 0x01
SPIM_1_BSPIM_TxStsReg__0__POS EQU 0
SPIM_1_BSPIM_TxStsReg__1__MASK EQU 0x02
SPIM_1_BSPIM_TxStsReg__1__POS EQU 1
SPIM_1_BSPIM_TxStsReg__2__MASK EQU 0x04
SPIM_1_BSPIM_TxStsReg__2__POS EQU 2
SPIM_1_BSPIM_TxStsReg__3__MASK EQU 0x08
SPIM_1_BSPIM_TxStsReg__3__POS EQU 3
SPIM_1_BSPIM_TxStsReg__4__MASK EQU 0x10
SPIM_1_BSPIM_TxStsReg__4__POS EQU 4
SPIM_1_BSPIM_TxStsReg__MASK EQU 0x1F
SPIM_1_BSPIM_TxStsReg__MASK_REG EQU CYREG_B1_UDB11_MSK
SPIM_1_BSPIM_TxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB11_ACTL
SPIM_1_BSPIM_TxStsReg__STATUS_REG EQU CYREG_B1_UDB11_ST
SPIM_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
SPIM_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
SPIM_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
SPIM_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
SPIM_1_IntClock__INDEX EQU 0x00
SPIM_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
SPIM_1_IntClock__PM_ACT_MSK EQU 0x01
SPIM_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
SPIM_1_IntClock__PM_STBY_MSK EQU 0x01
SPIM_1_RxInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
SPIM_1_RxInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
SPIM_1_RxInternalInterrupt__INTC_MASK EQU 0x01
SPIM_1_RxInternalInterrupt__INTC_NUMBER EQU 0
SPIM_1_RxInternalInterrupt__INTC_PRIOR_NUM EQU 7
SPIM_1_RxInternalInterrupt__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
SPIM_1_RxInternalInterrupt__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
SPIM_1_RxInternalInterrupt__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
SPIM_1_TxInternalInterrupt__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
SPIM_1_TxInternalInterrupt__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
SPIM_1_TxInternalInterrupt__INTC_MASK EQU 0x02
SPIM_1_TxInternalInterrupt__INTC_NUMBER EQU 1
SPIM_1_TxInternalInterrupt__INTC_PRIOR_NUM EQU 7
SPIM_1_TxInternalInterrupt__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
SPIM_1_TxInternalInterrupt__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
SPIM_1_TxInternalInterrupt__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 26
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E16C069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 26
CYDEV_CHIP_MEMBER_4AA EQU 25
CYDEV_CHIP_MEMBER_4AB EQU 30
CYDEV_CHIP_MEMBER_4AC EQU 14
CYDEV_CHIP_MEMBER_4AD EQU 15
CYDEV_CHIP_MEMBER_4AE EQU 16
CYDEV_CHIP_MEMBER_4D EQU 20
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 27
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 24
CYDEV_CHIP_MEMBER_4I EQU 32
CYDEV_CHIP_MEMBER_4J EQU 21
CYDEV_CHIP_MEMBER_4K EQU 22
CYDEV_CHIP_MEMBER_4L EQU 31
CYDEV_CHIP_MEMBER_4M EQU 29
CYDEV_CHIP_MEMBER_4N EQU 11
CYDEV_CHIP_MEMBER_4O EQU 8
CYDEV_CHIP_MEMBER_4P EQU 28
CYDEV_CHIP_MEMBER_4Q EQU 17
CYDEV_CHIP_MEMBER_4R EQU 9
CYDEV_CHIP_MEMBER_4S EQU 12
CYDEV_CHIP_MEMBER_4T EQU 10
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 23
CYDEV_CHIP_MEMBER_4W EQU 13
CYDEV_CHIP_MEMBER_4X EQU 7
CYDEV_CHIP_MEMBER_4Y EQU 18
CYDEV_CHIP_MEMBER_4Z EQU 19
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 33
CYDEV_CHIP_MEMBER_FM3 EQU 37
CYDEV_CHIP_MEMBER_FM4 EQU 38
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 34
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 35
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 36
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4AA_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AB_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AC_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AD_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4AE_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4W_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4X_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Y_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Z_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP EQU 1
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END