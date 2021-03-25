//
// Created by 张永斌 on 2021/3/25.
//

#include "../List/List.h"


#ifndef LEETCODE_147_INSERTION_SORT_LIST_H
#define LEETCODE_147_INSERTION_SORT_LIST_H

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dimmryNode = new ListNode(-1);
        dimmryNode->next = head;
        //待插入的节点
        ListNode* InsertNode = head->next;
        while(InsertNode != nullptr ) {
            ListNode* p = dimmryNode->next;
            ListNode* InsertNext = InsertNode->next;

            while(InsertNode != p ) {
                if(InsertNode->val < p->val) {
                    //插入
                    swap(InsertNode->val, p->val);
                    continue;
                } else {
                    p = p->next;
                }
            }
            //下一个继续操作

            InsertNode = InsertNext;
        }
        return dimmryNode->next;
    }
};

void Test() {
    vector<int>nums {1,2,3,2,5,9,7,5,3,1};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    solution.insertionSortList(head);
    Print(head);
}


#endif //LEETCODE_147_INSERTION_SORT_LIST_H
