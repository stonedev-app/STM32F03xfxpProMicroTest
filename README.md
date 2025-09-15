# STM32G030 ProMicro 型開発ボード ピン動作チェック

74thさんのSTM32G030 ProMicro 型開発ボードの各ピン動作を確認するためのソースです  
ジャンパワイヤやシリアルモニタを利用して、入力ピン、UART、SWD、リセットの動作確認ができます

---

## 対象マイコンボード

- [STM32G030 ProMicro 型開発ボードキット](https://74th.booth.pm/items/4879147)

---

## 開発環境

- **IDE**: Arduino IDE 2.3.5  
- **デバッガ**: [DAPLink・CH32V203使用ARMマイコンデバッガ](https://74th.booth.pm/items/4916891)  
電源スイッチは3V3

### 開発環境設定

開発環境設定: [スイッチサイエンス STM32開発ボード STM32G030F6搭載](https://www.switch-science.com/products/10542?_pos=3&_sid=4fc0d15f6&_ss=r)  

上記設定から変更する箇所:
- **Upload method**: `OpenOCD DapLink (SWD)`  

STM32開発参考: [Arduino IDEで始める！STM32開発ボード入門ガイド 実践編](https://www.switch-science.com/blogs/magazine/arduino-ide-stm32-start-guide-practice?srsltid=AfmBOopVepInhPBymRDxTHUD87gOzaU1gcVklViDTbNgGVfrr1Z1MPj7)  

---

## 使い方

### 1. デジタルピンのチェック
- ジャンパワイヤの片方を **GND**、もう片方を **チェックしたいピン** に接続
- 対象ピン: `A0-A7, A11, A12, B0, C14, C15`
- **シリアルモニタ (9600 baud)** にピン番号と、0又は、1のログが出力される

### 2. UART の確認
- `B3 (TX), B7 (RX)` を利用
- TX出力: シリアルモニタに起動時ログが表示される
- RX確認: シリアルモニタに入力したメッセージが出力される

### 3. SWD の確認
- `DIO, SCL` はピン動作チェックソース書き込み完了でOKとする

### 4. リセットスイッチと RT ピンの確認
- リセットスイッチ押下で、シリアルモニタに起動時ログが再度表示
- RTピン: ジャンパワイヤで **GND に落とす** とリセット確認可能

### 5. 電源ラインの確認
- `5V, 3V, GND` はテスターで確認
- 3V 通電時、**青色 LED が点灯**
- 5V は USB Type-C 接続が必要

⚠️ 注意: **USBの保護回路は未実装**  
→ USBとデバッガを同時接続しないことを推奨

---

## デバッグについて

### Arduino IDE 側の追加設定
- **Debug symbols and core logs**: `Symbols Enabled (-g)`
- **Optimize**: `Debug (-Og)`  
  ※なくても動作しましたが念の為

### `launch.json` 編集
デバッグ開始ボタンを押すと雛形が生成されるので、以下のように修正してください。

```json
"configFiles": [
  "interface/cmsis-dap.cfg",
  "target/stm32g0x.cfg"
]
