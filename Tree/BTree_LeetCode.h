//
// Created by 张永斌 on 2021/4/26.
//

#ifndef LEETCODE_BTREE_LEETCODE_H
#define LEETCODE_BTREE_LEETCODE_H
#include <iostream>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right) : val(value), left(left), right(right) {}
};

//按照先序遍历的方式创建二叉树
TreeNode* CreatTree();

//先序遍历二叉树
void PreOrderTraversal(TreeNode* root) ;

//中序遍历二叉树
void InOrderTraversal(TreeNode* root) ;

//后序遍历二叉树
void PostOrderTraversal(TreeNode* root) ;

//非递归先序遍历二叉树
void PreOrderTraversal2(TreeNode* root) ;

//非递归中序遍历二叉树
void InOrderTraversal2(TreeNode* root) ;

//非递归后序遍历二叉树
void PostOrderTraversal2(TreeNode* root) ;

//层序遍历
void levelOrder(TreeNode* root);


#endif //LEETCODE_BTREE_LEETCODE_H
