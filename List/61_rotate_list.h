//
// Created by 张永斌 on 2021/3/11.
//

#ifndef LEETCODE_61_ROTATE_LIST_H
#define LEETCODE_61_ROTATE_LIST_H

#include "List.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        int size = 0;
        ListNode* p = head;

        while(p->next != nullptr) {
            ++ size;
            p = p->next;
        }
        //形成循环链表
        p->next = head;
        //cout << size;
        int index = k % (size + 1);

        p = head;
        for (int i = 0; i < size - index; ++i) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;

        return head;
    }
};

void Test() {
    vector<int> nums {1,2,3,4,5};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.rotateRight(head,2);
    Print(head);
}


#endif //LEETCODE_61_ROTATE_LIST_H
