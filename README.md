## PIC16F-OLED-SSD1306  
PIC16F18326からSSD1306コントローラーのOLED(128x64)をI2C接続で利用するライブラリとサンプルプログラムです。  
オリジナルは[Adafruit GFX Lib](https://learn.adafruit.com/adafruit-gfx-graphics-library)で、Derk SteggewentzさんがPSOC4[Cypress-PSOC-OLED](https://github.com/derkst/Cypress-PSOC-OLED)対応したものをPICで動くように移植しました。  

### 使い方
#### 接続
|OLED|PIC16F|
|-|-|
|SDA|RC5|
|SCL|RC4|
PPSで他のピンに変更可能です。

### 他のPICへ移植
* MCCでサポート対象
* 2kB以上のRAM
* MSSP I2Cを内蔵

MCCで生成されたI2Cルーチンをコールしているだけなので、メモリーに余裕(約1kBのフレームバッファを確保)があれば他のPICに移植可能です。
```
uint8_t frameBuff[MAX_PAGE][MAX_COLUMN+1]={
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
    {SSD1306_DAT,0},
};
```


### 構成部品
* [PIC16F18326](http://akizukidenshi.com/catalog/g/gI-11886/)
* [０．９６インチ　１２８×６４ドット有機ＥＬディスプレイ（ＯＬＥＤ）](http://akizukidenshi.com/catalog/g/gP-12031/)

### 参考にしたサイト
* [mgo-tec電子工作](https://www.mgo-tec.com/blog-entry-ssd1306-revalidation-i2c-esp32-esp8266.html)
* Derk Steggewentzさんの[Cypress-PSOC-OLED](https://github.com/derkst/Cypress-PSOC-OLED)
