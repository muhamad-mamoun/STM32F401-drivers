/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupt.c
Date Created : Feb 6, 2024
Description  : Source file for the STM32F401xx External Interrupt Peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/external_interrupt_prv.h"
#include "../INCLUDES/external_interrupt_cfg.h"
#include "../INCLUDES/external_interrupt.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

/* Array of pointers to function stores the addresses of the call-back functions. */
static void (*G_callBackFunctionsArray[EXTI_NUMBER_OF_CHANNELS])(void) = {NULL_PTR};

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EXTI_init
 * [Description]   : Initialize the External Interrupt channels with specific static configurations.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXTI_init(void)
{
    /* If EXTI0 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_00_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_00,EXTI_CHANNEL_00_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_00,EXTI_CHANNEL_00_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_00);                                /* Enable EXTI0 channel interrupt. */
    #endif
    
    /* If EXTI1 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_01_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_01,EXTI_CHANNEL_01_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_01,EXTI_CHANNEL_01_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_01);                                /* Enable EXTI1 channel interrupt. */
    #endif
    
    /* If EXTI2 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_02_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_02,EXTI_CHANNEL_02_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_02,EXTI_CHANNEL_02_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_02);                                /* Enable EXTI2 channel interrupt. */
    #endif
    
    /* If EXTI3 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_03_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_03,EXTI_CHANNEL_03_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_03,EXTI_CHANNEL_03_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_03);                                /* Enable EXTI3 channel interrupt. */
    #endif
    
    /* If EXTI4 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_04_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_04,EXTI_CHANNEL_04_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_04,EXTI_CHANNEL_04_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_04);                                /* Enable EXTI4 channel interrupt. */
    #endif
    
    /* If EXTI5 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_05_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_05,EXTI_CHANNEL_05_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_05,EXTI_CHANNEL_05_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_05);                                /* Enable EXTI5 channel interrupt. */
    #endif
    
    /* If EXTI6 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_06_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_06,EXTI_CHANNEL_06_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_06,EXTI_CHANNEL_06_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_06);                                /* Enable EXTI6 channel interrupt. */
    #endif
    
    /* If EXTI7 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_07_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_07,EXTI_CHANNEL_07_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_07,EXTI_CHANNEL_07_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_07);                                /* Enable EXTI7 channel interrupt. */
    #endif
    
    /* If EXTI8 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_08_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_08,EXTI_CHANNEL_08_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_08,EXTI_CHANNEL_08_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_08);                                /* Enable EXTI8 channel interrupt. */
    #endif
    
    /* If EXTI9 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_09_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_09,EXTI_CHANNEL_09_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_09,EXTI_CHANNEL_09_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_09);                                /* Enable EXTI9 channel interrupt. */
    #endif
    
    /* If EXTI10 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_10_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_10,EXTI_CHANNEL_10_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_10,EXTI_CHANNEL_10_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_10);                               /* Enable EXTI10 channel interrupt. */
    #endif
    
    /* If EXTI11 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_11_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_11,EXTI_CHANNEL_11_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_11,EXTI_CHANNEL_11_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_11);                               /* Enable EXTI11 channel interrupt. */
    #endif
    
    /* If EXTI12 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_12_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_12,EXTI_CHANNEL_12_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_12,EXTI_CHANNEL_12_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_12);                               /* Enable EXTI12 channel interrupt. */
    #endif
    
    /* If EXTI13 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_13_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_13,EXTI_CHANNEL_13_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_13,EXTI_CHANNEL_13_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_13);                               /* Enable EXTI13 channel interrupt. */
    #endif
    
    /* If EXTI14 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_14_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_14,EXTI_CHANNEL_14_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_14,EXTI_CHANNEL_14_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_14);                               /* Enable EXTI14 channel interrupt. */
    #endif
    
    /* If EXTI15 channel is enabled, Initialize it. */
    #if(EXTI_CHANNEL_15_STATUS == EXTI_ENABLED_CHANNEL)
    EXTI_setTriggerMode(EXTI_CHANNEL_15,EXTI_CHANNEL_15_TRIGGER_MODE);   /* Set the selected trigger mode. */
    EXTI_setChannelSource(EXTI_CHANNEL_15,EXTI_CHANNEL_15_SOURCE);     /* Set the selected channel source. */
    EXTI_enableChannel(EXTI_CHANNEL_15);                               /* Enable EXTI15 channel interrupt. */
    #endif
}

