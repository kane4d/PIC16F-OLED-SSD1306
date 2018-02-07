/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F18326
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "ssd1306.h"
/*
                         Main application
 */

#define DEMO_DELAY_LONG (3000)
#define DEMO_DELAY_MID  (2000)
#define DEMO_DELAY_SHORT (1000)



void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    display_init();
    for(;;){

        // clearing display
        display_clear();    
        display_update();    


        // drawing a pixel
        gfx_drawPixel(40, 40, WHITE);    
        display_update(); 

        __delay_ms(DEMO_DELAY_SHORT);
        display_clear();    
        display_update();    

        
        // line drawing
        int16_t i = 0;
        for( i = 0 ; i < gfx_width(); i+=4) {
            gfx_drawLine(0, 0, i, gfx_height()-1, WHITE);
            display_update();
        }
        for( i = 0 ; i < gfx_height() ; i += 4 ){
            gfx_drawLine(0, 0, gfx_width()-1, i, WHITE);
            display_update();
        }    
     
        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    

        // text settings
        gfx_setTextSize(1);
        gfx_setTextColor(WHITE);
        gfx_setCursor(0,0);

        // text display
        for( i = 0 ; i < 168 ; i++){
            if( i == '\n' ) 
                continue;
            gfx_write(i);
          }    
        display_update(); 
        
        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    
        
        // cursor
        gfx_setCursor( 0, 0 );
        
        // text sizes
        gfx_setTextSize(2);
        gfx_write( '8' );
        gfx_setTextSize(3);
        gfx_write( '8' );
        gfx_setTextSize(4);
        gfx_write( '8' );
        display_update(); 
        
        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    

        // line printing
        gfx_setTextSize(1);
        gfx_setTextColor(WHITE);
        gfx_setCursor(0,0);
        gfx_println("test line 1 ...");
        gfx_println("2nd line ...");
        display_update();    

        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    

        
        // scrolling
        gfx_setTextSize(1);
        gfx_setTextColor(WHITE);
        gfx_setCursor(0,0);

        for( i = 1 ; i < 16 ; i++ ){
            gfx_println("scroll");
        
        }
        display_update();    
        
        
        
        display_scroll(SCROLL_PAGE_0,SCROLL_PAGE_7,SCROLL_RIGHT,SCROLL_SPEED_7);
        __delay_ms(DEMO_DELAY_MID);
        display_stopscroll();
        display_scroll(SCROLL_PAGE_2,SCROLL_PAGE_4,SCROLL_LEFT,SCROLL_SPEED_3);
        __delay_ms(DEMO_DELAY_MID);
        display_stopscroll();
        
        

        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    
        
        
        // rectangles
        for( i = 0 ; i < gfx_height()/2 ; i += 2 ){
            gfx_drawRect(i, i, gfx_width()-2*i, gfx_height()-2*i, WHITE);
            display_update();   
        }
        
        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    

        // filled rectangles
        uint8_t color = 1;
        for( i = 0 ; i < gfx_height()/2 ; i += 3 ){
            // alternate colors
            gfx_fillRect(i, i, gfx_width()-i*2, gfx_height()-i*2, color%2);
            display_update();    
            color++;
        }    

        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    
        
        // circles
        for( i = 0 ; i < gfx_height() ; i += 2 ){
            gfx_drawCircle( gfx_width()/2, gfx_height()/2, i, WHITE );
            display_update();    
        }    

        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    
        
        
    #define MIN(x, y) (((x) < (y)) ? (x) : (y))
        
        // triangles
        for( i = 0 ; i < MIN(gfx_width(),gfx_height())/2; i+=5) {
            gfx_drawTriangle(gfx_width()/2, gfx_height()/2-i,
                             gfx_width()/2-i, gfx_height()/2+i,
                             gfx_width()/2+i, gfx_height()/2+i, WHITE);
            display_update();    
        }    

        
        __delay_ms(DEMO_DELAY_LONG);
        display_clear();    
        display_update();    
       
        // rotation
        int16_t j = 0;
        for( j = 0 ; j < 4 ; j++ ){
            gfx_setRotation(j);
            for( i = 0 ; i < MIN(gfx_width(),gfx_height())/2; i+=5) {
                gfx_drawTriangle(gfx_width()/2, gfx_height()/2-i,
                                 gfx_width()/2-i, gfx_height()/2+i,
                                 gfx_width()/2+i, gfx_height()/2+i, WHITE);
                display_update(); 
                __delay_ms(200);
            }    
        }
        
        __delay_ms(DEMO_DELAY_LONG);
       
        // invert and dim
        display_invert(1);
        __delay_ms(DEMO_DELAY_SHORT);
        
        for( i = 256 ; i >= 0 ; i-- ){
            display_contrast(i); 
            __delay_ms(10);
        }
        
        
        
        display_invert(0);
        __delay_ms(DEMO_DELAY_SHORT);
        for( i = 0 ; i < 256 ; i++ ){
            display_contrast(i); 
            __delay_ms(10);
        }
        
    
        __delay_ms(DEMO_DELAY_LONG);

    }

}
/**
 End of File
*/