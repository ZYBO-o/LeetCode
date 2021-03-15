//
// Created by 张永斌 on 2021/3/14.
//

#ifndef LEETCODE_141_LINKED_LIST_CYCLE_H
#define LEETCODE_141_LINKED_LIST_CYCLE_H

//快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
            }
            if(fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};




#endif //LEETCODE_141_LINKED_LIST_CYCLE_H
