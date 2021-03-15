//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H
#define LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H

#include "Hash.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //存放结果
        unordered_set<int> result_set;
        unordered_set<int> set_nums1(nums1.begin(),nums1.end());
        for (auto num : nums2) {
            if(set_nums1.find(num) != set_nums1.end()) {
                result_set.insert(num);
            }
        }
        return vector<int> (result_set.begin(),result_set.end());
    }
};


void Test() {
    vector<int>nums1 {4,9,5};
    vector<int>nums2 {9,4,9,8,4};

    Solution solution;
    vector<int> answer = solution.intersection(nums1,nums2);
    PrintVector(answer);
}


#endif //LEETCODE_349_INTERSECTION_OF_TWO_ARRAYS_H
