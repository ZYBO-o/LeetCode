//
// Created by 张永斌 on 2021/7/21.
//

#ifndef LEETCODE_TEST_MONOTONICSTACK_H
#define LEETCODE_TEST_MONOTONICSTACK_H

#include "nextGreaterElement.h"

void Test_MonotonicStack() {
    std::vector<int> nums {2,1,2,4,3};
    std::vector<int>  ans = nextGreaterElement(nums);
    for(auto num : ans)
        std::cout << num << " ";
    std::cout << std::endl;
}

#endif //LEETCODE_TEST_MONOTONICSTACK_H
