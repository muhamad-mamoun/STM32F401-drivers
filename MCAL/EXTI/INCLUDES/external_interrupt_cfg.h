/*
=======================================================================================================================
Author       : Mamoun
Module       : External Interrupt
File Name    : external_interrupt_cfg.h
Date Created : Feb 6, 2024
Description  : Configuration file for the STM32F401xx External Interrupt Peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_CFG_H_
#define MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/*=====================================================================================================================
Set the status of every EXTI channel with one of these options: 1- EXTI_ENABLED_CHANNEL
                                                                2- EXTI_DISABLED_CHANNEL
=====================================================================================================================*/
#define EXTI_CHANNEL_00_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_01_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_02_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_03_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_04_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_05_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_06_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_07_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_08_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_09_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_10_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_11_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_12_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_13_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_14_STATUS                                    (EXTI_DISABLED_CHANNEL)
#define EXTI_CHANNEL_15_STATUS                                    (EXTI_DISABLED_CHANNEL)

/*=====================================================================================================================
Set the source of every EXTI channel with one of these options: 1- EXTI_PORTA_PIN
                                                                2- EXTI_PORTB_PIN
                                                                3- EXTI_PORTC_PIN
                                                                4- EXTI_PORTD_PIN
                                                                5- EXTI_PORTE_PIN
                                                                6- EXTI_PORTH_PIN
=====================================================================================================================*/
#define EXTI_CHANNEL_00_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_01_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_02_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_03_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_04_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_05_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_06_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_07_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_08_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_09_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_10_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_11_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_12_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_13_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_14_SOURCE                                    (EXTI_PORTA_PIN)
#define EXTI_CHANNEL_15_SOURCE                                    (EXTI_PORTA_PIN)

/*=====================================================================================================================
Set the trigger mode for every EXTI channel with one of these options: 1- EXTI_FALLING_EDGE_TRIGGER
                                                                       2- EXTI_RISING_EDGE_TRIGGER
                                                                       3- EXTI_ANY_CHANGE_TRIGGER
                                                                       4- EXTI_NO_EVENT_TRIGGER
=====================================================================================================================*/
#define EXTI_CHANNEL_00_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_01_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_02_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_03_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_04_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_05_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_06_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_07_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_08_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_09_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_10_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_11_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_12_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_13_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_14_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)
#define EXTI_CHANNEL_15_TRIGGER_MODE                              (EXTI_RISING_EDGE_TRIGGER)

#endif /* MCAL_EXTI_INCLUDES_EXTERNAL_INTERRUPT_CFG_H_ */
