//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_INSERTIONSORT_H
#define LEETCODE_INSERTIONSORT_H


template<typename T>
void InsertSort(std::vector<T> nums) {
    for(int i = 1; i < nums.size(); ++i) {
        T temp = nums[i];
        int index = i;
        for(int j = i - 1; j >= 0; --j) {
            if(temp <  nums[j]){
                nums[j+1] = nums[j];
                index = j;
            }
        }
        if(index != i) {
            nums[index] = temp;
        }
    }
    for(int i = 0; i < nums.size(); ++i ) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

#endif //LEETCODE_INSERTIONSORT_H
