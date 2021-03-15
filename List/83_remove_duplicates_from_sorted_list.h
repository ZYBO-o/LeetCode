//
// Created by 张永斌 on 2021/3/12.
//

#ifndef LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
#define LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H

#include "List.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* p = head;
        int value = p->val;
        while(p->next != nullptr) {
            int temp = p->next->val;
            if(temp == value) {
                ListNode* deleteNode = p->next;
                p->next = deleteNode->next;
                delete deleteNode;
            } else {
                value = temp;
                p = p->next;
            }

        }

        return head;

    }
};

void Test() {
    vector<int> nums {};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.deleteDuplicates(head);
    Print(head);
}

#endif //LEETCODE_83_REMOVE_DUPLICATES_FROM_SORTED_LIST_H
