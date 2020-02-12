/* ====================================
File name: exerc_2_2.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Kent Edström
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define MAX 99

void integerArray(){
    int array[MAX];
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++){
        array[i] = rand() % 100;
    }
    printf("The value of the label array is: %p \n", &array);
    printf("First integer in the array is: %d \n", array[0]);
    printf("The size of an integer is: %d \n", sizeof(array[0]));
    printf("The size of the whole array is: %d \n", sizeof(array));

    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++){
        printf("Integer value: %d, double value: %0.1f \n", array[i], (double)array[i]);
    }
}

