#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
// Created by razvi on 11/3/2019.
//
void getUserInfo(char *Username, char *Password){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(Username);
    printf("---Password:\n");
    gets(Password);
}

void additionalInfo(int *state, char *comment) {
    printf("Any additional info? (enter for no comment)\n");
    printf("c) Go back\n");
    gets(comment);
  if(comment[0]=='c'){
      (*state)--;
  }else{
      (*state)++;
  }
}


void displayContractStep(int *ok,char***specificFood,double**prices,char**drinks,double*drinkPrice,char *Username, int FoodChoice, int MenuChoice, int noAddItemsChosen, int *chosenAdditionalItems, int cutleryChoice, int *contractSigned, char *Comment, int *state){

    char v[][10]={"Yes","No"};
    printf("Name: %s\n",Username);
    printf("Food items:\n");
    printf("--%s (%.2f)\n", specificFood[FoodChoice][MenuChoice], prices[FoodChoice][MenuChoice]);
    double additionalItemsPrice = 0;
    if(*ok==1){
    for(int i=0;i<noAddItemsChosen;i++) {
        additionalItemsPrice += drinkPrice[chosenAdditionalItems[i]];
    }}
    else{additionalItemsPrice=0;

    }
    if(*ok==1){
        for(int i=0;i<noAddItemsChosen;i++) {
            printf("--%s (%.2f)\n", drinks[chosenAdditionalItems[i]], drinkPrice[chosenAdditionalItems[i]]);
        }
    }
    printf("Cutlery: %s\n",v[cutleryChoice]);
     if(strlen(Comment)!=0) {  printf("Additional info: %s\n", Comment);}
    printf("Total price: %.2f\n", prices[FoodChoice][MenuChoice] + additionalItemsPrice);
    printf("-------------\n");
    printf("Confirm your order?\n");
    printf("a) Sign\n");
    printf("b) Go back\n");
    int  choice = getchar();
    if(choice=='a') {
        *contractSigned = 1;
        printf("Order confirmed! Thank you for buying from us, %s!",Username);
    } else {
        (*state)--;
    }
    getchar();
}
