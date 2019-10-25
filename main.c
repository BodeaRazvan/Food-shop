#include <stdio.h>

int main() {
    char firstName[25];
    char lastName[25];
    char phoneNumber[15];
    char address[30];
    printf("Welcome to our Food Shop!\n");
    printf("Please input your data\n");
    printf("---First name:\n");
    gets(firstName);
    printf("---Last name:\n");
    gets(lastName);
    printf("---Phone number\n");
    gets(phoneNumber);
    printf("---Address\n");
    gets(address);

    int FoodMenu;
    char type[15];
    char types[][15] = {"Sides","Main Dishes","Pizza","Soups","Drinks","Desserts"};
    printf("Please choose the food type\n");
    for(int i=0;i<6;i++) {
        putchar('a'+i);
        printf(") %s\n",types[i]);
    }
    char choice = getchar();
    int foodChoice = choice - 'a';
    printf("Chosen food type is %s\n",types[foodChoice]);
    return 0;
}