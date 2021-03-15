//
// Created by 张永斌 on 2021/3/13.
//

#ifndef LEETCODE_OFFER18_H
#define LEETCODE_OFFER18_H


#include "List.h"

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr) return head;
        ListNode* p = head;
        if(head->val == val) {
            head = head->next;
            delete p;
        } else {
            while (p->next != nullptr) {
                if(p->next->val == val) {
                    ListNode* del = p->next;
                    p->next = p->next->next;
                    delete del;
                } else {
                    p = p->next;
                }
            }
        }
        return head;
    }
};

void Test() {
    vector<int> nums {1,2,3,4,5,6};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.deleteNode(head,1);
    Print(head);
}


#endif //LEETCODE_OFFER18_H
