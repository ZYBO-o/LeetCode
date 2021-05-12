//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_TEST_SORT_LEETCODE_H
#define LEETCODE_TEST_SORT_LEETCODE_H

#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

void Test_Sort_LeetCode () {
    int number = 100;
    std::vector<int> nums = SortTestHelper::generateRandomVector(number, 0 ,number);
    SelectSort(nums);
    InsertSort(nums);
}


#endif //LEETCODE_TEST_SORT_LEETCODE_H
