#include <stdio.h>
#include "myBank.h"

#define SIZE 51
#define FIRST 901
#define LAST 950

int accounts[51][2] = {0};

int getAccount(){
  int accountNum;
  printf("Please enter account number (901-950)\n");
  scanf("%d",&accountNum);

  //If user entered illegal account number
  while(accountNum < 901 || accountNum > 950)
  {
    printf("Wrong input! Please enter account number (901-950)\n");
    scanf("%d",&accountNum);
  }
  return (accountNum-900);
}

int checkAccount(int account){
    return accounts[account-900][0];
}

/*
  This function takes no parameters and opens an account for the client if
  there is room for one (our bankj can hold up to 50 accounts).
  It allows the client to make an initial deposit, if he would like to.
*/
void openAccount(){
  int flag = 0;
  for (int i = 1; i < SIZE; i++)
  {
    //If there is a free spot in this row
    if(accounts[i][0] == 0)
      {
        int funds = accounts[i][1];

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
          scanf("%d",&funds);
        }

        //We found an open spot for the new account and client entered a valid sum
        accounts[i][0] = 1;
        accounts[i][1] = funds;

        printf("Congratulations!\nYour account number is: %d \nYour balance is: %d\n", (i + 900), funds);
        flag = 1;
        break;
      }
  }
  if(!flag)
    printf("No room for new account, try later.\n");
}

/*
  This function prints the current balance for the requested account
*/
void checkBalance(){
  int account = getAccount();
  if(checkAccount(account))
    printf("Your current balance is: %d\n",accounts[account][1]);
  else
    printf("This account is inactive\n");
}

void deposit(){
  return;
}

void withdraw(){
  return;
}

void closeAccount(){
  return;
}

void interest(){
  return;
}

void print(){
  return;
}
void end(){
  return;
}
