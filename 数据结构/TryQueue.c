#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

typedef struct {
    int a;
} Try;

int main()
{
    QueueList *list;
    Try *try;
    Try *try1;
    try = malloc(sizeof(Try));
    list = QueueCreat();
    try->a = 2;
    EnQueue(try, list);
    try1 = OutQueue(try1, list);

    printf("%d\n", try1->a);
}
