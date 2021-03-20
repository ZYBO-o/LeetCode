//
// Created by 张永斌 on 2021/3/20.
//

#ifndef LEETCODE_2_2_KTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_2_2_KTH_NODE_FROM_END_OF_LIST_H

#include "../List/List.h"
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if(!head) return 0;
        ListNode* p = head;
        int length = 0;
        while (p != nullptr) {
            p = p->next;
            ++length;
        }
        int count = length + 1 - k;
        p = head;
        while(--count) {
            p = p->next;
        }
        return p->val;
    }
};

void Test() {
    vector<int>nums {};
    ListNode* head = Create(nums);
    Solution solution;
    cout << solution.kthToLast(head, 5) << endl;
}


#endif //LEETCODE_2_2_KTH_NODE_FROM_END_OF_LIST_H
