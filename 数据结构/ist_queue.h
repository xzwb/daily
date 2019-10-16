#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

typedef struct queue_node {
    void *data;
    struct queue_node *next;
} Qnode;

typedef struct list_queue {
    int len;
    Qnode *head;
    Qnode *tail;
} Queue;

#define queue_is_empty(queue) ((queue->len) == 0)

Queue *queue_create();
// 入队
int queue_enqueue(Queue *queue, void *data);
// 出队
int queue_dequeue(Queue *queue, void **data);

#endif
