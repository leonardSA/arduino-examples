#define LED_PIN         (9)
#define PUSHB_PIN       (2)     /* push button aka "switch" */
#define PUSHB_DELAY_MS  (300)

bool isOn = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);   /* led pin is output */
    pinMode(PUSHB_PIN, INPUT);  /* switch pin is input */
}

void loop() {
    bool input = digitalRead(PUSHB_PIN);
    if (input)
    {
        isOn = !isOn;
        digitalWrite(LED_PIN, (isOn ? HIGH : LOW));
        delay(PUSHB_DELAY_MS);  /* delay input read */
    }
}
