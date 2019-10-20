#ifndef _BST_H
#define _BST_H

typedef struct BST { 
    int data;
    struct BST *lchild;
    struct BST *rchild;
} BST, Tnode;

// 置空一个树
BST *MakeEmpty(BST *tree);
// 找到一棵树
Tnode *Find(int x, BST *tree);
// 找到最小的节点
Tnode *FindMin(BST *tree);
// 找到最大的节点
Tnode *FindMax(BST *tree);
// 插入一个节点
BST *Insert(int x, BST *tree);

#endif


