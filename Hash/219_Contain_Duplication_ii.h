//
// Created by 张永斌 on 2021/3/16.
//

#ifndef LEETCODE_219_CONTAIN_DUPLICATION_II_H
#define LEETCODE_219_CONTAIN_DUPLICATION_II_H

#include "Hash.h"

class Solution {
public:
    //Map的内容
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //维护一个包含当前窗口k+1个元素的hash表
        unordered_map<int, int> mps;
        for(int i=0; i<nums.size(); i++){
            if(mps.count(nums[i])){ //若在到来的数在窗口内已存在，直接返回
                return true;
            }
            mps[nums[i]] = i; //此时已mps.size() = k+1 窗口已满
            if(mps.size()>k){ //维持k个数,留一个坑给下一个数据
                mps.erase(nums[i-k]); //移除窗口最开始的key-value
            }
        }
        return false;
    }
};

void Test() {
    vector<int>nums {1,2,3,2};
    Solution solution;
    cout << solution.containsNearbyDuplicate(nums,2) << endl;
}

#endif //LEETCODE_219_CONTAIN_DUPLICATION_II_H
