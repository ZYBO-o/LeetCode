//
// Created by 张永斌 on 2021/7/21.
//

#ifndef LEETCODE_NEXTGREATERELEMENT_H
#define LEETCODE_NEXTGREATERELEMENT_H

#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElement (std::vector<int> &nums) {
    std::vector<int> ans(nums.size(),0);
    std::stack<int> stack;
    //从后往前遍历
    for(int i = nums.size() - 1; i >= 0; --i) {
        //如果单调栈不为空，且元素比栈顶大，则进行pop()
        while(!stack.empty() && nums[i] >= stack.top()) {
            stack.pop();
        }
        ans[i] = (stack.empty() ? -1 : stack.top() );
        stack.push(nums[i]);
    }
    return ans;
}

#endif //LEETCODE_NEXTGREATERELEMENT_H
