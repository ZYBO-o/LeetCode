//
// Created by 张永斌 on 2021/4/14.
//

#ifndef LEETCODE_137_SINGLE_NUMBER_II_H
#define LEETCODE_137_SINGLE_NUMBER_II_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0;
        int seen_twice = 0;

        for(auto i : nums) {
            seen_once = ~seen_twice & (seen_once ^ i);
            seen_twice = ~seen_once & (seen_twice ^ i);
        }
        return seen_once;
    }
};

void Test() {
    Solution solution;
    vector<int> nums {0,1,0,1,0,1,99};
    cout << solution.singleNumber(nums) << endl;
}

#endif //LEETCODE_137_SINGLE_NUMBER_II_H
