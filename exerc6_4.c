#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int program_time;   // The global time, start value 0

double get_time_ms(){
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

//-----Tread functions–--------------------------------------------
void *time_count(void *param) {
    double last_execution, current_time;
    last_execution = get_time_ms();
    while (program_time < 50){
        // Check system-time (get_time_ms())
        current_time = get_time_ms();
        if(current_time - last_execution >= 1000){
            program_time++; //Increase program_time by one every second.
            last_execution = get_time_ms();
        }

    }
    pthread_exit(0); // exit thread;
}

void *read_inport(void *param){
    double last_execution, current_time;
    last_execution = get_time_ms();
    while (program_time < 50){
        current_time = get_time_ms();
        if(current_time - last_execution >= 5000){ // Read Inport every 5 second.
            printf("Reading Inport now\n");
            last_execution = get_time_ms();
        }

        //( Simulate this just by print out a text : Reading Inport now)
    }
    pthread_exit(0);
}

//--------Function get_time_ms--------------------


int main(){

    program_time = 0;

    pthread_t count_id;
    pthread_t inport_id;
    // Start up the thread time_count
    pthread_create(&count_id, NULL, time_count, NULL);
    // Start up the thread read_in_port
    pthread_create(&inport_id, NULL, read_inport, NULL);

    double last_execution, current_time;

    last_execution = get_time_ms();

    while(program_time < 50){
        current_time = get_time_ms();
        //Print out system time every second.
        if(current_time - last_execution >= 1000){
            printf("%d\n", program_time);
            last_execution = get_time_ms();
        }
    }

    pthread_join(count_id, NULL);
    pthread_join(inport_id, NULL);

    return 0;
}