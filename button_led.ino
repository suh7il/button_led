#define BUTTON_PIN 4
#define LED_PIN 2

bool ledState = LOW;
bool lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, ledState);
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect a change in button state
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Check whether the state has remained stable
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // Detect a new button press
    if (buttonState == LOW && lastButtonState == HIGH) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  lastButtonState = buttonState;
}