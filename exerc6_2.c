/* ====================================
File name: exerc6_2.c
Date: 2020-03-01
Group nr 19
Members that contribute to the solutions
Joakim Deak
Kent Edström
Member not present at the demonstration time

Demonstration code: 41580
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sort(void * param);
void *find(void *param);

int main() {
	time_t t;
	pthread_t runner_id;
    pthread_t sort_id;
    pthread_t find_id;
	
	srand((unsigned) time(&t));

	printf("Enter max value\n");
	scanf("%d", &max_value);

	pthread_create(&runner_id, NULL, runner, NULL);
	pthread_join(runner_id, NULL);

	pthread_create(&sort_id, NULL, sort, NULL);
	pthread_join(sort_id, NULL);

	pthread_create(&find_id, NULL, find, NULL);
	pthread_join(find_id, NULL);

	return 0;
}

void *find(void *param){
    int search;
    printf("Enter value to find\n");
    scanf("%d", &search);
    printf("Finding element\n");

    int first = 0;
    int last = num_elems - 1;
    int middle = (first + last) / 2;
    int n;
    for(n=0; n<num_elems; n++){
        printf("\n %d", array[n]);
    }

    while (first <= last) {
        if (array[middle] < search){
            first = middle + 1;
        }
        else if (array[middle] == search) {
            printf("\n %d found at location %d.\n", search, middle + 1);
            break;
        } else{
            last = middle - 1;
        }

        middle = (first + last) / 2;
    }
    if (first > last){
        printf("\n Not found! %d is not present in the list.\n", search);
    }
    pthread_exit(0);
}

void *sort(void *param){
    printf("Sorting list\n");
    int c, d, swap;

    for (c = 0; c < num_elems; c++) {
        for (d = 0; d < num_elems - c - 1; d++) {
            if (array[d] > array[d + 1]) {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    pthread_exit(0);
}

void *runner(void *param) {
    printf("Filling list\n");
	int c = 0, n=0;

	for (c = 0; c < num_elems; c++) {
		for(n=0; n<1000; n++); // To delay a bit 
		array[c] = rand() % max_value;
	}

	pthread_exit(0);
}
