//
// Created by 张永斌 on 2021/3/2.
//

#ifndef LEETCODE_88_MERGE_SORTED_ARRAY_H
#define LEETCODE_88_MERGE_SORTED_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

//倒叙双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};


void Test()
{
    vector<int> nums1 {2,2,3};
    vector<int> nums2 {1,5,6};
    Solution solution;
    solution.merge(nums1,3,nums2,3);
    for (auto i : nums1) {
        cout << i << " " ;
    }
    cout << endl;
}

#endif //LEETCODE_88_MERGE_SORTED_ARRAY_H
