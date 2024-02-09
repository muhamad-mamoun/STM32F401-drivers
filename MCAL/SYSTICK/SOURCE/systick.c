/*
=======================================================================================================================
Author       : Mamoun
Module       : SysTick
File Name    : systick.c
Date Created : Feb 9, 2024
Description  : Source file for the ARM Cortex-M4 SysTick peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/systick_prv.h"
#include "../INCLUDES/systick_cfg.h"
#include "../INCLUDES/systick.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/

static uint32 G_timerFrequency = CPU_CLOCK;                                 /* SysTick clock frequency.           */
static void (*G_ptr2callBackFunction)(void) = NULL_PTR;                     /* Pointer to the call-back function. */
static SYSTICK_currentModeType G_systickCurrentMode = SYSTICK_NOT_RUNNING;  /* SysTick current operation mode.    */

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : SYSTICK_init
 * [Description]   : Initialize SysTick by setting its clock source.
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source for SysTick.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SYSTICK_init(SYSTICK_clockSourceType a_clockSource)
{
    /* Set the required clock source for SysTick. */
    WRITE_BIT(SYSTICK->CTRL,SYSTICK_CTRL_CLKSOURCE_BIT,a_clockSource);
    /* Update the value of SysTick clock frequency. */
    G_timerFrequency = ((a_clockSource == SYSTICK_CPU_CLOCK) ? CPU_CLOCK : (CPU_CLOCK / 8));
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setBusyWait
 * [Description]   : Set a blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setBusyWait(uint16 a_timeInterval)
{
    SYSTICK_errorStatusType LOC_errorStatus = SYSTICK_NO_ERRORS;

    /* Calculate the maximum time interval for SysTick according to the current frequency. */
    uint16 LOC_maxTimeInterval = ((SYSTICK_MAX_TICKS / G_timerFrequency) * SYSTICK_MILLIS_IN_SECOND);

    if(G_systickCurrentMode != SYSTICK_NOT_RUNNING)
    {
        LOC_errorStatus = SYSTICK_BUSY_ERROR;
    }

    else if(a_timeInterval > LOC_maxTimeInterval)
    {
        LOC_errorStatus = SYSTICK_OVERFLOW_ERROR;
    }

    else
    {
        G_systickCurrentMode = SYSTICK_BUSY_WAIT_MODE;               /* Change SysTick current mode.           */
        SYSTICK->LOAD = SYSTICK_GET_TICKS_COUNT(a_timeInterval);     /* Calculate and Set the number of ticks. */
        SYSTICK->VAL = 0;                                            /* Reset the Current Value Register.      */
        SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_BIT);              /* Enable SysTick counter.                */

        /* Wait until the time interval is elapsed and count flag is set to HIGH. */
        while(BIT_IS_CLEAR(SYSTICK->CTRL,SYSTICK_CTRL_COUNTFLAG_BIT));
        /* Stop and Reset SysTick. */
        SYSTICK_deinit();
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setSingleInterval
 * [Description]   : Set a single non-blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setSingleInterval(uint16 a_timeInterval)
{
    SYSTICK_errorStatusType LOC_errorStatus = SYSTICK_NO_ERRORS;

    /* Calculate the maximum time interval for SysTick according to the current frequency. */
    uint16 LOC_maxTimeInterval = ((SYSTICK_MAX_TICKS / G_timerFrequency) * SYSTICK_MILLIS_IN_SECOND);

    if(G_systickCurrentMode != SYSTICK_NOT_RUNNING)
    {
        LOC_errorStatus = SYSTICK_BUSY_ERROR;
    }

    else if(a_timeInterval > LOC_maxTimeInterval)
    {
        LOC_errorStatus = SYSTICK_OVERFLOW_ERROR;
    }

    else
    {
        G_systickCurrentMode = SYSTICK_SINGLE_INTERVAL_MODE;         /* Change SysTick current mode.           */
        SYSTICK->LOAD = SYSTICK_GET_TICKS_COUNT(a_timeInterval);     /* Calculate and Set the number of ticks. */
        SYSTICK->VAL = 0;                                            /* Reset the Current Value Register.      */
        SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_BIT);             /* Enable SysTick interrupt.              */
        SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_BIT);              /* Enable SysTick counter.                */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setPeriodicInterval
 * [Description]   : Set a periodic non-blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setPeriodicInterval(uint16 a_timeInterval)
{
    SYSTICK_errorStatusType LOC_errorStatus = SYSTICK_NO_ERRORS;

    /* Calculate the maximum time interval for SysTick according to the current frequency. */
    uint16 LOC_maxTimeInterval = ((SYSTICK_MAX_TICKS / G_timerFrequency) * SYSTICK_MILLIS_IN_SECOND);

    if(G_systickCurrentMode != SYSTICK_NOT_RUNNING)
    {
        LOC_errorStatus = SYSTICK_BUSY_ERROR;
    }

    else if(a_timeInterval > LOC_maxTimeInterval)
    {
        LOC_errorStatus = SYSTICK_OVERFLOW_ERROR;
    }

    else
    {
        G_systickCurrentMode = SYSTICK_PERIODIC_INTERVAL_MODE;       /* Change SysTick current mode.           */
        SYSTICK->LOAD = SYSTICK_GET_TICKS_COUNT(a_timeInterval);     /* Calculate and Set the number of ticks. */
        SYSTICK->VAL = 0;                                            /* Reset the Current Value Register.      */
        SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_BIT);             /* Enable SysTick interrupt.              */
        SET_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_BIT);              /* Enable SysTick counter.                */
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setCallBackFunction(void (*a_ptr2callBackFunction)(void))
{
    SYSTICK_errorStatusType LOC_errorStatus = SYSTICK_NO_ERRORS;

    if(a_ptr2callBackFunction == NULL_PTR)
    {
        LOC_errorStatus = SYSTICK_NULL_PTR_ERROR;
    }

    else
    {
        /* Store the address of the call-back function in the global variable. */
        G_ptr2callBackFunction = a_ptr2callBackFunction;
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_getElapsedTicks
 * [Description]   : Get the number of elapsed ticks in the current time interval.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the number of elapsed ticks.
 ====================================================================================================================*/
uint32 SYSTICK_getElapsedTicks(void)
{
    /* The number of elapsed ticks = (Reload Value Register - Current Value Register). */
    return (SYSTICK->LOAD - SYSTICK->VAL);
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_getRemainingTicks
 * [Description]   : Get the number of remaining ticks in the current time interval.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the number of remaining ticks.
 ====================================================================================================================*/
uint32 SYSTICK_getRemainingTicks(void)
{
    /* The number of remaining ticks = the value of the Current Value Register. */
    return SYSTICK->VAL;
}

/*=====================================================================================================================
 * [Function Name] : SYSTICK_deinit
 * [Description]   : Stop and reset SysTick.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SYSTICK_deinit(void)
{
    CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_ENABLE_BIT);                     /* Disable SysTick counter.          */
    CLEAR_BIT(SYSTICK->CTRL,SYSTICK_CTRL_TICKINT_BIT);                    /* Disable SysTick interrupt.        */
    SYSTICK->LOAD = 0;                                                    /* Reset the Reload Value Register.  */
    SYSTICK->VAL = 0;                                                     /* Reset the Current Value Register. */
    G_systickCurrentMode = SYSTICK_NOT_RUNNING;                           /* Reset SysTick current mode.       */
}

/*=====================================================================================================================
 * [Function Name] : SysTick_Handler
 * [Description]   : The interrupt service routine for SysTick .
 * [Arguments]     : The function Takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SysTick_Handler(void)
{
    if(G_ptr2callBackFunction != NULL_PTR)
    {
        G_ptr2callBackFunction();                                              /* Call the call-back function. */
        if(G_systickCurrentMode == SYSTICK_SINGLE_INTERVAL_MODE)
        {
            SYSTICK_deinit();                  /* If SysTick current mode is Single Interval, Deinitialize it. */
        }
    }
}
