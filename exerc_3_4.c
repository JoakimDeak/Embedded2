#include <stdio.h>

typedef struct{
    char firstName[20];
    char famName[20];
    char pers_number[13]; // yyyymmddxxxx
}Person;

Person inputRecord(){

}

void writeNewFile(Person *inRecord){

}

void printFile(){

}

void searchByFirstName(char *name){

}

void appendFile(Person *inRecord){
    FILE *fout;
    if((fout = fopen("personDB.bin", "ab")) == NULL){
        printf("Couldn't open file to write\n");
        return;
    } else{
        printf("could open file to write\n");
    }
    if((fwrite(inRecord, sizeof(Person), 1, fout)) == -1){
        printf("Couldn't write to file write\n");
    } else{
        printf("Successfully wrote to the write\n");
    }
    fclose(fout);
}

int main(){

    return 0;
}