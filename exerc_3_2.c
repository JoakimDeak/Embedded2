/* ====================================
File name: exerc_2_8.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Kent Edström
Member not present at the demonstration time

Demonstration code: 24925
====================================== */
#include <stdio.h>
#include <string.h>

int searchNumber(int n, int array[], int size){
    for (int i = 0; i <size; i++){
        if (array[i] == n){
            return i;
        }
    }
    return -1;


}

void bubble_sort(int number, int tab[]) {
    int i = 0, j = 0, tmp;
    for (i = 0; i < number; i++) {   // loop n times - 1 per element
        for (j = 0; j < number - i - 1; j++) { // last i elements are sorted already
            if (tab[j] > tab[j + 1]) {  // swap if larger
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }

}


int main(){
    int test [] = { 1,2,34,5,67,3,23,12,13,10};
    bubble_sort(10,test);
    printf("%d",searchNumber(34,test,10));
}