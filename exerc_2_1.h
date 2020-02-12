/* ====================================
File name: exerc_2_1.h
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
void copyString(){
    char copied[21];
    char input[sizeof copied];
    char libraryCopy[sizeof copied];
    printf("Enter string to be copied \n");
    fgets(input, sizeof input, stdin);
    strcpy(libraryCopy, input);
    for (int i = 0; i < sizeof input ; i++){
        copied[i] = input[i];

    }
    printf("%s \n", copied );
    printf("%s", libraryCopy);
}

