/*
 * Minimal N32G031 peripheral header (subset for starter project).
 * Matches actual N32G031 register layout (STM32F0/G0-style, NOT STM32F1-style).
 */
#ifndef N32G031_H
#define N32G031_H

#include <stdint.h>

#define __NOP()   __asm volatile ("nop")

/* RCC */
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

/* GPIO — modern layout (STM32F0/G0-style) */
typedef struct {
    volatile uint32_t PMODE;   /* 0x00  pin mode:   2 bits per pin, 00=in, 01=out, 10=AF, 11=analog */
    volatile uint32_t POTYPE;  /* 0x04  output type:1 bit per pin,  0=push-pull, 1=open-drain */
    volatile uint32_t SR;      /* 0x08  speed:      2 bits per pin */
    volatile uint32_t PUPD;    /* 0x0C  pull-up/down: 2 bits per pin, 00=none, 01=up, 10=down */
    volatile uint32_t PID;     /* 0x10  input data (read) */
    volatile uint32_t POD;     /* 0x14  output data */
    volatile uint32_t PBSC;    /* 0x18  bit set/clear: hi16=clear, lo16=set */
    volatile uint32_t PLOCK;   /* 0x1C */
    volatile uint32_t AFL;     /* 0x20  alt function low  (pins 0..7)  */
    volatile uint32_t AFH;     /* 0x24  alt function high (pins 8..15) */
    volatile uint32_t PBC;     /* 0x28 */
    volatile uint32_t DS;      /* 0x2C  drive strength */
} GPIO_TypeDef;

#define RCC    ((RCC_TypeDef *)  0x40021000UL)
#define GPIOA  ((GPIO_TypeDef *) 0x40010800UL)
#define GPIOB  ((GPIO_TypeDef *) 0x40010C00UL)
#define GPIOC  ((GPIO_TypeDef *) 0x40011000UL)
#define GPIOF  ((GPIO_TypeDef *) 0x40011400UL)

/* GPIO helper: set pin N to output mode (PMODE bits [N*2+1 : N*2] = 01) */
#define GPIO_SET_OUTPUT(port, pin)  do { \
    (port)->PMODE &= ~(0x3u << ((pin) * 2)); \
    (port)->PMODE |=  (0x1u << ((pin) * 2)); \
} while (0)

#endif
