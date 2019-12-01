//
// Created by razvi on 11/29/2019.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int countCharacters(const char *str, char character)
{
    const char *p = str;
    int count = 0;

    do {
        if (*p == character)
            count++;
    } while (*(p++));

    return count;
}
int getIndex(char* string, char c) {
    char *e = strchr(string, c);
    if (e == NULL) {
        return -1;
    }
    return (int)(e - string);
}
char *extract(const char *const string, const char *const left, const char *const right)
{
    char  *head;
    char  *tail;
    size_t length;
    char  *result;

    if ((string == NULL) || (left == NULL) || (right == NULL))
        return NULL;
    length = strlen(left);
    head   = strstr(string, left);
    if (head == NULL)
        return NULL;
    head += length;
    tail  = strstr(head, right);
    if (tail == NULL)
        return tail;
    length = tail - head;
    result = malloc(1 + length);
    if (result == NULL)
        return NULL;
    result[length] = '\0';

    memcpy(result, head, length);
    return result;
}
void removeString (char text[MAX_LENGTH], int index, int rm_length)
{
    int i;

    for ( i = 0; i < index; ++i )
        if ( text[i] == '\0' )
            return;

    for ( ; i < index + rm_length; ++i )
        if ( text[i] == '\0' ) {
            text[index] = '\0';
            return;
        }

    do {
        text[i - rm_length] = text[i];
    } while ( text[i++] != '\0' );
}
void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

