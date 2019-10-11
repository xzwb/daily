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

    current = list->head;
    len = list->len;
    while (len--) {
        next = current->next;
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

    if (!list->len) {
        node->prev = node->next = NULL;
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    node->value = value;
    list->len++;
}

void *Push(List *list, void *value)
{
    ListNode *node;
    if (!list->len) {
        value = NULL;
    } else {
        value = list->tail->value;
        if (--list->len) {
            node = list->tail->prev;
            node->next = NULL;
            free(list->tail);
            list->tail = node;
        } else {
            free(list->tail);
            list->head = list->tail = NULL;
        }
    }

    return value;
}

void *GetTop(List *list)
{
    return list->tail->value;
}
