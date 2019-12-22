//
// Created by razvi on 11/5/2019.
//
#include <stdio.h>

void askCutlery(int *state, int *cutleryChoice){ *state=4;
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
