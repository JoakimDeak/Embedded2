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
    FILE *fin;
    Person *pr;
    if((fin = fopen("personDB.bin", "rb")) == NULL){
        printf("Couldn't open file to read\n");
        return;
    } else{
        printf("Could open file to read\n");
    }
    while(!feof(fin)){ // repeat until end of file is reached
        if((fread(pr, sizeof(Person), 1, fin)) == -1){
            printf("Couldn't read from file\n");
            return;
        } else{
            printf("First Name: %s")
        }
    }
}

void searchByFirstName(char *name){

}

void appendFile(Person *inRecord){
    FILE *fout;
    if((fout = fopen("personDB.bin", "ab")) == NULL){
        printf("Couldn't open file to write\n");
        return;
    } else{
        printf("Could open file to write\n");
    }
    if((fwrite(inRecord, sizeof(Person), 1, fout)) == -1){
        printf("Couldn't write to file write\n");
    } else{
        printf("Successfully wrote to the write\n");
    }
    fclose(fout);
}

int main(){

    Person p = {"Joakim", "Deak", "199910064196"};

    return 0;
}