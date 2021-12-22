/**
 * File              : blink.c
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 11.11.2021
 * Last Modified Date: 11.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */

#ifndef __AVR_ATmega328P__
#include <avr/iom328p.h>
#endif

#define F_CPU          (16000000)   // 16 MHz CPU frequency
#include <util/delay.h>             // for _delay_ms()
#include <avr/io.h>                 // for port names

#define BLINK_DELAY_MS (1000)

int main(void) {
    DDRB |= _BV(PORTB1); // output for led
    for (;;) 
    {
        // on
        PORTB |= _BV(PORTB1);
        _delay_ms(BLINK_DELAY_MS);

        // off
        PORTB &= ~_BV(PORTB1);
        _delay_ms(BLINK_DELAY_MS);
    }
}
