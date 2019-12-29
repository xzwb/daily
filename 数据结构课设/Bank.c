#include "Bank.h"

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"


// 初始化用户数据
BankPerson *createPerson(int num, int vip) 
{
    BankPerson *bp = malloc(sizeof(BankPerson));
    bp->number = num;
    bp->vip = vip;

    return bp;
}

// 构造节点
Node *createNode(int num, int vip)
{
    BankPerson *bp = createPerson(num, vip);
    Node *node = malloc(sizeof(Node));
    node->data = bp;

    return node;
}
