#include <stdio.h>
#include "Functions.h"

int main() {
    printf("Welcome to our food shop!\n");
    // food data
    char Comment[100] ;
    int ok=0;
    int nrMenu=0;
    int noAdditionalItems = 4;
    char additionalItems[][30] = {"Coca-cola","Fanta","Lipton","Water"};
    double additionalItemsPrices[] = {5, 5, 5, 4};
    //user input
    char Username[20];
    char Password[20];
    int FoodChoice=0, MenuChoice=0,cutleryChoice=0;
    int noAddItemsChosen = 0;
    int chosenAdditionalItems[3];
    int state =0;
    int contractSigned = 0;

    while(!contractSigned){
        switch (state) {
            case 0: {
                GetUserInfo(Username,Password);
                state++;
                break;}
            case 1: {
                ChooseFood(&state, &nrMenu, &FoodChoice);
                break;}
            case 2: {
                ChooseMenu( nrMenu, FoodChoice, &state, &MenuChoice );
                break;}
            case 3: {
                printAdditionalItemsChoices(noAdditionalItems,additionalItems,  additionalItemsPrices);
                noAddItemsChosen = chooseAdditionalItems(noAdditionalItems, chosenAdditionalItems, &state);
                break;}
            case 4:{
                AskCutlery( &state,&cutleryChoice);
                break;}
            case 5: {
                AdditionalInfo( &state, &ok, Comment);
                break;}
            case 6:{
                DisplayContract(Username, FoodChoice, MenuChoice, noAddItemsChosen, chosenAdditionalItems, cutleryChoice, ok, &contractSigned, Comment, &state);
                break;}
        }
    }
    return 0;
}