//
// Created by 张永斌 on 2021/3/16.
//

#ifndef LEETCODE_217_CONTAINS_DUPLICATE_H
#define LEETCODE_217_CONTAINS_DUPLICATE_H


#include "Hash.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> map ;
        bool flag = false;
        for (auto i : nums) {
            ++ map[i];
        }
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            if(iter->second >= 2) {
                flag =  true;
                break;
            }

        }
        return flag;
    }
};

void Test() {
    vector<int>nums {7,10,5,5,6,6,4,10,5,4,9,4,9,6,5,9,6,3,6,5,6,7,7,4,9,9,10,5,8,1,8,3,2,7,5,10,1,8,5,8,4,3,6,4,9,4,2,8,3,2,2,1,5,6,3,2,6,1,8,6,2,9,1,4,5,10,8,5,10,5,10,1,4,8,3,6,4,10,9,1,1,1,2,2,9,6,6,8,1,9,2,5,5,2,1,8,5,2,3,10};
    Solution solution;
    cout << solution.containsDuplicate(nums) << endl;
}


#endif //LEETCODE_217_CONTAINS_DUPLICATE_H
