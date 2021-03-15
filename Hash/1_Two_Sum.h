//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_1_TWO_SUM_H
#define LEETCODE_1_TWO_SUM_H

#include "Hash.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> result_map;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = result_map.find(target - nums[i]);
            if(iter != result_map.end()) {
                return {iter->second, i};
            }
            result_map.insert(make_pair(nums[i],i));
        }
        return {};
    }
};



void Test() {
    vector<int>nums {2,7,11,15};
    Solution solution;
    vector<int>ans = solution.twoSum(nums,9);
    PrintVector(ans);
}

#endif //LEETCODE_1_TWO_SUM_H
