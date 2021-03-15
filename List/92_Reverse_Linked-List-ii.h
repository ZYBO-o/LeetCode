//
// Created by 张永斌 on 2021/3/14.
//

#ifndef LEETCODE_92_REVERSE_LINKED_LIST_II_H
#define LEETCODE_92_REVERSE_LINKED_LIST_II_H

#include "List.h"

//穿针引线方法
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        ListNode* dummpHead = new ListNode(0);
        dummpHead ->next = head;
        ListNode* p = dummpHead;
        int index = left;
        int count = 1;
        //找到开头
        while(count != index) {
            p = p->next;
            ++count;
        }

        ListNode* r = p->next;
        count = right - left;
        //倒着插入
        while(count --) {
            ListNode* temp = r->next;
            r->next = temp->next;
            temp->next = p->next;
            p->next = temp;

        }
        return dummpHead->next;
    }
};

void Test() {
    vector<int> nums {1,2,3,4,5};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.reverseBetween(head,2,4);
    Print(head);
}




#endif //LEETCODE_92_REVERSE_LINKED_LIST_II_H
