/*
 * UnityMbed starter — N32G031 (Cortex-M0, 64KB flash / 8KB RAM)
 * Blinks an LED on PA8.
 */
#include "n32g031.h"

static void delay(volatile uint32_t n) { while (n--) { __NOP(); } }

int main(void) {
    /* Enable GPIOA clock (AHBPCLKEN bit 17) */
    RCC->AHBPCLKEN |= (1u << 17);

    /* Set PA8 as output */
    GPIO_SET_OUTPUT(GPIOA, 8);

    while (1) {
        GPIOA->POD ^= (1u << 8);
        delay(500000);
    }
}
