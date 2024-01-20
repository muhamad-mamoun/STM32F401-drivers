/*
=======================================================================================================================
Author       : Mamoun
Module       : GPIO
File Name    : gpio_prv.h
Date Created : Dec 8, 2023
Description  : Private file for the STM32F401xx GPIO peripheral driver.
=======================================================================================================================
*/


#ifndef MCAL_GPIO_INCLUDES_GPIO_PRV_H_
#define MCAL_GPIO_INCLUDES_GPIO_PRV_H_

/*=====================================================================================================================
                                < Definitions and Static Configurations >
=====================================================================================================================*/

#define GPIO_NUM_OF_PORTS                            (6U)      /* The number of ports in the chip. */
#define GPIO_NUM_OF_PINS_PER_PORT                    (16U)     /* The number of pins in each port. */
#define GPIO_HALF_PORT_THRESHOLD                     (8U)      /* The number of the threshold bit. */

/*=====================================================================================================================
                                       < User-defined Data Types >
=====================================================================================================================*/

typedef struct
{
    volatile uint32 MODER;       /* GPIO port mode register.               */
    volatile uint32 OTYPER;      /* GPIO port output type register.        */
    volatile uint32 OSPEEDR;     /* GPIO port output speed register.       */
    volatile uint32 PUPDR;       /* GPIO port pull-up/pull-down register.  */
    volatile uint32 IDR;         /* GPIO port input data register.         */
    volatile uint32 ODR;         /* GPIO port output data register.        */
    volatile uint32 BSRR;        /* GPIO port bit set/reset register.      */
    volatile uint32 LCKR;        /* GPIO port configuration lock register. */
    volatile uint32 AFRL;        /* GPIO alternate function low register.  */
    volatile uint32 AFRH;        /* GPIO alternate function high register. */
}GPIOx_registersType;

/*=====================================================================================================================
                                < Peripheral Registers and Bits Definitions >
=====================================================================================================================*/

/* All GPIO peripherals base addresss. */
#define GPIOA                    ((volatile GPIOx_registersType*)0X40020000)
#define GPIOB                    ((volatile GPIOx_registersType*)0X40020400)
#define GPIOC                    ((volatile GPIOx_registersType*)0X40020800)
#define GPIOD                    ((volatile GPIOx_registersType*)0X40020C00)
#define GPIOE                    ((volatile GPIOx_registersType*)0X40021000)
#define GPIOH                    ((volatile GPIOx_registersType*)0X40021C00)

/*=====================================================================================================================
                                         < Function-like Macros >
=====================================================================================================================*/

/* Two macros used to write on multiple bits for corresponding pin in the GPIO registers. */
#define GPIO_WRITE_TWO_BITS(REG,PIN,VALUE)  (REG = (REG & (~(0X03 << (PIN * 2)))) | ((VALUE & 0X03) << (PIN * 2)))
#define GPIO_WRITE_FOUR_BITS(REG,PIN,VALUE) (REG = (REG & (~(0X0F << (PIN * 4)))) | ((VALUE & 0X0F) << (PIN * 4)))

#endif /* MCAL_GPIO_INCLUDES_GPIO_PRV_H_ */
