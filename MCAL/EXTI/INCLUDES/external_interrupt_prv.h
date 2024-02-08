/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupt_prv.h
Date Created : Feb 6, 2024
Description  : Private file for the STM32F401xx External Interrupt Peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_PRV_H_
#define MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The number of EXTI channels on the IO pins. */
#define EXTI_NUMBER_OF_CHANNELS      (16U)

/* Two macros used in the channel configurations [Disabled - Enabled]. */
#define EXTI_DISABLED_CHANNEL        (0U)
#define EXTI_ENABLED_CHANNEL         (1U)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 IMR;          /* Interrupt mask register.                     */
    volatile uint32 EMR;          /* Event mask register.                         */
    volatile uint32 RTSR;         /* Rising trigger selection register.           */
    volatile uint32 FTSR;         /* Falling trigger selection register.          */
    volatile uint32 SWIER;        /* Software interrupt event register.           */
    volatile uint32 PR;           /* Pending register.                            */
}EXTI_registersType;              /* EXTI peripheral registers.                   */

typedef struct
{
    volatile uint32 MEMRMP;       /* Memory remap register.                       */
    volatile uint32 PMC;          /* Peripheral mode configuration register.      */
    volatile uint32 EXTICR1;      /* External interrupt configuration register 1. */
    volatile uint32 EXTICR2;      /* External interrupt configuration register 2. */
    volatile uint32 EXTICR3;      /* External interrupt configuration register 3. */
    volatile uint32 EXTICR4;      /* External interrupt configuration register 4. */
}SYSCFG_registersType;            /* SYSCFG peripheral registers.                 */

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* EXTI peripheral registers base addresss. */
#define EXTI                      ((volatile EXTI_registersType*)  0X40013C00)

/* SYSCFG peripheral registers base addresss. */
#define SYSCFG                    ((volatile SYSCFG_registersType*)0X40013800)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Macros used to write on multiple bits for corresponding External Interrupt channel in the SYSCFG registers. */
#define EXTI_WRITE_FOUR_BITS(REG,CHANNEL,VALUE) (REG = ((REG & (~(0X0F << (CHANNEL * 4)))) | ((VALUE & 0X0F) << (CHANNEL * 4))))

#endif /* MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_PRV_H_ */
