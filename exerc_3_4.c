#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
            fclose(fin);
            break;
        } else{
            printf("First Name: %s\n Last Name: %s\n Personnummer: %s\n", pr.firstName, pr.famName, pr.pers_number);
        }
    }
    fclose(fin);
}

void searchByFirstName(char *name){

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

    int choice;
    do{
        printf("Welcome, choose one of the following options\n");
        printf("1. Create a new and delete the old file\n");
        printf("2. Add a new person to the file\n");
        printf("3. Search for a person in the file\n");
        printf("4. Print out everyone in the file\n");
        printf("5. Exit the program\n");

        scanf("%d", &choice);
        fflush(stdin);

        switch(choice){
            case 1:
                Person p = {"John", "Doe", "196001011234"};
                writeNewFile(&p);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                break;
            default:

                break;
        } while(choice != 5);
    }


    return 0;
}