/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupt.h
Date Created : Feb 6, 2024
Description  : Interface file for the STM32F401xx External Interrupt Peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    EXTI_NO_ERRORS,             /* All Good.                   */
    EXTI_NULL_PTR_ERROR,        /* Null Pointer Error.         */
    EXTI_TRIGGER_MODE_ERROR,    /* Wrong Trigger Mode Error.   */
    EXTI_CHANNEL_INDEX_ERROR,   /* Wrong Channel Index Error.  */
    EXTI_CHANNEL_SOURCE_ERROR,  /* Wrong Channel Source Error. */
}EXTI_errorStatusType;

typedef enum
{
    EXTI_FALLING_EDGE_TRIGGER,  /* Trigger an interrupt at falling edge ONLY.                 */
    EXTI_RISING_EDGE_TRIGGER,   /* Trigger an interrupt at rising edge ONLY.                  */
    EXTI_ANY_CHANGE_TRIGGER,    /* Trigger an interrupt at both falling edge and rising edge. */
    EXTI_NO_EVENT_TRIGGER,      /* No interrupt triggered at any edge.                        */
}EXTI_triggerModeType;

typedef enum
{
    EXTI_PORTA_PIN,             /* PORTA source for EXTI channel. */
    EXTI_PORTB_PIN,             /* PORTB source for EXTI channel. */
    EXTI_PORTC_PIN,             /* PORTC source for EXTI channel. */
    EXTI_PORTD_PIN,             /* PORTD source for EXTI channel. */
    EXTI_PORTE_PIN,             /* PORTE source for EXTI channel. */
    EXTI_PORTH_PIN = 0X07,      /* PORTH source for EXTI channel. */
}EXTI_channelSourceType;

typedef enum
{
    EXTI_CHANNEL_00,            /* External Interrupt Channel 0.  */
    EXTI_CHANNEL_01,            /* External Interrupt Channel 1.  */
    EXTI_CHANNEL_02,            /* External Interrupt Channel 2.  */
    EXTI_CHANNEL_03,            /* External Interrupt Channel 3.  */
    EXTI_CHANNEL_04,            /* External Interrupt Channel 4.  */
    EXTI_CHANNEL_05,            /* External Interrupt Channel 5.  */
    EXTI_CHANNEL_06,            /* External Interrupt Channel 6.  */
    EXTI_CHANNEL_07,            /* External Interrupt Channel 7.  */
    EXTI_CHANNEL_08,            /* External Interrupt Channel 8.  */
    EXTI_CHANNEL_09,            /* External Interrupt Channel 9.  */
    EXTI_CHANNEL_10,            /* External Interrupt Channel 10. */
    EXTI_CHANNEL_11,            /* External Interrupt Channel 11. */
    EXTI_CHANNEL_12,            /* External Interrupt Channel 12. */
    EXTI_CHANNEL_13,            /* External Interrupt Channel 13. */
    EXTI_CHANNEL_14,            /* External Interrupt Channel 14. */
    EXTI_CHANNEL_15,            /* External Interrupt Channel 15. */
}EXTI_channelIndexType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : EXTI_init
 * [Description]   : Initialize the External Interrupt channels with specific static configurations.
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void EXTI_init(void);

/*=====================================================================================================================
 * [Function Name] : EXTI_enableChannel
 * [Description]   : Enable a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>      -> Indicates to the required channel to be enabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_enableChannel(EXTI_channelIndexType a_channelIndex);

/*=====================================================================================================================
 * [Function Name] : EXTI_disableChannel
 * [Description]   : Disable a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>      -> Indicates to the required channel to be disabled.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_disableChannel(EXTI_channelIndexType a_channelIndex);

/*=====================================================================================================================
 * [Function Name] : EXTI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>     -> Indicates to the required channel.
 *                   <a_triggerMode>      -> Indicates to the required trigger mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Channel Index Error.
 *                                                          - Channel Source Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setChannelSource(EXTI_channelIndexType a_channelIndex, EXTI_channelSourceType a_channelSource);

/*=====================================================================================================================
 * [Function Name] : EXTI_setTriggerMode
 * [Description]   : Set the trigger mode for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>     -> Indicates to the required channel.
 *                   <a_triggerMode>      -> Indicates to the required trigger mode.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Trigger Mode Error.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setTriggerMode(EXTI_channelIndexType a_channelIndex, EXTI_triggerModeType a_triggerMode);

/*=====================================================================================================================
 * [Function Name] : EXTI_setCallBackFunction
 * [Description]   : Set the address of the call-back function for a specific External Interrupt channel.
 * [Arguments]     : <a_channelIndex>         -> Indicates to the required channel.
 *                   <a_ptr2callBackFunction> -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Channel Index Error.
 ====================================================================================================================*/
EXTI_errorStatusType EXTI_setCallBackFunction(EXTI_channelIndexType a_channelIndex, void (*a_ptr2callBackFunction)(void));

#endif /* MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_H_ */
