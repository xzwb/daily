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


// 获取栈队列长度
#define ListLength(l) ((l)->len)
// 获取当前结点的直接前驱
#define ListPrevNode(n) ((n)->prev)
// 获取当前结点的直接后继
#define ListNextNode(n) ((n)->next)
// 获取尾结点
#define ListLast(l) ((l)->tail)
// 获取头结点
#define ListHead(l) ((l)->head)


// 栈的创建
List *ListCreat(void);
// 栈清空
void ListEmpty(List *list);
// 栈销毁
void ListRelease(List *list);
// 入栈
void Pop(void *value, List *list);
// 出栈
void Push(List *list, void *value);

#endif
