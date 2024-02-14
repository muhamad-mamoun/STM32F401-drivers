/*
=======================================================================================================================
Author       : Mamoun
Module       : UART
File Name    : uart.h
Date Created : Feb 13, 2024
Description  : Interface file for the STM32F401xx UART peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_UART_INCLUDES_UART_H_
#define MCAL_UART_INCLUDES_UART_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    UART_NO_ERRORS,                      /* All Good.                    */
    UART_INDEX_ERROR,                    /* Invalid Index Error.         */
    UART_NULL_PTR_ERROR,                 /* Null Pointer Error.          */
    UART_BAUD_RATE_ERROR,                /* Invalid Baud Rate Error.     */
    UART_DEVICE_MODE_ERROR,              /* Invalid Device Mode Error.   */
    UART_PARITY_STATUS_ERROR,            /* Invalid Parity Status Error. */
}UART_errorStatusType;

typedef enum
{
    UART1_ID,                            /* UART1 Index. */
    UART2_ID,                            /* UART2 Index. */
    UART6_ID,                            /* UART6 Index. */
}UART_peripheralIndexType;

typedef enum
{
    UART_RECEIVER_MODE    = 0X01,        /* Receiver Mode.    */
    UART_TRANSMITTER_MODE = 0X02,        /* Transmitter Mode. */
    UART_FULL_DUPLEX_MODE = 0X03,        /* Full-Duplex Mode. */
}UART_deviceModeType;

typedef enum
{
    UART_PARITY_DISABLED,                /* Parity Disabled.     */
    UART_EVEN_PARITY_ENABLED,            /* Even Parity Enabled. */
    UART_ODD_PARITY_ENABLED = 0X03,      /* Odd Parity Enabled.  */
}UART_parityStatusType;

typedef struct
{
    uint32 baudRate;                     /* Baud Rate Value [1200 ~ 3000000].                    */
    UART_deviceModeType deviceMode;      /* Device Mode [Transmitter - Receiver - Full-Duplex].  */
    UART_parityStatusType parityStatus;  /* Parity Status [Disabled - Even Parity - Odd Parity]. */
}UART_configurationsType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

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
UART_errorStatusType UART_init(UART_peripheralIndexType a_peripheralIndex, UART_configurationsType* a_ptr2configurations);

/*=====================================================================================================================
 * [Function Name] : UART_sendByte
 * [Description]   : Send a specific byte using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_byte>             -> Indicates to the required byte to be sent.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 ====================================================================================================================*/
UART_errorStatusType UART_sendByte(UART_peripheralIndexType a_peripheralIndex, uint8 a_byte);

/*=====================================================================================================================
 * [Function Name] : UART_receiveByte
 * [Description]   : Receive a byte using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex> -> Indicates to the required UART peripheral.
 *                   <a_ptr2byte>        -> Pointer to variable to store the received byte.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_receiveByte(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2byte);

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
UART_errorStatusType UART_sendBuffer(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer, uint8 a_bufferSize);

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
UART_errorStatusType UART_receiveBuffer(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer, uint8 a_bufferSize);

/*=====================================================================================================================
 * [Function Name] : UART_sendString
 * [Description]   : Send a specific string using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2string>       -> Pointer to the required string to be sent.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_sendString(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2string);

/*=====================================================================================================================
 * [Function Name] : UART_receiveString
 * [Description]   : Receive a string using a specific UART peripheral.
 * [Arguments]     : <a_peripheralIndex>  -> Indicates to the required UART peripheral.
 *                   <a_ptr2string>       -> Pointer to a buffer to store the received string.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Index Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
UART_errorStatusType UART_receiveString(UART_peripheralIndexType a_peripheralIndex, uint8* a_ptr2buffer);

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
UART_errorStatusType UART_setCallBackFunction(UART_peripheralIndexType a_peripheralIndex, void (*a_ptr2callBackFunction)(uint8));
#endif

#endif /* MCAL_UART_INCLUDES_UART_H_ */
