//
// Created by 张永斌 on 2021/3/22.
//

#ifndef LEETCODE_2_4_PARTITION_LIST_H
#define LEETCODE_2_4_PARTITION_LIST_H

#include "../List/List.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};

void Test() {
    vector<int>nums {3,5,8,5,10,2,1};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.partition(head,3);
    Print(head);
}

#endif //LEETCODE_2_4_PARTITION_LIST_H
