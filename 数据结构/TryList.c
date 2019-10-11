#include <stdio.h>
#include <stdlib.h>

#include "List.h"

typedef struct {
    int a;
    double b;
    char c;
} Try;

int main()
{
    List *list;
    Try *try;
    Try *try1;
    list = ListCreat();
    try = malloc(sizeof(Try));
    try1 = malloc(sizeof(try1)); 
    try->a = 1;
    try->b = 2;
    try->c = 'a';
    Pop(try, list);
    try = malloc(sizeof(Try));
    try->a = 2;
    try->b = 3;
    try->c = 'b';
    Pop(try, list);
    try1 = Push(list, try1);
    printf("%d\n", try1->a);
    if (list->len == 1) {
        printf("sss\n");
    }
}