/*=====================================================================================================================
 * [Function Name] : EXTI_enableChannel
 * [Description]   : Enable a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>      -> Indicates to the required channel to be enabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_enableChannel(EXTI_channelIndexType a_channelIndex)
{
    EXTI_errorStatusType LOC_errorStatus = EXTI_NO_ERRORS;

    if((a_channelIndex < EXTI_CHANNEL_00) || (a_channelIndex > EXTI_CHANNEL_15))
    {
        LOC_errorStatus = EXTI_CHANNEL_INDEX_ERROR;
    }

    else
    {
        /* Set the corresponding bit for the required channel to enable it. */
        SET_BIT(EXTI->IMR,a_channelIndex);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXTI_disableChannel
 * [Description]   : Disable a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>      -> Indicates to the required channel to be disabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_disableChannel(EXTI_channelIndexType a_channelIndex)
{
    EXTI_errorStatusType LOC_errorStatus = EXTI_NO_ERRORS;

    if((a_channelIndex < EXTI_CHANNEL_00) || (a_channelIndex > EXTI_CHANNEL_15))
    {
        LOC_errorStatus = EXTI_CHANNEL_INDEX_ERROR;
    }

    else
    {
        /* Clear the corresponding bit for the required channel to disable it. */
        CLEAR_BIT(EXTI->IMR,a_channelIndex);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXTI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>     -> Indicates to the required channel.
 *                   <a_triggerMode>      -> Indicates to the required trigger mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 *                                                          - Channel Source Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setChannelSource(EXTI_channelIndexType a_channelIndex, EXTI_channelSourceType a_channelSource)
{
    EXTI_errorStatusType LOC_errorStatus = EXTI_NO_ERRORS;

    if((a_channelIndex < EXTI_CHANNEL_00) || (a_channelIndex > EXTI_CHANNEL_15))
    {
        LOC_errorStatus = EXTI_CHANNEL_INDEX_ERROR;
    }

    else if((a_channelSource < EXTI_PORTA_PIN) || ((a_channelSource > EXTI_PORTE_PIN) && (a_channelSource != EXTI_PORTH_PIN)))
    {
        LOC_errorStatus = EXTI_CHANNEL_SOURCE_ERROR;
    }

    else
    {
        /* Future work: remove the magic numbers. */
        switch (a_channelIndex)
        {
        case EXTI_CHANNEL_00:
        case EXTI_CHANNEL_01:
        case EXTI_CHANNEL_02:
        case EXTI_CHANNEL_03:
            EXTI_WRITE_FOUR_BITS(SYSCFG->EXTICR1,(a_channelIndex - 0),a_channelSource);
            break;
        
        case EXTI_CHANNEL_04:
        case EXTI_CHANNEL_05:
        case EXTI_CHANNEL_06:
        case EXTI_CHANNEL_07:
            EXTI_WRITE_FOUR_BITS(SYSCFG->EXTICR2,(a_channelIndex - 4),a_channelSource);
            break;
        
        case EXTI_CHANNEL_08:
        case EXTI_CHANNEL_09:
        case EXTI_CHANNEL_10:
        case EXTI_CHANNEL_11:
            EXTI_WRITE_FOUR_BITS(SYSCFG->EXTICR3,(a_channelIndex - 8),a_channelSource);
            break;
        
        case EXTI_CHANNEL_12:
        case EXTI_CHANNEL_13:
        case EXTI_CHANNEL_14:
        case EXTI_CHANNEL_15:
            EXTI_WRITE_FOUR_BITS(SYSCFG->EXTICR4,(a_channelIndex - 12),a_channelSource);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXTI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>     -> Indicates to the required channel.
 *                   <a_triggerMode>      -> Indicates to the required trigger mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Trigger Mode Error.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setTriggerMode(EXTI_channelIndexType a_channelIndex, EXTI_triggerModeType a_triggerMode)
{
    EXTI_errorStatusType LOC_errorStatus = EXTI_NO_ERRORS;

    if((a_channelIndex < EXTI_CHANNEL_00) || (a_channelIndex > EXTI_CHANNEL_15))
    {
        LOC_errorStatus = EXTI_CHANNEL_INDEX_ERROR;
    }

    else if((a_triggerMode != EXTI_FALLING_EDGE_TRIGGER) && (a_triggerMode != EXTI_RISING_EDGE_TRIGGER) &&  (a_triggerMode != EXTI_ANY_CHANGE_TRIGGER))
    {
        LOC_errorStatus = EXTI_TRIGGER_MODE_ERROR;
    }

    else
    {
        switch (a_triggerMode)
        {
        case EXTI_FALLING_EDGE_TRIGGER:
            /* Enable the falling edge detection and disable the rising edge detection. */
            SET_BIT(EXTI->FTSR,a_channelIndex);
            CLEAR_BIT(EXTI->RTSR,a_channelIndex);
            break;
        
        case EXTI_RISING_EDGE_TRIGGER:
            /* Enable the rising edge detection and disable the falling edge detection. */
            SET_BIT(EXTI->RTSR,a_channelIndex);
            CLEAR_BIT(EXTI->FTSR,a_channelIndex);
            break;
        
        case EXTI_ANY_CHANGE_TRIGGER:
            /* Enable both the falling edge detection and the rising edge detection. */
            SET_BIT(EXTI->FTSR,a_channelIndex);
            SET_BIT(EXTI->RTSR,a_channelIndex);
            break;
        
        case EXTI_NO_EVENT_TRIGGER:
            /* Disable both the falling edge detection and the rising edge detection. */
            CLEAR_BIT(EXTI->FTSR,a_channelIndex);
            CLEAR_BIT(EXTI->RTSR,a_channelIndex);
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXTI_setCallBackFunction
 * [Description]   : Set the address of the call-back function for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>         -> Indicates to the required channel.
 *                   <a_ptr2callBackFunction> -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setCallBackFunction(EXTI_channelIndexType a_channelIndex, void (*a_ptr2callBackFunction)(void))
{
    EXTI_errorStatusType LOC_errorStatus = EXTI_NO_ERRORS;

    if((a_channelIndex < EXTI_CHANNEL_00) || (a_channelIndex > EXTI_CHANNEL_15))
    {
        LOC_errorStatus = EXTI_CHANNEL_INDEX_ERROR;
    }

    else if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = EXTI_NULL_PTR_ERROR;
    }

    else
    {
        /* Store the address of the call-back function in the global array. */
        *(G_callBackFunctionsArray + a_channelIndex) = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : EXTI0_IRQHandler
 * [Description]   : The interrupt service routine for the EXTI0.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
#if(EXTI_CHANNEL_00_STATUS == EXTI_ENABLED_CHANNEL)
void EXTI0_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + EXTI_CHANNEL_00) != NULL_PTR)
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_00);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_00))();                 /* Call the call-back function. */
    }
}
#endif

/*=====================================================================================================================
 * [Function Name] : EXTI1_IRQHandler
 * [Description]   : The interrupt service routine for the EXTI1.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
#if(EXTI_CHANNEL_01_STATUS == EXTI_ENABLED_CHANNEL)
void EXTI1_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + EXTI_CHANNEL_01) != NULL_PTR)
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_01);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_01))();                 /* Call the call-back function. */
    }
}
#endif

