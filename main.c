//To-do list
//Enjoy the holidays and learn LD
//
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "StringFunctions.h"
#include "Buyer_Struct_Functions.h"
#include "Drinks_Struct_Functions.h"

#define MAX 200
#define MAX_TYPE_NAME 60
#define LOAD_DATA "Loading the data"
#define MAX_LENGTH 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define FILE_PATH "../data.txt"

int main() {
    printf("%s\n",LOAD_DATA);
    printf("Welcome to our food shop!\n");
    int nrMenu=0;
    //user input
    int FoodChoice=0, MenuChoice=0,cutleryChoice=0;
    int noAddItemsChosen = 0;
    int state =0;
    int ok=1;
    int contractSigned = 0;
    char *comment=(char*)malloc(MAX_LENGTH* sizeof(char));
    char *str = (char *) malloc(MAX * sizeof(char));
    char *ptr;
    int noOfFoodTypes;
    FILE *data;
    if ((data = fopen(FILE_PATH, "r")) == NULL){
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    fgets(str,MAX,data);
    noOfFoodTypes=strtol(str,&ptr,10);       //get no of foods
    int * noOfSpecificFood = (int*)malloc(noOfFoodTypes * sizeof(int));
    //create specific food structure f
    specificFood f= createSpecificFoods( noOfFoodTypes,str,data,noOfSpecificFood);
    //read no of drinks
    int noOfDrinks;
    fgets(str,MAX,data);
    noOfDrinks=strtol(str,&ptr,10);
    int * chosenAdditionalItems = (int*)malloc(noOfDrinks * sizeof(int));
    fgets(str, MAX, data);
    removeChar(str,',');
    //create drinks structure d
    drinks d =createDrinks(noOfDrinks);
    extractDrinks(noOfDrinks, &d, str);
    //create buyer structure b
    buyer b = createBuyer();
    enum state {INPUT_CUSTOMER_DATA,CHOOSE_FOOD,CHOOSE_SPECIFIC_FOOD,CHOOSE_DRINKS,ASK_CUTLERY,COMMENT,PRINT_ORDER_CONTRACT};
    while(!contractSigned){
        switch (state) {
            case INPUT_CUSTOMER_DATA: {
                getUserInfo(&b);
                state++;
                break;}
            case CHOOSE_FOOD: {
                chooseFood(&f,&state, &nrMenu, &FoodChoice);
                break;}
            case CHOOSE_SPECIFIC_FOOD: {
                chooseMenu( &f,noOfSpecificFood, nrMenu,  FoodChoice,&state,&MenuChoice );
                break;}
            case CHOOSE_DRINKS: {
                printAdditionalItemsChoices(noOfDrinks,&d);
                noAddItemsChosen = chooseAdditionalItems(&ok,noOfDrinks, chosenAdditionalItems, &state);
                break;}
            case ASK_CUTLERY:{
                askCutlery(&state, &cutleryChoice);
                break;}
            case COMMENT: {
                additionalInfo(&state,comment);
                break;}
            case PRINT_ORDER_CONTRACT:{
                printName(&b);
                displayContractStep(&f,&ok,&d, FoodChoice, MenuChoice, noAddItemsChosen, chosenAdditionalItems,cutleryChoice, comment);
                confirmOrder(&contractSigned,&state,&b);
                break;}
        }
    }
    freeBuyer(&b);
    freeSpecificFood(& f, noOfFoodTypes,noOfSpecificFood);
    freeDrinks(&d,noOfDrinks);
    free(comment);
    free(str);
    fclose(data);
    free(noOfSpecificFood);
    free(chosenAdditionalItems);
    return 0;
}

