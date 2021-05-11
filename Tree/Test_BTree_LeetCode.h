//
// Created by 张永斌 on 2021/4/26.
//

#ifndef LEETCODE_TEST_BTREE_LEETCODE_H
#define LEETCODE_TEST_BTREE_LEETCODE_H

#include "BTree_LeetCode.h"
#include "BSTree_LeetCode.h"

void Test_BTree_LeetCode() {


    std::cout << "Create a BSTree : ";
    TreeNode *root=  CreatTree();

    //1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
    std::cout << "Print the btree by PreOrderTraversal : " ;
    PreOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Print the btree by PreOrderTraversal2 : " ;
    PreOrderTraversal2(root);
    std::cout << std::endl;

    std::cout << "Print the btree by InOrderTraversal : " ;
    InOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Print the btree by InOrderTraversal2 : " ;
    InOrderTraversal2(root);
    std::cout << std::endl;

    std::cout << "Print the btree by PostOrderTraversal : " ;
    PostOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Print the btree by PostOrderTraversal2 : " ;
    PostOrderTraversal2(root);
    std::cout << std::endl;



    std::cout << "=============================================" << std::endl;

    BSTreeNode *bstree;
    std::cout << "Create a BSTree : ";
    CreatBSTree(bstree);

    std::cout << "Print the btree by PreOrderTraversalBSTree : " ;
    PreOrderTraversalBSTree(bstree);
    std::cout << std::endl;

    std::cout << "Print the btree by InOrderTraversalBSTree : " ;
    InOrderTraversalBSTree(bstree);
    std::cout << std::endl;

    std::cout << "Print the btree by PostOrderTraversalBSTree : " ;
    PostOrderTraversalBSTree(bstree);
    std::cout << std::endl;

}

#endif //LEETCODE_TEST_BTREE_LEETCODE_H
