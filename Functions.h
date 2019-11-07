#include <stdio.h>
#define MAX_ADDITIONAL_ITEM_NAME 30

//
// Created by razvi on 11/3/2019.
//
#ifndef FOODSHOP_FUNCTII_H
#define FOODSHOP_FUNCTII_H


void ChooseMenu(int nrMenu, int FoodChoice, int *state, int *MenuChoice );
void DisplayContract(char Username[], int FoodChoice, int MenuChoice, int noAddItemsChosen,const int *chosenAdditionalItems, int cutleryChoice, int ok, int *contractSigned, char *Comment, int *state);
void ChooseFood(int *state, int *nrMenu, int *FoodChoice);
void GetUserInfo(char Username[],char Password[]);
void printAdditionalItemsChoices(int noAdditionalItems, char additionalItems[][MAX_ADDITIONAL_ITEM_NAME], double additionalItemsPrices[]);
int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int * state);
void AskCutlery(int *state,int *cutleryChoice);
void AdditionalInfo(int *state, int *ok,char *Comment);


#endif //FOODSHOP_FUNCTII_H
