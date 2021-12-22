#ifndef __AVR_ATmega328P__
#include <avr/iom328p.h>
#endif

#include <avr/io.h>
#include <stdbool.h>
#define F_CPU (16000000)
#include <util/delay.h>

#define TOGGLE_LED_DELAY  (300)

/* bool isOn = false; */

/* void setup(void) { */
/*     DDRB |= _BV(PORTB1); // output for led is B1 */
/*     PORTD |= _BV(PIND2); // input for switch is D2 */
/* } */

int main(void) {
    DDRB |= _BV(PORTB1); // output for led is B1
    PORTD |= _BV(PIND2); // input for switch is D2
    for (;;)
    {
        bool input = PIND & (1 << PIND2); /* switch input on PIN2 PORTD2 */
        if (input)
        {
            PORTB ^= _BV(PORTB1);         /* toggle led */
            _delay_ms(TOGGLE_LED_DELAY);  /* wait after toggling led 
                                             -- space out input */
        }
    }
}
