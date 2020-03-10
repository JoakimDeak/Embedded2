#include <stdio.h>

//#define ML13_Status 0xB10
//define ML13_Control 0x0B00

unsigned char ML13_Status = 0xB10;
unsigned char ML13_Control = 0x0B00;

void delay(x){
    for(int i = 0; i < x; i++);
}

void door(){
    while(1){ // run forever unless door breaks down
        if(ML13_Status >> 3 & 1){ // if sensor activated
            ML13_Control |= 1 << 0; // open the door
            ML13_Status |= 1 << 6; // opening slowly
            ML13_Status &= ~(1 << 5); // door is not closed
            delay(10);
            ML13_Status |= 1 << 4; // door is wide open
            ML13_Status &= ~(1 << 6); // door is not opening
        }

        for(int i = 0; i < 100; i++){ // will stay for as long as the sensor gets activated before i reaches 100
            delay(10);
            if(ML13_Status >> 3 & 1){
                i = 0;
            }
        }

        ML13_Control |= 1 << 1; // close the door
        ML13_Status |= 1 << 7; // closing door
        delay(10);
        ML13_Status &= ~(1 << 4); // door is not open

        ML13_Status |= 1 << 5; // door is closed
        ML13_Status &= ~(1 << 7); // door is not closing

    }
}

int main(){

    door(); // starts the door program

    return 0;
}
