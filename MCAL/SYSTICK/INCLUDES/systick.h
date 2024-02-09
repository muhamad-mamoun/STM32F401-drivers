/*
=======================================================================================================================
Author       : Mamoun
Module       : SysTick
File Name    : systick.h
Date Created : Feb 9, 2024
Description  : Interface file for the ARM Cortex-M4 SysTick peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_SYSTICK_INCLUDES_SYSTICK_H_
#define MCAL_SYSTICK_INCLUDES_SYSTICK_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    SYSTICK_NO_ERRORS,          /* All Good.                                     */
    SYSTICK_BUSY_ERROR,         /* SysTick is busy.                              */
    SYSTICK_NULL_PTR_ERROR,     /* Null Pointer Error.                           */
    SYSTICK_OVERFLOW_ERROR,     /* The time interval exceedes the SysTick limit. */
}SYSTICK_errorStatusType;

typedef enum
{
    SYSTICK_CPU_CLOCK_PS8,      /* SysTick clock source is CPU clock divided by 8. */
    SYSTICK_CPU_CLOCK,          /* SysTick clock source is CPU clock.              */
}SYSTICK_clockSourceType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : SYSTICK_init
 * [Description]   : Initialize SysTick by setting its clock source.
 * [Arguments]     : <a_clockSource>      -> Indicates to the required clock source for SysTick.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SYSTICK_init(SYSTICK_clockSourceType a_clockSource);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setBusyWait
 * [Description]   : Set a blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setBusyWait(uint16 a_timeInterval);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setSingleInterval
 * [Description]   : Set a single non-blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setSingleInterval(uint16 a_timeInterval);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setPeriodicInterval
 * [Description]   : Set a periodic non-blocking delay with a specific time interval.
 * [Arguments]     : <a_timeInterval>      -> Indicates to the required time interval value [in milliseconds].
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Busy Error.
 *                                                          - Overflow Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setPeriodicInterval(uint16 a_timeInterval);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_setCallBackFunction
 * [Description]   : Set the address of the call-back function.
 * [Arguments]     : <a_ptr2callBackFunction>      -> Pointer to the call-back function.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SYSTICK_errorStatusType SYSTICK_setCallBackFunction(void (*a_ptr2callBackFunction)(void));

/*=====================================================================================================================
 * [Function Name] : SYSTICK_getElapsedTicks
 * [Description]   : Get the number of elapsed ticks in the current time interval.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the number of elapsed ticks.
 ====================================================================================================================*/
uint32 SYSTICK_getElapsedTicks(void);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_getRemainingTicks
 * [Description]   : Get the number of remaining ticks in the current time interval.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns the number of remaining ticks.
 ====================================================================================================================*/
uint32 SYSTICK_getRemainingTicks(void);

/*=====================================================================================================================
 * [Function Name] : SYSTICK_deinit
 * [Description]   : Stop and reset SysTick.
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns void.
 ====================================================================================================================*/
void SYSTICK_deinit(void);

#endif /* MCAL_SYSTICK_INCLUDES_SYSTICK_H_ */
