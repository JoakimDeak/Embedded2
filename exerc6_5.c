#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t count_mutex   = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  not_empty   = PTHREAD_COND_INITIALIZER;
pthread_cond_t  not_full   = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
#define MAX 10//buffer size
char  letter = 'a'; //the starting letter
unsigned short count = 0;
char buffer[MAX]; // circular buffer
int inpos = 0; // index for next character to be put in buffer (put)
int outpos = 0; // index for next character to be read ( fetch )

void delay(){
    sleep(1);
}

void *put(){
    int r;

    while(1){
        delay();
        if ((r = pthread_mutex_lock (&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }

        if(count != 0){
            pthread_cond_wait(&not_full, &count_mutex);
        }

        printf("Buffer store");
        buffer[inpos] = letter;

        if (letter == 'z'){
            letter = 'a';
        } else{
            letter++;
        }
        if(inpos < MAX - 1){
            inpos++;
        } else{

            inpos = 0;
        }
        count++;
        pthread_cond_signal(&not_empty);

        pthread_mutex_unlock(&count_mutex);

    }

}

void *fetch(){
    int r;

    while(1){
        delay();
        if ((r = pthread_mutex_lock (&count_mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }

        if(count == 0) {
            pthread_cond_wait(&not_empty, &count_mutex);
        }

        printf("Buffer output : %c\n", buffer[outpos]);

        if(outpos < MAX - 1){
            outpos++;
        } else{
            outpos = 0;
        }

        count--;

        pthread_cond_signal(&not_full);

        pthread_mutex_unlock(&count_mutex);

    }

}

int main(){
    pthread_t putThread, fetchThread;
    pthread_create(&putThread, NULL, put, NULL);
    pthread_create(&fetchThread, NULL, fetch, NULL);

    while(1){
        delay();
        printf("Main is executing\n");
    }
}