/*=====================================================================================================================
 * [Function Name] : EXTI2_IRQHandler
 * [Description]   : The interrupt service routine for the EXTI2.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
#if(EXTI_CHANNEL_02_STATUS == EXTI_ENABLED_CHANNEL)
void EXTI2_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + EXTI_CHANNEL_02) != NULL_PTR)
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_02);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_02))();                 /* Call the call-back function. */
    }
}
#endif

/*=====================================================================================================================
 * [Function Name] : EXTI3_IRQHandler
 * [Description]   : The interrupt service routine for the EXTI3.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
#if(EXTI_CHANNEL_03_STATUS == EXTI_ENABLED_CHANNEL)
void EXTI3_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + EXTI_CHANNEL_03) != NULL_PTR)
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_03);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_03))();                 /* Call the call-back function. */
    }
}
#endif

/*=====================================================================================================================
 * [Function Name] : EXTI4_IRQHandler
 * [Description]   : The interrupt service routine for the EXTI4.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
#if(EXTI_CHANNEL_04_STATUS == EXTI_ENABLED_CHANNEL)
void EXTI4_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + EXTI_CHANNEL_04) != NULL_PTR)
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_04);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_04))();                 /* Call the call-back function. */
    }
}
#endif

#if((EXTI_CHANNEL_05_STATUS == EXTI_ENABLED_CHANNEL) || (EXTI_CHANNEL_06_STATUS == EXTI_ENABLED_CHANNEL) || \
    (EXTI_CHANNEL_07_STATUS == EXTI_ENABLED_CHANNEL) || (EXTI_CHANNEL_08_STATUS == EXTI_ENABLED_CHANNEL) || \
    (EXTI_CHANNEL_09_STATUS == EXTI_ENABLED_CHANNEL))
