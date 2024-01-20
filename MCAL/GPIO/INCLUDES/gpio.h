/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio.h
Date Created : Dec 8, 2023
Description  : Interface file for the STM32F4xx GPIO peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_GPIO_INCLUDES_GPIO_H_
#define MCAL_GPIO_INCLUDES_GPIO_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    GPIO_NO_ERRORS,                  /* All Good.               */
    GPIO_PIN_ID_ERROR,               /* Wrong Pin ID Error.     */
    GPIO_PORT_ID_ERROR,              /* Wrong Port ID Error.    */
    GPIO_NULL_PTR_ERROR,             /* Null Pointer Error.     */
    GPIO_PIN_MODE_ERROR,             /* Wrong Pin Mode Error.   */
    GPIO_PIN_SPEED_ERROR,            /* Wrong Pin Speed Error.  */
    GPIO_PIN_STATUS_ERROR,           /* Wrong Pin Status Error. */
}GPIO_errorStatusType;

typedef enum
{
    GPIO_LOW_PIN,                     /* Low Pin Status.  */
    GPIO_HIGH_PIN,                    /* High Pin Status. */
}GPIO_pinStatusType;

typedef enum
{
    GPIO_ALTERNATE_FUNCTION_00,      /* ALTERNATE FUNCTION 00 ID. */
    GPIO_ALTERNATE_FUNCTION_01,      /* ALTERNATE FUNCTION 01 ID. */
    GPIO_ALTERNATE_FUNCTION_02,      /* ALTERNATE FUNCTION 02 ID. */
    GPIO_ALTERNATE_FUNCTION_03,      /* ALTERNATE FUNCTION 03 ID. */
    GPIO_ALTERNATE_FUNCTION_04,      /* ALTERNATE FUNCTION 04 ID. */
    GPIO_ALTERNATE_FUNCTION_05,      /* ALTERNATE FUNCTION 05 ID. */
    GPIO_ALTERNATE_FUNCTION_06,      /* ALTERNATE FUNCTION 06 ID. */
    GPIO_ALTERNATE_FUNCTION_07,      /* ALTERNATE FUNCTION 07 ID. */
    GPIO_ALTERNATE_FUNCTION_08,      /* ALTERNATE FUNCTION 08 ID. */
    GPIO_ALTERNATE_FUNCTION_09,      /* ALTERNATE FUNCTION 09 ID. */
    GPIO_ALTERNATE_FUNCTION_10,      /* ALTERNATE FUNCTION 10 ID. */
    GPIO_ALTERNATE_FUNCTION_11,      /* ALTERNATE FUNCTION 11 ID. */
    GPIO_ALTERNATE_FUNCTION_12,      /* ALTERNATE FUNCTION 12 ID. */
    GPIO_ALTERNATE_FUNCTION_13,      /* ALTERNATE FUNCTION 13 ID. */
    GPIO_ALTERNATE_FUNCTION_14,      /* ALTERNATE FUNCTION 14 ID. */
    GPIO_ALTERNATE_FUNCTION_15,      /* ALTERNATE FUNCTION 15 ID. */
}GPIO_alternateFunctionType;

typedef enum
{
    GPIO_PORTA_ID,                   /* PORTA ID. */
    GPIO_PORTB_ID,                   /* PORTB ID. */
    GPIO_PORTC_ID,                   /* PORTC ID. */
    GPIO_PORTD_ID,                   /* PORTD ID. */
    GPIO_PORTE_ID,                   /* PORTE ID. */
    GPIO_PORTH_ID,                   /* PORTH ID. */
}GPIO_portIDType;

typedef enum
{
    GPIO_PIN00_ID,                   /* PORTx Pin 00 ID. */
    GPIO_PIN01_ID,                   /* PORTx Pin 01 ID. */
    GPIO_PIN02_ID,                   /* PORTx Pin 02 ID. */
    GPIO_PIN03_ID,                   /* PORTx Pin 03 ID. */
    GPIO_PIN04_ID,                   /* PORTx Pin 04 ID. */
    GPIO_PIN05_ID,                   /* PORTx Pin 05 ID. */
    GPIO_PIN06_ID,                   /* PORTx Pin 06 ID. */
    GPIO_PIN07_ID,                   /* PORTx Pin 07 ID. */
    GPIO_PIN08_ID,                   /* PORTx Pin 08 ID. */
    GPIO_PIN09_ID,                   /* PORTx Pin 09 ID. */
    GPIO_PIN10_ID,                   /* PORTx Pin 10 ID. */
    GPIO_PIN11_ID,                   /* PORTx Pin 11 ID. */
    GPIO_PIN12_ID,                   /* PORTx Pin 12 ID. */
    GPIO_PIN13_ID,                   /* PORTx Pin 13 ID. */
    GPIO_PIN14_ID,                   /* PORTx Pin 14 ID. */
    GPIO_PIN15_ID,                   /* PORTx Pin 15 ID. */
}GPIO_pinIDType;

