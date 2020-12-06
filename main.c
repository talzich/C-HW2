#include <stdio.h>
#include "myBank.h"

int main(void){
  //int accounts[51][2] = {0};
  int run = 1;
  printf("Welcome to our bank!\n");
  while (run)
  {
    char action;
    printf("Here is a list of actions you can preform: \n"
          "O\t Open a new account\n"
          "B\t Check balance\n"
          "D\t Make a deposit\n"
          "W\t Make a withdrawl\n"
          "C\t Close your account\n"
          "I\t Add interest to all accounts\n"
          "P\t Get info of all accounts\n"
          "E\t Close all accounts and end this program\n");

    scanf("%s",&action);

    if(action == 'O') openAccount();
    else if(action == 'B') checkBalance();
    else if(action == 'D') deposit();
    else if(action == 'W') withdraw();
    else if(action == 'C') closeAccount();
    else if(action == 'I') interest();
    else if(action == 'P') print();
    else if(action == 'E') end();
    else
      {
        printf("No valid action was entered, try again!\n");
        run = 1;
        continue;
      }

    printf("Would you like to do anything else? (0 - No, 1 - Yes)\n");
    scanf("%d",&run);
  }
}
