//
// Created by 张永斌 on 2021/4/7.
//

#ifndef LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H
#define LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H

#include "Hash.h"

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i : nums) {
            ++ map[i];
        }

        vector<pair<int, int>> values;
        for (auto& kv: map) {
            values.push_back(kv);
        }

        sort(values.begin(),values.end(),cmp);
        for( auto iter = values.begin(); iter != values.begin() + 3; ++iter) {
            ans.push_back(iter->first );
        }
        return ans;
    }
};


void Test() {
    vector<int>nums {1,2,3,4,5,4,3,2,1,3,2,1,2,1,1,5,5,5,5};
    Solution solution;
    vector<int> ans = solution.topKFrequent(nums, 3);
    for (int i : ans) {
        cout << i << " ";
    }

}


#endif //LEETCODE_347_TOP_K_FREQUENT_ELEMENTS_H
