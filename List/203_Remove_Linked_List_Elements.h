//
// Created by 张永斌 on 2021/3/10.
//

#ifndef LEETCODE_203_REMOVE_LINKED_LIST_ELEMENTS_H
#define LEETCODE_203_REMOVE_LINKED_LIST_ELEMENTS_H

#include "List.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        while( head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr) {
            if(p->next->val == val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};

void Test() {
    vector<int> nums {7,7,7,7};
    ListNode* head = Create(nums);
    //Print(head);
    Solution solution;
   head = solution.removeElements(head,7);
   Print(head);
}

#endif //LEETCODE_203_REMOVE_LINKED_LIST_ELEMENTS_H
