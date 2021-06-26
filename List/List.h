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

ListNode* deleteNode(ListNode* head, int val) {
    ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
    dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
    ListNode* cur = dummyHead;
    while (cur->next != nullptr) {
        if(cur->next->val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
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