/*=====================================================================================================================
 * [Function Name] : EXTI9_5_IRQHandler
 * [Description]   : The interrupt service routine for the [EXTI5 ~ EXTI9].
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXTI9_5_IRQHandler(void)
{
    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_05)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_05) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_05);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_05))();                 /* Call the call-back function. */
    }
    
    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_06)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_06) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_06);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_06))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_07)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_07) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_07);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_07))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_08)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_08) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_08);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_08))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_09)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_09) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_09);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_09))();                 /* Call the call-back function. */
    }
}
#endif

#if((EXTI_CHANNEL_10_STATUS == EXTI_ENABLED_CHANNEL) || (EXTI_CHANNEL_11_STATUS == EXTI_ENABLED_CHANNEL) || \
    (EXTI_CHANNEL_12_STATUS == EXTI_ENABLED_CHANNEL) || (EXTI_CHANNEL_13_STATUS == EXTI_ENABLED_CHANNEL) || \
    (EXTI_CHANNEL_14_STATUS == EXTI_ENABLED_CHANNEL) || (EXTI_CHANNEL_15_STATUS == EXTI_ENABLED_CHANNEL))
/*=====================================================================================================================
 * [Function Name] : EXTI15_10_IRQHandler
 * [Description]   : The interrupt service routine for the [EXTI10 ~ EXTI15].
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXTI15_10_IRQHandler(void)
{
    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_10)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_10) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_10);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_10))();                 /* Call the call-back function. */
    }
    
    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_11)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_11) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_11);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_11))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_12)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_12) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_12);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_12))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_13)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_13) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_13);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_13))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_14)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_14) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_14);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_14))();                 /* Call the call-back function. */
    }

    if((BIT_IS_SET(EXTI->PR,EXTI_CHANNEL_15)) && (*(G_callBackFunctionsArray + EXTI_CHANNEL_15) != NULL_PTR))
    {
        SET_BIT(EXTI->PR,EXTI_CHANNEL_15);                                      /* Clear the pending flag. */
        (*(G_callBackFunctionsArray + EXTI_CHANNEL_15))();                 /* Call the call-back function. */
    }
}
#endif
