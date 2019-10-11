#ifndef _Queue_H
#define _Queue_H

typedef unsigned int Len;

typedef struct Queue {
    struct Queue *prev;
    struct Queue *next;
    void *value;
} Queue;

typedef struct QueueList {
    Queue *head;
    Queue *tail;
    Len len;
} QueueList;

// 获取队列长度
#define QueueLength(l) ((l)->len)
// 获取头结点
#define GetQueueHead(l) ((l)->head)
// 获取尾结点
#define GetQueueTail(l) ((l)->tail)
// 获取结点的直接前驱
#define GetNodePrev(n) ((n)->prev)
// 获取结点的直接后继
#define GetNodeNext(n) ((n)->next)

// 初始化一个队列
QueueList *QueueCreat(void);
// 将一个队列置空
void QueueEmpty(QueueList *list);
// 销毁队列
void QueueRelease(QueueList *list);
// 入队
void EnQueue(void *value, QueueList *list);
// 出队
void *OutQueue(void *value, QueueList *list);

#endif

