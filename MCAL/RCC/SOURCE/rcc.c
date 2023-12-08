/*
=======================================================================================================================
Author       : Mamoun
Module       : RCC
File Name    : rcc.c
Date Created : Dec 4, 2023
Description  : Source file for the STM32F401 RCC peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/rcc_prv.h"
#include "../INCLUDES/rcc_cfg.h"
#include "../INCLUDES/rcc.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : RCC_enableClockSource
 * [Description]   : Enable a clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source to be enabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_enableClockSource(RCC_clockSourceType a_clockSource)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;
    uint32 LOC_functionTimeout = RCC_FUNCTION_TIMEOUT_VALUE;

    if((a_clockSource != RCC_HSI_CLOCK) && (a_clockSource != RCC_HSE_CLOCK) && (a_clockSource != RCC_PLL_CLOCK))
    {
        LOC_errorStatus = RCC_CLOCK_SOURCE_ERROR;
    }

    else
    {
        switch (a_clockSource)
        {
        case RCC_HSI_CLOCK:
            SET_BIT(RCC->CR,RCC_CR_HSION_BIT);                 /* Enable the HSI clock source. */
            /* Wait until the HSI clock ready flag is set or the function's timeout has ended. */
            while((BIT_IS_CLEAR(RCC->CR,RCC_CR_HSIRDY_BIT)) && (LOC_functionTimeout--));
            /* If the function's timeout has ended, return the Function Timeout error.         */
            if(LOC_functionTimeout == 0) LOC_errorStatus = RCC_FUNCTION_TIMEOUT_ERROR;
            break;
        
        case RCC_HSE_CLOCK:
            SET_BIT(RCC->CR,RCC_CR_HSEON_BIT);                 /* Enable the HSE clock source. */
            /* Wait until the HSE clock ready flag is set or the function's timeout has ended. */
            while((BIT_IS_CLEAR(RCC->CR,RCC_CR_HSERDY_BIT)) && (LOC_functionTimeout--));
            /* If the function's timeout has ended, return the Function Timeout error.         */
            if(LOC_functionTimeout == 0) LOC_errorStatus = RCC_FUNCTION_TIMEOUT_ERROR;
            break;
        
        case RCC_PLL_CLOCK:
            SET_BIT(RCC->CR,RCC_CR_PLLON_BIT);                 /* Enable the PLL clock source. */
            /* Wait until the PLL clock ready flag is set or the function's timeout has ended. */
            while((BIT_IS_CLEAR(RCC->CR,RCC_CR_PLLRDY_BIT)) && (LOC_functionTimeout--));
            /* If the function's timeout has ended, return the Function Timeout error.         */
            if(LOC_functionTimeout == 0) LOC_errorStatus = RCC_FUNCTION_TIMEOUT_ERROR;
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_disableClockSource
 * [Description]   : Enable a clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source to be disabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_disableClockSource(RCC_clockSourceType a_clockSource)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if((a_clockSource != RCC_HSI_CLOCK) && (a_clockSource != RCC_HSE_CLOCK) && (a_clockSource != RCC_PLL_CLOCK))
    {
        LOC_errorStatus = RCC_CLOCK_SOURCE_ERROR;
    }

    else
    {
        switch (a_clockSource)
        {
        case RCC_HSI_CLOCK:
            CLEAR_BIT(RCC->CR,RCC_CR_HSION_BIT);              /* Disable the HSI clock source. */
            break;
        
        case RCC_HSE_CLOCK:
            CLEAR_BIT(RCC->CR,RCC_CR_HSEON_BIT);              /* Disable the HSE clock source. */
            break;
        
        case RCC_PLL_CLOCK:
            CLEAR_BIT(RCC->CR,RCC_CR_PLLON_BIT);              /* Disable the PLL clock source. */
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_selectSystemClock
 * [Description]   : Select the system clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_clockSource>  -> Indicates to the required clock source to provide the system with the clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Clock Source Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_selectSystemClock(RCC_clockSourceType a_clockSource)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if((a_clockSource != RCC_HSI_CLOCK) && (a_clockSource != RCC_HSE_CLOCK) && (a_clockSource != RCC_PLL_CLOCK))
    {
        LOC_errorStatus = RCC_CLOCK_SOURCE_ERROR;
    }

    else
    {
        RCC->CFGR = ((RCC->CFGR & 0XFCUL) | (a_clockSource));              /* Select the required clock source. */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_getSystemClock
 * [Description]   : Get the current system clock source [HSI clock - HSE clock - PLL clock].
 * [Arguments]     : <a_ptr2clockSource>  -> Pointer to a variable to store the current clock source.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_getSystemClock(RCC_clockSourceType* a_ptr2clockSource)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if(a_ptr2clockSource == NULL_PTR)
    {
        LOC_errorStatus = RCC_NULL_PTR_ERROR;
    }

    else
    {
        *a_ptr2clockSource = ((RCC->CFGR >> RCC_CFGR_SWS_FIELD) & 0X03UL);     /* Get the current clock source. */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_enablePeripheralClock
 * [Description]   : Enable the clock for a specific peripheral on a specific bus.
 * [Arguments]     : <a_peripheralBus>   -> Indicates to the peripheral's bus.
 *                   <a_peripheral>      -> Indicates to the required peripheral to enable its clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Peripheral Bus Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_enablePeripheralClock(RCC_peripheralBusType a_peripheralBus, uint8 a_peripheral)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if((a_peripheralBus != RCC_AHB1_BUS) && (a_peripheralBus != RCC_AHB2_BUS) && (a_peripheralBus != RCC_APB1_BUS) && (a_peripheralBus != RCC_APB2_BUS))
    {
        LOC_errorStatus = RCC_PERIPHERAL_BUS_ERROR;
    }

    else
    {
        switch (a_peripheralBus)
        {
        case RCC_AHB1_BUS:
            SET_BIT(RCC->AHB1ENR,a_peripheral);     /* Enable the clock for a specific peripheral on AHB1 bus. */
            break;
        
        case RCC_AHB2_BUS:
            SET_BIT(RCC->AHB2ENR,a_peripheral);     /* Enable the clock for a specific peripheral on AHB2 bus. */
            break;
        
        case RCC_APB1_BUS:
            SET_BIT(RCC->APB1ENR,a_peripheral);     /* Enable the clock for a specific peripheral on APB1 bus. */
            break;
        
        case RCC_APB2_BUS:
            SET_BIT(RCC->APB2ENR,a_peripheral);     /* Enable the clock for a specific peripheral on APB2 bus. */
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_disablePeripheralClock
 * [Description]   : Disable the clock for a specific peripheral on a specific bus.
 * [Arguments]     : <a_peripheralBus>   -> Indicates to the peripheral's bus.
 *                   <a_peripheral>      -> Indicates to the required peripheral to disable its clock.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Peripheral Bus Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_disablePeripheralClock(RCC_peripheralBusType a_peripheralBus, uint8 a_peripheral)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if((a_peripheralBus != RCC_AHB1_BUS) && (a_peripheralBus != RCC_AHB2_BUS) && (a_peripheralBus != RCC_APB1_BUS) && (a_peripheralBus != RCC_APB2_BUS))
    {
        LOC_errorStatus = RCC_PERIPHERAL_BUS_ERROR;
    }

    else
    {
        switch (a_peripheralBus)
        {
        case RCC_AHB1_BUS:
            CLEAR_BIT(RCC->AHB1ENR,a_peripheral);  /* Disable the clock for a specific peripheral on AHB1 bus. */
            break;
        
        case RCC_AHB2_BUS:
            CLEAR_BIT(RCC->AHB2ENR,a_peripheral);  /* Disable the clock for a specific peripheral on AHB2 bus. */
            break;
        
        case RCC_APB1_BUS:
            CLEAR_BIT(RCC->APB1ENR,a_peripheral);  /* Disable the clock for a specific peripheral on APB1 bus. */
            break;
        
        case RCC_APB2_BUS:
            CLEAR_BIT(RCC->APB2ENR,a_peripheral);  /* Disable the clock for a specific peripheral on APB2 bus. */
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : RCC_configurePLL
 * [Description]   : Configure the PLL clock source according to some factors.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to a structure that holds the PLL configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Clock Source Error.
 *                                                          - Wrong PLL Factor Error.
 ====================================================================================================================*/
RCC_errorStatusType RCC_configurePLL(RCC_PLLConfigurationsType* a_ptr2configurations)
{
    RCC_errorStatusType LOC_errorStatus = RCC_NO_ERRORS;

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = RCC_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->clock_source != RCC_HSI_CLOCK) && (a_ptr2configurations->clock_source != RCC_HSE_CLOCK))
    {
        LOC_errorStatus = RCC_CLOCK_SOURCE_ERROR;
    }

    else if((a_ptr2configurations->N_multiplication_factor < RCC_PLL_N_FACTOR_MIN_VALUE) || \
            (a_ptr2configurations->N_multiplication_factor > RCC_PLL_N_FACTOR_MAX_VALUE) || \
            (a_ptr2configurations->N_multiplication_factor == RCC_PLL_N_FACTOR_WRONG_CONFIGURATION))
    {
        LOC_errorStatus = RCC_PLL_WRONG_FACTOR_ERROR;
    }

    else if((a_ptr2configurations->M_division_factor < RCC_PLL_M_FACTOR_MIN_VALUE) || \
            (a_ptr2configurations->M_division_factor > RCC_PLL_M_FACTOR_MAX_VALUE))
    {
        LOC_errorStatus = RCC_PLL_WRONG_FACTOR_ERROR;
    }

    else if((a_ptr2configurations->P_division_factor < RCC_PLL_P_FACTOR_MIN_VALUE) || \
            (a_ptr2configurations->P_division_factor > RCC_PLL_P_FACTOR_MAX_VALUE))
    {
        LOC_errorStatus = RCC_PLL_WRONG_FACTOR_ERROR;
    }

    else if((a_ptr2configurations->Q_division_factor < RCC_PLL_Q_FACTOR_MIN_VALUE) || \
            (a_ptr2configurations->Q_division_factor > RCC_PLL_Q_FACTOR_MAX_VALUE))
    {
        LOC_errorStatus = RCC_PLL_WRONG_FACTOR_ERROR;
    }

    else
    {
        /* Set the PLL factors to configure its output clock. */
        RCC->PLLCFGR = ((a_ptr2configurations->M_division_factor << RCC_PLLCFGR_PLLM_FIELD)       | \
                        (a_ptr2configurations->N_multiplication_factor << RCC_PLLCFGR_PLLN_FIELD) | \
                        (a_ptr2configurations->P_division_factor << RCC_PLLCFGR_PLLP_FIELD)       | \
                        (a_ptr2configurations->clock_source << RCC_PLLCFGR_PLLSRC_BIT)            | \
                        (a_ptr2configurations->Q_division_factor << RCC_PLLCFGR_PLLQ_FIELD));
    }

    return LOC_errorStatus;
}
