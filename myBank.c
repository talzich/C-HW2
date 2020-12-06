#include <stdio.h>
#include <stdlib.h>
#include "myBank.h"

#define SIZE 51
#define FIRST 901
#define LAST 950

int accounts[51][2];// = {0};

/*
  We will use this function before every action to get the account the user
  wants to work with
*/
int getAccount(){
  int accountNum;
  printf("Please enter account number (901-950)\n");
  if(scanf("%d",&accountNum) != 1)
    {
      printf("Invalid input, exiting program\n");
      exit(0);
    }

  //If user entered illegal account number
  while(accountNum < FIRST || accountNum > LAST)
  {
    printf("Wrong input! Please enter account number (901-950)\n");
    scanf("%d",&accountNum);
  }
  return (accountNum-900);
}

//Checks if the account is active, returns 1 if yes and 0 if no
int checkAccount(int account){
    return accounts[account][0];
}

/*
  This function takes no parameters and opens an account for the client if
  there is room for one (our bankj can hold up to 50 accounts).
  It allows the client to make an initial deposit, if he would like to.
*/
void openAccount(){
  int flag = 0;
  int funds;
  printf("How much would you like to deposit?\n");
  if (scanf(" %d",&funds) != 1)
    printf("Wrong input!\n");

  else if(funds < 0)
  {
    printf("Wrong input!\n");
  }
  else{
  for (int i = 1; i < SIZE; i++)
  {
    //If there is a free spot in this row
    if(accounts[i][0] == 0)
      {
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

/*
  This function allows the user to deposit funds into their account. Only
  non negative amounts will be valid.
*/
void deposit(){
  int accountNum = getAccount();
  if(checkAccount(accountNum))
  {
    int funds;
    printf("How much would you like to deposit?\n");
    if(scanf("%d",&funds) != 1) return;
    else if(funds >= 0)
    {
      accounts[accountNum][1] += funds;
      printf("%d has been added to your account\n",funds);
    }
    else
      printf("Invalid ammount, try again\n");
  }
  else
    printf("This account is inactive\n");
}

/*
  This function allows the user to withdraw funds from his account, if it has
  enough funds in it.
*/
void withdraw(){
  int account = getAccount();
  if(checkAccount(account))
  {
    //The amount client would like to withdraw
    int sum;

    int balance = accounts[account][1];

    printf("How much would you like to withdraw?\n");
    if(scanf("%d",&sum) != 1)
      return;

    //If there are no sufficient funds in this account
    if(sum > balance)
    {
      printf("You can not withdraw this sum from your account because you do not have sufficient funds\n");
    }

    else
    {
      accounts[account][1] = (accounts[account][1] - sum);
      printf("You have withdrawn the requested sum and your balance is now: %d\n", accounts[account][1]);
    }
  }
  else printf("This account is inactive\n");
}

/*
  This function allows the user to close his account
*/
void closeAccount(){
  int account = getAccount();
  if(checkAccount(account))
  {
    accounts[account][0] = 0;
    accounts[account][1] = 0;
    printf("Your account was closed and all funds have been withdrawn. Thank you\n");
  }
  else printf("This account is inactive\n");
}

void interest(){
  int interest;
  printf("Please enter interest rate\n");
  scanf("%d",&interest);
  if(interest < 0 || interest > 100)
    printf("Invalid interest rate\n");
  else
  {
    for (int i = 0; i < SIZE; i++)
    {
      if(accounts[i][0] == 1)
      {
        accounts[i][1] += accounts[i][1]*(interest/100.0);
      }
    }
  }
}

/*
  This function prints the balance for all active accounts
*/
void print(){
  for (int i = 1; i < SIZE; i++) {
    if(accounts[i][0] == 1)
      printf("Account %d balance: %d\n",i+900, accounts[i][1]);
  }
}

/*
  This function zeros all values in the matrix representing the bank.
*/
void end(){
  for (int i = 1; i < SIZE; i++) {
    accounts[i][0] = 0;
    accounts[i][1] = 0;
  }
  printf("All accounts has been closed\n");
  exit(0);
}
