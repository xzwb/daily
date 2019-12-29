#ifndef _Queue_H
#define _Queue_H

// 双向链表实现队列
typedef struct Node {
    struct Node *next;
    struct Node *prev;
    // 队列的数据域
    void *data;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    // 队列的长度
    int len;
} Queue;

// 队列初始化
Queue *create();
// 队列出队
Node *del(Queue *queue);
// 队列入队
void add(Queue *queue, Node *node);
// 销毁队列
void release(Queue *queue);

#endif
