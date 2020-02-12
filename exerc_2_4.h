/* ====================================
File name: exerc_2_4.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdio.h>
#include <string.h>

#define MAX 20

int palCheck(char input[]){

    int inputL = strlen(input);

    if(inputL > 2){
        for(int i = 0; i < inputL / 2; i++){
            if(input[i] != input[inputL - 1 - i]){
                return 0;
            }
        }
    }

    return 1;
}