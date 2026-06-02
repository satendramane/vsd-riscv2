#include <stdio.h>
#include <stdint.h>

#define GPIO_BASE   0x400020

#define GPIO_DATA  (*((volatile uint32_t *)(GPIO_BASE + 0x00)))
#define GPIO_DIR   (*((volatile uint32_t *)(GPIO_BASE + 0x04)))

void delay() {
    volatile int i;
    for(i = 0; i < 500000; i++);
}

int main() {
    printf("=== BLINK TEST ===\n");

    GPIO_DIR  = 0xFF;
    GPIO_DATA = 0x00;

    int count = 0;
    while(count < 20) {
        GPIO_DATA = 0x01;  // RED ON
        delay();
        GPIO_DATA = 0x00;  // RED OFF
        delay();
        printf("Blink #%d\n", count+1);
        count++;
    }

    printf("=== DONE ===\n");
    return 0;
}
