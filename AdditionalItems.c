#include <stdio.h>
#define MAX_ADDITIONAL_ITEM_NAME 30
//
// Created by razvi on 11/4/2019.
//

void printAdditionalItemsChoices(int noOfDrinks, char** drinks, double* drinkPrice) {
    // Choose the additional items
    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", drinks[i], drinkPrice[i]);
    }
    printf("%c) No drink\n", 'a' + noOfDrinks);
    printf("%c) Go back\n", 'a' + noOfDrinks+1);
}

int chooseAdditionalItems(int* ok,int noOfDrinks, int* chosenAdditionalItems, int * state)
{
    int noAddItemsChosen = 0;
    int choice = getchar();
    if(choice == 'a' + noOfDrinks)
    {*ok=0;}
    if(choice == 'a' + noOfDrinks+1) {
        (*state)--;
                 //consume new line
        getchar();
    } else {
        noAddItemsChosen = 0;
        while (choice != '\n') {
            chosenAdditionalItems[noAddItemsChosen] = choice - 'a';
            noAddItemsChosen++;
            //read comma
            char comma = getchar();
            if (comma == '\n') {
                //after the last letter, a new line entered
                break;
            }
            choice = getchar();
        }
        (*state)++;
    }
    return noAddItemsChosen;
}