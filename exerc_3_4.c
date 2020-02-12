#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char firstName[20];
    char famName[20];
    char pers_number[13]; // yyyymmddxxxx
}Person;

Person inputRecord(){

}

void writeNewFile(Person *inRecord){
    FILE *ptr;
    if (access ("personDB.bin", F_OK) != -1){
        //FILE EXISTS
        remove("personDB.bin");
        printf("Successfully deleted /n");
    }

    ptr = fopen("personDB.bin", "wb");
    if((fwrite(inRecord, sizeof(Person), 1, ptr)) == -1){
        printf("Couldn't write to file write\n");
    } else{
        printf("Successfully wrote to the write\n");
    }
    printf("Made file");


}

void printFile(){
    FILE *fin;
    Person pr;
    if((fin = fopen("personDB.bin", "rb")) == NULL){
        printf("Couldn't open file to read\n");
        return;
    }
    /*while(!feof(fin)){ // repeat until end of file is reached
        if((fread(&pr, sizeof(Person), 1, fin)) == -1){
            printf("Couldn't read from file\n");
            fclose(fin);
            return;
        } else{
            printf("First Name: %s\n Last Name: %s\n Personnummer: %s\n", pr.firstName, pr.famName, pr.pers_number);
        }
    }*/
    while(1){
        fread(&pr, sizeof(Person), 1, fin);
        if(feof(fin) != 0){
            break;
        } else{
            printf("First Name: %s\n Last Name: %s\n Personnummer: %s\n", pr.firstName, pr.famName, pr.pers_number);
        }
    }
    fclose(fin);
}

void searchByFirstName(char *name){
    FILE *fin;
    Person pr;
    if((fin = fopen("personDB.bin", "rb")) == NULL){
        printf("Couldn't open file to read\n");
        return;
    }
    while(1){
        fread(&pr, sizeof(Person), 1, fin);
        if(feof(fin) != 0){
            break;
        } else{
            if(strcmp(pr.firstName, name) == 0 || strcmp(pr.famName, name) == 0) {
                printf("SAME");
                printf("Searched for Kent: Given record:  "
                       "First Name: %s\n Last Name: %s\n Personnummer: %s\n", pr.firstName, pr.famName, pr.pers_number);
            }
        }
    }

    fclose(fin);

}

void appendFile(Person *inRecord){
    FILE *fout;
    if((fout = fopen("personDB.bin", "ab")) == NULL){
        printf("Couldn't open file to write\n");
        return;
    }
    if((fwrite(inRecord, sizeof(Person), 1, fout)) == -1){
        printf("Couldn't write to file write\n");
        return;
    }
    fclose(fout);
}

int main(){

    Person p1 = {"Joakim", "Deak", "199910064196"};
    Person p2 = {"Kent", "Deak", "199910064196"};
    Person p3 = {"Bengt", "Deak", "199910064196"};
    appendFile(&p1);
    appendFile(&p2);
    appendFile(&p3);

    printFile();
    char name = "Kent";
    searchByFirstName("Kent");
    return 0;
}