//
// Created by 张永斌 on 2021/4/14.
//

#ifndef LEETCODE_136_SINGLE_NUMBER_H
#define LEETCODE_136_SINGLE_NUMBER_H

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};

#endif //LEETCODE_136_SINGLE_NUMBER_H





