#include <stdint.h>
#include "ch552.h"

#define LED_PIN 0  // P3.0 (Pino 30 da WeAct CH552)

void delay_ms(uint16_t ms) {
    uint16_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++);  // Ajuste de tempo
    }
}

void main() {
    // Configurar P3.0 como saída push-pull
    P3_MOD_OC &= ~(1 << LED_PIN);  // Push-pull
    P3_DIR_PU |= (1 << LED_PIN);   // Define como saída

    while (1) {
        P3 ^= (1 << LED_PIN);  // Alterna o estado do LED
        delay_ms(500);         // Aguarda 500ms
    }
}

