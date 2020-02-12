/* ====================================
File name: exerc_2_7.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */
#include <stdio.h>

int nearestGreater(int num){
    if(num % 10 == 0){
        return num;
    }
    num = num / 10;
    num = num + 1;
    num = num * 10;
    return num;
}
int controlDigit(char persnr[]){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        int product = persnr[i] - '0';
        if(i % 2 == 0){
            product = product * 2;
        }
        sum = sum + (product / 10);
        sum = sum + (product % 10);
    }
    return nearestGreater(sum) - sum;
}


int readPersnr(char persnr[]){
    int year = (persnr[0] - '0') * 10 + (persnr[1] - '0');
    int month = (persnr[2] - '0') * 10 + (persnr[3] - '0');
    int day = (persnr[4] - '0') * 10 + (persnr[5] - '0');

    if(month > 12 || month < 1){
        return 0;
    }

    if(day > 31 || day < 1){
        return 0;
    }

    if(month % 2 == 0 && day > 30){
        return 0;
    }

    if(month == 2){
        if(day > 29){
            return 0;
        }
        if(day > 28 && year % 4 == 0){
            return 0;
        }
    }

    if(persnr[9] - '0' != controlDigit(persnr)){
        return 0;
    }

    return 1;
}

loopPersnrCheck(){
    char persnr[11];
    do{
        printf("Enter person number \n");
        fgets(persnr, 11, stdin);
        if(persnr[0] == 'q'){
            break;
        }
        while ((getchar()) != '\n');
        if(readPersnr(persnr)){
            printf("The entered number is valid \n");
        } else{
            printf("The entered number is invalid \n");
        }
    } while(persnr[0] != 'q');
    printf("q was entered, shutting down \n");
}