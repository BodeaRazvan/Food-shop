//
// Created by razvi on 11/29/2019.
//
#include <stdlib.h>
void freeMemory(char*userName,char*userPassword,char*comment,int* chosenAdditionalItems,int noOfFoodTypes,int* noOfSpecificFood,char*** specificFood, char** foodType,double** specificFoodPrice,int noOfDrinks,char** drink,double* drinkPrice){
    // free memory
    for(int i=0;i<noOfFoodTypes;i++){
        for(int j=0;j<noOfSpecificFood[i];j++){
            free(specificFood[i][j]);
        }
        free(foodType[i]);
    }
    free(specificFood);
    free(specificFoodPrice);
    free(foodType);
    free(noOfSpecificFood);
    for(int i=0;i< noOfDrinks;i++){
        free(drink[i]);
    }
    free(drink);
    free(drinkPrice);
    free(chosenAdditionalItems);
    free(chosenAdditionalItems);
    free(userName);
    free(userPassword);
    free(comment);
}

