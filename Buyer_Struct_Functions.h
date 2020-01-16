//
// Created by razvi on 12/17/2019.
//

#ifndef FOODSHOP_BUYER_STRUCT_FUNCTIONS_H
#define FOODSHOP_BUYER_STRUCT_FUNCTIONS_H

typedef struct _buyer{
    char *userName;
    char *userPassword;
} buyer ;

buyer createBuyer();
void getUserInfo(buyer *b);
void confirmOrder(int *contractSigned,int *state,buyer *b);
void printName(buyer *b);
void freeBuyer(buyer *b);

#endif //FOODSHOP_BUYER_STRUCT_FUNCTIONS_H
