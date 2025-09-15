// USART1(RX:PB7, TX:PB6)
HardwareSerial MySerial1(PB7, PB6);

// 各PINのHIGH、LOW状態保持用構造体
typedef struct InputPinsTag {
  int pa0;    // PA0
  int pa1;    // PA1
  int pa2;    // PA2
  int pa3;    // PA3
  int pa4;    // PA4
  int pa5;    // PA5
  int pa6;    // PA6
  int pa7;    // PA7
  int pa11;   // PA11
  int pa12;   // PA12
  int pb0;    // PB0
  int pc14;   // PC14
  int pc15;   // PC15
} InputPins;

// 各ピンの状態(初期値:HIGH プルアップ)
InputPins inputPins = { 
    HIGH, HIGH, HIGH, HIGH, HIGH,
    HIGH, HIGH, HIGH, HIGH, HIGH, 
    HIGH, HIGH, HIGH 
  };

void setup() {

  // USART1初期化
  MySerial1.begin(9600);

  // 各ピンを入力ピンに設定する(プルアップ)
  pinMode(PA0, INPUT_PULLUP);
  pinMode(PA1, INPUT_PULLUP);
  pinMode(PA2, INPUT_PULLUP);
  pinMode(PA3, INPUT_PULLUP);
  pinMode(PA4, INPUT_PULLUP);
  pinMode(PA5, INPUT_PULLUP);
  pinMode(PA6, INPUT_PULLUP);
  pinMode(PA7, INPUT_PULLUP);
  pinMode(PA11, INPUT_PULLUP);
  pinMode(PA12, INPUT_PULLUP);
  pinMode(PB0, INPUT_PULLUP);
  pinMode(PC14, INPUT_PULLUP);
  pinMode(PC15, INPUT_PULLUP);

  // USART1出力確認
  MySerial1.println("STM32 setup OK!!");
}

void loop() {

  // USART1入力確認
  while (MySerial1.available() > 0) {
    int data = MySerial1.read();
    MySerial1.write(data);
    MySerial1.flush();
  }

  // PA0の状態取得
  int state = digitalRead(PA0);
  // PA0の状態が変化した場合
  if (state != inputPins.pa0) {
    // 状態をUSART1に出力
    MySerial1.printf("PA0 State:%d\n", state);
    // PA0の状態を更新
    inputPins.pa0 = state;
  }

  // PA1の状態取得
  state = digitalRead(PA1);
  // PA1の状態が変化した場合
  if (state != inputPins.pa1) {
    // 状態をUSART1に出力
    MySerial1.printf("PA1 State:%d\n", state);
    // PA1の状態を更新
    inputPins.pa1 = state;
  }

  // PA2の状態取得
  state = digitalRead(PA2);
  // PA2の状態が変化した場合
  if (state != inputPins.pa2) {
    // 状態をUSART1に出力
    MySerial1.printf("PA2 State:%d\n", state);
    // PA2の状態を更新
    inputPins.pa2 = state;
  }

  // PA3の状態取得
  state = digitalRead(PA3);
  // PA3の状態が変化した場合
  if (state != inputPins.pa3) {
    // 状態をUSART1に出力
    MySerial1.printf("PA3 State:%d\n", state);
    // PA3の状態を更新
    inputPins.pa3 = state;
  }

  // PA4の状態取得
  state = digitalRead(PA4);
  // PA4の状態が変化した場合
  if (state != inputPins.pa4) {
    // 状態をUSART1に出力
    MySerial1.printf("PA4 State:%d\n", state);
    // PA4の状態を更新
    inputPins.pa4 = state;
  }

  // PA5の状態取得
  state = digitalRead(PA5);
  // PA5の状態が変化した場合
  if (state != inputPins.pa5) {
    // 状態をUSART1に出力
    MySerial1.printf("PA5 State:%d\n", state);
    // PA5の状態を更新
    inputPins.pa5 = state;
  }

  // PA6の状態取得
  state = digitalRead(PA6);
  // PA6の状態が変化した場合
  if (state != inputPins.pa6) {
    // 状態をUSART1に出力
    MySerial1.printf("PA6 State:%d\n", state);
    // PA6の状態を更新
    inputPins.pa6 = state;
  }

  // PA7の状態取得
  state = digitalRead(PA7);
  // PA7の状態が変化した場合
  if (state != inputPins.pa7) {
    // 状態をUSART1に出力
    MySerial1.printf("PA7 State:%d\n", state);
    // PA7の状態を更新
    inputPins.pa7 = state;
  }

  // PA11の状態取得
  state = digitalRead(PA11);
  // PA11の状態が変化した場合
  if (state != inputPins.pa11) {
    // 状態をUSART1に出力
    MySerial1.printf("PA11 State:%d\n", state);
    // PA11の状態を更新
    inputPins.pa11 = state;
  }

  // PA12の状態取得
  state = digitalRead(PA12);
  // PA12の状態が変化した場合
  if (state != inputPins.pa12) {
    // 状態をUSART1に出力
    MySerial1.printf("PA12 State:%d\n", state);
    // PA12の状態を更新
    inputPins.pa12 = state;
  }

  // PB0の状態取得
  state = digitalRead(PB0);
  // PB0の状態が変化した場合
  if (state != inputPins.pb0) {
    // 状態をUSART1に出力
    MySerial1.printf("PB0 State:%d\n", state);
    // PB0の状態を更新
    inputPins.pb0 = state;
  }

  // PC14の状態取得
  state = digitalRead(PC14);
  // PC14の状態が変化した場合
  if (state != inputPins.pc14) {
    // 状態をUSART1に出力
    MySerial1.printf("PC14 State:%d\n", state);
    // PC14の状態を更新
    inputPins.pc14 = state;
  }

  // PC15の状態取得
  state = digitalRead(PC15);
  // PC15の状態が変化した場合
  if (state != inputPins.pc15) {
    // 状態をUSART1に出力
    MySerial1.printf("PC15 State:%d\n", state);
    // PC15の状態を更新
    inputPins.pc15 = state;
  }

  // 300ms待機
  delay(300);
}
