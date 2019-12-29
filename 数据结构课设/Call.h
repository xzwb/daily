#ifndef _Call_H
#define _Call_H
#include "Queue.h"

// 叫号函数 传入参数是空的柜台号和我的用户队列
void call(Queue *queue, int num);
// 取号函数传入参数是号码数和是否为vip
int give(Queue *queue, int num, int vip);
// 菜单
void menu();

#endif
