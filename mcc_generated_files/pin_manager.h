/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC16F18326
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SCL1 aliases
#define SCL1_TRIS               TRISCbits.TRISC4
#define SCL1_LAT                LATCbits.LATC4
#define SCL1_PORT               PORTCbits.RC4
#define SCL1_WPU                WPUCbits.WPUC4
#define SCL1_OD                ODCONCbits.ODCC4
#define SCL1_ANS                ANSELCbits.ANSC4
#define SCL1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SCL1_GetValue()           PORTCbits.RC4
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SCL1_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define SCL1_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define SCL1_SetPushPull()    do { ODCONCbits.ODCC4 = 0; } while(0)
#define SCL1_SetOpenDrain()   do { ODCONCbits.ODCC4 = 1; } while(0)
#define SCL1_SetAnalogMode()  do { ANSELCbits.ANSC4 = 1; } while(0)
#define SCL1_SetDigitalMode() do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS               TRISCbits.TRISC5
#define SDA1_LAT                LATCbits.LATC5
#define SDA1_PORT               PORTCbits.RC5
#define SDA1_WPU                WPUCbits.WPUC5
#define SDA1_OD                ODCONCbits.ODCC5
#define SDA1_ANS                ANSELCbits.ANSC5
#define SDA1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDA1_GetValue()           PORTCbits.RC5
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDA1_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define SDA1_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define SDA1_SetPushPull()    do { ODCONCbits.ODCC5 = 0; } while(0)
#define SDA1_SetOpenDrain()   do { ODCONCbits.ODCC5 = 1; } while(0)
#define SDA1_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define SDA1_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/