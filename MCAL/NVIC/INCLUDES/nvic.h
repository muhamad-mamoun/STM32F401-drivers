/*
=======================================================================================================================
Author       : Mamoun
Module       : NVIC
File Name    : nvic.h
Date Created : Dec 5, 2023
Description  : Interface file for the STM32 Cortex-M4 NVIC peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_NVIC_INCLUDES_NVIC_H_
#define MCAL_NVIC_INCLUDES_NVIC_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

/* The valid group levels for the NVIC. */
#if((NVIC_PRIORITY_LEVEL != NVIC_PRIORITY_LEVEL_A) && \
    (NVIC_PRIORITY_LEVEL != NVIC_PRIORITY_LEVEL_B) && \
    (NVIC_PRIORITY_LEVEL != NVIC_PRIORITY_LEVEL_C) && \
    (NVIC_PRIORITY_LEVEL != NVIC_PRIORITY_LEVEL_D) && \
    (NVIC_PRIORITY_LEVEL != NVIC_PRIORITY_LEVEL_E))
#error "Invalid interrupt priority group level!"
#endif

#if(NVIC_PRIORITY_LEVEL == NVIC_PRIORITY_LEVEL_A)
/* Level A priority groups and subgroups. */
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (1U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (2U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (3U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_00          (5U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_00          (6U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_00          (7U)
#define NVIC_PRIORITY_GROUP_08_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_09_SUBGROUP_00          (9U)
#define NVIC_PRIORITY_GROUP_10_SUBGROUP_00          (10U)
#define NVIC_PRIORITY_GROUP_11_SUBGROUP_00          (11U)
#define NVIC_PRIORITY_GROUP_12_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_13_SUBGROUP_00          (13U)
#define NVIC_PRIORITY_GROUP_14_SUBGROUP_00          (14U)
#define NVIC_PRIORITY_GROUP_15_SUBGROUP_00          (15U)

#elif(NVIC_PRIORITY_LEVEL == NVIC_PRIORITY_LEVEL_B)
/* Level B priority groups and subgroups. */
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (2U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (3U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_01          (5U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (6U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_01          (7U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_04_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_00          (10U)
#define NVIC_PRIORITY_GROUP_05_SUBGROUP_01          (11U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_06_SUBGROUP_01          (13U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_00          (14U)
#define NVIC_PRIORITY_GROUP_07_SUBGROUP_01          (15U)

#elif(NVIC_PRIORITY_LEVEL == NVIC_PRIORITY_LEVEL_C)
/* Level C priority groups and subgroups. */
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (4U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (5U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_02          (6U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_03          (7U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_02          (10U)
#define NVIC_PRIORITY_GROUP_02_SUBGROUP_03          (11U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_00          (12U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_01          (13U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_02          (14U)
#define NVIC_PRIORITY_GROUP_03_SUBGROUP_03          (15U)

#elif(NVIC_PRIORITY_LEVEL == NVIC_PRIORITY_LEVEL_D)
/* Level D priority groups and subgroups. */
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_04          (4U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_05          (5U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_06          (6U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_07          (7U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_00          (8U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_01          (9U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_02          (10U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_03          (11U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_04          (12U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_05          (13U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_06          (14U)
#define NVIC_PRIORITY_GROUP_01_SUBGROUP_07          (15U)

#elif(NVIC_PRIORITY_LEVEL == NVIC_PRIORITY_LEVEL_E)
/* Level E priority groups and subgroups. */
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_00          (0U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_01          (1U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_02          (2U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_03          (3U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_04          (4U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_05          (5U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_06          (6U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_07          (7U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_08          (8U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_09          (9U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_10          (10U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_11          (11U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_12          (12U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_13          (13U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_14          (14U)
#define NVIC_PRIORITY_GROUP_00_SUBGROUP_15          (15U)

#endif

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    NVIC_NO_ERRORS,                        /* All Good.                                      */
    NVIC_IRQ_NUM_ERROR,                    /* Invalid Interrupt Request Number Error.        */
    NVIC_PRIORITY_ERROR,                   /* Invalid Interrupt Priority Group and Subgroup. */
    NVIC_NULL_PTR_ERROR,                   /* Null Pointer Error.                            */
}NVIC_errorStatusType;

typedef enum
{
    NVIC_INTERRUPT_NOT_PENDING,            /* The interrupt status is currently not pending. */
    NVIC_INTERRUPT_PENDING,                /* The interrupt status is currently pending.     */
}NVIC_pendingStatusType;

typedef enum
{
    NVIC_WWDG_IRQ                =  0,     /* Window Watchdog interrupt.                                                        */
    NVIC_EXTI16_PVD_IRQ          =  1,     /* EXTI Line 16 interrupt and PVD through EXTI line detection interrupt.             */
    NVIC_EXTI21_TAMP_STAMP_IRQ   =  2,     /* EXTI Line 21 interrupt and Tamper and TimeStamp interrupts through the EXTI line. */
    NVIC_EXTI22_RTC_WKUP_IRQ     =  3,     /* EXTI Line 22 interrupt and RTC Wakeup interrupt through the EXTI line.            */
    NVIC_FLASH_IRQ               =  4,     /* Flash global interrupt.                                                           */
    NVIC_RCC_IRQ                 =  5,     /* RCC global interrupt.                                                             */
    NVIC_EXTI0_IRQ               =  6,     /* EXTI Line0 interrupt.                                                             */
    NVIC_EXTI1_IRQ               =  7,     /* EXTI Line1 interrupt.                                                             */
    NVIC_EXTI2_IRQ               =  8,     /* EXTI Line2 interrupt.                                                             */
    NVIC_EXTI3_IRQ               =  9,     /* EXTI Line3 interrupt.                                                             */
    NVIC_EXTI4_IRQ               = 10,     /* EXTI Line4 interrupt.                                                             */
    NVIC_DMA1_STREAM0_IRQ        = 11,     /* DMA1 Stream0 global interrupt.                                                    */
    NVIC_DMA1_STREAM1_IRQ        = 12,     /* DMA1 Stream1 global interrupt.                                                    */
    NVIC_DMA1_STREAM2_IRQ        = 13,     /* DMA1 Stream2 global interrupt.                                                    */
    NVIC_DMA1_STREAM3_IRQ        = 14,     /* DMA1 Stream3 global interrupt.                                                    */
    NVIC_DMA1_STREAM4_IRQ        = 15,     /* DMA1 Stream4 global interrupt.                                                    */
    NVIC_DMA1_STREAM5_IRQ        = 16,     /* DMA1 Stream5 global interrupt.                                                    */
    NVIC_DMA1_STREAM6_IRQ        = 17,     /* DMA1 Stream6 global interrupt.                                                    */
    NVIC_ADC_IRQ                 = 18,     /* ADC1 global interrupts.                                                           */
    NVIC_EXTI9_5_IRQ             = 23,     /* EXTI Line[9:5] interrupts.                                                        */
    NVIC_TIM1_BRK_TIM9_IRQ       = 24,     /* TIM1 Break interrupt and TIM9 global interrupt.                                   */
    NVIC_TIM1_UP_TIM10_IRQ       = 25,     /* TIM1 Update interrupt and TIM10 global interrupt.                                 */
    NVIC_TIM1_TRG_COM_TIM11_IRQ  = 26,     /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt.               */
    NVIC_TIM1_CC_IRQ             = 27,     /* TIM1 Capture Compare interrupt.                                                   */
    NVIC_TIM2_IRQ                = 28,     /* TIM2 global interrupt.                                                            */
    NVIC_TIM3_IRQ                = 29,     /* TIM3 global interrupt.                                                            */
    NVIC_TIM4_IRQ                = 30,     /* TIM4 global interrupt.                                                            */
    NVIC_I2C1_EV_IRQ             = 31,     /* I2C1 event interrupt.                                                             */
    NVIC_I2C1_ER_IRQ             = 32,     /* I2C1 error interrupt.                                                             */
    NVIC_I2C2_EV_IRQ             = 33,     /* I2C2 event interrupt.                                                             */
    NVIC_I2C2_ER_IRQ             = 34,     /* I2C2 error interrupt.                                                             */
    NVIC_SPI1_IRQ                = 35,     /* SPI1 global interrupt.                                                            */
    NVIC_SPI2_IRQ                = 36,     /* SPI2 global interrupt.                                                            */
    NVIC_USART1_IRQ              = 37,     /* USART1 global interrupt.                                                          */
    NVIC_USART2_IRQ              = 38,     /* USART2 global interrupt.                                                          */
    NVIC_EXTI15_10_IRQ           = 40,     /* EXTI Line[15:10] interrupts.                                                      */
    NVIC_EXTI17_RTC_ALARM_IRQ    = 41,     /* EXTI Line 17 interrupt and RTC Alarms (A and B) through EXTI line interrupt.      */
    NVIC_EXTI18_OTG_FS_WKUP_IRQ  = 42,     /* EXTI Line 18 interrupt and USB On-The-Go FS Wakeup through EXTI line interrupt.   */
    NVIC_DMA1_STREAM7_IRQ        = 47,     /* DMA1 Stream7 global interrupt.                                                    */
    NVIC_SDIO_IRQ                = 49,     /* SDIO global interrupt.                                                            */
    NVIC_TIM5_IRQ                = 50,     /* TIM5 global interrupt.                                                            */
    NVIC_SPI3_IRQ                = 51,     /* SPI3 global interrupt.                                                            */
    NVIC_DMA2_STREAM0_IRQ        = 56,     /* DMA2 Stream0 global interrupt.                                                    */
    NVIC_DMA2_STREAM1_IRQ        = 57,     /* DMA2 Stream1 global interrupt.                                                    */
    NVIC_DMA2_STREAM2_IRQ        = 58,     /* DMA2 Stream2 global interrupt.                                                    */
    NVIC_DMA2_STREAM3_IRQ        = 59,     /* DMA2 Stream3 global interrupt.                                                    */
    NVIC_DMA2_STREAM4_IRQ        = 60,     /* DMA2 Stream4 global interrupt.                                                    */
    NVIC_OTG_FS_IRQ              = 67,     /* USB On The Go FS global interrupt.                                                */
    NVIC_DMA2_STREAM5_IRQ        = 68,     /* DMA2 Stream5 global interrupt.                                                    */
    NVIC_DMA2_STREAM6_IRQ        = 69,     /* DMA2 Stream6 global interrupt.                                                    */
    NVIC_DMA2_STREAM7_IRQ        = 70,     /* DMA2 Stream7 global interrupt.                                                    */
    NVIC_USART6_IRQ              = 71,     /* USART6 global interrupt.                                                          */
    NVIC_I2C3_EV_IRQ             = 72,     /* I2C3 Event interrupt.                                                             */
    NVIC_I2C3_ER_IRQ             = 73,     /* I2C3 Error interrupt.                                                             */
    NVIC_FPU_IRQ                 = 81,     /* FPU global interrupt.                                                             */
    NVIC_SPI4_IRQ                = 84,     /* SPI 4 global interrupt.                                                           */
}NVIC_interruptRequestType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : NVIC_enableInterrupt
 * [Description]   : Enable a specific interrupt channel.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_enableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_disableInterrupt
 * [Description]   : Disable a specific interrupt channel.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_disableInterrupt(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPending
 * [Description]   : Set the pending status for a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_clearInterruptPending
 * [Description]   : Clear the pending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_clearInterruptPending(NVIC_interruptRequestType a_interruptRequestNumber);

/*=====================================================================================================================
 * [Function Name] : NVIC_getPendingStatus
 * [Description]   : Get the prending status of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2status>                -> Pointer to a variable to store the pending status.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getPendingStatus(NVIC_interruptRequestType a_interruptRequestNumber, NVIC_pendingStatusType* a_ptr2status);

/*=====================================================================================================================
 * [Function Name] : NVIC_setInterruptPriority
 * [Description]   : Set the priority value for a specific IRQ [Group and Subgroup].
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_priority>                  -> Indicates to the required priority group and subgroup.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Priority Value Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_setInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8 a_priority);

/*=====================================================================================================================
 * [Function Name] : NVIC_getInterruptPriority
 * [Description]   : Get the priority value of a specific IRQ.
 * [Arguments]     : <a_interruptRequestNumber>    -> Indicates to the required IRQ Number.
 *                   <a_ptr2priority>              -> Pointer to a variable to store the IRQ priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - IRQ Number Error.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
NVIC_errorStatusType NVIC_getInterruptPriority(NVIC_interruptRequestType a_interruptRequestNumber, uint8* a_ptr2priority);

#endif /* MCAL_NVIC_INCLUDES_NVIC_H_ */
