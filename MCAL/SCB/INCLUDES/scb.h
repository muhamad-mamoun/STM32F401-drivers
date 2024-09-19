/*
=======================================================================================================================
Author       : Mamoun
Module       : SCB
File Name    : scb.h
Date Created : Dec 4, 2023
Description  : Interface file for the STM32 Cortex-M4 SCB peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_SCB_INCLUDES_SCB_H_
#define MCAL_SCB_INCLUDES_SCB_H_

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef enum
{
    SCB_NO_ERRORS,                   /* All Good.                                              */
    SCB_EXC_NUM_ERROR,               /* Invalid Exception Number Error.                        */
    SCB_NULL_PTR_ERROR,              /* Null Pointer Error.                                    */
    SCB_PRIORITY_LEVEL_ERROR,        /* Wrong Priority Level Error.                            */
}SCB_errorStatusType;

typedef enum
{
    SCB_PRIORITY_LEVEL_A = 0X00,     /* 4-bit for Group [7:4],  and 0-bit for Subgroup [None]. */
    SCB_PRIORITY_LEVEL_B = 0X04,     /* 3-bit for group [7:5],  and 1-bit for Subgroup [4].    */
    SCB_PRIORITY_LEVEL_C = 0X05,     /* 2-bit for group [7:6],  and 2-bit for Subgroup [5:4].  */
    SCB_PRIORITY_LEVEL_D = 0X06,     /* 1-bit for group [7],    and 3-bit for Subgroup [6:4].  */
    SCB_PRIORITY_LEVEL_E = 0X07,     /* 0-bit for group [None], and 4-bit for Subgroup [7:4].  */
}SCB_priorityLevelType;

typedef enum
{
    SCB_PENDSV_EXCEPTION,            /* PendSV Exception.                                      */
    SCB_SYSTICK_EXCEPTION,           /* SysTick Exception.                                     */
}SCB_exceptionType;

/*=====================================================================================================================
                                         < Functions Prototypes >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : SCB_setPriorityLevel
 * [Description]   : Set the priority group level [The bit point for the priority group and subgroup].
 * [Arguments]     : <a_priorityLevel>     -> Indicates to the required priority group level to be select.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Priority Level Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setPriorityLevel(SCB_priorityLevelType a_priorityLevel);

/*=====================================================================================================================
 * [Function Name] : SCB_getPriorityLevel
 * [Description]   : Get the priority group level [The bit point for the priority group and subgroup].
 * [Arguments]     : <a_ptr2priorityLevel>     -> Pointer to variable to store the priority level.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_getPriorityLevel(SCB_priorityLevelType* a_ptr2priorityLevel);

/*=====================================================================================================================
 * [Function Name] : SCB_setExceptionPending
 * [Description]   : Set the pending status for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>      -> Indicates to the required Exception.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setExceptionPending(SCB_exceptionType a_exceptionNumber);

/*=====================================================================================================================
 * [Function Name] : SCB_clearExceptionPending
 * [Description]   : Clear the pending status for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>      -> Indicates to the required Exception.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_clearExceptionPending(SCB_exceptionType a_exceptionNumber);

/*=====================================================================================================================
 * [Function Name] : SCB_setExceptionPriority
 * [Description]   : Set the priority value for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>  -> Indicates to the required Exception.
 *                   <a_priority>         -> Indicates to the required priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setExceptionPriority(SCB_exceptionType a_exceptionNumber, uint8 a_priority);

/*=====================================================================================================================
 * [Function Name] : SCB_getExceptionPriority
 * [Description]   : Get the priority value for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>  -> Indicates to the required Exception.
 *                   <a_ptr2priority>     -> Pointer to a variable to store the exception priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_getExceptionPriority(SCB_exceptionType a_exceptionNumber, uint8* a_ptr2priority);

#endif /* MCAL_SCB_INCLUDES_SCB_H_ */
