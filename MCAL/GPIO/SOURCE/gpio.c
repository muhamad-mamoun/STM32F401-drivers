/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio.c
Date Created : Dec 8, 2023
Description  : Source file for the STM32F401xx GPIO peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/gpio_prv.h"
#include "../INCLUDES/gpio_cfg.h"
#include "../INCLUDES/gpio.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : GPIO_init
 * [Description]   : Initialize all the pins with specific static configurations.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void GPIO_init(void)
{
    /* For Future Work. */
    /* Goal: Configure all the pins using static configurations during preprocessing stage. */
}

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
GPIO_errorStatusType GPIO_configurePin(GPIO_pinConfigurationsType* a_ptr2configurations)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->portID < GPIO_PORTA_ID) || (a_ptr2configurations->portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_ptr2configurations->pinID < GPIO_PIN00_ID) || (a_ptr2configurations->pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if((a_ptr2configurations->pinMode < GPIO_INPUT_FLOAT_MODE) || (a_ptr2configurations->pinMode > GPIO_ALTERNATE_OPEN_DRAIN_MODE) && (a_ptr2configurations->pinMode != GPIO_INPUT_PULLDOWN_MODE))
    {
        LOC_errorStatus = GPIO_PIN_MODE_ERROR;
    }

    else if((a_ptr2configurations->pinSpeed < GPIO_LOW_SPEED) || (a_ptr2configurations->pinSpeed > GPIO_VERY_HIGH_SPEED))
    {
        LOC_errorStatus = GPIO_PIN_SPEED_ERROR;
    }

    else
    {
        /* Set the I/O mode for the required pin [Input - Output - Alternate Function - Analog]. */
        GPIO_WRITE_TWO_BITS((*(LOC_ptr2GPIOx + a_ptr2configurations->portID))->MODER,a_ptr2configurations->pinID,a_ptr2configurations->pinMode);

        switch (a_ptr2configurations->pinMode)
        {
        case GPIO_INPUT_FLOAT_MODE:
        case GPIO_INPUT_PULLUP_MODE:
        case GPIO_INPUT_PULLDOWN_MODE:
            /* In case of input mode, Set the input type for the required pin [Floating - Pull-up - Pull-down]. */
            GPIO_WRITE_TWO_BITS((*(LOC_ptr2GPIOx + a_ptr2configurations->portID))->PUPDR,a_ptr2configurations->pinID,(a_ptr2configurations->pinMode >> 0X02));
            break;
        
        case GPIO_OUTPUT_PUSH_PULL_MODE:
        case GPIO_OUTPUT_OPEN_DRAIN_MODE:
        case GPIO_ALTERNATE_PUSH_PULL_MODE:
        case GPIO_ALTERNATE_OPEN_DRAIN_MODE:
            /* In case of output mode, Set the output type for the required pin [Push-Pull - Open-Drain]. */
            GPIO_WRITE_TWO_BITS((*(LOC_ptr2GPIOx + a_ptr2configurations->portID))->OTYPER,a_ptr2configurations->pinID,(a_ptr2configurations->pinMode >> 0X02));
            /* In case of output mode, Set the output speed for the required pin [Low - Medium - High - Very High]. */
            GPIO_WRITE_TWO_BITS((*(LOC_ptr2GPIOx + a_ptr2configurations->portID))->OSPEEDR,a_ptr2configurations->pinID,a_ptr2configurations->pinSpeed);
            break;
        
        case GPIO_ANALOG_MODE:
            /* Do Nothing. */
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatusType GPIO_writePin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_pinStatusType a_pinStatus)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if((a_pinStatus != GPIO_LOW_PIN) && (a_pinStatus != GPIO_HIGH_PIN))
    {
        LOC_errorStatus = GPIO_PIN_STATUS_ERROR;
    }

    else
    {
        /* Write the corresponding bit for this pin in the ODR register with the required status. */
        WRITE_BIT((*(LOC_ptr2GPIOx + a_portID))->ODR,a_pinID,a_pinStatus);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_writePinAtomic
 * [Description]   : Write a specific logic [High or Low] on a specific pin [atomically].
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 *                   <a_pinStatus>   -> Indicates to the value [High - Low].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 *                                                          - Pin Status Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_writePinAtomic(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_pinStatusType a_pinStatus)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if((a_pinStatus != GPIO_LOW_PIN) && (a_pinStatus != GPIO_HIGH_PIN))
    {
        LOC_errorStatus = GPIO_PIN_STATUS_ERROR;
    }

    else
    {
        switch (a_pinStatus)
        {
        case GPIO_HIGH_PIN:
            /* Set the corresponding bit for this pin in the ODR register. */
            (*(LOC_ptr2GPIOx + a_portID))->BSRR = (1 << a_pinID);
            break;
        
        case GPIO_LOW_PIN:
            /* Reset the corresponding bit for this pin in the ODR register. */
            (*(LOC_ptr2GPIOx + a_portID))->BSRR = (1 << (a_pinID + GPIO_NUM_OF_PINS_PER_PORT));
            break;
        
        default:
            /* Do Nothing. */
            break;
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_writePort
 * [Description]   : Write a specific value on a certain port.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_portValue>   -> Indicates to the value of the port [0 ~ 65535].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_writePort(GPIO_portIDType a_portID, uint16 a_portValue)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else
    {
        /* Write the required port value in the ODR register. */
        (*(LOC_ptr2GPIOx + a_portID))->ODR = a_portValue;
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatusType GPIO_readPin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_pinStatusType* a_ptr2pinStatus)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_ptr2pinStatus == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else
    {
        /* Read the value of the corresponding bit for this pin in the IDR register and store it. */
        *a_ptr2pinStatus = GET_BIT((*(LOC_ptr2GPIOx + a_portID))->IDR,a_pinID);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_readPort
 * [Description]   : Read the value of a specific port.
 * [Arguments]     : <a_portID>          -> Indicates to the required port ID.
 *                   <a_ptr2portValue>   -> Pointer to variable to store the value of the port.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Port ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_readPort(GPIO_portIDType a_portID, uint16* a_ptr2portValue)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if(a_ptr2portValue == NULL_PTR)
    {
        LOC_errorStatus = GPIO_NULL_PTR_ERROR;
    }

    else if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else
    {
        /* Read the value of the IDR register and store it. */
        *a_ptr2portValue = (*(LOC_ptr2GPIOx + a_portID))->IDR;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_togglePin
 * [Description]   : Toggle the logic of a specific pin.
 * [Arguments]     : <a_portID>      -> Indicates to the required port ID.
 *                   <a_pinID>       -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_togglePin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else
    {
        /* Toggle the value of the corresponding bit for this pin in the ODR register. */
        TOGGLE_BIT((*(LOC_ptr2GPIOx + a_portID))->ODR,a_pinID);
    }

    return LOC_errorStatus;
}

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
GPIO_errorStatusType GPIO_setPinFunction(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID, GPIO_alternateFunctionType a_alternateFunction)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else if((a_alternateFunction < GPIO_ALTERNATE_FUNCTION_00) || (a_alternateFunction > GPIO_ALTERNATE_FUNCTION_15))
    {
        LOC_errorStatus = GPIO_PIN_STATUS_ERROR;
    }

    else if(a_pinID < GPIO_HALF_PORT_THRESHOLD)
    {
        /* For low bits: Set the required alternate function in the corresponding 4-bit fot this pin. */
        GPIO_WRITE_FOUR_BITS((*(LOC_ptr2GPIOx + a_portID))->AFRL,a_pinID,a_alternateFunction);
    }

    else
    {
        /* For high bits: Set the required alternate function in the corresponding 4-bit fot this pin. */
        GPIO_WRITE_FOUR_BITS((*(LOC_ptr2GPIOx + a_portID))->AFRH,(a_pinID - GPIO_HALF_PORT_THRESHOLD),a_alternateFunction);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : GPIO_lockPin
 * [Description]   : Lock the configurations for a specific pin.
 * [Arguments]     : <a_portID>        -> Indicates to the required port ID.
 *                   <a_pinID>         -> Indicates to the required pin ID.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Port ID Error.
 *                                                          - Pin ID Error.
 ====================================================================================================================*/
GPIO_errorStatusType GPIO_lockPin(GPIO_portIDType a_portID, GPIO_pinIDType a_pinID)
{
    GPIO_errorStatusType LOC_errorStatus = GPIO_NO_ERRORS;
    GPIOx_registersType* LOC_ptr2GPIOx[GPIO_NUM_OF_PORTS] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};

    if((a_portID < GPIO_PORTA_ID) || (a_portID > GPIO_PORTH_ID))
    {
        LOC_errorStatus = GPIO_PORT_ID_ERROR;
    }

    else if((a_pinID < GPIO_PIN00_ID) || (a_pinID > GPIO_PIN15_ID))
    {
        LOC_errorStatus = GPIO_PIN_ID_ERROR;
    }

    else
    {
        /* Step 1: WR LCKR = (LCKR[16] = ‘1’) + LCKR[15:0]. */
        (*(LOC_ptr2GPIOx + a_portID))->LCKR = ((1 << 16) | (1 << a_pinID));
        /* Step 2: WR LCKR = (LCKR[16] = ‘0’) + LCKR[15:0]. */
        (*(LOC_ptr2GPIOx + a_portID))->LCKR = (1 << a_pinID);
        /* Step 3: WR LCKR = (LCKR[16] = ‘1’) + LCKR[15:0]. */
        (*(LOC_ptr2GPIOx + a_portID))->LCKR = ((1 << 16) | (1 << a_pinID));
        /* Step 4: RD LCKR. */
        (void)(*(LOC_ptr2GPIOx + a_portID))->LCKR;
    }

    return LOC_errorStatus;
}
