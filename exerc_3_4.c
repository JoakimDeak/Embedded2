#include <stdio.h>
#include <unistd.h>

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
    } else{
        printf("Could open file to read\n");
    }
    while(1){ // repeat until end of file is reached
        printf("got in loop\n");
        if((fread(&pr, sizeof(Person), 1, fin)) == -1){
            printf("Couldn't read from file\n");
            fclose(fin);
            return;
        } else{
            printf("First Name: %s\n Last Name: %s\n Personnummer: %s\n", pr.firstName, pr.famName, pr.pers_number);
        }
        if(feof(fin)){
            fclose(fin);
            break;
        }
        //pr++;
    }
    fclose(fin);
}

void searchByFirstName(char *name){
    FILE *fin;
    Person *pr;
while(!feof(fin)){
    if((fread(&pr, sizeof(Person),1,fin)) == -1){
        printf("Couldnt read from file to search for person \n");
        return;
    }
    if (pr->firstName == name || pr ->famName == name){

    }
}
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

    return 0;
}