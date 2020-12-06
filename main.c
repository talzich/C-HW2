#include <stdio.h>
#include "myBank.h"

int main(void){
  printf("Welcome to our bank!\n");
  char action = ' ';
  while (action != EOF)
  {
    printf("\nHere is a list of actions you can preform:\n");
    printf("O\t Open a new account\n");
    printf("B\t Check balance\n");
    printf("D\t Make a deposit\n");
    printf("W\t Make a withdrawl\n");
    printf("C\t Close your account\n");
    printf("I\t Add interest to all accounts\n");
    printf("P\t Get info of all accounts\n");
    printf("E\t Close all accounts and end this program\n");

    scanf(" %c", &action);

    switch (action) {
           case 'O':
               openAccount(); break;
           case 'B':
               checkBalance(); break;
           case 'D':
               deposit(); break;
           case 'W':
               withdraw(); break;
           case 'C':
               closeAccount(); break;
           case 'I':
               interest(); break;
           case 'P':
               print(); break;
           case 'E':
               end();
           default:
               printf("Invalid action was entered\n"); break;
    }
  }
  return 0;
}
