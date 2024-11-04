#define LED_PIN 8
#define BUTTON_PIN 2


volatile unsigned long lastTimeButtonReleased = millis();
unsigned long debounceDelay = 50;
int LEDState = LOW;
volatile bool buttonReleased = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                  buttonReleasedInterrupt,
                  FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonReleased) {
    buttonReleased = false;
    toggleLED();
  }
}

void buttonReleasedInterrupt() {
  unsigned long currButtonPressed = millis();
  if (currButtonPressed - lastTimeButtonReleased > debounceDelay) {
    buttonReleased = true;
    lastTimeButtonReleased = currButtonPressed;
  }
}

void toggleLED() {
  if (LEDState == LOW) {
    LEDState = HIGH;
  } else {
    LEDState = LOW;
  }
  digitalWrite(LED_PIN, LEDState);
}
