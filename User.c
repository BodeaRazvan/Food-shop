#include <stdio.h>
#include <string.h>
#include "Drinks_Struct_Functions.h"
#include "SpecificFood_Struct_Functions.h"
//
// Created by razvi on 11/3/2019.
//

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

void displayContractStep(specificFood *f,int *ok,drinks *d, int FoodChoice, int MenuChoice, int noAddItemsChosen, int *chosenAdditionalItems, int cutleryChoice, char *Comment){
    char v[][10]={"Yes","No"};
    printf("Food items:\n");
    printf("--%s (%.2f)\n", f->specificFood[FoodChoice][MenuChoice], f->specificFoodPrice[FoodChoice][MenuChoice]);
    int price= calculateAdditionalPrice(noAddItemsChosen,d,chosenAdditionalItems,ok);
    printDrinks(ok,noAddItemsChosen,d,chosenAdditionalItems);
    printf("Cutlery: %s\n",v[cutleryChoice]);
     if(strlen(Comment)!=0) {  printf("Additional info: %s\n", Comment);}
    printf("Total price: %.2f\n", f->specificFoodPrice[FoodChoice][MenuChoice] + price);

}