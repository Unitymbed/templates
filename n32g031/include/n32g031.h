/*
 * Minimal N32G031 peripheral header (subset for starter project).
 * Replace with full Nations SDK headers when 'unitymbed setup' fetches them.
 */
#ifndef N32G031_H
#define N32G031_H

#include <stdint.h>

#define __NOP()   __asm volatile ("nop")

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t CFG;
    volatile uint32_t CLKINT;
    volatile uint32_t APB2PRST;
    volatile uint32_t APB1PRST;
    volatile uint32_t AHBPCLKEN;
    volatile uint32_t APB2PCLKEN;
    volatile uint32_t APB1PCLKEN;
    volatile uint32_t BDCTRL;
    volatile uint32_t CTRLSTS;
} RCC_TypeDef;

typedef struct {
    volatile uint32_t PL_CFG;
    volatile uint32_t PH_CFG;
    volatile uint32_t PID;
    volatile uint32_t POD;
    volatile uint32_t PBSC;
    volatile uint32_t PBC;
    volatile uint32_t PLOCK_CFG;
} GPIO_TypeDef;

#define RCC    ((RCC_TypeDef *)  0x40021000UL)
#define GPIOA  ((GPIO_TypeDef *) 0x40010800UL)
#define GPIOB  ((GPIO_TypeDef *) 0x40010C00UL)

#endif
