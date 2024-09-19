/*
=======================================================================================================================
Author       : Mamoun
Module       : SCB
File Name    : scb_prv.h
Date Created : Dec 4, 2023
Description  : Private file for the STM32 Cortex-M4 SCB peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_SCB_INCLUDES_SCB_PRV_H_
#define MCAL_SCB_INCLUDES_SCB_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define SCB_AIRCR_WRITE_VECTKEY                     (0X05FAUL)     /* The key value to write in AIRCR register. */

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 CPUID;     /* CPUID Base Register.                              */
    volatile uint32 ICSR;      /* Interrupt Control and State Register.             */
    volatile uint32 VTOR;      /* Vector Table Offset Register.                     */
    volatile uint32 AIRCR;     /* Application Interrupt and Reset Control Register. */
    volatile uint32 SCR;       /* System Control Register.                          */
    volatile uint32 CCR;       /* Configuration and Control Register.               */
    volatile uint32 SHPR1;     /* System Handler Priority Register 1.               */
    volatile uint32 SHPR2;     /* System Handler Priority Register 2.               */
    volatile uint32 SHPR3;     /* System Handler Priority Register 3.               */
    volatile uint32 SHCRS;     /* System Handler Control and State Register.        */
    volatile uint32 CFSR;      /* Configurable Fault Status Register.               */
}SCB_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* The System Control Block (SCB) peripheral registers base addresss. */
#define SCB                    ((volatile SCB_registersType*)0XE000ED00)

#define SCB_AIRCR_PRIGROUP_FIELD                    (8UL)      /* PRIGROUP field base bit number.          */
#define SCB_AIRCR_VECTKEY_FIELD                     (16UL)     /* VECTKEY field base bit number.           */
#define SCB_SHPR3_PENDSV_FIELD                      (16UL)     /* PendSV Priority field base bit number.   */
#define SCB_SHPR3_SYSTICK_FIELD                     (24UL)     /* SysTick Priority field base bit number.  */

#define SCB_ICSR_PENDSTCLR_BIT                      (25UL)     /* SysTick Clear Pending bit number.        */
#define SCB_ICSR_PENDSTSET_BIT                      (26UL)     /* SysTick Set Pending bit number.          */
#define SCB_ICSR_PENDSVCLR_BIT                      (27UL)     /* PendSV Clear Pending bit number.         */
#define SCB_ICSR_PENDSVSET_BIT                      (28UL)     /* PendSV Set Pending bit number.           */

#endif /* MCAL_SCB_INCLUDES_SCB_PRV_H_ */
