//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_BSTREE_LEETCODE_H
#define LEETCODE_BSTREE_LEETCODE_H

#include <vector>
#include <iostream>

class BSTreeNode {
public:
    int val;
    BSTreeNode* left;
    BSTreeNode* right;
    BSTreeNode() : val(0), left(nullptr), right(nullptr) {}
    BSTreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
    BSTreeNode(int value, BSTreeNode* left, BSTreeNode* right) : val(value), left(left), right(right) {}
};

//创建二叉搜索树
void CreatBSTree(BSTreeNode* &root);

//递归先序遍历二插搜索树
void PreOrderTraversalBSTree(BSTreeNode* root) ;

//中序遍历二叉树
void InOrderTraversalBSTree(BSTreeNode* root) ;

//后序遍历二叉树
void PostOrderTraversalBSTree(BSTreeNode* root) ;

#endif //LEETCODE_BSTREE_LEETCODE_H
