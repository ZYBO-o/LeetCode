//
// Created by 张永斌 on 2021/5/11.
//

#include "BSTree_LeetCode.h"

void CreatBSTree(BSTreeNode* &root) {
    int value;
    while(std::cin >> value) {
        //声明临时节点并把数据放进去，注意不能delete
        auto newNode = new BSTreeNode(value);
        //树没有根结点的情况
        if (root == nullptr)
        {
            root = newNode;
        }
        //树存在根节点
        else
        {
            //声明移动指针
            BSTreeNode* pTemp = root;
            //找到插入的位置才退出
            while (true)
            {
                //输入的数小于该节点的值
                if (value < pTemp->val) {
                    //左孩子为空，则新的节点为左孩子
                    if (pTemp->left == nullptr)
                    {
                        pTemp->left = newNode;
                        break;
                    }
                        //左孩子不为空，p指针移动为左孩子
                    else
                    {
                        pTemp = pTemp->left;
                    }
                }
                //输入的数不小于该节点的值
                else
                {
                    //右孩子为空，则新的节点为右孩子
                    if (pTemp->right == nullptr)
                    {
                        pTemp->right = newNode;
                        break;
                    }
                        //右孩子不为空，p指针移动为右孩子
                    else
                    {
                        pTemp = pTemp->right;
                    }
                }
            }
        }
        //判断是否输入结束
        if (std::cin.get() == '\n')
            break;
    }
}

void PreOrderTraversalBSTree(BSTreeNode* root) {
    if(root != nullptr) {
        std::cout << (root->val) << " ";
        PreOrderTraversalBSTree(root->left);
        PreOrderTraversalBSTree(root->right);
    }
}

void InOrderTraversalBSTree(BSTreeNode* root) {
    if(root != nullptr) {
        InOrderTraversalBSTree(root->left);
        std::cout << (root->val) << " ";
        InOrderTraversalBSTree(root->right);
    }
}

void PostOrderTraversalBSTree(BSTreeNode* root) {
    if(root != nullptr) {
        PostOrderTraversalBSTree(root->left);
        PostOrderTraversalBSTree(root->right);
        std::cout << (root->val) << " ";
    }
}