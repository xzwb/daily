// 括号匹配

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

#define TURE 0
#define FALSE -1

typedef struct {
    char bracket;
} LeftBracket;

int Judge(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) {
        return TURE;
    } else {
        return FALSE;
    }
}

int main()
{
    LeftBracket *bracket, *left;
    List *list;
    list = ListCreat();
    left = malloc(sizeof(LeftBracket));
    char str[1000];
    fgets(str, 1000, stdin);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            left->bracket = str[i];    
            Pop(left, list);
            left = malloc(sizeof(LeftBracket));
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (!list->len) {
                free(left);
                printf("不匹配!\n");
                return 0;
            }
            bracket = Push(list, bracket);
            if (!Judge(bracket->bracket, str[i])) {
                free(bracket);
            } else {
                free(bracket);
                ListRelease(list);
                free(left);   
                printf("不匹配!!\n");
                return 0;
            }
        }
        i++;
    }
    free(left);
    if (list->len) {
        printf("不匹配!!!\n");
        ListRelease(list);
    }

    return 0;
}
