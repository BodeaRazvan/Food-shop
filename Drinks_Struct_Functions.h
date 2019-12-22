//
// Created by razvi on 12/21/2019.
//

#ifndef FOODSHOP_DRINKS_STRUCT_FUNCTIONS_H
#define FOODSHOP_DRINKS_STRUCT_FUNCTIONS_H

typedef struct _drinks{
    char **name;
    double *price;
}drinks;

drinks createDrinks(int noOfDrinks);
void printAdditionalItemsChoices(int noOfDrinks, drinks *d);
void extractDrinks(int noOfDrinks, drinks *d, char *str);
int calculateAdditionalPrice(int noAddItemsChosen,drinks*d,int* chosenAdditionalItems,int *ok);
void printDrinks(int *ok,int noAddItemsChosen,drinks*d,int*chosenAdditionalItems);
void freeDrinks(drinks *d,int noOfDrinks);
#endif //FOODSHOP_DRINKS_STRUCT_FUNCTIONS_H
