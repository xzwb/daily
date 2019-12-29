#ifndef _Bank_H
#define _Bank_H
#include "Queue.h"

typedef struct BankPerson {
    // 号码
    int number;
    // 是否vip
    int vip;
} BankPerson;

// 构造结点
Node *createNode(int num, int vip);
// 构造用户
BankPerson *createPerson(int num, int vip);

#endif
