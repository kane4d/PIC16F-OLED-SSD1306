/*

SSD1306 OLED - I2C driver

Derk Steggewentz, 3/2015 
https://github.com/derkst/Cypress-PSOC-OLED

kane4d, 2/2018
 
This is a I2C driver for SSD1306 OLED displays including graphics library.


The graphics library part (gfx_ functions) is based on the Adafruit graphics library.


No license restrictions on my part, do whatever you want as long as you follow the inherited
license requirements (applying to the Adafruit graphics library part).


===== derived license (for graphics library) ======

Copyright (c) 2013 Adafruit Industries. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef SSD1306_H
#define	SSD1306_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifndef SSD1306_ADDR
#define SSD1306_ADDR  (0x78 >> 1)
#endif
// https://github.com/derkst/Cypress-PSOC-OLED
#define DISPLAYWIDTH 128
#define DISPLAYHEIGHT 64
  
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR 0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SETPAGESTART 0xB0

// I2C result status
#define TRANSFER_CMPLT    (0x00u)
#define TRANSFER_ERROR    (0xFFu)

//control byte, Co bit = 0, D/C# = 0 (command)
#define SSD1306_CMD (0b00000000)
//control byte, Co bit = 0 (continue), D/C# = 1
#define SSD1306_DAT (0b01000000)    

#define MAX_PAGE (8u)
#define MAX_COLUMN (128u)
#if 0   
     const uint8_t ssd1306_init_cmd[] = {
        0x00,
        SSD1306_DISPLAYOFF,
        SSD1306_SETDISPLAYCLOCKDIV,
        0x80,
        SSD1306_SETMULTIPLEX,
        0x3f,
        SSD1306_SETDISPLAYOFFSET,
        0x00,
        SSD1306_SETSTARTLINE | 0x0,
        SSD1306_CHARGEPUMP,
        0x14,
        SSD1306_MEMORYMODE,
        0x00,
        SSD1306_SEGREMAP | 0x1,
        SSD1306_COMSCANDEC,
        SSD1306_SETCOMPINS,
        0x12,
        SSD1306_SETCONTRAST,
        0xcf,
        SSD1306_SETPRECHARGE,
        0xf1,
        SSD1306_SETVCOMDETECT,
        0x40,
        SSD1306_DISPLAYALLON_RESUME,
        SSD1306_NORMALDISPLAY,
        SSD1306_DISPLAYON
    };
#else
const uint8_t ssd1306_init_cmd[]= {
    // https://www.mgo-tec.com/blog-entry-ssd1306-revalidation-i2c-esp32-esp8266.html/4
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_DISPLAYOFF, //display off
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SETMULTIPLEX, //Set Multiplex Ratio  0xA8, 0x3F
	0b00111111, //64MUX
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)    
	SSD1306_SETDISPLAYOFFSET, //Set Display Offset 0xD3, 0x00
	0x00,
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SETSTARTLINE, //Set Display Start Line 0x40
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SEGREMAP, //Set Segment re-map 0xA0/0xA1
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_COMSCANINC, //Set COM Output Scan Direction 0xC0,/0xC8
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SETCOMPINS, //Set COM Pins hardware configuration 0xDA, 0x02
	0b00010010,
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SETCONTRAST, //Set Contrast Control 0x81, default=0x7F
	255, //0-255
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_DISPLAYALLON_RESUME, //Disable Entire Display On
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_NORMALDISPLAY, //Set Normal Display 0xA6, Inverse display 0xA7
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_SETDISPLAYCLOCKDIV, //Set Display Clock Divide Ratio/Oscillator Frequency 0xD5, 0x80
	0b10000000,
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_MEMORYMODE, //Set Memory Addressing Mode
	0x10, //Page addressing mode
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_PAGEADDR, //Set Page Address
	0, //Start page set
	7, //End page set
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_COLUMNADDR, //set Column Address
	0, //Column Start Address
	127, //Column Stop Address
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_CHARGEPUMP, //Set Enable charge pump regulator 0x8D, 0x14
	0x14,
	SSD1306_CMD, //control byte, Co bit = 0, D/C# = 0 (command)
	SSD1306_DISPLAYON, //Display On 0xAF
};
#endif

const uint8_t ssd1306_cmd_setColAddr[] = {
    SSD1306_CMD,
    SSD1306_COLUMNADDR,   // set column address
    0,      // start col
    127     // stop col
};
uint8_t ssd1306_cmd[10]={0};
const uint8_t DotB1[]={
    SSD1306_DAT, // data
    0b11111111,
    0b00000111,
    0b11111111,
    0b00000011,
    0b00000101,
    0b00001001,
    0b00010001,
    0b00100001
};
uint8_t dummy_cmd =0;
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


#define BLACK 0
#define WHITE 1
#define INVERSE 2   

typedef enum{
    SCROLL_RIGHT = 0x26,
    SCROLL_LEFT = 0x2A
}SCROLL_DIR;

typedef enum{
    SCROLL_SPEED_0 = 0x03,  // slowest
    SCROLL_SPEED_1 = 0x02,
    SCROLL_SPEED_2 = 0x01,
    SCROLL_SPEED_3 = 0x06,
    SCROLL_SPEED_4 = 0x00,
    SCROLL_SPEED_5 = 0x05,
    SCROLL_SPEED_6 = 0x04,
    SCROLL_SPEED_7 = 0x07   // fastest
}SCROLL_SPEED;

typedef enum{
    SCROLL_PAGE_0 = 0,
    SCROLL_PAGE_1,
    SCROLL_PAGE_2,
    SCROLL_PAGE_3,
    SCROLL_PAGE_4,
    SCROLL_PAGE_5,
    SCROLL_PAGE_6,
    SCROLL_PAGE_7   
}SCROLL_AREA;

void display_init( void );
void display_update(void);
void display_clear(void);
void display_stopscroll(void);
void display_scroll( SCROLL_AREA start, SCROLL_AREA end, SCROLL_DIR dir, SCROLL_SPEED speed );
void display_contrast( uint8_t contrast );
void display_invert( uint8_t invert );




void gfx_drawPixel(int16_t x, int16_t y, uint16_t color);
void gfx_drawLine( int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color );
void gfx_setCursor( int16_t x, int16_t y );
void gfx_setTextSize( uint8_t size );
void gfx_setTextColor( uint16_t color );
void gfx_setTextBg( uint16_t background );
void gfx_write( uint8_t ch );
int16_t gfx_width(void);
int16_t gfx_height(void);
void gfx_print( const char* s );
void gfx_println( const char* s );
void gfx_drawRect( int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color );
void gfx_fillRect( int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color );
void gfx_drawCircle( int16_t x0, int16_t y0, int16_t r,uint16_t color );
void gfx_drawTriangle( int16_t x0, int16_t y0,int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color );
void gfx_setRotation( uint8_t x );


void clear_modifiedPixel(void);
I2C1_MESSAGE_STATUS oled_sendData(uint8_t* data, uint8_t len /*, bit cnt */);
I2C1_MESSAGE_STATUS oled_sendCmd(uint8_t* cmd, uint8_t len);
void oled_clearDisplay(void);
void oled_drawArrow(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SSD1306_H */

