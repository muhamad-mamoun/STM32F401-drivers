/*
=======================================================================================================================
Author       : Mamoun
Module       : RCC
File Name    : rcc_prv.h
Date Created : Dec 4, 2023
Description  : Private file for the STM32F401xx RCC peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_RCC_INCLUDES_RCC_PRV_H_
#define MCAL_RCC_INCLUDES_RCC_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The function timeout used in RCC_enableClockSource function. */
#define RCC_FUNCTION_TIMEOUT_VALUE                              (1000000UL)

/* PLL Configurations: N Factor. */
#define RCC_PLL_N_FACTOR_MIN_VALUE                              (2UL)
#define RCC_PLL_N_FACTOR_MAX_VALUE                              (510UL)
#define RCC_PLL_N_FACTOR_WRONG_CONFIGURATION                    (433UL)

/* PLL Configurations: M Factor. */
#define RCC_PLL_M_FACTOR_MIN_VALUE                              (2UL)
#define RCC_PLL_M_FACTOR_MAX_VALUE                              (63UL)

/* PLL Configurations: P Factor. */
#define RCC_PLL_P_FACTOR_MIN_VALUE                              (0UL)
#define RCC_PLL_P_FACTOR_MAX_VALUE                              (3UL)

/* PLL Configurations: Q Factor. */
#define RCC_PLL_Q_FACTOR_MIN_VALUE                              (2UL)
#define RCC_PLL_Q_FACTOR_MAX_VALUE                              (15UL)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 CR;             /* RCC clock control register.                                   */
    volatile uint32 PLLCFGR;        /* RCC PLL configuration register.                               */
    volatile uint32 CFGR;           /* RCC clock configuration register.                             */
    volatile uint32 CIR;            /* RCC clock interrupt register.                                 */
    volatile uint32 AHB1RSTR;       /* RCC AHB1 peripheral reset register.                           */
    volatile uint32 AHB2RSTR;       /* RCC AHB2 peripheral reset register.                           */
    volatile uint32 RESERVED01;     /* Reserved register.                                            */
    volatile uint32 RESERVED02;     /* Reserved register.                                            */
    volatile uint32 APB1RSTR;       /* RCC APB1 peripheral reset register.                           */
    volatile uint32 APB2RSTR;       /* RCC APB2 peripheral reset register.                           */
    volatile uint32 RESERVED03;     /* Reserved register.                                            */
    volatile uint32 RESERVED04;     /* Reserved register.                                            */
    volatile uint32 AHB1ENR;        /* RCC AHB1 peripheral clock enable register.                    */
    volatile uint32 AHB2ENR;        /* RCC AHB2 peripheral clock enable register.                    */
    volatile uint32 RESERVED05;     /* Reserved register.                                            */
    volatile uint32 RESERVED06;     /* Reserved register.                                            */
    volatile uint32 APB1ENR;        /* RCC APB1 peripheral clock enable register.                    */
    volatile uint32 APB2ENR;        /* RCC APB2 peripheral clock enable register.                    */
    volatile uint32 RESERVED07;     /* Reserved register.                                            */
    volatile uint32 RESERVED08;     /* Reserved register.                                            */
    volatile uint32 AHB1LPENR;      /* RCC AHB1 peripheral clock enable in low power mode register.  */
    volatile uint32 AHB2LPENR;      /* RCC AHB2 peripheral clock enable in low power mode register.  */
    volatile uint32 RESERVED09;     /* Reserved register.                                            */
    volatile uint32 RESERVED10;     /* Reserved register.                                            */
    volatile uint32 APB1LPENR;      /* RCC APB1 peripheral clock enable in low power mode register.  */
    volatile uint32 APB2LPENR;      /* RCC APB2 peripheral clock enabled in low power mode register. */
    volatile uint32 RESERVED11;     /* Reserved register.                                            */
    volatile uint32 RESERVED12;     /* Reserved register.                                            */
    volatile uint32 BDCR;           /* RCC Backup domain control register.                           */
    volatile uint32 CSR;            /* RCC clock control & status register.                          */
    volatile uint32 RESERVED13;     /* Reserved register.                                            */
    volatile uint32 RESERVED14;     /* Reserved register.                                            */
    volatile uint32 SSCGR;          /* RCC spread spectrum clock generation register.                */
    volatile uint32 PLLI2SCFGR;     /* RCC PLLI2S configuration register.                            */
    volatile uint32 RESERVED15;     /* Reserved register.                                            */
    volatile uint32 DCKCFGR;        /* RCC Dedicated Clocks Configuration Register.                  */
}RCC_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* The Reset and Clock Control (RCC) peripheral registers base addresss. */
#define RCC                         ((volatile RCC_registersType*)0X40023800)

/* CR register fields and bits number. */
#define RCC_CR_HSION_BIT                          (0UL)
#define RCC_CR_HSIRDY_BIT                         (1UL)
#define RCC_CR_HSEON_BIT                          (16UL)
#define RCC_CR_HSERDY_BIT                         (17UL)
#define RCC_CR_PLLON_BIT                          (24UL)
#define RCC_CR_PLLRDY_BIT                         (25UL)

/* PLLCFGR register fields and bits number. */
#define RCC_PLLCFGR_PLLM_FIELD                    (0UL)
#define RCC_PLLCFGR_PLLN_FIELD                    (6UL)
#define RCC_PLLCFGR_PLLP_FIELD                    (16UL)
#define RCC_PLLCFGR_PLLSRC_BIT                    (22UL)
#define RCC_PLLCFGR_PLLQ_FIELD                    (24UL)

/* CFGR register fields and bits number. */
#define RCC_CFGR_SW_FIELD                         (0UL)
#define RCC_CFGR_SWS_FIELD                        (2UL)

#endif /* MCAL_RCC_INCLUDES_RCC_PRV_H_ */
