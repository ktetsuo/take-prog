// 課題3:
// 1.と同じ回路で、スイッチをクリックするたびにLEDの点灯と消灯が
// 入れ替わるプログラムを作成してください。（初期状態は消灯）

static const uint8_t SWPin = 12;
static const uint8_t LEDPin = 13;

static uint8_t lastSW = LOW;
static uint8_t currentLED = LOW;

static uint8_t ChatteringFilter(uint8_t val) {
  static const unsigned long chatteringMs = 50; // チャタリング防止する時間
  static unsigned long lastChangeTime = 0;  // 最後に変化した時刻
  static uint8_t filteredVal = LOW;
  static uint8_t lastVal = LOW;
  unsigned long ms = millis();
  if(lastVal != val) {
    // 前の状態から変化したら現在時刻でリセット
    lastChangeTime = ms;
  }
  if(chatteringMs <= ms - lastChangeTime) {
    // 最後に変化してから一定時間経過していたら切替え
    filteredVal = val;
  }
  lastVal = val;
  return filteredVal;
}

void setup() {
  pinMode(SWPin, INPUT_PULLUP);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  uint8_t currentSW = ChatteringFilter(digitalRead(SWPin));
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

