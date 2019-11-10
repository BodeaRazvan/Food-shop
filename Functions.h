#include <stdio.h>
#define MAX_ADDITIONAL_ITEM_NAME 30

//
// Created by razvi on 11/3/2019.
//

#ifndef FOODSHOP_FUNCTII_H
#define FOODSHOP_FUNCTII_H

void chooseMenu(int nrMenu, int FoodChoice, int *state, int *MenuChoice );
void contractStep(char *Username, int FoodChoice, int MenuChoice, int noAddItemsChosen, int *chosenAdditionalItems, int cutleryChoice, int ok, int *contractSigned, char *Comment, int *state);
void chooseFood(int *state, int *nrMenu, int *FoodChoice);
void getUserInfo(char *Username, char *Password);
void printAdditionalItemsChoices(int noAdditionalItems, char additionalItems[][MAX_ADDITIONAL_ITEM_NAME], double additionalItemsPrices[]);
int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int * state);
void askCutlery(int *state, int *cutleryChoice);
void additionalInfo(int *state, int *ok, char *Comment);

#endif //FOODSHOP_FUNCTII_H