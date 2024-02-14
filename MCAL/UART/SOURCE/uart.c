/*
=======================================================================================================================
Author       : Mamoun
Module       : UART
File Name    : uart.c
Date Created : Feb 13, 2024
Description  : Source file for the STM32F401xx UART peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/uart_prv.h"
#include "../INCLUDES/uart_cfg.h"
#include "../INCLUDES/uart.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

#if(UART_RECEIVE_MODE == UART_RECEIVE_USING_INTERRUPT)
/* Array of pointers to function stores the addresses of the call-back functions. */
static void (*G_callBackFunctionsArray[UART_NUMBER_OF_UART_PERIPHERALS])(uint8) = {NULL_PTR,NULL_PTR,NULL_PTR};
#endif

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : UART_setBaudRate
 * [Description]   : Set the required baud rate into the BRR register for specific UART.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_baudRate>         -> Indicates to the required baud rate.
 * [return]        : The function returns void.
 ====================================================================================================================*/
static void UART_setBaudRate(UART_peripheralIndexType a_peripheralIndex, uint32 a_baudRate)
{
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};
    uint8 LOC_fraction = 0, LOC_carryFlag = 0;
    uint16 LOC_mantissa = 0;

    /* Calculate the USARTDIV factor using the given equation in the target reference manual. */
    float32 LOC_USARTDIV = ((UART_CLOCK_FREQUECY / (float32)a_baudRate) / (float32)UART_OVERSAMPLING_VALUE);

    /* Calculate the fraction part and round it to the nearest integer number. */
    float32 LOC_fractionDIV = ((LOC_USARTDIV - (uint32)LOC_USARTDIV) * UART_OVERSAMPLING_VALUE);
    UART_ROUND_NUMBER(LOC_fractionDIV);

    if((uint8)LOC_fractionDIV >= UART_OVERSAMPLING_VALUE)
    {
        LOC_fraction = 0;
        LOC_carryFlag = 1;
    }

    else
    {
        LOC_fraction = (uint8)LOC_fractionDIV;
    }

    /* Calculate the mantissa part. */
    LOC_mantissa = (uint16)((uint32)LOC_USARTDIV + LOC_carryFlag);
    /* Set the required baud rate into the BRR register. */
    (*(LOC_ptr2UARTx + a_peripheralIndex))->BRR = (((LOC_mantissa & 0X0FFF) << UART_BRR_MANTISSA_FIELD) | (LOC_fraction));
}

/*=====================================================================================================================
 * [Function Name] : UART_init
 * [Description]   : Initialize a specific UART peripheral with specific configurations.
 * [Arguments]     : <a_peripheralIndex>    -> Indicates to the required UART peripheral.
 *                   <a_ptr2configurations> -> Pointer to a structure that holds the configurations.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Baud Rate Error.
 *                                                          - Device Mode Error.
 *                                                          - Null Pointer Error.
 *                                                          - Parity Status Error.
 ====================================================================================================================*/
