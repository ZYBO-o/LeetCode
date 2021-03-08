//
// Created by 张永斌 on 2021/3/8.
//

#ifndef LEETCODE_283_MOVE_ZEROES_H
#define LEETCODE_283_MOVE_ZEROES_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    //0 3 1 0 12
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};


void  Test() {
    vector<int>nums {4,2,4,0,0,3,0,5,1,0};
    Solution solution;
    solution.moveZeroes(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

#endif //LEETCODE_283_MOVE_ZEROES_H
