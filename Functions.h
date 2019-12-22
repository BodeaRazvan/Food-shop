#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Drinks_Struct_Functions.h"
#include "SpecificFood_Struct_Functions.h"

//
// Created by razvi on 11/3/2019.
//

#ifndef FOODSHOP_FUNCTII_H
#define FOODSHOP_FUNCTII_H

void displayContractStep(specificFood *f,int *ok,drinks *d, int FoodChoice, int MenuChoice, int noAddItemsChosen, int *chosenAdditionalItems, int cutleryChoice, char *Comment);
int chooseAdditionalItems(int *ok,int noOfDrinks, int chosenAdditionalItems[], int * state);
void askCutlery(int *state, int *cutleryChoice);
void additionalInfo(int *state, char *comment);

#endif //FOODSHOP_FUNCTII_H