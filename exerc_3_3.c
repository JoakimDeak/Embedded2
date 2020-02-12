#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX 5

typedef struct q{
int number;
struct q *next;
struct q *prev;
} REGTYPE;

REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

int main(int argc, char *argv[]){
    int nr=0;
    REGTYPE*akt_post , *head=NULL;
    srand( time(0));
    head=random_list();
    akt_post=head;
    while( akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }
    printf("\n Setting new head");
    head=add_first(head,rand() %100);
    nr = 0;
    akt_post=head;
    while( akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }
    while((akt_post=head)!=NULL){
        head=akt_post->next;
    free(akt_post);
    }


return 0;
}

REGTYPE* random_list(void ){
    int nr,i=0;
    //REGTYPE *top, *old, *item;
    REGTYPE *head;
    head = (struct q*)malloc(sizeof(struct q));
    head->number = rand()%100;
    REGTYPE *current;
    current = head;
    for (int i = 0; i < MAX; i++){
        REGTYPE *new;
        new = (struct q*)malloc(sizeof(struct q));
        new->number = rand()%100;
        new->prev = current;
        current->next = new;
        current = new;
    }
    return(head);
}

REGTYPE* add_first(REGTYPE* head, int data){
    REGTYPE *new;
    new = (struct q*)malloc(sizeof(struct q));
    new->number = data;
    new->next = head;
    head->prev = new;
    return new;
    //Adds a record first i list and set the field tal to data
}