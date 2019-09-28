#ifndef _List_H
#define _List_H

typedef struct ListNode {
    struct ListNode *prev;
    struct ListNode *next;
    void *value;
} ListNode;

typedef struct List {
    ListNode *head;
    ListNode *tail;
    unsigned long len;
} List;

// 栈的创建
List *ListCreat(void);
// 栈清空
void ListEmpty(List *list);
// 栈销毁
void ListRelease(List *list);
// 入栈
void Pop(void *value, List *list);
// 出栈
void *Push(List *list, void *value);
// 获取栈顶元素
void *GetTop(List *list);

#endif
