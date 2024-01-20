/*
=======================================================================================================================
Author       : Mamoun
Module       : RCC
File Name    : rcc.h
Date Created : Dec 4, 2023
Description  : Interface file for the STM32F4xx RCC peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_RCC_INCLUDES_RCC_H_
#define MCAL_RCC_INCLUDES_RCC_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* AHB1 Bus Peripherals. */
#define RCC_AHB1_GPIOA_PERIPHERAL           (0UL)
#define RCC_AHB1_GPIOB_PERIPHERAL           (1UL)
#define RCC_AHB1_GPIOC_PERIPHERAL           (2UL)
#define RCC_AHB1_GPIOD_PERIPHERAL           (3UL)
#define RCC_AHB1_GPIOE_PERIPHERAL           (4UL)
#define RCC_AHB1_GPIOH_PERIPHERAL           (7UL)
#define RCC_AHB1_CRC_PERIPHERAL             (12UL)
#define RCC_AHB1_DMA1_PERIPHERAL            (21UL)
#define RCC_AHB1_DMA2_PERIPHERAL            (22UL)

/* AHB2 Bus Peripherals. */
#define RCC_AHB2_OTGFS_PERIPHERAL           (7UL)

/* APB1 Bus Peripherals. */
#define RCC_APB1_TIM2_PERIPHERAL            (0UL)
#define RCC_APB1_TIM3_PERIPHERAL            (1UL)
#define RCC_APB1_TIM4_PERIPHERAL            (2UL)
#define RCC_APB1_TIM5_PERIPHERAL            (3UL)
#define RCC_APB1_WWDG_PERIPHERAL            (11UL)
#define RCC_APB1_SPI2_PERIPHERAL            (14UL)
#define RCC_APB1_SPI3_PERIPHERAL            (15UL)
#define RCC_APB1_USART2_PERIPHERAL          (17UL)
#define RCC_APB1_I2C1_PERIPHERAL            (21UL)
#define RCC_APB1_I2C2_PERIPHERAL            (22UL)
#define RCC_APB1_I2C3_PERIPHERAL            (23UL)
#define RCC_APB1_PWR_PERIPHERAL             (28UL)

/* APB2 Bus Peripherals. */
#define RCC_APB2_TIM1_PERIPHERAL            (0UL)
#define RCC_APB2_USART1_PERIPHERAL          (4UL)
#define RCC_APB2_USART6_PERIPHERAL          (5UL)
#define RCC_APB2_ADC1_PERIPHERAL            (8UL)
#define RCC_APB2_SDIO_PERIPHERAL            (11UL)
#define RCC_APB2_SPI1_PERIPHERAL            (12UL)
#define RCC_APB2_SPI4_PERIPHERAL            (13UL)
#define RCC_APB2_SYSCFG_PERIPHERAL          (14UL)
#define RCC_APB2_TIM9_PERIPHERAL            (16UL)
#define RCC_APB2_TIM10_PERIPHERAL           (17UL)
#define RCC_APB2_TIM11_PERIPHERAL           (18UL)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    RCC_NO_ERRORS,                        /* All Good.                                                    */
    RCC_NULL_PTR_ERROR,                   /* Null Pointer Error.                                          */
    RCC_CLOCK_SOURCE_ERROR,               /* Wrong Clock Source Error.                                    */
    RCC_PERIPHERAL_BUS_ERROR,             /* Wrong Peripheral Bus Error.                                  */
    RCC_PLL_WRONG_FACTOR_ERROR,           /* Wrong Value for PLL Factor Error.                            */
    RCC_FUNCTION_TIMEOUT_ERROR,           /* Function Timeout Ended Error.                                */
}RCC_errorStatusType;

typedef enum
{
    RCC_HSI_CLOCK,                        /* High Speed Internal Clock Source.                            */
    RCC_HSE_CLOCK,                        /* High Speed External Clock Source.                            */
    RCC_PLL_CLOCK,                        /* Phase Locked Loop Clock Source.                              */
}RCC_clockSourceType;

typedef enum
{
    RCC_AHB1_BUS,                         /* AHB1 Bus.                                                    */
    RCC_AHB2_BUS,                         /* AHB2 Bus.                                                    */
    RCC_APB1_BUS,                         /* APB1 Bus.                                                    */
    RCC_APB2_BUS,                         /* APB2 Bus.                                                    */
}RCC_peripheralBusType;

typedef struct
{
    RCC_clockSourceType clock_source;     /* PLL Input Clock Source [RCC_HSI_CLOCK or RCC_HSE_CLOCK].     */
    uint16 N_multiplication_factor;       /* PLL N Factor [2 ~ 510] except 433.                           */
    uint8 M_division_factor;              /* PLL M Factor [2 ~ 63].                                       */
    uint8 P_division_factor;              /* PLL P Factor [0 ~ 3].                                        */
    uint8 Q_division_factor;              /* PLL Q Factor [2 ~ 15].                                       */
}RCC_PLLConfigurationsType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : RCC_enableClockSource
 * [Description]   : Enable a clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source to be enabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_enableClockSource(RCC_clockSourceType a_clockSource);

/*=====================================================================================================================
 * [Function Name] : RCC_disableClockSource
 * [Description]   : Enable a clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source to be disabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_disableClockSource(RCC_clockSourceType a_clockSource);

/*=====================================================================================================================
 * [Function Name] : RCC_selectSystemClock
 * [Description]   : Select the system clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>  -> Indicates to the required clock source to provide the system with the clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_selectSystemClock(RCC_clockSourceType a_clockSource);

/*=====================================================================================================================
 * [Function Name] : RCC_getSystemClock
 * [Description]   : Get the current system clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_ptr2clockSource>  -> Pointer to a variable to store the current clock source.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_getSystemClock(RCC_clockSourceType* a_ptr2clockSource);

/*=====================================================================================================================
 * [Function Name] : RCC_enablePeripheralClock
 * [Description]   : Enable the clock for a specific peripheral on a specific bus.
 * [Arguments]     : <a_peripheralBus>   -> Indicates to the peripheral's bus.
 *                   <a_peripheral>      -> Indicates to the required peripheral to enable its clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Peripheral Bus Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_enablePeripheralClock(RCC_peripheralBusType a_peripheralBus, uint8 a_peripheral);

/*=====================================================================================================================
 * [Function Name] : RCC_disablePeripheralClock
 * [Description]   : Disable the clock for a specific peripheral on a specific bus.
 * [Arguments]     : <a_peripheralBus>   -> Indicates to the peripheral's bus.
 *                   <a_peripheral>      -> Indicates to the required peripheral to disable its clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Peripheral Bus Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_disablePeripheralClock(RCC_peripheralBusType a_peripheralBus, uint8 a_peripheral);

/*=====================================================================================================================
 * [Function Name] : RCC_configurePLL
 * [Description]   : Configure the PLL clock source according to some factors.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to a structure that holds the PLL configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Clock Source Error.
 *                                                          - Wrong PLL Factor Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_configurePLL(RCC_PLLConfigurationsType* a_ptr2configurations);

#endif /* MCAL_RCC_INCLUDES_RCC_H_ */
