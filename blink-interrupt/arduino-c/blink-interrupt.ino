/**
 * File              : blink-interrupt.ino
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 11.11.2021
 * Last Modified Date: 11.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */

#include <TimerOne.h>       /* TIMER1 librairy */

#define LED_PIN (9)
#define DELAY   (1000000)   /* 1 second */

/**
* @brief Toggle led on LED_PIN.
*/
void blink_isr() {
    static bool toggle = LOW;
    toggle = !toggle;
    digitalWrite(LED_PIN, toggle);
}


void setup() {
    pinMode(LED_PIN, OUTPUT);
    Timer1.initialize(DELAY);           /* init timer1 with delay */
    Timer1.attachInterrupt(blink_isr);  /* add blink_isr to timer1 int vector */
}


void loop() {
//  _____________________
// < Nothing to see here >
//  ---------------------
//         \   ^__^
//          \  (oo)\_______
//             (__)\       )\/\
//                 ||----w |
//                 ||     ||
}
