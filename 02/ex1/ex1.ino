// 課題1:
// タクトスイッチ1個とLED1個を使い、
// スイッチを押している間だけLEDが点灯するプログラムを作成してください。

static const uint8_t SWPin = 12;
static const uint8_t LEDPin = 13;

void setup() {
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  if (digitalRead(SWPin) == LOW) {
    digitalWrite(LEDPin, HIGH);
  } else {
    digitalWrite(LEDPin, LOW);
  }
  delay(1);
}

