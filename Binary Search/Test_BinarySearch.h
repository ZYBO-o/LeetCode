//
// Created by 张永斌 on 2021/6/19.
//

#ifndef LEETCODE_TEST_BINARYSEARCH_H
#define LEETCODE_TEST_BINARYSEARCH_H

#include <iostream>
#include <vector>
#include "SearchNum.h"

void Test_Binary_Search() {
    std::vector<int> nums {0, 2, 5, 7, 7, 7, 19, 34, 44, 100};
    binary_search(nums, 7);
    left_bound(nums, 10);
    right_bound(nums, 10);

}


#endif //LEETCODE_TEST_BINARYSEARCH_H
