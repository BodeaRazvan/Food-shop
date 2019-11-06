#include <stdio.h>
#define MAX_FOOD_NAME 20
//
// Created by razvi on 11/5/2019.
//
void ChooseFood(int *state, int *nrMenu, int *FoodChoice){
    // Choose the food
    int var=0;
    int nrFood=3;
    char Food[][10] = {"Pizza","Pasta","Salad"};
    int choice;
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<nrFood;i++) {
        putchar('a'+i);
        printf(") %s\n",Food[i]);
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



void AskCutlery(int *state,int *cutleryChoice){*state=4;
    int nocutlery=2;
    char cutlery[][15]={"Yes","No,thanks!"};
    int choice;
    printf("Do you want cutlery?\n");
    for(int i=0;i<nocutlery;i++) {
        putchar('a'+i);
        printf(") %s\n",cutlery[i]);
    }
    printf("%c) Go back\n",'a'+nocutlery);
    choice = getchar();
    getchar();
    if(choice == 'a'+nocutlery) {
        (*state)--;
        (*state)--;
    }
    *cutleryChoice = choice - 'a';
    (*state)++;

}




void ChooseMenu(int nrMenu, int FoodChoice, int *state, int *MenuChoice ){
    // Choose the food type
    int FoodType[] = {3,3,4};
    char Food[][10] = {"Pizza","Pasta","Salad"};
    char Options[3][4][20] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita" },
            {"Chicken alfredo", "Mac&cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    double prices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21 }
    };
    printf("Please choose the type of %s\n",Food[FoodChoice]);
    for(int i=0;i<nrMenu;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",Options[FoodChoice][i], prices[FoodChoice][i]);
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