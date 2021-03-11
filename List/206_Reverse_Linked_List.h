//
// Created by 张永斌 on 2021/3/10.
//

#ifndef LEETCODE_206_REVERSE_LINKED_LIST_H
#define LEETCODE_206_REVERSE_LINKED_LIST_H

#include "List.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = nullptr;
        ListNode* cur = head;
        ListNode* node = nullptr;
        while(cur != nullptr) {
            node = cur->next;
            cur->next = p;
            p = cur;
            cur = node;
        }
        return p;
    }
};

void Test() {
    Solution solution;
    vector<int> nums {1,2,3,4,5};
    ListNode* head = Create(nums);
    Print(head);
    ListNode* p = solution.reverseList(head);
    Print(p);
}

#endif //LEETCODE_206_REVERSE_LINKED_LIST_H
