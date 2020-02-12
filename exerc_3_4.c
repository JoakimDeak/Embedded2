#include <stdio.h>

typedef struct{
    char firstName[20];
    char famName[20];
    char pers_number[13]; // yyyymmddxxxx
    int test;
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
        printf("Couldnt open file\n");
        return;
    } else{
        printf("could open file\n");
    }
    fwrite(&inRecord, sizeof(Person), 1, fout);
    fclose(fout);



    Person* pr;
    FILE *fin = fopen("personDB.bin", "rb");
    fread(&pr, sizeof(Person), 1, fin);
    printf("%s, %s, %s, %d", pr->firstName, pr->famName, pr->pers_number, pr->test);
    fclose(fin);
}

int main(){

    Person p = {"joakim", "Deak", "199910064196", 6};
    appendFile(&p);

    return 0;
}