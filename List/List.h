//
// Created by 张永斌 on 2021/3/10.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* Create(const vector<int>& nums) {
    ListNode* newList = new ListNode();
    if(nums.empty()) return newList;
    ListNode* p = newList;
    p->val = nums[0];
    p->next = nullptr;
    for (int i = 1; i < nums.size(); ++i) {
        ListNode* temp = new ListNode();
        temp->val = nums[i];
        temp->next = nullptr;
        p->next = temp;
        p = temp;
    }
    return newList;
}

void Print(ListNode* List) {
    if(List == nullptr) return;
    ListNode* p = List;
    while(p != nullptr) {
        cout << p->val << " " ;
        p = p->next;
    }
    cout << endl;
}

#endif //LEETCODE_LIST_H
