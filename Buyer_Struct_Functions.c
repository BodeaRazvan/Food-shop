//
// Created by razvi on 12/17/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include "Buyer_Struct_Functions.h"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LENGTH 100

buyer createBuyer(){
    buyer b;
    b.userName=(char*)malloc(MAX_USERNAME_LENGTH* sizeof(char));
    b.userPassword=(char*)malloc(MAX_PASSWORD_LENGTH* sizeof(char));
    return b;
}

void getUserInfo(buyer *b){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(b->userName);
    printf("---Password:\n");
    gets(b->userPassword);
}

void confirmOrder(int *contractSigned,int *state,buyer *b){
    printf("-------------\n");
    printf("Confirm your order?\n");
    printf("a) Sign\n");
    printf("b) Go back\n");
    int  choice = getchar();
    if(choice=='a') {
        *contractSigned = 1;
        printf("Order confirmed! Thank you for buying from us, %s!",b->userName);
    } else {
        (*state)--;
    }
    getchar();
}

void printName(buyer *b){
    printf("Name: %s\n",b->userName);
}

void freeBuyer(buyer *b){
    free(b->userName);
    free(b->userPassword);
    free(b);
}