UART_errorStatusType UART_init(UART_peripheralIndexType a_peripheralIndex, UART_configurationsType* a_ptr2configurations)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2configurations == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else if((a_ptr2configurations->baudRate < UART_MIN_VALID_BAUDRATE) || \
            (a_ptr2configurations->baudRate > UART_MAX_VALID_BAUDRATE))
    {
        LOC_errorStatus = UART_BAUD_RATE_ERROR;
    }

    else if((a_ptr2configurations->deviceMode != UART_RECEIVER_MODE) && \
            (a_ptr2configurations->deviceMode != UART_TRANSMITTER_MODE) && \
            (a_ptr2configurations->deviceMode != UART_FULL_DUPLEX_MODE))
    {
        LOC_errorStatus = UART_DEVICE_MODE_ERROR;
    }

    else if((a_ptr2configurations->parityStatus != UART_PARITY_DISABLED) && \
            (a_ptr2configurations->parityStatus != UART_EVEN_PARITY_ENABLED) && \
            (a_ptr2configurations->parityStatus != UART_ODD_PARITY_ENABLED))
    {
        LOC_errorStatus = UART_PARITY_STATUS_ERROR;
    }

    else
    {
        /* Set the parity status [Enabled or Disabled], and the parity type [Even or Odd].   */
        /* In the enum value, bit0 indicates to the status, and bit 1 indicates to the type. */
        WRITE_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_PARITY_ENABLE_BIT,GET_BIT(a_ptr2configurations->parityStatus,0));
        WRITE_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_PARITY_SELECTION_BIT,GET_BIT(a_ptr2configurations->parityStatus,1));

        /* Set the status of the transmitter and the receiver [Enabled or Disabled].                                 */
        /* In the enum value, bit0 indicates to the receiver status, and bit 1 indicates to the transmitter status.  */
        WRITE_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_RECEIVER_ENABLE_BIT,GET_BIT(a_ptr2configurations->deviceMode,0));
        WRITE_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_TRANSMITTER_ENABLE_BIT,GET_BIT(a_ptr2configurations->deviceMode,1));

        /* Set the required baud rate. */
        UART_setBaudRate(a_peripheralIndex,a_ptr2configurations->baudRate);

        /* If the interrupt mode is selected, enable the UART interrupt. */
        #if(UART_RECEIVE_MODE == UART_RECEIVE_USING_INTERRUPT)
        SET_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_INTERRUPT_ENABLE_BIT);
        #endif

        /* Enable the required UART peripheral to start the communication. */
        SET_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->CR1,UART_CR1_UART_ENABLE_BIT);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_sendByte
 * [Description]   : Send a specific byte using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_byte>             -> Indicates to the required byte to be sent.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 ====================================================================================================================*/
UART_errorStatusType UART_sendByte(UART_peripheralIndexType a_peripheralIndex, uint8 a_byte)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else
    {
        /* Write the required byte into the data register. */
        (*(LOC_ptr2UARTx + a_peripheralIndex))->DR = a_byte;
        /* Wait until the frame transmission is complete, and the Transmission Complete flag is set. */
        while(BIT_IS_CLEAR((*(LOC_ptr2UARTx + a_peripheralIndex))->SR,UART_SR_TRANSMISSION_COMPLETE_BIT));
        /* Clear the Transmission Complete flag. */
        CLEAR_BIT((*(LOC_ptr2UARTx + a_peripheralIndex))->SR,UART_SR_TRANSMISSION_COMPLETE_BIT);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_receiveByte
 * [Description]   : Receive a byte using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex> -> Indicates to the required UART peripheral.
 *                   <a_ptr2byte>        -> Pointer to variable to store the received byte.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_receiveByte(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2byte)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2byte == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        /* Wait until the data is ready to be read, and the DR Not Empty flag is set. */
        while(BIT_IS_CLEAR((*(LOC_ptr2UARTx + a_peripheralIndex))->SR,UART_SR_DR_NOT_EMPTY_BIT));
        /* Read the data register and store the byte into the variable. */
        *a_ptr2byte = (*(LOC_ptr2UARTx + a_peripheralIndex))->DR;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_sendBuffer
 * [Description]   : Send a specific buffer with a specific size using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2buffer>       -> Pointer to the required buffer to be sent.
 *                   <a_bufferSize>       -> Indicates to the buffer size.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_sendBuffer(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer, uint8 a_bufferSize)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        /* Loop on the buffer bytes and send them byte by byte. */
        for(uint8 LOC_iterator = 0; LOC_iterator < a_bufferSize; LOC_iterator++)
        {
            UART_sendByte(a_peripheralIndex,*(a_ptr2buffer + LOC_iterator));
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_receiveBuffer
 * [Description]   : Receive a buffer with a specific size using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2buffer>       -> Pointer to a buffer to store the received data.
 *                   <a_bufferSize>       -> Indicates to the buffer size.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_receiveBuffer(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer, uint8 a_bufferSize)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        /* Iterate with the buffer size and receive the data, then store it in the buffer. */
        for(uint8 LOC_iterator = 0; LOC_iterator < a_bufferSize; LOC_iterator++)
        {
            UART_receiveByte(a_peripheralIndex,(a_ptr2buffer + LOC_iterator));
        }
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_sendString
 * [Description]   : Send a specific string using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2string>       -> Pointer to the required string to be sent.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_sendString(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2string)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2string == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        /* Loop on the string characters until the Null character and send them byte by byte. */
        for(uint8 LOC_iterator = 0; *(a_ptr2string + LOC_iterator) != NULL_CHAR; LOC_iterator++)
        {
            UART_sendByte(a_peripheralIndex,*(a_ptr2string + LOC_iterator));
        }

        /* Send the Null character to indicate the end of the string. */
        UART_sendByte(a_peripheralIndex,NULL_CHAR);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : UART_receiveString
 * [Description]   : Receive a string using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2string>       -> Pointer to a buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_receiveString(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer)
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;
    UARTx_registersType* LOC_ptr2UARTx[UART_NUMBER_OF_UART_PERIPHERALS] = {UART1,UART2,UART6};

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2buffer == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        uint8 LOC_receivedByte = NULL_CHAR, LOC_iterator = 0;
        UART_receiveByte(a_peripheralIndex,&LOC_receivedByte);

        /* Check if the received character is a NULL character or not. */
        while(LOC_receivedByte != NULL_CHAR)
        {
            /* If not, store it in the buffer. */
            *(a_ptr2buffer + LOC_iterator) = LOC_receivedByte;
            /* Receive the next character. */
            UART_receiveByte(a_peripheralIndex,&LOC_receivedByte);
            LOC_iterator++;
        }

        /* Put a Null character at the end of the received string. */
        *(a_ptr2buffer + LOC_iterator) = NULL_CHAR;
    }

    return LOC_errorStatus;
}

