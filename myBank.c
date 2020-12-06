#include <stdio.h>

define SIZE 51;

accounts = {{0}, {0}};

/*
  This function takes no parameters and opens an account for the client if
  there is room for one (our bankj can hold up to 50 accounts).
  It allows the client to make an initial deposit, if he would like to.
*/
void openAccount(){
  int funds;
  for (int i = 1; i < SIZE; i++)
  {
    //If there is a free spot in this row
    if(accounts[i][0] == 0)
      {
        //If the new client would like to make a deposit
        printf("Initial deposit? Enter 0 if you don't want to make a deposit now\n");
        printf("Otherwise, enter the sum you would like to deposit\n");
        scanf("%d",&funds);

        //If the client entered a negative sum to deposit
        while(funds < 0)
        {
          printf("Invalid sum entered!\n");
          printf("Enter 0 if you don't want to make a deposit now\n");
          printf("Otherwise, enter the sum you would like to deposit\n");
        }

        //We found an open spot for the new account and client entered a valid sum
        accounts[i][0] = 1;
        accounts[i][1] = funds;

        printf("Congratulations! Your account number is: %d and your balance is: %d\n", (i + 900), funds);
        break;
      }
  }
  printf("No room for new account, try later\n");
}
