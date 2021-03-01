//
// Created by 张永斌 on 2021/3/1.
//

#ifndef LEETCODE_26_REMOVE_DUPLICATES_H
#define LEETCODE_26_REMOVE_DUPLICATES_H

#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto p1 = nums.begin();
        auto p2 = nums.begin() + 1;
        while (p2 != nums.end())
        {
            if (*p2 == *p1) {
                p2 = nums.erase(p2);
            } else {
                p1 = p2;
                ++ p2;
            }
        }
        return nums.size();
    }
};
*/

/*泛型算法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin() ,nums.end()),nums.end() );
        return nums.size() ;
    }
};

 */

//简单数组操作
//一样的i继续往后找
//不一样的，j+1，然后把不一样的赋给这个位置，继续往后
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[j] != nums[i])
            {
                ++j;
                nums[j] = nums[i];
            }

        return ++j;
    }
};

void Test()
{
    vector<int> nums {1,2,2,3,4,4,4};
    Solution solution;
    int len = solution.removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout<<nums[i] << " " ;
    }
}

#endif //LEETCODE_26_REMOVE_DUPLICATES_H
