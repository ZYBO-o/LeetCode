//
// Created by 张永斌 on 2021/3/26.
//

#ifndef LEETCODE_148_SORT_LIST_H
#define LEETCODE_148_SORT_LIST_H

#include "../List/List.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* dimmeryNode = new ListNode(-1);
        dimmeryNode->next = head;
        ListNode* StartNode = dimmeryNode;
        ListNode* p = head;

        int count = 0;

        while(p != nullptr) {
            p = p->next;
            ++ count;
        }

        for (int i = 0; i <= count; ++i) {
            for (int j = 0; j < i; ++j) {
                StartNode = StartNode->next;
            }
                while(StartNode->next != nullptr && StartNode->next->next != nullptr && StartNode->next->val < StartNode->next->next->val) {
                    //交换
                    ListNode* temp1 = StartNode->next;
                    ListNode* temp2 = StartNode->next->next;
                    temp1->next = temp2->next;
                    temp2->next = temp1;
                    StartNode->next = temp2;
                    StartNode = StartNode->next;
                }
            StartNode = dimmeryNode;
        }

        //反转
//        ListNode* start = dimmeryNode;
//        while(start->next->next != nullptr) {
//            ListNode* insert = start->next;
//            while(insert->next!= nullptr && insert->next->next != nullptr) {
//                insert = insert->next;
//            }
//            if(insert->next != nullptr) {
//                ListNode* change = insert->next;
//                insert->next = change->next;
//                change->next = start->next;
//                start->next = change;
//                start = start->next;
//            }
//        }


        return dimmeryNode->next;
    }
};

void Test()
{
    vector<int> nums {-1,-2,0,1,2,-4,9,-10,-1,-100};
    ListNode* head = Create(nums);
    Print(head);
    Solution solution;
    head = solution.sortList(head);
    Print(head);

}
#endif //LEETCODE_148_SORT_LIST_H
