//
// Created by 张永斌 on 2021/3/20.
//

#ifndef LEETCODE_2_1_REMOVE_DUPLICATE_POINTS_H
#define LEETCODE_2_1_REMOVE_DUPLICATE_POINTS_H

#include "../List/List.h"
#include <unordered_map>

class Solution {
public:
    void Delete(ListNode* p) {
        ListNode* del = p->next;
        p->next = del->next;
        delete del;
    }
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head) return head;
        unordered_map<int,int> map;
        ++map[head->val];
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr) {
            if(map.count(p->next->val)) {
                Delete(p);
            } else {
                ++map[p->next->val];
                p = p->next;
            }
        }
        return head;
    }
};

void Test() {
    vector<int> nums = {1, 2, 3, 3, 2, 1};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.removeDuplicateNodes(head);
    Print(head);
}

#endif //LEETCODE_2_1_REMOVE_DUPLICATE_POINTS_H
