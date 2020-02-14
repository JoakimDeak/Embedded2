/* ====================================
File name: exerc_2_3.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code: 
====================================== */
#include <stdio.h>

#define MAX_ARGS 6

unsigned char packVariables(char **args, int const argumentRanges[]){
    unsigned char b = 0;
    // left shifting values based on required bits
    b |= (*args[5] - '0' << 0);
    b |= (*args[4] - '0' << 1);
    b |= (*args[3] - '0' << 2);
    b |= (*args[2] - '0' << 4);
    b |= (*args[1] - '0' << 7);

    return b;
}

int validateInputs(char **args, int argc, int const argumentRanges[]){
    if(argc != MAX_ARGS){
        printf("Incorrect number of arguments.\n");
        return 0;
    }
    for(int i = 1; i < MAX_ARGS; i++){
        if(*args[i] - '0' > argumentRanges[i- 1]){
            printf("Argument %d with a value of %d is not within its range of %d\n", i, *args[i] - '0',argumentRanges[i - 1]);
            return 0;
        }
    }

    return 1;
}

int main(int argc, char **argv) {
    int const argumentRanges[5] = {1, 4, 2, 1, 1}; // accepted ranges for the arguments as define in the project description

    if(!validateInputs(argv, argc, argumentRanges)){
        printf("Failed input validation\n");
        return 1;
    }

    printf("Result in hexadecimal: %02x\n", packVariables(argv, argumentRanges));

    return 0;
}