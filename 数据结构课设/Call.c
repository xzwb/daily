#include "Call.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Queue.h"
#include "Bank.h"

void call(Queue *queue, int num)
{
    Node *node = del(queue);
    if (node) {
        printf("请%d号顾客到%d号窗口办理！！！\n", ((BankPerson *)(node->data))->number, num);
        sleep(1);
        printf("请%d号顾客到%d号窗口办理！！！\n", ((BankPerson *)(node->data))->number, num);
        sleep(1);
        printf("请%d号顾客到%d号窗口办理！！！\n", ((BankPerson *)(node->data))->number, num);
        free(node->data);
        free(node);
    } else {
        printf("现在没有人在等待！！！\n");
    }
}

int give(Queue *queue, int num, int vip) 
{
    Node *node = createNode(num, vip);
    add(queue, node);

    return num;
}

void menu() 
{
    printf("\033c");
    printf("*************银行取号***************\n");
    printf("**                                **\n");
    printf("**         1. 普通取号            **\n");
    printf("**         2. vip取号             **\n");
    printf("**         3. 柜台叫号            **\n");
    printf("**         4. 系统退出            **\n");
    printf("**                                **\n");
    printf("************************************\n");
    printf("\n请选择你需要的业务:\n");
}