typedef enum
{
    GPIO_INPUT_FLOAT_MODE,           /* The pin works as floating input without pull-up or pull-down.       */
    GPIO_OUTPUT_PUSH_PULL_MODE,      /* The pin works as output push-pull without pull-up or pull-down.     */
    GPIO_ALTERNATE_PUSH_PULL_MODE,   /* The pin works as alternate push-pull without pull-up or pull-down.  */
    GPIO_ANALOG_MODE,                /* The pin works as analog input.                                      */
    GPIO_INPUT_PULLUP_MODE,          /* The pin works as input with pull-up resistor.                       */
    GPIO_OUTPUT_OPEN_DRAIN_MODE,     /* The pin works as output open-drain without pull-up or pull-down.    */
    GPIO_ALTERNATE_OPEN_DRAIN_MODE,  /* The pin works as alternate open-drain without pull-up or pull-down. */
    GPIO_INPUT_PULLDOWN_MODE = 0X08, /* The pin works as input with pull-down resistor.                     */
}GPIO_pinModeType;

typedef enum
{
    GPIO_LOW_SPEED,                  /* Low speed pin.    */
    GPIO_MEDIUM_SPEED,               /* Medium speed pin. */
    GPIO_HIGH_SPEED,                 /* High pin.         */
    GPIO_VERY_HIGH_SPEED,            /* Very high pin.    */
}GPIO_pinSpeedType;

typedef struct
{
    GPIO_portIDType portID;          /* Port ID [PORTA - PORTB - PORTC - PORTD - PORTE - PORTH].    */
    GPIO_pinIDType pinID;            /* Pin ID [0 ~ 15].                                            */
    GPIO_pinModeType pinMode;        /* Pin mode [one option from GPIO_pinModeType enum].           */
    GPIO_pinSpeedType pinSpeed;      /* Pin speed in output mode [Low - Medium - High - Very High]. */
}GPIO_pinConfigurationsType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GPIO_init
 * [Description]   : Initialize all the pins with specific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void GPIO_init(void);

/*=====================================================================================================================
 * [Function Name] : GPIO_configurePin
 * [Description]   : Configure a specific GPIO pin with specific configurations.
 * [Arguments]     : <a_ptr2configurations>      -> Pointer to a structure that holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Speed Error.
 *                                                          - Mode Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_configurePin(GPIO_pinConfigurationsType* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : GPIO_writePin
 * [Description]   : Write a specific logic [High or Low] on a specific pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_pinStatus>   -> Indicates to the value [High - Low].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Pin Status Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_writePin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_pinStatusType a_pinStatus);

/*=====================================================================================================================
 * [Function Name] : GPIO_writePort
 * [Description]   : Write a specific value on a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_portValue>   -> Indicates to the value of the port [0 ~ 65535].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_writePort(GPIO_portIDType a_portID, uint16 a_portValue);

/*=====================================================================================================================
 * [Function Name] : GPIO_readPin
 * [Description]   : Read the logic of a specific pin [High - LOW].
 * [Arguments]     : <a_portID>         -> Indicates to the required port ID.
 *                   <a_pinID>          -> Indicates to the required pin ID.
 *                   <a_ptr2pinStatus>  -> Pointer to variable to store the value of the pin.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_readPin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_pinStatusType* a_ptr2pinStatus);

/*=====================================================================================================================
 * [Function Name] : GPIO_readPort
 * [Description]   : Read the value of a specific port.
 * [Arguments]     : <a_portID>          -> Indicates to the required port ID.
 *                   <a_ptr2portValue>   -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_readPort(GPIO_portIDType a_portID, uint16* a_ptr2portValue);

/*=====================================================================================================================
 * [Function Name] : GPIO_togglePin
 * [Description]   : Toggle the logic of a specific pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_togglePin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID);

/*=====================================================================================================================
 * [Function Name] : GPIO_setPinFuction
 * [Description]   : Select the alternate function for a specific pin.
 * [Arguments]     : <a_portID>             -> Indicates to the required port ID.
 *                   <a_pinID>              -> Indicates to the required pin ID.
 *                   <a_alternateFunction>  -> Indicates to the required alternate function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Pin Function Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_setPinFunction(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_alternateFunctionType a_alternateFunction);

/*=====================================================================================================================
 * [Function Name] : GPIO_lockPin
 * [Description]   : Lock the configurations for a specific pin.
 * [Arguments]     : <a_portID>        -> Indicates to the required port ID.
 *                   <a_pinID>         -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_lockPin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID);

#endif /* MCAL_GPIO_INCLUDES_GPIO_H_ */
