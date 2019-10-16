#ifndef _Tree_H
#define _Tree_H

typedef struct TreeNode {
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} Tnode, Tree;

// 创建二叉树
void binarytree_create(Tree **root);
// 销毁二叉树
void binarytree_destory(Tree *root);
// 先序遍历
void binarytree_preorder(Tree *root);
// 中序遍历
void binarytree_inorder(Tree *root);
// 后序遍历
void binarytree_postorder(Tree *root);
// 水平遍历
void binarytree_levelorder(Tree *root);
// 打印叶子结点
void binarytree_printleaf(Tree *root);
// 打印叶子个数
int binarytree_getleafnum(Tree *root);
// 打印树的高度
int binarytree_gethigh(Tree *root);

#endif
