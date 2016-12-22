// 課題2:
// 1.と同じ回路で、スイッチを押している間だけLEDが0.5秒周期(0.25秒点灯、0.25秒消灯)
// で点滅するプログラムを作成してください。

static const uint8_t SWPin = 12;
static const uint8_t LEDPin = 13;

static uint8_t currentLED = LOW;
static unsigned long togglems = 0;

void setup() {
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  if (digitalRead(SWPin) == LOW) {
    unsigned long ms = millis();
    if(250 < ms - togglems) {
      if(currentLED == LOW) {
        currentLED = HIGH;
      } else {
        currentLED = LOW;
      }
      togglems = ms;
      digitalWrite(LEDPin, currentLED);
    }
  } else {
    digitalWrite(LEDPin, LOW);
  }
  delay(1);
}