#if(UART_RECEIVE_MODE == UART_RECEIVE_USING_INTERRUPT)
/*=====================================================================================================================
 * [Function Name] : UART_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_peripheralIndex>      -> Indicates to the required UART peripheral.
 *                   <a_ptr2callBackFunction> -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_setCallBackFunction(UART_peripheralIndexType a_peripheralIndex, void (*a_ptr2callBackFunction)(uint8))
{
    UART_errorStatusType LOC_errorStatus = UART_NO_ERRORS;

    if((a_peripheralIndex != UART1_ID) && (a_peripheralIndex != UART2_ID) && (a_peripheralIndex != UART6_ID))
    {
        LOC_errorStatus = UART_INDEX_ERROR;
    }

    else if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = UART_NULL_PTR_ERROR;
    }

    else
    {
        /* Store the address of the call-back function in the global array. */
        *(G_callBackFunctionsArray + a_peripheralIndex) = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : USART1_IRQHandler
 * [Description]   : The interrupt service routine for UART1 .
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void USART1_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + UART1_ID) != NULL_PTR)
    {
        /* Call the UART1 call-back function and pass the Data Register value to it. */
        (*(G_callBackFunctionsArray + UART1_ID))((*(LOC_ptr2UARTx + UART1_ID))->DR);
    }
}

/*=====================================================================================================================
 * [Function Name] : USART2_IRQHandler
 * [Description]   : The interrupt service routine for UART2 .
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void USART2_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + UART2_ID) != NULL_PTR)
    {
        /* Call the UART2 call-back function and pass the Data Register value to it. */
        (*(G_callBackFunctionsArray + UART2_ID))((*(LOC_ptr2UARTx + UART2_ID))->DR);
    }
}

/*=====================================================================================================================
 * [Function Name] : USART6_IRQHandler
 * [Description]   : The interrupt service routine for UART6 .
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void USART6_IRQHandler(void)
{
    if(*(G_callBackFunctionsArray + UART6_ID) != NULL_PTR)
    {
        /* Call the UART6 call-back function and pass the Data Register value to it. */
        (*(G_callBackFunctionsArray + UART6_ID))((*(LOC_ptr2UARTx + UART6_ID))->DR);
    }
}
#endif

