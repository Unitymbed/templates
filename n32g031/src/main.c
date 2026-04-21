/*
 * UnityMbed starter — N32G031 (Cortex-M0, 64KB flash / 8KB RAM)
 * Blinks an LED on PA8.
 */
#include "n32g031.h"

static void delay(volatile uint32_t n) { while (n--) { __NOP(); } }

int main(void) {
    /* Enable GPIOA clock */
    RCC->AHBPCLKEN |= (1u << 17);

    /* PA8 as output */
    GPIOA->PL_CFG &= ~(0xFu << ((8 - 0) * 4));
    GPIOA->PH_CFG |=  (0x1u << ((8 - 8) * 4));   /* MODE = output, 10MHz */

    while (1) {
        GPIOA->POD ^=  (1u << 8);
        delay(500000);
    }
}
