#ifndef N32G45X_H
#define N32G45X_H

#include <stdint.h>

#define __NOP() __asm volatile ("nop")

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t CFG;
    volatile uint32_t CLKINT;
    volatile uint32_t APB2PRST;
    volatile uint32_t APB1PRST;
    volatile uint32_t AHB1PCLKEN;
    volatile uint32_t APB2PCLKEN;
    volatile uint32_t APB1PCLKEN;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t PMODE;
    volatile uint32_t POTYPE;
    volatile uint32_t POSPEED;
    volatile uint32_t PUPD;
    volatile uint32_t PID;
    volatile uint32_t POD;
    volatile uint32_t PBSC;
    volatile uint32_t PLOCK_CFG;
    volatile uint32_t AFL;
    volatile uint32_t AFH;
} GPIO_TypeDef;

#define RCC    ((RCC_TypeDef *)  0x40023800UL)
#define GPIOA  ((GPIO_TypeDef *) 0x40020000UL)
#define GPIOB  ((GPIO_TypeDef *) 0x40020400UL)

#endif
