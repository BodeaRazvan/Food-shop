#include <stdio.h>
#define MAX_ADDITIONAL_ITEM_NAME 30

//
// Created by razvi on 11/4/2019.
//

void printAdditionalItemsChoices(int noAdditionalItems, char additionalItems[][MAX_ADDITIONAL_ITEM_NAME], double additionalItemsPrices[]) {

    // Choose the additional items

    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noAdditionalItems; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);
    }
    printf("%c) Go back\n", 'a' + noAdditionalItems);
}


int chooseAdditionalItems(int noAdditionalItems, int chosenAdditionalItems[], int * state)
{
    int noAddItemsChosen = 0;
    int choice = getchar();
    if(choice == 'a'+noAdditionalItems) {
        (*state)--;
        //consume new line
        getchar();
    } else {
        noAddItemsChosen = 0;
        while (choice != '\n') {
            chosenAdditionalItems[noAddItemsChosen] = choice - 'a';
            noAddItemsChosen++;
            //read comma
           int comma = getchar();
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