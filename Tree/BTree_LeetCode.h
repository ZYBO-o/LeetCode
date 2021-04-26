//
// Created by 张永斌 on 2021/4/26.
//

#ifndef LEETCODE_BTREE_H
#define LEETCODE_BTREE_H

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
TreeNode* CreatTree(const vector<int>& nums);

//先序遍历二叉树
void PreOrderTraversal(TreeNode* root, vector<int>& ret) ;

//中序遍历二叉树
void InOrderTraversal(TreeNode* root, vector<int>& ret) ;

//后序遍历二叉树
void PostOrderTraversal(TreeNode* root, vector<int>& ret) ;



#endif //LEETCODE_BTREE_H
