#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ADDITIONAL_ITEM_NAME 30

//
// Created by razvi on 11/3/2019.
//

#ifndef FOODSHOP_FUNCTII_H
#define FOODSHOP_FUNCTII_H

void chooseMenu(char**Food,char***Options,int*FoodType,double**prices,int nrMenu, int FoodChoice, int *state, int *MenuChoice );
void displayContractStep(int *ok,char***specificFood,double**prices,char**drinks,double*drinkPrice,char *Username, int FoodChoice, int MenuChoice, int noAddItemsChosen, int *chosenAdditionalItems, int cutleryChoice, int *contractSigned, char *Comment, int *state);
void chooseFood(char** foodType, int *state, int *nrMenu, int *FoodChoice);
void getUserInfo(char *Username, char *Password);
void printAdditionalItemsChoices(int noOfDrinks, char** drinks, double* drinkPrice);
int chooseAdditionalItems(int *ok,int noOfDrinks, int chosenAdditionalItems[], int * state);
void askCutlery(int *state, int *cutleryChoice);
void additionalInfo(int *state, char *comment);
void freeMemory(char*userName,char*userPassword,char*comment,int* chosenAdditionalItems,int noOfFoodTypes,int* noOfSpecificFood,char*** specificFood, char** foodType,double** specificFoodPrice,int noOfDrinks,char** drink,double* drinkPrice);
#endif //FOODSHOP_FUNCTII_H
