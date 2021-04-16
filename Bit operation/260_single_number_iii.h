//
// Created by 张永斌 on 2021/4/16.
//

#ifndef LEETCODE_260_SINGLE_NUMBER_III_H
#define LEETCODE_260_SINGLE_NUMBER_III_H

#include <vector>

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = 0;
        for (auto num : nums) {
            diff ^= num;
        }

        int bit = 1;
        while((diff & bit) == 0) {
            bit <<= 1;
        }

        int a = 0;
        int b = 0;

        for (auto num : nums) {
            if(bit & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return vector<int>{a,b};
    }
};

#endif //LEETCODE_260_SINGLE_NUMBER_III_H
