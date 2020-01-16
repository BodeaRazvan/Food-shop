//
// Created by razvi on 11/4/2019.
//
#include <stdio.h>

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