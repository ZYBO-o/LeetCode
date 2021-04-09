//
// Created by 张永斌 on 2021/4/9.
//

#ifndef LEETCODE_24_SWAP_NODES_IN_PAIRS_H
#define LEETCODE_24_SWAP_NODES_IN_PAIRS_H


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

#endif //LEETCODE_24_SWAP_NODES_IN_PAIRS_H
