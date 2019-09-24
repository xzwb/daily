#include "List.h"

#include <stdio.h>
#include <stdlib.h>

List *ListCreat(void)
{
    struct List *list;
    
    if ((list = malloc(sizeof(*list))) == NULL) {
        exit(1);
    }

    list->head = list->tail = NULL;
    list->len = 0;

    return list;
}

void ListEmpty(List *list)
{
    unsigned long len;
    ListNode *current, *next;

    current = ListHead(list);
    len = ListLength(list);
    while (len--) {
        next = ListNextNode(current);
        free(current->value);
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    list->len = 0;
}

void ListRelease(List *list)
{
    ListEmpty(list);
    free(list);
}

void Pop(void *value, List *list)
{
    ListNode *node;
    
    if ((node = malloc(sizeof(*node))) == NULL) {
        exit(1);
    }

    if (!ListLength(list)) {
        node->prev = node->next = NULL;
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    list->tail->value = value;
    list->len++;
}

void Push(List *list, void *value)
{
    ListNode *node;
    if (!ListLength(list)) {
        value = NULL;
    } else {
        value = list->tail->value;
        if (--list->len) {
            node = ListPrevNode(list->tail);
            node->next = NULL;
            free(list->tail);
            list->tail = node;
        } else {
            ListEmpty(list);
        }
    }
}
