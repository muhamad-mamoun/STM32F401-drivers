/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic_prv.h
Date Created : Dec 5, 2023
Description  : Private file for the STM32 Cortex-M4 NVIC peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_NVIC_INCLUDES_NVIC_PRV_H_
#define MCAL_NVIC_INCLUDES_NVIC_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The max priority group and subgroup value. */
#define NVIC_MAX_PRIORITY_GROUP_SUBGROUP_VALUE   (15UL)

/* The priority levels refers to the bit point for the priority group and subgroup. */
#define NVIC_PRIORITY_LEVEL_A                    (0X00) /* 4-bit for Group [7:4],  and 0-bit for Subgroup [None]. */
#define NVIC_PRIORITY_LEVEL_B                    (0X04) /* 3-bit for group [7:5],  and 1-bit for Subgroup [4].    */
#define NVIC_PRIORITY_LEVEL_C                    (0X05) /* 2-bit for group [7:6],  and 2-bit for Subgroup [5:4].  */
#define NVIC_PRIORITY_LEVEL_D                    (0X06) /* 1-bit for group [7],    and 3-bit for Subgroup [6:4].  */
#define NVIC_PRIORITY_LEVEL_E                    (0X07) /* 0-bit for group [None], and 4-bit for Subgroup [7:4].  */

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 ISER[8];           /* Interrupt Set-enable Registers.      */
    volatile uint32 RESERVED0[24];     /* Reserved Registers.                  */
    volatile uint32 ICER[8];           /* Interrupt Clear-enable Registers.    */
    volatile uint32 RESERVED1[24];     /* Reserved Registers.                  */
    volatile uint32 ISPR[8];           /* Interrupt Set-pending Registers.     */
    volatile uint32 RESERVED2[24];     /* Reserved Registers.                  */
    volatile uint32 ICPR[8];           /* Interrupt Clear-pending Registers.   */
    volatile uint32 RESERVED3[24];     /* Reserved Registers.                  */
    volatile uint32 IABR[8];           /* Interrupt Active Bit Registers.      */
    volatile uint32 RESERVED4[56];     /* Reserved Registers.                  */
    volatile uint8  IPR[240];          /* Interrupt Priority Registers.        */
    volatile uint32 RESERVED5[643];    /* Reserved Registers.                  */
    volatile uint32 STIR;              /* Software Trigger Interrupt Register. */
}NVIC_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* NVIC peripheral registers base addresss. */
#define NVIC                           ((volatile NVIC_registersType*)0XE000E100)

/* IPR 4-bit priority field for each interrupt. */
#define NVIC_IPR_PRIORITY_FIELD        (4UL)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Get the number of the register that includes the required IRQ bit. */
#define NVIC_GET_INTERRUPT_REGISTER(IRQ)     ((uint32)IRQ / 32UL)                 /* [32] is the register size. */

/* Get the number of the bit for the required IRQ. */
#define NVIC_GET_INTERRUPT_BIT(IRQ)          ((uint32)IRQ % 32UL)                 /* [32] is the register size. */

#endif /* MCAL_NVIC_INCLUDES_NVIC_PRV_H_ */
