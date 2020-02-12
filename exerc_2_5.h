/* ====================================
File name: exerc_2_5.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdlib.h>

#define MAX 100
#define MAXNUMBER 20

void create_random(int *table){
    for(int i = 0; i < MAX; i++){
        table[i] = rand() % MAXNUMBER;
    }
}

void count_frequency(int *table, int *freq){
    for(int i = 0; i < MAX; i++){
        freq[table[i]]++;
    }
}

void draw_histogram(int *freq){
    for(int i = 0; i < MAXNUMBER; i++){
        if(freq[i] != 0){
            printf("%d ", i);
            for(int j = 0; j < freq[i]; j++){
                printf("x");
            }
            printf("\n");
        }
    }
}


void frequencyCounter(){
    int table[MAX];
    int freq[MAXNUMBER] = {0};

    create_random(&table);
    count_frequency(&table, &freq);
    draw_histogram(&freq);
}
