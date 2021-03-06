//
// Created by 张永斌 on 2021/3/5.
//

#ifndef LEETCODE_31_NEXT_PERMUTATION_H
#define LEETCODE_31_NEXT_PERMUTATION_H


#include <iostream>
#include <vector>

using namespace std;


/*
 * 从后往前找到第一个【相邻升序对】，即A[i]<A[i+1]。此时A[i+1,end)为降序。
 * 在区间[i+1,end)中，从后往前找到第一个大于A[i]的元素A[j]
 * 交换A[i]和A[j]，此时A[i+1,end)一定还是降序，因为A[j]是从右侧起第一个大于A[i]的值
 * 反转A[i+1,end)，变成升序
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i = 0;
        for (i = nums.size() - 2; i >= 0 ; -- i) {
            if(nums[i + 1] > nums[i])
                break;
        }
        if( i == -1)
            reverse(nums.begin(),nums.end());
        else {
            for (int j = nums.size() - 1; j > i; --j) {
                if(nums[j] > nums[i]) {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    break;
                }

            }
        }
    }
};


void Test()
{
    vector<int> nums {4,2,0,2,3,2,0};
    Solution solution;
    solution.nextPermutation(nums);
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

#endif //LEETCODE_31_NEXT_PERMUTATION_H
