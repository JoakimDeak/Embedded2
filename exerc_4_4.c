/* ====================================
File name: exerc_4_4.c
Date: 2020-02-19
Group nr 19
Members that contribute to the solutions
Kent Edström
Joakim Deak
Member not present at the demonstration time

Demonstration code: 27922
====================================== */
// ----Program template for Arduino in Tinkercad VT 2020
#include <avr/io.h>
#include <util/delay.h>
/* ---Macros predefined for the compiler
DDRB  Data direction register B
PORTB Outport B
PINB  Inport B
DDRD  Data direction register D
PORTD Outport D
PIND  Inport D*/

unsigned char input;
void setup(){
    DDRD = 0xFF; // To set all Port D bits as outbits.
    DDRB = 0x00;
    PORTD = B00000011;
    //DDRB=  //.......( Set all to inbits. You will only use bit 0.
}

void loop(){

    if (PINB == 0){
        PORTD = PORTD << 1;
        if(PORTD == B10000000){
            PORTD = B10000001;
        }
        if(PORTD == B00000010){
            PORTD = B00000011;
        }
    }
    delay(1000);
}