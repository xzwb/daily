#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"

#define POP 0
#define PUSH 1

typedef struct Infix {
    char operator;
} Infix;

int Judge(char a, char b) 
{
    switch(a) {
        case '+':
                if (b == ')' || b == '+') {
                    return PUSH;
                } else {
                    return POP;
                }
        case '-':
                if (b == ')' || b == '-' || b == '+') {
                    return PUSH;
                } else {
                    return POP;
                }
        case '*':
                if (b == '+' || b == '-' || b == ')' || b == '*') {
                    return PUSH;
                } else {
                    return POP;
                }
        case '/':
                if (b == '+' || b == '-' || b == ')' || b == '/') {
                    return PUSH;
                } else {
                    return POP;
                }
        case '(':
                if (b == ')') {
                    return PUSH;
                } else {
                    return POP;
                }
        default:exit(1);
    }
}

int main()
{
    List *list;
    list = ListCreat();
    Infix *infix;
    infix = malloc(sizeof(Infix));
    Infix *result;
    char operator[20];
    fgets(operator, 20, stdin);
    int i = 0;
    while (operator[i] != '\0' && operator[i] != '\n') {
        if (operator[i] >= '0' && operator[i] <= '9') {
            printf("%c", operator[i]);
        } else {
            printf(" ");
            infix->operator = operator[i];
            if (list->len == 0) {
                Pop(infix, list);
                infix = malloc(sizeof(Infix));
            } else {
                result = GetTop(list);
                while (list->len != 0 && Judge(result->operator, infix->operator)) {
                    result = Push(list, result);
                    if (result->operator == '(') {
                       free(result);
                       break;
                    }
                    printf("%c ", result->operator);
                    free(result);
                    if (list->len != 0) {
                        result = GetTop(list);
                    }
                }
                if (infix->operator == ')') {
                    i++;
                    continue;
                } else {
                    Pop(infix, list);
                    infix = malloc(sizeof(Infix));
                }
            }
        }
        i++;
    }
    while (list->len != 0) {
        result = Push(list, result);
        printf("%c ", result->operator);
        free(result);
    }
    ListRelease(list);
    printf("\n");

    return 0;
}
