/**
 * File              : blink-interrupt.c
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 11.11.2021
 * Last Modified Date: 11.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */

#ifndef __AVR_ATmega328P__
#include <avr/iom328p.h>
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define F_CPU           (16000000)  // 16 MHz
#define PRESCALER       (10)        // 1024
#define COUNTER_VALUE   (F_CPU >> PRESCALER)    // number of ticks in a second


// Executed on counter compare value matches OCR1A
ISR(TIMER1_COMPA_vect) {
    PORTB ^= _BV(PORTB1);
}


int main(void) {
    DDRB |= _BV(PORTB1);        // output is digital pin 9
    OCR1A = COUNTER_VALUE;      // output compare register for timer 1

    TCCR1A = 0x00;
    TCCR1B |= (1 << WGM12);                 // CTC Mode -- compare to OCR1A
    TCCR1B |= (1 << CS10) | (1 << CS12);    // set prescaler to 1024

    TIMSK1 |= (1 << OCIE1A);    // timer interrupt mask reg  
    
    sei();  // enable interrupts globally

    for (;;);
    //  ________________________________________
    // / Do you also find yourself staring back \
    // \ into the void sometimes ?              /
    //  ----------------------------------------
    //         \   ^__^
    //          \  (oo)\_______
    //             (__)\       )\/\
    //                 ||----w |
    //                 ||     ||
}
