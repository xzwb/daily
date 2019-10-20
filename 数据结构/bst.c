#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

BST *MakeEmpty(BST *tree)
{
    if (tree != NULL) {
        MakeEmpty(tree->lchild);
        MakeEmpty(tree->rchild);
        free(tree);
    }

    return NULL;
}

Tnode *Find(int x, BST *tree)
{
    if (tree == NULL) {
        return NULL;
    }
    if (x > tree->data) {
        return Find(x, tree->rchild);
    } else if (x < tree->data) {
        return Find(x, tree->lchild);
    } else {
        return tree;
    }
}

Tnode *FindMin(BST *tree)
{
    if (tree == NULL) {
        return NULL;
    } else if (tree->lchild == NULL) {
        return tree;
    } else {
        return FindMin(tree->lchild);
    }
}

Tnode *FindMax(BST *tree) 
{
    if (tree == NULL) {
        return NULL;
    } else if (tree->rchild == NULL) {
        return tree;
    } else {
        return FindMax(tree->rchild);
    }
}

BST *Insert(int x, BST *tree) 
{
    if (tree == NULL) {
        tree = malloc(sizeof(BST));
        tree->data = x;
        tree->lchild = tree->rchild = NULL;
    } else if (x < tree->data) {
        tree->lchild = Insert(x, tree->lchild);
    } else if (x > tree->data) {
        tree->rchild = Insert(x, tree->rchild);
    }

    return tree;
}


