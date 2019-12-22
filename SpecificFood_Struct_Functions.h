//
// Created by razvi on 12/22/2019.
//

#ifndef FOODSHOP_SPECIFICFOOD_STRUCT_FUNCTIONS_H
#define FOODSHOP_SPECIFICFOOD_STRUCT_FUNCTIONS_H

#include <stdio.h>

#define MAX_TYPE_NAME 60

typedef struct _specificFood{
    char **foodType;
    char ***specificFood;
    double **specificFoodPrice;
}specificFood;

specificFood createSpecificFoods(int noOfFoodTypes,char *str,FILE*data,int *noOfSpecificFood);
void chooseFood(specificFood *f, int *state, int *nrMenu, int *FoodChoice);
void chooseMenu(specificFood *f,int*FoodType,int nrMenu, int FoodChoice, int *state, int *MenuChoice );
void freeSpecificFood(specificFood * f, int noOfFoodTypes, int *noOfSpecificFood);
#endif //FOODSHOP_SPECIFICFOOD_STRUCT_FUNCTIONS_H
