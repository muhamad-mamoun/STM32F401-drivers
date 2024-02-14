/*
=======================================================================================================================
Author       : Mamoun
Module       : UART
File Name    : uart_cfg.h
Date Created : Feb 13, 2024
Description  : Configuration file for the STM32F401xx UART peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_UART_INCLUDES_UART_CFG_H_
#define MCAL_UART_INCLUDES_UART_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/*=====================================================================================================================
Set the UART receive mode with one of these options: 1- UART_RECEIVE_USING_POLLING
                                                     2- UART_RECEIVE_USING_INTERRUPT
=====================================================================================================================*/
#define UART_RECEIVE_MODE                    (UART_RECEIVE_USING_POLLING)

/* Set the UART clock frequency [APB clock]. */
#define UART_CLOCK_FREQUECY                  (16000000UL)

#endif /* MCAL_UART_INCLUDES_UART_CFG_H_ */
