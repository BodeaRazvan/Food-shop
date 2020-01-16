//
// Created by razvi on 12/21/2019.
//
#include "Drinks_Struct_Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"

#define MAX_DRINK_NAME 30
#define MAX_TYPE_NAME 25

drinks createDrinks(int noOfDrinks){
    drinks d;
    d.name=(char**)malloc(noOfDrinks* sizeof(char*));
    for(int i=0; i < noOfDrinks; i++){
        d.name[i]=(char*)malloc(MAX_DRINK_NAME* sizeof(char));
    }
    d.price=(double*)malloc(noOfDrinks* sizeof(double));
    return d;
}
void extractDrinks(int noOfDrinks, drinks *d, char *str){
    char *ptr;
    for(int i=0; i < noOfDrinks; i++){
        d->name[i]=extract(str,"(","-");
       char* token=extract(str,"-",")");
        d->price[i]=strtol(token,&ptr,10);
        removeString(str,1,getIndex(str,')'));
        removeChar(d->name[i],'(');
    }
}
void printAdditionalItemsChoices(int noOfDrinks, drinks *d) {
    // Choose the additional items
    printf("Choose additional items (separated by comma)\n");
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s (%.2f)\n", d->name[i], d->price[i]);
    }
    printf("%c) No drink\n", 'a' + noOfDrinks);
    printf("%c) Go back\n", 'a' + noOfDrinks+1);
}

int calculateAdditionalPrice(int noAddItemsChosen,drinks*d,int* chosenAdditionalItems,int *ok){
 double additionalItemsPrice=0;
    if(*ok==1){
    for(int i=0;i<noAddItemsChosen;i++) {
        additionalItemsPrice += d->price[chosenAdditionalItems[i]];
    }}
else{additionalItemsPrice=0;
}
return additionalItemsPrice;
}

void printDrinks(int *ok,int noAddItemsChosen,drinks*d,int*chosenAdditionalItems){
    if(*ok==1){
        for(int i=0;i<noAddItemsChosen;i++) {
            printf("--%s (%.2f)\n", d->name[chosenAdditionalItems[i]], d->price[chosenAdditionalItems[i]]);
        }
    }
}

void freeDrinks(drinks *d,int noOfDrinks){
    for (int i = 0; i < noOfDrinks; i++) {
        free(d->name[i]);
    }
    free(d->name);
    free(d->price);
    free(d);
}