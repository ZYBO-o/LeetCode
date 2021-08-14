//
// Created by 张永斌 on 2021/8/10.
//

#ifndef LEETCODE_FIRSTSMALLERNUMONLEFT_H
#define LEETCODE_FIRSTSMALLERNUMONLEFT_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class FirstSmallerNumOnLeft {
public:
vector<int> First_SmallerNum_On_Left(vector<int>& nums) {
    vector<int> res;

    stack<int> s;

    for(auto num : nums) {
        while (!s.empty() && num <= s.top()) {// 判定个子高矮
            s.pop(); // 矮个起开，反正也被挡着了。。。
        }
        int temp = s.empty() ? 0 : s.top(); // 这个元素身后的第一个高个
        res.push_back(temp);
        s.push(num);
    }

    return res;
}


};

void Test_First_SmallerNum_On_Left() {
    vector<int> nums {3,4,2,7,5};
    FirstSmallerNumOnLeft firstSmallerNumOnLeft;
    vector<int> res = firstSmallerNumOnLeft.First_SmallerNum_On_Left(nums);
    for(auto num : res) {
        cout << num << " ";
    }
}

#endif //LEETCODE_FIRSTSMALLERNUMONLEFT_H
