/*
=======================================================================================================================
Author       : Mamoun
Module       : SCB
File Name    : scb.c
Date Created : Dec 4, 2023
Description  : Source file for the STM32 Cortex-M4 SCB peripheral driver.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../../../OTHERS/std_types.h"
#include "../../../OTHERS/common_macros.h"
#include "../INCLUDES/scb_prv.h"
#include "../INCLUDES/scb_cfg.h"
#include "../INCLUDES/scb.h"

/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : SCB_setPriorityLevel
 * [Description]   : Set the priority group level [The bit point for the priority group and subgroup].
 * [Arguments]     : <a_priorityLevel>     -> Indicates to the required priority group level to be select.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Priority Level Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setPriorityLevel(SCB_priorityLevelType a_priorityLevel)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if(((a_priorityLevel < SCB_PRIORITY_LEVEL_B) && (a_priorityLevel != SCB_PRIORITY_LEVEL_A)) || (a_priorityLevel > SCB_PRIORITY_LEVEL_E))
    {
        LOC_errorStatus = SCB_PRIORITY_LEVEL_ERROR;
    }

    else
    {
        /* Set the required priority group level and write the VECTKEY other wise the write will be ignored */
        SCB->AIRCR = ((SCB->AIRCR & 0XF8FFUL) | (SCB_AIRCR_WRITE_VECTKEY << SCB_AIRCR_VECTKEY_FIELD) | (a_priorityLevel << SCB_AIRCR_PRIGROUP_FIELD));
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_getPriorityLevel
 * [Description]   : Get the priority group level [The bit point for the priority group and subgroup].
 * [Arguments]     : <a_ptr2priorityLevel>     -> Pointer to variable to store the priority level.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_getPriorityLevel(SCB_priorityLevelType* a_ptr2priorityLevel)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if(a_ptr2priorityLevel == NULL_PTR)
    {
        LOC_errorStatus = SCB_NULL_PTR_ERROR;
    }

    else
    {
        /* Get the current priority group level. */
        *a_ptr2priorityLevel = ((SCB->AIRCR >> SCB_AIRCR_PRIGROUP_FIELD) & 0X07UL);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_setExceptionPending
 * [Description]   : Set the pending status for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>      -> Indicates to the required Exception.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setExceptionPending(SCB_exceptionType a_exceptionNumber)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if((a_exceptionNumber != SCB_PENDSV_EXCEPTION) && (a_exceptionNumber != SCB_SYSTICK_EXCEPTION))
    {
        LOC_errorStatus = SCB_EXC_NUM_ERROR;
    }

    else
    {
        /* Set the pending status for the required exception. */
        if(a_exceptionNumber == SCB_PENDSV_EXCEPTION) SET_BIT(SCB->ICSR, SCB_ICSR_PENDSVSET_BIT);
        else if(a_exceptionNumber == SCB_SYSTICK_EXCEPTION) SET_BIT(SCB->ICSR, SCB_ICSR_PENDSTSET_BIT);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_clearExceptionPending
 * [Description]   : Clear the pending status for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>      -> Indicates to the required Exception.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_clearExceptionPending(SCB_exceptionType a_exceptionNumber)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if((a_exceptionNumber != SCB_PENDSV_EXCEPTION) && (a_exceptionNumber != SCB_SYSTICK_EXCEPTION))
    {
        LOC_errorStatus = SCB_EXC_NUM_ERROR;
    }

    else
    {
        /* Clear the pending status for the required exception. */
        if(a_exceptionNumber == SCB_PENDSV_EXCEPTION) SET_BIT(SCB->ICSR, SCB_ICSR_PENDSVCLR_BIT);
        else if(a_exceptionNumber == SCB_SYSTICK_EXCEPTION) SET_BIT(SCB->ICSR, SCB_ICSR_PENDSTCLR_BIT);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_setExceptionPriority
 * [Description]   : Set the priority value for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>  -> Indicates to the required Exception.
 *                   <a_priority>         -> Indicates to the required priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_setExceptionPriority(SCB_exceptionType a_exceptionNumber, uint8 a_priority)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if((a_exceptionNumber != SCB_PENDSV_EXCEPTION) && (a_exceptionNumber != SCB_SYSTICK_EXCEPTION))
    {
        LOC_errorStatus = SCB_EXC_NUM_ERROR;
    }

    else
    {
        /* Set the priority value for the required exception. */
        if(a_exceptionNumber == SCB_PENDSV_EXCEPTION) SCB->SHPR3 |= (a_priority << SCB_SHPR3_PENDSV_FIELD);
        else if(a_exceptionNumber == SCB_SYSTICK_EXCEPTION) SCB->SHPR3 |= (a_priority << SCB_SHPR3_SYSTICK_FIELD);
    }

    return LOC_errorStatus;
}

/*=====================================================================================================================
 * [Function Name] : SCB_getExceptionPriority
 * [Description]   : Get the priority value for a specific Exception.
 * [Arguments]     : <a_exceptionNumber>  -> Indicates to the required Exception.
 *                   <a_ptr2priority>     -> Pointer to a variable to store the exception priority.
 * [return]        : The function returns the error status: - No Errors.
 *                                                          - Null Pointer Error.
 *                                                          - Exception Number Error.
 ====================================================================================================================*/
SCB_errorStatusType SCB_getExceptionPriority(SCB_exceptionType a_exceptionNumber, uint8* a_ptr2priority)
{
    SCB_errorStatusType LOC_errorStatus = SCB_NO_ERRORS;

    if(a_ptr2priority == NULL_PTR)
    {
        LOC_errorStatus = SCB_NULL_PTR_ERROR;
    }

    else if((a_exceptionNumber != SCB_PENDSV_EXCEPTION) && (a_exceptionNumber != SCB_SYSTICK_EXCEPTION))
    {
        LOC_errorStatus = SCB_EXC_NUM_ERROR;
    }

    else
    {
        /* Get the priority value for the required exception. */
        if(a_exceptionNumber == SCB_PENDSV_EXCEPTION) *a_ptr2priority = ((SCB->SHPR3 >> SCB_SHPR3_PENDSV_FIELD) & 0X000000FF);
        else if(a_exceptionNumber == SCB_SYSTICK_EXCEPTION) *a_ptr2priority = ((SCB->SHPR3 >> SCB_SHPR3_SYSTICK_FIELD) & 0X000000FF);
    }

    return LOC_errorStatus;
}