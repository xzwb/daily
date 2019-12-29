#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "Bank.h"

// 队列初始化
Queue *create()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = queue->tail = NULL;
    queue->len = 0;

    return queue;
}

// 队列出队
Node *del(Queue *queue)
{
    if (queue->head == NULL) {
        return NULL;
    }
    Node *node = queue->head;
    Node *temp;
    while (((BankPerson *)(node->data))->vip != 1 && node->next != NULL) {
        node = node->next;
    }
    if (((BankPerson *)(node->data))->vip == 1) {
        if (node->next != NULL) {
            temp = node->prev;
            temp->next = node->next;
            temp->next->prev = temp;
        } else {
            node->prev->next = NULL;
        }
    } else {
        node = queue->head;
        queue->head = node->next;
    }
    queue->len--;

    return node;
}

// 队列入队
void add(Queue *queue, Node *node)
{
    if (node == NULL) {
        return;
    }
    if (queue->head == NULL) {
        node->prev = node->next = NULL;
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
        node->prev = queue->tail;
        node->next = NULL;
        queue->tail = node;
    }
    queue->len++;
}

// 销毁队列
void release(Queue *queue) {
    Node *node;
    while (queue->len != 0) {
        node = queue->head;
        queue->head = node->next;
        free(node->data);
        free(node);
        queue->len--;
    }
    free(queue);
}

