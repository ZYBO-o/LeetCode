//
// Created by 张永斌 on 2021/3/26.
//

#ifndef LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H
#define LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) {
            swap(nums2, nums1);
        }

        unordered_map<int,int> map;
        for (int i : nums1) {
            ++map[i];
        }

        vector<int> ans;

        for(int num : nums2) {
            if(map.count(num)) {
                ans.push_back(num);
                --map[num];
                if(map[num] == 0) {
                    map.erase(num);
                }
            }

        }

        return ans;

    }
};

void Test() {
    vector<int> nums1 {4,9,5};
    vector<int> nums2 {9,4,9,8,4};

    Solution solution;
    vector<int> ans = solution.intersect(nums1,nums2);

    for (int i : ans) {
        cout << i <<" ";
    }
}


#endif //LEETCODE_350_INTERSECTION_OF_TWO_ARRAYS_II_H
