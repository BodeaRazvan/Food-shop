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
    return 0;
}