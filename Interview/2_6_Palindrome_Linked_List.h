//
// Created by 张永斌 on 2021/3/21.
//

#ifndef LEETCODE_2_6_PALINDROME_LINKED_LIST_H
#define LEETCODE_2_6_PALINDROME_LINKED_LIST_H

#include <iostream>
#include "../List/List.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> s;
        ListNode* p = head;
        while(p != nullptr) {
            s.push_back(p->val);
            p = p->next;
        }
        for(int i = 0,j = s.size() - 1; i < s.size(), j >=0 ; ++i,--j)
        {
            if(s[i] != s[j])
                return false;
            else
                return true;
        }
    }
};

void Test(){
    vector<int>nums {1,2,3,2,1};
    ListNode* head = Create(nums);
    Solution solution;
    cout << solution.isPalindrome(head) << endl;
}

#endif //LEETCODE_2_6_PALINDROME_LINKED_LIST_H
