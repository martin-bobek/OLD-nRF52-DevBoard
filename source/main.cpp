#include <nrf.h>
#include "init.h"

extern "C" void RTC0_IRQHandler() __attribute((interrupt));

static volatile uint8_t Tick = 0;

int main() {
    Init();
    __enable_irq();

    NRF_P0->OUTCLR = LED_ALL;

    for (uint8_t i = 0; i < 4; i++, Tick = 0)
        while (!Tick);

    NRF_P0->OUTSET = LED_ALL;

    for (uint8_t i = 0; i < 4; i++, Tick = 0)
        while (!Tick);

    // RE-ENABLE LEDS TO INDICATE TEST OUTCOME
}

void RTC0_IRQHandler() {
    NRF_RTC0->EVENTS_TICK = 0;
    Tick = 1;
}
