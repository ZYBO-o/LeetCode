//
// Created by 张永斌 on 2021/3/14.
//

#ifndef LEETCODE_86_PARTITION_LIST_H
#define LEETCODE_86_PARTITION_LIST_H

#include "List.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while(p->next != nullptr) {
            if(p->next->val < x)
                p = p->next;
            else
                break;
        }

        ListNode* f = p->next;

        while(f != nullptr && f->next != nullptr) {
            if(f->next->val < x) {
                ListNode* temp= f->next;
                f->next = temp->next;
                temp->next = p->next;
                p->next = temp;
                p = temp;
            }
            else
                f = f->next;
        }
        return dummyHead->next;

    }
};

void Test() {
    vector<int> nums {1};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.partition(head,2);
    Print(head);
}
#endif //LEETCODE_86_PARTITION_LIST_H
