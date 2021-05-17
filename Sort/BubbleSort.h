//
// Created by 张永斌 on 2021/5/13.
//

#ifndef LEETCODE_BUBBLESORT_H
#define LEETCODE_BUBBLESORT_H

template <typename T>
void BubbleSort(std::vector<T> nums) {
    for(int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            if(nums[j] < nums[i] ) {
                swap(nums[j],nums[i]);
            }
        }
    }

    for(int i = 0; i < nums.size(); ++i ) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}


#endif //LEETCODE_BUBBLESORT_H
