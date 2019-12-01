//
// Created by razvi on 11/29/2019.
//
#define MAX_LENGTH 100
#ifndef FOODSHOP_STRINGFUNCTIONS_H
#define FOODSHOP_STRINGFUNCTIONS_H

void removeChar(char *str, char garbage);
void removeString (char text[MAX_LENGTH], int index, int rm_length);
int countCharacters(const char *str, char character);
char *extract(const char *const string, const char *const left, const char *const right);
int getIndex(char* string, char c);

#endif //FOODSHOP_STRINGFUNCTIONS_H

