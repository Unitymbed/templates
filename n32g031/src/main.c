/*
 * UnityMbed starter — N32G031 (Cortex-M0, 64KB flash / 8KB RAM)
 * Blinks an LED on PB7.
 */
#include "n32g031.h"

static void delay(volatile uint32_t n) { while (n--) { __NOP(); } }

int main(void) {
    /* Enable GPIOB clock via APB2 (bit 3) */
    RCC->APB2PCLKEN |= (1u << 3);

    /* PB7 as output */
    GPIO_SET_OUTPUT(GPIOB, 7);

    while (1) {
        GPIOB->POD ^= (1u << 7);
        delay(800000);
    }
}
