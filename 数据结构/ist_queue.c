#include <stdio.h>
#include <stdlib.h>
#include "ist_queue.h"

Queue *queue_create()
{
    Queue *queue;
    queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        exit(-1);
    }
    queue->len = 0;
    queue->tail = queue->head = NULL;

    return queue;
}

int queue_enqueue(Queue *queue, void *data)
{
    Qnode *node = malloc(sizeof(Qnode));
    if (node == NULL) {
        exit(-1);
    }
    node->data = data;
    node->next = NULL;
    if (queue->head == NULL) {
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
    }
    queue->tail = node;
    queue->len++;

    return 0;
}

int queue_dequeue(Queue *queue, void **data)
{
    Qnode *node = NULL;
    if ((queue == NULL) || (data ==NULL) || queue_is_empty(queue)) {
        return -1;
    }
    *data = queue->head->data;
    node = queue->head;
    queue->head = queue->head->next;
    queue->len--;
    if (queue->head == NULL) {
        queue->tail ==NULL;
    }
    free(node);

    return 0;
}

