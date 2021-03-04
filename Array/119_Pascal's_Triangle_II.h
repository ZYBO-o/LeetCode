//
// Created by 张永斌 on 2021/3/3.
//

#ifndef LEETCODE_119_PASCAL_S_TRIANGLE_II_H
#define LEETCODE_119_PASCAL_S_TRIANGLE_II_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums;
        nums.resize(rowIndex + 1);
        for(int i = 0; i <= rowIndex; ++i) {
            nums[i] = 1;
            for(int j = i - 1; j >= 1; --j) {
                nums[j] += nums[j - 1];
            }
        }
        return nums;

    }
};


void Test(){
    Solution solution;
    vector<int> nums = solution.getRow(0);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
#endif //LEETCODE_119_PASCAL_S_TRIANGLE_II_H
