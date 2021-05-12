//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_SELECTIONSORT_H
#define LEETCODE_SELECTIONSORT_H

#include <iostream>

template< typename T>
void SelectSort (std::vector<T> nums)
{
    for(int i = 0; i < nums.size(); ++i ) {
        int minIndex = i;
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(nums[minIndex],nums[i]);
    }

    for(int i = 0; i < nums.size(); ++i ) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}





#endif //LEETCODE_SELECTIONSORT_H
