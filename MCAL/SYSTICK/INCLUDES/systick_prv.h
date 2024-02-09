/*
=======================================================================================================================
Author       : Mamoun
Module       : SysTick
File Name    : systick_prv.h
Date Created : Feb 9, 2024
Description  : Private file for the ARM Cortex-M4 SysTick peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_SYSTICK_INCLUDES_SYSTICK_PRV_H_
#define MCAL_SYSTICK_INCLUDES_SYSTICK_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define SYSTICK_MAX_TICKS                    (16777215UL)     /* The maximum number of ticks for SysTick. */
#define SYSTICK_MILLIS_IN_SECOND             (1000.00)        /* The number milliseconds in one second.   */

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    SYSTICK_NOT_RUNNING,                     /* SysTick is NOT running.                              */
    SYSTICK_BUSY_WAIT_MODE,                  /* SysTick is running in a busy wait.                   */
    SYSTICK_SINGLE_INTERVAL_MODE,            /* SysTick is running and counting a single interval.   */
    SYSTICK_PERIODIC_INTERVAL_MODE,          /* SysTick is running and counting a periodic interval. */
}SYSTICK_currentModeType;

typedef struct
{
    volatile uint32 CTRL;                    /* SysTick Control and Status Register. */
    volatile uint32 LOAD;                    /* SysTick Reload Value Register.       */
    volatile uint32 VAL;                     /* SysTick Current Value Register.      */
    volatile uint32 CALIB;                   /* SysTick Calibration Value Register.  */
}SYSTICK_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* SysTick registers base addresss. */
#define SYSTICK                              ((volatile SYSTICK_registersType*)0XE000E010)

/* SysTick bit definitions. */
#define SYSTICK_CTRL_ENABLE_BIT              (0)
#define SYSTICK_CTRL_TICKINT_BIT             (1)
#define SYSTICK_CTRL_CLKSOURCE_BIT           (2)
#define SYSTICK_CTRL_COUNTFLAG_BIT           (16)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Macro used to calculate the total number of ticks needed for a specific time interval. */
#define SYSTICK_GET_TICKS_COUNT(INTERVAL) (((uint32)((INTERVAL / SYSTICK_MILLIS_IN_SECOND) * G_timerFrequency)) - 1)

#endif /* MCAL_SYSTICK_INCLUDES_SYSTICK_PRV_H_ */
