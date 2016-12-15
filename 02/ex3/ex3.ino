// 課題3:
// 1.と同じ回路で、スイッチをクリックするたびにLEDの点灯と消灯が
// 入れ替わるプログラムを作成してください。（初期状態は消灯）

static const uint8_t SWPin = 12;
static const uint8_t LEDPin = 13;

static uint8_t lastSW = LOW;
static uint8_t currentLED = LOW;

void setup() {
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  uint8_t currentSW = digitalRead(SWPin);
  if(lastSW == HIGH && currentSW == LOW) {
    // OFF→ONになったときに切り替える
    if(currentLED == LOW) {
      currentLED = HIGH;
    } else {
      currentLED = LOW;
    }
    digitalWrite(LEDPin, currentLED);
  }
  lastSW = currentSW;
  delay(1);
}

