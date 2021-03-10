//
// Created by 张永斌 on 2021/3/10.
//

#ifndef LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_21_MERGE_TWO_SORTED_LISTS_H

#include "List.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode();

        ListNode* p = newList;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                ListNode* temp = new ListNode();
                temp->val = l1->val;
                temp->next = nullptr;
                p->next = temp;
                p = temp;
                l1 = l1->next;
            } else {
                ListNode* temp = new ListNode();
                temp->val = l2->val;
                temp->next = nullptr;
                p->next = temp;
                p = temp;
                l2 = l2->next;
            }
        }

        if(l1 == nullptr) {
            p->next = l2;
        }
        if(l2 == nullptr) {
            p->next = l1;
        }
        newList = newList->next;
        return newList;
    }
};


void Test() {
    vector<int> nums1 {1,2,4};
    vector<int> nums2 {1,3,4,5,6,7};
    ListNode* l1 = Create(nums1);
    ListNode* l2 = Create(nums2);

    Solution solution;
    ListNode* newList = solution.mergeTwoLists(l1,l2);
    Print(newList);


}

#endif //LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
