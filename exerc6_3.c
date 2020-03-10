/* ====================================
File name: exerc6_3.c
Date: 2020-03-09
Group nr 19
Members that contribute to the solutions
Joakim Deak
Kent Edström
Member not present at the demonstration time
Demonstration code: 41975
====================================== */
#include <stdio.h>

#define ML13_Status 0xB10
#define ML13_Control 0x0B00

#define REG8(x) *((unsigned char *)(x))

unsigned char Status = REG8(ML13_Status);
unsigned char Control = REG8(ML13_Control);

void delay(x){
    for(int i = 0; i < x; i++);
}

void door(){
    while(1){ // run forever unless door breaks down
        if(Status >> 3 & 1){ // if sensor activated
            Control |= 1 << 0; // open the door
            Status |= 1 << 6; // opening slowly
            Status &= ~(1 << 5); // door is not closed
            delay(10);
            Status |= 1 << 4; // door is wide open
            Status &= ~(1 << 6); // door is not opening
        }

        for(int i = 0; i < 100; i++){ // will stay for as long as the sensor gets activated before i reaches 100
            delay(10);
            if(Status >> 3 & 1){
                i = 0;
            }
        }

        Control |= 1 << 1; // close the door
        Status |= 1 << 7; // closing door
        delay(10);
        Status &= ~(1 << 4); // door is not open

        Status |= 1 << 5; // door is closed
        Status &= ~(1 << 7); // door is not closing

    }
}

int main(){

    door(); // starts the door program

    return 0;
}
