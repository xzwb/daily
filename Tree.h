#ifndef _Tree_H
#define _Tree_H

typedef int Height;
typedef unsigned int Depth;

typedef struct TreeNode {
   struct TreeNode *LeftChild;
   struct TreeNode *RightChild;
   void *value;
   int num;
} TreeNode;

typedef struct Tree {
    // 指向根节点
    TreeNode *root;
    // 最大深度
    Height height;
} Tree;

// 创建一棵树
Tree *Init(void);
// 初始化一颗高度为n的二叉树
Tree *Creat(Tree *tree, TreeNode *node, Heigth heigth);
// 给标号为i的地方赋值
void Assignment(Tree *tree, void *value, int num);
// 先序遍历
void Preorder(Tree *tree);
// 后序遍历
void Postorder(Tree *tree);

#endif
