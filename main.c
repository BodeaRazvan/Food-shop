#include <stdio.h>
int main() {
    printf("Welcome to our food shop!\n");

    // food data

    char Comment[100] ;

    int ok=0;

    int nrMenu;

    int nrFood = 3;

    char v[][10]={"Yes","No"};

    char Food[][10] = {"Pizza","Pasta","Salad"};

    int FoodType[] = {3,3,4};

    char Options[3][4][20] = {

            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita" },

            {"Chicken alfredo", "Mac&cheese"},

            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}

    };
    int nocutlery=2;
    char cutlery[][15]={"Yes","No,thanks!"};

    double prices[3][4] = {

            {21, 23, 19},

            {23, 21},

            {23, 22, 19, 21 }

    };

    int noAdditionalItems = 4;

    char additionalItems[][30] = {"Coca-cola","Fanta","Lipton","Water"};

    double additionalItemsPrices[] = {5, 5, 5, 4};

    //user input

    char Username[20];

    char Password[20];

    int choice, FoodChoice, MenuChoice,cutleryChoice;

    int noAddItemsChosen = 0;

    int chosenAdditionalItems[3];

    int state =0;

    int contractSigned = 0;

    while(!contractSigned){

        switch (state) {

            case 0: {

                // Input personal data

                printf("Please sign in to continue!\n");

                printf("---Username:\n");

                gets(Username);

                printf("---Password:\n");

                gets(Password);

                state++;

                break;

            }

            case 1: {

                // Choose the food

                printf("Please choose the food you feel like eating today:\n");

                for(int i=0;i<nrFood;i++) {

                    putchar('a'+i);

                    printf(") %s\n",Food[i]);

                }

                printf("%c) Go back\n",'a'+nrFood);

                choice = getchar();

                getchar();

                if(choice == 'a'+nrFood) {

                    state--;

                    break;

                }

                if (choice=='a')
                    nrMenu=3;
                    if (choice=='b')
                        nrMenu=2;
                        if (choice=='c')
                            nrMenu=4;

                FoodChoice = choice - 'a';

                state++;

                break;

            }

            case 2: {

                // Choose the food type

                printf("Please choose the type of %s\n",Food[FoodChoice]);

                for(int i=0;i<nrMenu;i++) {

                    putchar('a'+i);

                    printf(") %s (%.2f)\n",Options[FoodChoice][i], prices[FoodChoice][i]);

                }

                printf("%c) Go back\n",'a'+FoodType[FoodChoice]);

                choice = getchar();

                getchar();

                if(choice == 'a'+FoodType[FoodChoice]) {

                    state--;

                    break;

                }

                MenuChoice = choice - 'a';

                state++;

                break;

            }

            case 3: {

                // Choose the drink

                printf("Please choose a drink to go with your %s (separated by comma if more),(press enter to skip this)\n",Food[FoodChoice]);

                for(int i=0;i<noAdditionalItems;i++) {

                    putchar('a'+i);

                    printf(") %s (%.2f)\n", additionalItems[i], additionalItemsPrices[i]);

                }

                printf("%c) Go back\n",'a'+noAdditionalItems);

                //we want to check here for '\n' to allow the user to select 0 additional items

                choice = getchar();

                if(choice == 'a'+noAdditionalItems) {

                    state--;

                    getchar();

                    break;

                }

                noAddItemsChosen = 0;

                while (choice !='\n') {

                    chosenAdditionalItems[noAddItemsChosen] = choice - 'a';

                    noAddItemsChosen++;

                    char comma = getchar();

                    if(comma=='\n'){

                        break;

                    }

                    choice = getchar();

                }

                state++;

                break;

            }

            case 4:{
                //ask for cutlery
                printf("Do you want cutlery?\n");
                for(int i=0;i<nocutlery;i++) {

                    putchar('a'+i);

                    printf(") %s\n",cutlery[i]);

                }
                printf("%c) Go back\n",'a'+nocutlery);

                choice = getchar();

                getchar();

                if(choice == 'a'+nocutlery) {

                    state--;

                    break;

                }

                cutleryChoice = choice - 'a';

                state++;

                break;

            }

            case 5: {
                //additional information
                printf("Any additional info?\n");
                printf("%c) Yes\n", 'a');
                printf("%c) No\n", 'b');
                printf("%c) Go back\n", 'c');
                choice = getchar();

                getchar();

                if (choice == 'b')
                {state++;
                  ok=0;
                    break;
                }
                if(choice == 'c') {

                    state--;

                    break;

                }
                if(choice == 'a')
                { printf("Please write your additional information!\n");
                    gets(Comment);
                ok=1;
                state++;}

            }
            case 6:{

                // Display contract

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

                choice = getchar();

                if(choice=='a') {

                    contractSigned = 1;
                    printf("Order confirmed! Thank you for buying from us, %s!",Username);
                } else {

                    state--;

                }

                getchar();

                break;

            }

        }

    }

    return 0;

}