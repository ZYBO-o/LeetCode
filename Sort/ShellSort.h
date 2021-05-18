//
// Created by 张永斌 on 2021/5/17.
//

#ifndef LEETCODE_SHELLSORT_H
#define LEETCODE_SHELLSORT_H

template<typename T>
void ShellSort(std::vector<T> nums) {
    int d = nums.size();
    do {
        d = d / 3 + 1;
        for (int i = d; i < nums.size(); i += d) {
            T temp = nums[i];
            int minIndex = i;
            for (int j = i - d; j >= 0; j -= d) {
                if(temp < nums[j] ) {
                    nums[j + d] = nums[j];
                    minIndex = j;
                }
            }
            if(minIndex != i) {
                nums[minIndex] = temp;
            }
        }
    } while (d > 1);

    for(int i = 0; i < nums.size(); ++i ) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

#endif //LEETCODE_SHELLSORT_H
