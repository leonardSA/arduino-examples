/**
 * File              : blink.ino
 * Author            : leonardSA <leonard.stephenauguste@gmail.com>
 * Date              : 11.11.2021
 * Last Modified Date: 11.11.2021
 * Last Modified By  : leonardSA <leonard.stephenauguste@gmail.com>
 */

#define LED_PIN (9)

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    delay(1000); // 1 second delay
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
}
