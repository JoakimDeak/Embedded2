/* ====================================
File name: exerc_2_6.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdio.h>

int initQue(int list[], int max){
    for(int i = 0; i < max; i++){
        list[i] = -1;
    }
}

int input(int list[], int number, int max){
    for(int i = 0; i < max; i++){
        if(list[i] == -1){
            list[i] = number;
            return 1;
        }
    }
    return 0;
}

int output(int list[], int max){
    if(list[0] == -1){
        return 0;
    }
    int output = list[0];

    for(int i = 1; i < max; i++){
        list[i - 1] = list[i];
    }

    list[max - 1] = -1;

    return output;
}

void runQueue(){
    int max = 5;
    int list[max];

    printf("before init: ");
    for(int i = 0; i < max; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    initQue(list, max);

    printf("after init: ");
    for(int i = 0; i < max; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    input(list, 3, max);
    input(list, 4, max);
    input(list, 5, max);
    input(list, 8, max);

    printf("after inputs: ");
    for(int i = 0; i < max; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("output result: %d \n", output(list, max));

    printf("after output: ");
    for(int i = 0; i < max; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}