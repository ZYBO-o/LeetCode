//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_TEST_SORT_LEETCODE_H
#define LEETCODE_TEST_SORT_LEETCODE_H

#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "CountSort.h"
#include "BucketSort.h"
#include "RadixSort.h"

void Test_Sort_LeetCode () {
    int number = 100;
    std::vector<int> nums = SortTestHelper::generateRandomVector(number, 1,number);
//    SelectSort(nums);
//    InsertSort(nums);
   BubbleSort(nums);
//    ShellSort(nums);
        /*MergeSort(nums);
        QuickSort(nums);*/
        //HeapSort1(nums);
        // CountSort(nums);
       //BucketSort(nums);
       //radixSort(nums);




}


#endif //LEETCODE_TEST_SORT_LEETCODE_H
