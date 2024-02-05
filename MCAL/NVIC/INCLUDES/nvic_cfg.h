/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic_cfg.h
Date Created : Dec 5, 2023
Description  : Configuration file for the STM32 Cortex-M4 NVIC peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_NVIC_INCLUDES_NVIC_CFG_H_
#define MCAL_NVIC_INCLUDES_NVIC_CFG_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/*=====================================================================================================================
The NVIC priority group level can only configured as: - NVIC_PRIORITY_LEVEL_A
                                                      - NVIC_PRIORITY_LEVEL_B
    [Check "SCB/INCLUDES/scb.h" for more details]     - NVIC_PRIORITY_LEVEL_C
                                                      - NVIC_PRIORITY_LEVEL_D
                                                      - NVIC_PRIORITY_LEVEL_E
=====================================================================================================================*/
#define NVIC_PRIORITY_LEVEL                            (NVIC_PRIORITY_LEVEL_C)

#endif /* MCAL_NVIC_INCLUDES_NVIC_CFG_H_ */
