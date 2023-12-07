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
