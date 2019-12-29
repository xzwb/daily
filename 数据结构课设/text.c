#include <stdio.h>
#include <stdlib.h>

#include "Bank.h"
#include "Queue.h"

int main() 
{
    Queue *queue = create();
    Node *node = createNode(1, 0);
    add(queue, node);
    node = createNode(2, 0);
    add(queue, node);
    node = createNode(3, 1);
    add(queue, node);
    Node *node1 = del(queue);
    printf("%d %d\n", ((BankPerson *)(node1->data))->vip, ((BankPerson*)(node1->data))->number);
    free(node1);
    node1 = del(queue);
    printf("%d %d\n", ((BankPerson *)(node1->data))->vip, ((BankPerson*)(node1->data))->number);
    free(node1);
    node1 = del(queue);
    printf("%d %d\n", ((BankPerson *)(node1->data))->vip, ((BankPerson*)(node1->data))->number);
    free(node1);
    release(queue); 
}
