/* ====================================
File name: exerc_5_1.c
Date: 2020-02-24
Group nr 19
Members that contribute to the solutions
Joakim Deak
Kent Edström
Member not present at the demonstration time

Demonstration code 5.1: 20905
Demonstration code 5.2: 27920
====================================== */
#include <avr/io.h>
#include <util/delay.h>

int column;
int row;

int timer = 0;

char keyPressed = '\u0000';

char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
};

void readKeyboard(){
    column = 0;
    row = 0;

    //iterate over the rows
    for(int i=0; i < 4; i++)
    {
        row = i;
        setRowLow(i);
        column = checkColumn();

        if(column != -1){
            keyPressed = keys[row][column];
        }

    }
}

void setup(){
    Serial.begin(9600);
    DDRB = 0x0f;
    DDRD = 0x00;
    attachInterrupt(digitalPinToInterrupt(2), readKeyboard , FALLING);
    pinMode(A0, INPUT);
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

    timer++;

    if(keyPressed != '\u0000'){
        Serial.println(keyPressed);
        keyPressed = '\u0000';
    }
    if(timer % 100 == 0){
        float temp = ((analogRead(A0) * (5.0 / 1024)) - 0.5) / 0.01;
        Serial.println(temp);
    }


    setRowLow(0);
    setRowLow(1);
    setRowLow(2);
    setRowLow(3);
    delay(10);
}
