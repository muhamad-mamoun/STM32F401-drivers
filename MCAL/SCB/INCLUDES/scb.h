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

#endif /* MCAL_SCB_INCLUDES_SCB_H_ */
