/*
=======================================================================================================================
Author       : Mamoun
Module       : UART
File Name    : uart_prv.h
Date Created : Feb 13, 2024
Description  : Private file for the STM32F401xx UART peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_UART_INCLUDES_UART_PRV_H_
#define MCAL_UART_INCLUDES_UART_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The number of UART peripherals in the chip. */
#define UART_NUMBER_OF_UART_PERIPHERALS                    (3U)

/* The number of samples taken for each bit in UART. */
#define UART_OVERSAMPLING_VALUE                            (16U)

/* UART has only two receiving modes [Polling - Interrupt]. */
#define UART_RECEIVE_USING_POLLING                         (0U)
#define UART_RECEIVE_USING_INTERRUPT                       (1U)

/* The maximum and the minimum valid baud rate values. */
#define UART_MIN_VALID_BAUDRATE                            (1200UL)
#define UART_MAX_VALID_BAUDRATE                            (3000000UL)

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 SR;                                    /* Status register.                   */
    volatile uint32 DR;                                    /* Data register.                     */
    volatile uint32 BRR;                                   /* Baud rate register.                */
    volatile uint32 CR1;                                   /* Control register 1.                */
    volatile uint32 CR2;                                   /* Control register 2.                */
    volatile uint32 CR3;                                   /* Control register 3.                */
    volatile uint32 GTPR;                                  /* Guard time and prescaler register. */
}UARTx_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* All UART peripherals base addresss. */
#define UART1                                              ((volatile UARTx_registersType*)0X40011000)
#define UART2                                              ((volatile UARTx_registersType*)0X40004400)
#define UART6                                              ((volatile UARTx_registersType*)0X40011400)

/* UART bit definitions. */
#define UART_BRR_MANTISSA_FIELD                            (4U)
#define UART_SR_DR_NOT_EMPTY_BIT                           (5U)
#define UART_SR_TRANSMISSION_COMPLETE_BIT                  (6U)
#define UART_CR1_RECEIVER_ENABLE_BIT                       (2U)
#define UART_CR1_TRANSMITTER_ENABLE_BIT                    (3U)
#define UART_CR1_INTERRUPT_ENABLE_BIT                      (5U)
#define UART_CR1_PARITY_SELECTION_BIT                      (9U)
#define UART_CR1_PARITY_ENABLE_BIT                         (10U)
#define UART_CR1_UART_ENABLE_BIT                           (13U)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Macro used to return the nearest integer value of the given float. */
#define UART_ROUND_NUMBER(NUM) (NUM = (((uint8)((NUM - (uint32)NUM) * 10) >= 5) ? ((uint32)NUM + 1) : (uint32)NUM))

#endif /* MCAL_UART_INCLUDES_UART_PRV_H_ */
