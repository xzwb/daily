#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "ist_queue.h"

void binarytree_create(Tree **root)
{
    int a = 0;
    printf("\n输入结点数值(当输入为100时,当前结点创建完成)");
    scanf("%d", &a);
    if (a == 100) {
        *root = NULL;
    } else {
        *root = malloc(sizeof(Tnode));
        if (*root == NULL) {
            exit(1);
        }
        (*root)->data = a;
        printf("\n创建%d的左孩子:", a);
        binarytree_create(&((*root)->lchild));
        printf("\n创建%d的右孩子:", a);
        binarytree_create(&((*root)->rchild));
    }
}

void binarytree_destory(Tree *root)
{
    if (root == NULL) {
        return;
    }
    binarytree_destory(root->lchild);
    binarytree_destory(root->rchild);
    free(root);
}

// 先序遍历 根->左->右
void binarytree_preorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->data);
    binarytree_preorder(root->lchild);
    binarytree_preorder(root->rchild);
}

// 中序遍历 左->根->右
void binarytree_inorder(Tree *root)
{
    if (root == NULL) {
        return;
    }
    binarytree_inorder(root->lchild);
    printf("%d\n", root->data);
    binarytree_inorder(root->rchild);
}

// 后序遍历 左->右->根
void binarytree_postorder(Tree *root)
{
    if (root == NULL) {
        return;
    }
    binarytree_postorder(root->lchild);
    binarytree_postorder(root->rchild);
    printf("%d\n", root->data);
}

void binarytree_levelorder(Tree *root)
{
    Queue *queue = NULL;
    Tnode *node = NULL;
    if (root == NULL) {
        return;
    }
    queue = queue_create();
    // 根节点先入队
    queue_enqueue(queue, (void *)root);
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue, (void *)&node);
        printf("%d\n", node->data);
        if (node->lchild != NULL) {
            queue_enqueue(queue, (void *)node->lchild);
        }
        if (node->rchild != NULL) {
            queue_enqueue(queue, (void *)node->rchild);
        }
    }

    free(queue);
}

void binarytree_printleaf(Tree *root)
{
    if (root == NULL) {
        return;
    }
    if ((root->lchild == NULL) && (root->rchild) == NULL) {
        printf("%d\n", root->data);
    } else {
        binarytree_printleaf(root->lchild);
        binarytree_printleaf(root->rchild);
    }
}

int binarytree_getleafnum(Tree *root)
{
    if (root == NULL) {
        return 0;
    } 
    if ((root->lchild == NULL) && (root->rchild == NULL)) {
        return 1;
    }

    return binarytree_getleafnum(root->lchild) + binarytree_getleafnum(root->rchild);
}

int binarytree_gethigh(Tree *root)
{
    int lhigh = 0;
    int rhigh = 0;
    if (root == NULL) {
        return 0;
    }
    lhigh = binarytree_gethigh(root->lchild);
    rhigh = binarytree_gethigh(root->rchild);

    return ((lhigh > rhigh) ? (lhigh + 1) : (rhigh + 1));
}

int main()
{
    Tree *root = NULL;
    printf("\n创建二叉树:");
    binarytree_create(&root);
    printf("\n先序遍历:");
    binarytree_preorder(root);
    printf("\n中序遍历:");
    binarytree_inorder(root);
    printf("\n后序遍历:");
    binarytree_postorder(root);
    printf("\n层次遍历:");
    binarytree_levelorder(root);

    printf("\n打印二叉树的叶子结点");
    binarytree_printleaf(root);
    printf("\r\n打印二叉树叶子节点数%d", binarytree_getleafnum(root));
    printf("\r\n打印二叉树高度%d", binarytree_gethigh(root));

    return 0;
}
