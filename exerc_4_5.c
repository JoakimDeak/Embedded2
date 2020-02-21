/* ====================================
File name: exerc_4_5.c
Date: 2020-02-19
Group nr 19
Members that contribute to the solutions
Kent Edström
Joakim Deak
Member not present at the demonstration time

Demonstration code:22753
====================================== */
#include <avr/io.h>
#include <util/delay.h>

int column;
int row;

char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
};

void setup(){
    Serial.begin(9600);
    DDRB = 0x0f;
    DDRD = 0x00;
}

void setRowLow(int i){
    switch(i){
        case 0:
            PORTB = 0b00000111;
            break;
        case 1:
            PORTB = 0b00001011;
            break;
        case 2:
            PORTB = 0b00001101;
            break;
        case 3:
            PORTB = 0b00001110;
            break;
    }

}

int checkColumn(){
    if((PIND & (1 << PD7)) == 0){
        return 0;
    }
    else if((PIND & (1 << PD6)) == 0){
        return 1;
    }
    else if((PIND & (1 << PD5)) == 0){

        return 2;
    }
    else if((PIND & (1 << PD4)) == 0){

        return 3;
    }

    else{
        return -1;
    }
}


void loop()
{
    column = 0;
    row = 0;

    //iterate over the rows
    for(int i=0; i < 4; i++)
    {
        row = i;
        setRowLow(i);
        column = checkColumn();

        if(column != -1){
            Serial.println(keys[row][column]);
        }


    }
    delay(100);
}