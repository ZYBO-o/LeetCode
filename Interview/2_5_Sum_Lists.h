//
// Created by 张永斌 on 2021/3/22.
//

#ifndef LEETCODE_2_5_SUM_LISTS_H
#define LEETCODE_2_5_SUM_LISTS_H

#include "../List/List.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int count = 0;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while (l1 != nullptr || l2 != nullptr || count != 0) {
            int sum = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + count;//求两个节点相加的值
            count = sum / 10;//取进位的值
            p->next = new ListNode(sum % 10);//sum对10求余后放到节点中
            p = p->next;
            l1 = l1 != nullptr ? l1->next : l1;
            l2 = l2 != nullptr ? l2->next : l2;
        }
        return head->next;
    }
};


void Test() {
    vector<int>nums1 {7,1,6};
    vector<int>nums2 {5,9,2};
    ListNode* l1 = Create(nums1);
    ListNode* l2 = Create(nums2);

    Solution solution;
    ListNode* head = solution.addTwoNumbers(l1,l2);
    Print(head);

}


#endif //LEETCODE_2_5_SUM_LISTS_H
