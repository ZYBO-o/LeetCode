//
// Created by 张永斌 on 2021/3/12.
//

#ifndef LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

#include "List.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* Next = p->next;

        bool flag = false;

        while (Next != nullptr && Next->next != nullptr) {

            while(Next->next != nullptr && p->next->val == Next->next->val) {
                flag = true;
                ListNode* del = p->next;
                p->next = Next->next;
                delete del;
                Next = p->next;
            }

            if(flag) {
                ListNode* del = p->next;
                p->next = Next->next;
                Next = p->next;
                delete del;
                flag = false;
            } else {
                p = p->next;
                Next = p->next;
            }
        }


        return dummyHead->next;


    }
};

void Test() {
    vector<int> nums {2,2,3,3,3,4,5,5,6,7,8,8,9};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.deleteDuplicates(head);
    Print(head);
}




#endif //LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
