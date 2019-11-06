#include <stdio.h>
//
// Created by razvi on 11/3/2019.
//

void GetUserInfo(char Username[],char Password[]){
    printf("Please sign in to continue!\n");

    printf("---Username:\n");

    gets(Username);

    printf("---Password:\n");

    gets(Password);

}




void AdditionalInfo(int *state, int *ok,char *Comment){
    int choice;
    //additional information
    printf("Any additional info?\n");
    printf("%c) Yes\n", 'a');
    printf("%c) No\n", 'b');
    printf("%c) Go back\n", 'c');
    choice = getchar();
    getchar();
    if (choice == 'b')
    {(*state)++;
        *ok=0;
    }
    if(choice == 'c') {
        (*state)--;
    }
    if(choice == 'a')
    { printf("Please write your additional information!\n");
        gets(Comment);
        *ok=1;
        (*state)++;}
}




void DisplayContract(char Username[], int FoodChoice, int MenuChoice, int noAddItemsChosen, const int *chosenAdditionalItems, int cutleryChoice, int ok, int *contractSigned, char *Comment, int *state){
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
    char v[][10]={"Yes","No"};
    char additionalItems[][30] = {"Coca-cola","Fanta","Lipton","Water"};
    double additionalItemsPrices[] = {5, 5, 5, 4};
    printf("Name: %s\n",Username);
    printf("Food items:\n");
    printf("--%s (%.2f)\n", Options[FoodChoice][MenuChoice], prices[FoodChoice][MenuChoice]);
    double additionalItemsPrice = 0;
    for(int i=0;i<noAddItemsChosen;i++) {
        additionalItemsPrice += additionalItemsPrices[chosenAdditionalItems[i]];
    }
    if(noAddItemsChosen!=0){
        for(int i=0;i<noAddItemsChosen;i++) {
            printf("--%s (%.2f)\n", additionalItems[chosenAdditionalItems[i]], additionalItemsPrices[chosenAdditionalItems[i]]);
        }

    }
    printf("Cutlery: %s\n",v[cutleryChoice]);

    if(ok) printf("Additional info: %s\n",Comment);

    printf("Total price: %.2f\n", prices[FoodChoice][MenuChoice] + additionalItemsPrice);

    printf("-------------\n");

    printf("a) Sign\n");

    printf("b) Go back\n");

    int  choice = getchar();

    if(choice=='a') {

        *contractSigned = 1;
        printf("Order confirmed! Thank you for buying from us, %s!",Username);
    } else {

        (*state)--;

    }

    getchar();

}