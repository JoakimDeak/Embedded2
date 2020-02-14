/* ====================================
File name: decode.c
Date: 2020-02-14
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdio.h>
#include <stdlib.h>

int validateInput(int brake2, int brake1, int key_pos, int gear_pos, int engine_on){
    if(brake2 > 1 || brake1 > 1 || key_pos > 2 || gear_pos > 4 || engine_on > 1){
        return 0;
    }

    return 1;
}

void unpackAndPrint(unsigned char byte){
    unsigned int brake2, brake1, key_pos, gear_pos, engine_on;

    brake2 = (((1 << 1) - 1) & (byte >> (0))) >> 0;
    brake1 = (((1 << 1) - 1) & (byte >> (1)));
    key_pos = (((1 << 2) - 1) & (byte >> (2)));
    gear_pos = (((1 << 3) - 1) & (byte >> (4))); // takes 3 bits from byte starting at position 4 going right to left
    engine_on = (((1 << 1) - 1) & (byte >> (7)));

    if(validateInput(brake2, brake1, key_pos, gear_pos, engine_on)){
        printf("Name     Value\n");
        printf("---------------\n");
        printf("engine_on  %d\n", engine_on);
        printf("gear_pos   %d\n", gear_pos);
        printf("key_pos    %d\n", key_pos);
        printf("brake1     %d\n", brake1);
        printf("brake2     %d\n", brake2);
    } else{
        printf("Input contains invalid values");
    }

}

int main(int argc, char **argv){

    if(argc != 2){
        return 1;
    }

    // *argv[1] is a string. bellow converts string to hexadecimal representation of integer
    unsigned char byte = strtol(argv[1], NULL, 16);
    unpackAndPrint(byte);

    return 0;
}