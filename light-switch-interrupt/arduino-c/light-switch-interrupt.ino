/**
 * File              : light-switch-interrupt.ino
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 12.11.2021
 * Last Modified Date: 12.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */


#define LED_PIN         (9)
#define PUSHB_PIN       (2)     /* push button aka "switch" */
#define PUSHB_DELAY_MS  (300)


/**
* @brief Toggle led on LED_PIN.
*/
void light_switch_isr(void) {
    static bool toggle = false;
    toggle = !toggle;
    digitalWrite(LED_PIN, (toggle ? HIGH : LOW));
}

void setup(void) {
    pinMode(LED_PIN, OUTPUT);   /* led pin is output */
    pinMode(PUSHB_PIN, INPUT);  /* switch pin is input */
    /* attachInterrupt@arg1:
     * digitalPinToInterrupt func should be used (err on compilation - 
     * "never declared" ?) : digitalPinToInterrupt(PUSHB_PIN) == 0 */
    attachInterrupt(0, light_switch_isr, RISING);
} 


void loop() {
}
