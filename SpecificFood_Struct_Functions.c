//
// Created by razvi on 12/22/2019.
//
#include "SpecificFood_Struct_Functions.h"
#include "StringFunctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 200

specificFood createSpecificFoods(int noOfFoodTypes,char *str,FILE*data,int *noOfSpecificFood){
    specificFood f;
    char *ptr;
    f.foodType = (char**)malloc(noOfFoodTypes * sizeof(char*));
    f.specificFood= (char***)malloc(noOfFoodTypes * sizeof(char**));
    f.specificFoodPrice=(double**)malloc(noOfFoodTypes * sizeof(double*));
    for(int i=0;i<noOfFoodTypes;i++) {
        f.foodType[i] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        fgets(str, MAX, data);
        noOfSpecificFood[i] = countCharacters(str,')');  //Read number of specific foods (it is = to the nr of ')' chars
        f.specificFood[i] = (char **) malloc(noOfSpecificFood[i] * sizeof(char *));
        f.specificFoodPrice[i] = (double *) malloc(noOfSpecificFood[i] * sizeof(double));
        strncpy(f.foodType[i],str,getIndex(str,':'));
        int c=getIndex(str,' ');
        strncpy(f.foodType[i],str,c);
        f.foodType[i][c]='\0';
        for(int j=0;j<=noOfSpecificFood[i];j++){
            f.specificFood[i][j] = (char*)malloc(MAX_TYPE_NAME * sizeof(char));
            f.specificFood[i][j]=extract(str,"(","-");
            char *token=extract(str,"-",")");
            f.specificFoodPrice[i][j]=strtol(token,&ptr,10);
            removeString(str,2,getIndex(str,')'));
        }
    }
    return f;
}

void chooseFood(specificFood *f, int *state, int *nrMenu, int *FoodChoice){
    // Choose the food
    int var=0;
    int nrFood=3;
    int choice;
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<nrFood;i++) {
        putchar('a'+i);
        printf(") %s\n",f->foodType[i]);
    }
    printf("%c) Go back\n",'a'+nrFood);
    choice = getchar();
    getchar();
    if(choice == 'a'+nrFood) {
        var=1;
    }
    if (choice=='a')
        *nrMenu=3;
    if (choice=='b')
        *nrMenu=2;
    if (choice=='c')
        *nrMenu=4;
    if (var) {(*state)--;}
    else{*FoodChoice = choice - 'a';
        (*state)++;}

}

void chooseMenu(specificFood *f,int*FoodType,int nrMenu, int FoodChoice, int *state, int *MenuChoice ){
    // Choose the food type
    printf("Please choose the type of %s\n",f->foodType[FoodChoice]);
    for(int i=0;i<nrMenu;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",f->specificFood[FoodChoice][i], f->specificFoodPrice[FoodChoice][i]);
    }
    printf("%c) Go back\n",'a'+FoodType[FoodChoice]);
    int choice = getchar();
    getchar();
    if(choice == 'a'+FoodType[FoodChoice]) {
        (*state)--;
        (*state)--;
    }
    *MenuChoice = choice - 'a';
    (*state)++;
}

void freeSpecificFood(specificFood * f, int noOfFoodTypes, int *noOfSpecificFood) {
    for (int i = 0; i < noOfFoodTypes; i++) {
        for (int j = 0; j < noOfSpecificFood[i]; j++) {
            free(f->specificFood[i][j]);
        }
        free(f->specificFood[i]);
        free(f->specificFoodPrice[i]);
        free(f->foodType[i]);
    }
    free(f->foodType);
    free(f->specificFood);
    free(f->specificFoodPrice);
    free(f);
}