//
// Created by 张永斌 on 2021/3/16.
//

#ifndef LEETCODE_136_SINGLE_NUMBER_H
#define LEETCODE_136_SINGLE_NUMBER_H

#include "Hash.h"

//hashMap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        for(auto iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if(iter->second == 1)
                return iter->first;
        }
        return 0;
    }
};

void Test() {
    vector<int>nums {-1};
    Solution solution;
    int ans = solution.singleNumber(nums);
    cout << ans << endl;
}

#endif //LEETCODE_136_SINGLE_NUMBER_H
