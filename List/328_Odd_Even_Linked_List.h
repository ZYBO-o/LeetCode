//
// Created by 张永斌 on 2021/3/11.
//

#ifndef LEETCODE_328_ODD_EVEN_LINKED_LIST_H
#define LEETCODE_328_ODD_EVEN_LINKED_LIST_H


#include "List.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};



void Test() {
    vector<int> nums {1,2,3,4,5,6,7,8};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    ListNode* oddEvenList = solution.oddEvenList(head);
    Print(oddEvenList);

}


#endif //LEETCODE_328_ODD_EVEN_LINKED_LIST_H
