#include "Tree/Test_BTree_LeetCode.h"
#include <iostream>
#include "Backtracking/Test_Backtracking.h"
#include "Sort/Test_Sort_LeetCode.h"
#include "Binary Search/Test_BinarySearch.h"
#include "string/Test_String.h"
#include <list>
#include "List/List.h"



int main() {



    //Test_Backtracking();
    //Test_BTree_LeetCode();

    //Test_Sort_LeetCode();
    //Test_Binary_Search();
    //Test_String();
    std::vector<int> nums {1,2,3,4,5,6,7,8,9};
    ListNode* list = Create(nums);
    Print(list);

    ListNode* p = deleteNode(list, 1);

    Print(list);
    Print(p);

}
