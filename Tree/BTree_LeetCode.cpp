//
// Created by 张永斌 on 2021/4/26.
//

#include "BTree_LeetCode.h"
#include <stack>
#include <queue>

TreeNode* CreatTree()
{
    TreeNode *root;
    int value;
    std::cin>>value;

    if(value == 0)
        return nullptr;

    root = new TreeNode();
    root->val = value;

    root->left = CreatTree();
    root->right = CreatTree();

    return root;
}

//1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
void PreOrderTraversal(TreeNode* root) {
    if(root != nullptr) {
        std::cout << (root->val) << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void InOrderTraversal(TreeNode* root) {
    if(root != nullptr) {

        InOrderTraversal(root->left);
        std::cout << (root->val) << " ";
        InOrderTraversal(root->right);
    }
}

void PostOrderTraversal(TreeNode* root) {
    if(root != nullptr) {

        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        std::cout << (root->val) << " ";
    }
}

void PreOrderTraversal2(TreeNode* root)  {

    if(!root) return;

    std::stack<TreeNode*> stack;
    TreeNode* node = root;

    //栈为空且结点为空时结束遍历
    while((!stack.empty()) || (node != nullptr)) {
        //压栈
        while(node != nullptr) {
            std::cout << node->val << " ";
            stack.emplace(node);
            //左结点压栈
            node = node->left;
        }

        //出栈
        node = stack.top();
        stack.pop();
        //遍历又结点
        node = node->right;
    }
}

void InOrderTraversal2(TreeNode* root) {
    if(!root) return;

    std::stack<TreeNode*> stack;
    TreeNode* node = root;

    while (!stack.empty() || node != nullptr) {
        while (node != nullptr) {
            stack.emplace(node);
            node = node->left;
        }
        std::cout << (stack.top())->val << " ";
        node =  stack.top();
        stack.pop();
        node = node->right;
    }
}

void PostOrderTraversal2(TreeNode* root) {
    if(!root) return;

    std::stack<TreeNode*> stack;
    TreeNode* node = root;
    //标记是否访问过
    TreeNode *prev = nullptr;

    while (!stack.empty() || node != nullptr) {
        while (node != nullptr) {
            //左子树一直入栈
            stack.emplace(node);
            node = node->left;
        }
        //左子树为空时遍历最左子树的右子树
        node = stack.top();
        //弹出栈
        stack.pop();
        //如果右子树还为空，或者右子树被访问过
        if (node->right == nullptr || node->right == prev) {
            //输出结点
            std::cout << node->val << " ";
            //标记已访问过该结点
            prev = node;
            node = nullptr;
        }
        //如果存在右节点，则再次入栈
        else {
            //遍历它的右子树
            stack.emplace(node);
            node = node->right;
        }
    }
}

void levelOrder(TreeNode* root) {
    if(!root) return;

    std::queue<TreeNode*> queue;
    queue.push(root);

    while(!queue.empty()) {
        for (int i = 0; i < queue.size(); ++i) {

            TreeNode* node = queue.front();
            std::cout << node->val << " ";

            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);

            queue.pop();
        }
    }
}













