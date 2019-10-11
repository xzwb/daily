#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

QueueList *QueueCreat(void)
{
    QueueList *list;
    if ((list = malloc(sizeof(*list))) == NULL) {
        exit(1);
    }
    list->len = 0;
    list->head = list->tail = NULL;

    return list;
}

void QueueEmpty(QueueList *list)
{
    Queue *now, *next;
    now = list->head;
    while (list->len--) {
        next = now->next;
        free(now->value);
        free(now);
        now = next;
    }
    list->head = list->tail = NULL;
    list->len = 0;
}

void QueueRelease(QueueList *list)
{
    QueueEmpty(list);
    free(list);
}

void EnQueue(void *value, QueueList *list)
{
    Queue *node;
    if ((node = malloc(sizeof(*node))) == NULL) {
        exit(1);
    }
    node->value = value;
    if (!list->len) {
        node->prev = node->next = NULL;
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        node->next = NULL;
        list->tail = node;
    }
    list->len++;
}

void *OutQueue(void *value, QueueList *list) {
    Queue *node = list->head->next;
    if (!list->len) {
        return value = NULL;
    } else {
        value = list->head->value;
        free(list->head);
        list->head = node;
        if (node) {
            node->prev = NULL;
        }
    }
    list->len--;

    return value;
}
