/*
=======================================================================================================================
Author       : Mamoun
File Name    : main.c
Date Created : Nov 15, 2023
Description  : Source file to test all STM32F401 device drivers.
=======================================================================================================================
*/


/*=====================================================================================================================
                                               < Includes >
=====================================================================================================================*/

#include "../OTHERS/std_types.h"
#include "../OTHERS/common_macros.h"
#include "../MCAL/RCC/INCLUDES/rcc.h"
#include "../MCAL/GPIO/INCLUDES/gpio.h"
#include "../MCAL/UART/INCLUDES/uart.h"

/*=====================================================================================================================
                                           < Global Variables >
=====================================================================================================================*/



/*=====================================================================================================================
                                          < Functions Definitions >
=====================================================================================================================*/

/*=====================================================================================================================
 * [Function Name] : main
 * [Description]   : The main function
 * [Arguments]     : The function takes no arguments.
 * [return]        : The function returns 0.
 ====================================================================================================================*/
int main(void)
{
    GPIO_pinConfigurationsType LOC_TxPin = {GPIO_PORTA_ID,GPIO_PIN02_ID,GPIO_ALTERNATE_PUSH_PULL_MODE,GPIO_LOW_SPEED};
    GPIO_pinConfigurationsType LOC_RxPin = {GPIO_PORTA_ID,GPIO_PIN03_ID,GPIO_ALTERNATE_PUSH_PULL_MODE,GPIO_LOW_SPEED};
    UART_configurationsType LOC_configUART = {9600,UART_FULL_DUPLEX_MODE,UART_PARITY_DISABLED};
    uint8 LOC_receivedByte = '\0';

    RCC_enablePeripheralClock(RCC_APB1_BUS,RCC_APB1_USART2_PERIPHERAL);
    RCC_enablePeripheralClock(RCC_AHB1_BUS,RCC_AHB1_GPIOA_PERIPHERAL);

    GPIO_configurePin(&LOC_TxPin);
    GPIO_configurePin(&LOC_RxPin);

    GPIO_setPinFunction(GPIO_PORTA_ID,GPIO_PIN02_ID,GPIO_ALTERNATE_FUNCTION_07);
    GPIO_setPinFunction(GPIO_PORTA_ID,GPIO_PIN03_ID,GPIO_ALTERNATE_FUNCTION_07);

    UART_init(UART2_ID,&LOC_configUART);

    while(1)
    {
        UART_sendString(UART2_ID,"Mamoun was here!");
        for(uint32 counter = 0; counter < 2000000; counter++);
    }
}

