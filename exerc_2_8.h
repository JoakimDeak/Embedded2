/* ====================================
File name: exerc_2_8.h
Date: 2020-02-06
Group nr 19
Members that contribute to the solutions
Kent Edström
Joakim Deak
Member not present at the demonstration time

Demonstration code:
====================================== */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>     


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int nimMain()
{
  int pile,			// This is how many coins we have
    player,			// Who is playing?
    n_coins;			// Number of coins taken
  
  srand( time(0) );		// Setup random

  printf("Welcome to NIM by big brain squad \n");
  
  pile = MAX_COINS;		// Set start values (= init)
  player = HUMAN;

  /* 
   *  Program main loop 
   */
  while( true ) {

    printf("There are %d  coins in the pile\n", pile );
    
    if( player == HUMAN ){
      n_coins = human_choice(pile);      
    }else{
      n_coins = computer_choice(pile);
      printf("- I took %d\n", n_coins);
    }
    pile -= n_coins;
    player = toggle( player );
      
    if( pile <= 1 ){
      break;
    }
  }
  /*
   * end main loop
   */
   
  write_winner( player );
  play_again();
 
  printf("Finished\n");

  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/


void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}

int human_choice(int pile){
    int choice = 0;
    printf("How many do you take? \n");

    scanf("%d", &choice);
    fflush(stdin);
    if(choice <= pile && choice > 0 && choice < 4){
        return choice;
    } else{
        printf("invalid number \n");
        human_choice(pile);
    }
}

int computer_choice(int pile){
    int choice = 0;
    if(pile > 4){
        return (rand() % (3 - 1 + 1)) + 1;
    } else {
        switch(pile){
            case 4:
                choice =3;
                break;
            case 3:
                choice = 2;
                break;
            case 2:
                choice = 1;
                break;
            case 1:
                choice = 1;
                write_winner(0);
                break;
        }
        return choice;
    }
}

void write_winner(int player ){
   if (player == 0){
       printf("The computer wins! \n");
   }
   else {
       printf("You win! \n");
   }
}

int play_again(){
    printf("Do you want to play again? Y/N \n");
    char answer;
    scanf("%c", &answer);
    fflush(stdin);
    if(answer == 'Y'){
        nimMain();
    } else if(answer != 'N'){
        printf("Invalid input \n");
        play_again();
    }
}

int toggle( int player ){
    if(player == 1){
        return 0;
    } else{
        return 1;
    }
}
