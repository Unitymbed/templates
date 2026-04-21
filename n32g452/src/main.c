/*
 * UnityMbed starter — N32G452 (Cortex-M4F, 256KB flash / 48KB RAM)
 * Blinks an LED on PA8.
 */
#include "n32g45x.h"

static void delay(volatile uint32_t n) { while (n--) { __NOP(); } }

int main(void) {
    RCC->AHB1PCLKEN |= (1u << 0);           /* GPIOA clock */
    GPIOA->PMODE  &= ~(0x3u << (8 * 2));
    GPIOA->PMODE  |=  (0x1u << (8 * 2));    /* PA8 output */

    while (1) {
        GPIOA->POD ^= (1u << 8);
        delay(1000000);
    }
}
