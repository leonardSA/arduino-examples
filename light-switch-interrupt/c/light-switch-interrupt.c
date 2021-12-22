/**
 * File              : light-switch-interrupt.c
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 12.11.2021
 * Last Modified Date: 25.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */

#ifndef __AVR_ATmega328P__
#include <avr/iom328p.h>
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>


/**
 * @brief ISR triggered by INT0 on rising edge to toggle led.
 *
 * @param INT0_vect External Interrupt 0 vector
 */
ISR(INT0_vect) {
    PORTB ^= _BV(PORTB1); // toggle led
}


int main(void) {
    DDRB |= _BV(PORTB1); // output for led is B1
    PORTD |= _BV(PIND2); // input for switch is D2

    EIMSK |= _BV(INT0);                 // enable ext interrupt 0
    EICRA |= _BV(ISC00) | _BV(ISC01);   // trigger on rising edge

    sei();

    for (;;)
    {
    }
}
