/* *******************************
Program file : bit_manage_function.c
Peter Lundin / 2016-01-97
For test IO program function 

******************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void f_delay(int);
unsigned char random_inport( void);
void printport( int);


int main(){
	int nr;
	unsigned char port;
	srand(time(NULL));
	for ( nr=0; nr < 10; nr++){
	   port = random_inport();
	   printport( port);
	   f_delay(5);
	}
	return(0);
}


void f_delay( int tenth_sec){

   clock_t start_t, end_t;
   long int i;
   start_t = clock();
   do{
      for(i=0; i< 10000000; i++);
      end_t = clock();
   }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
   return;
}

unsigned char random_inport( void){
	unsigned char inport = 0;
	inport=  rand() % 256;
	return (inport);
}

void printport( int portvalue){
	int binchar[8], rest,j, i=0;
	rest = portvalue;
    while(rest!=0){
         binchar[i++]= rest % 2;
         rest = rest / 2;
    }
	// Fill to 8 bits 
    while( i<8){
		binchar[i++]=0;
	}
	// Print bits and at the end corresponding decimal value
    int pressed = binchar[7];
    for(j =i-1 ;j > -1;j--){
        if(pressed){
            printf("  %d",binchar[j]);
        }
    }
    if(pressed){
        printf(" --------Porten value = %X  \n", portvalue);
    }
}
	
	
	