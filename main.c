//To-do list
//free memory
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"
#include "StringFunctions.h"

#define MAX 200
#define MAX_TYPE_NAME 60
#define LOAD_DATA "Loading the data"
#define MAX_LENGTH 100
#define MAX_ACCOUNT_LENGTH 20

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
    char *userName=(char*)malloc(MAX_ACCOUNT_LENGTH* sizeof(char));
    char *userPassword=(char*)malloc(MAX_ACCOUNT_LENGTH* sizeof(char));
    char *comment=(char*)malloc(MAX_LENGTH* sizeof(char));
    char*token;
    char *str = (char *) malloc(MAX * sizeof(char));
    char *ptr;
    int noOfFoodTypes;
    FILE *data;
    if ((data = fopen("C:\\CP\\food-ordering\\data.txt", "r")) == NULL){
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    fgets(str,MAX,data);
    noOfFoodTypes=strtol(str,&ptr,10);       //get no of foods
    int * noOfSpecificFood = (int*)malloc(noOfFoodTypes * sizeof(int));
    char ** foodType;
    foodType = (char**)malloc(noOfFoodTypes * sizeof(char*));
    char *** specificFood = (char***)malloc(noOfFoodTypes * sizeof(char**));
    double ** specificFoodPrice = (double**)malloc(noOfFoodTypes * sizeof(double*));
    //reading specific food & specific food prices
    for(int i=0;i<noOfFoodTypes;i++) {
        foodType[i] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        fgets(str, MAX, data);
        noOfSpecificFood[i] = countCharacters(str,')');  //Read number of specific foods (it is = to the nr of ')' chars)
        specificFood[i] = (char **) malloc(noOfSpecificFood[i] * sizeof(char *));
        specificFoodPrice[i] = (double *) malloc(noOfSpecificFood[i] * sizeof(double));
        strncpy(foodType[i],str,getIndex(str,':'));
        int c=getIndex(str,' ');
        strncpy(foodType[i],str,c);
        foodType[i][c]='\0';
        for(int j=0;j<=noOfSpecificFood[i];j++){
            specificFood[i][j] = (char*)malloc(MAX_TYPE_NAME * sizeof(char));
            specificFood[i][j]=extract(str,"(","-");
            token=extract(str,"-",")");
            specificFoodPrice[i][j]=strtol(token,&ptr,10);
            removeString(str,2,getIndex(str,')'));
        }
    }
//read drinks & drink prices
    int noOfDrinks;
    fgets(str,MAX,data);
    noOfDrinks=strtol(str,&ptr,10);
    char **drink;
    double * drinkPrice = (double*)malloc(noOfDrinks * sizeof(double));
    drink = (char**)malloc(noOfDrinks * sizeof(char*));
    int * chosenAdditionalItems = (int*)malloc(noOfDrinks * sizeof(int));
    fgets(str, MAX, data);
    removeChar(str,',');

    for(int i=0; i < noOfDrinks; i++){
        drink[i]= (char*)malloc(MAX_TYPE_NAME * sizeof(char));
        drink[i]=extract(str,"(","-");
        token=extract(str,"-",")");
        drinkPrice[i]=strtol(token,&ptr,10);
        removeString(str,1,getIndex(str,')'));
        removeChar(drink[i],'(');
    }

    while(!contractSigned){
        switch (state) {
            case 0: {
                getUserInfo(userName, userPassword);
                state++;
                break;}
            case 1: {
                chooseFood(foodType,&state, &nrMenu, &FoodChoice);
                break;}
            case 2: {
                chooseMenu(foodType,specificFood,noOfSpecificFood,specificFoodPrice,nrMenu, FoodChoice, &state, &MenuChoice);
                break;}
            case 3: {
                printAdditionalItemsChoices(noOfDrinks,drink, drinkPrice);
                noAddItemsChosen = chooseAdditionalItems(&ok,noOfDrinks, chosenAdditionalItems, &state);
                break;}
            case 4:{
                askCutlery(&state, &cutleryChoice);
                break;}
            case 5: {
                additionalInfo(&state,comment);
                break;}
            case 6:{
                displayContractStep(&ok,specificFood,specificFoodPrice,drink,drinkPrice,userName, FoodChoice, MenuChoice, noAddItemsChosen, chosenAdditionalItems,cutleryChoice, &contractSigned, comment, &state);
                break;}
        }
    }
    freeMemory(userName,userPassword,comment,chosenAdditionalItems,noOfFoodTypes,noOfSpecificFood,specificFood,foodType,specificFoodPrice,noOfDrinks,drink,drinkPrice);
    fclose(data);
    return 0;
}
