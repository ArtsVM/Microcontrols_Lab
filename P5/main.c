// Arturo Vázquez Muñoz - A00570187
// Laboratorio de Microcontroladores 
// Práctica 5 - Introducción a MPLAB

// Libraries/headers section
#include "device_config.h"

// Directives section
#define _XTAL_FREQ 1000000
#define ONE_SECOND 1000

// Data Type section

enum port_dir {output, input}; // output = 0, input = 1
enum port_ACDC {digital, analog};// digital = 0, analog = 1
enum resistor_state {set_ON, res_ON};// set_ON = 0, res_ON = 1
enum led_state {led_OFF, led_ON};// led_OFF = 0, led_ON = 1
enum butto_state {pushed, no_pushed};// pushed = 0, no_pushed = 1


// ISR for high-priority
void __interrupt (high_priority ) high_isr ( void );

//ISR for low-priority
void __interrupt (low_priority) low_isr (void);

//Functions declaration
void portsInit( void );  // Ports configuration

// Main Section - Donde se harán las operaciones en esta práctica
void main(void){ 
    // Configuration
    portsInit();
    
    //Infinite Cycle
    while(1){
        // If button is pushed then:
        // Turn on the RA4 LED, otherwise turn off RA4 LED
//        if(PORTBbits.RB4 == pushed) {  
//            LATA &= LATAbits.LATA7 ;
//        } else {
//            LATA | = LATAbits.LATA7;
//        }

        LATA = 8;
        __delay_ms(ONE_SECOND);     // Delay function XC8 Compiler
        LATA >>= 1;
        __delay_ms(ONE_SECOND);
        LATA >>= 1;
        __delay_ms(ONE_SECOND);
        LATA >>= 1;
        __delay_ms(ONE_SECOND);
    }
}

// Functions Section

//Ports configuration.
void portsInit(void){
    // Set PORTA as digital port also set RA4 and RA7 as output
    ANSELA = digital;
    TRISAbits.TRISA4 = output;   // Se configuran Puertos A seleccionados como output, por lo tanto = 0;
    TRISAbits.TRISA7 = output;   
    TRISBbits.TRISB4 = input;   // Puerto RB4 como input
    // Set PORTB as digital port also set RA4 as input 
    ANSELB = digital;           // Todos lo puertos B como digitales, es decir 0;
}