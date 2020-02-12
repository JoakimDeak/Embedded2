/* ====================================
File name: exerc_2_3.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Kent Edström
Member not present at the demonstration time

Demonstration code:30969
====================================== */
#include <stdio.h>
#include <string.h>

int checkStrings(char string1[], char string2[]){
    int i = 0;
    if (strlen(string1) != strlen(string2)){
        printf("Strings are not the same due to length");
        return 0;
    }
    for (int i = 0; i < strlen(string1); i++){
        if (!(string1[i] == string2[i])){
            printf("Strings are not the same due to character array");
            return 0;
        }
    }
    printf("Strings are the same according to checkstrings method");
    return 1;
}

int main(int argc, char **argv) {

    if (argc == 3) {
        checkStrings(argv[1],argv[2]);
        if (strcmp(argv[1], argv[2]) == 0){
          printf("Strings are the same");
        }
        else {
            printf("Strings are not the same");
        }




    }


}