//
// Created by 张永斌 on 2021/3/3.
//

#ifndef LEETCODE_18_4SUM_H
#define LEETCODE_18_4SUM_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> fourSum ;
        if (nums.size() <= 3) return fourSum;
        sort(nums.begin(),nums.end());
        int pb, i, j, pe;

        for (pb = 0; pb <= nums.size() - 4; ++pb) {
            //确保nums[pb]发生了改变
            if(pb > 0 && nums[pb] == nums[pb - 1]) continue;

            for (i = pb + 1; i <= nums.size() - 3; i++) {
                //确保nums[i]发生了变化
                if(i > pb + 1 && nums[i] == nums[i - 1]) continue;
                j = i + 1; pe = nums.size() - 1;
                while (j < pe){
                    if(nums[pb] + nums[i] + nums[j] + nums[pe] == target) {
                        fourSum.push_back({nums[pb], nums[i], nums[j], nums[pe]});
                        //确保nums[j]发生了变化
                        while (j < pe && nums[j] == nums[j + 1])
                            ++ j;
                        //确保nums[pe]发生了变化
                        while (j < pe && nums[pe - 1] == nums[pe])
                            --pe;
                        ++ j;
                        -- pe;
                    } else if (nums[pb] + nums[i] + nums[j] + nums[pe] < target) {
                        ++ j;
                    } else {
                        -- pe;
                    }
                }
            }
        }
        return fourSum;
    }
};


void Test()
{
    vector<int> nums {1,0,-1,0,-2,2};
    Solution solution;
    vector<vector<int>> fourSum = solution.fourSum(nums,0);
    for(const auto i : fourSum)

    {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }


}

#endif //LEETCODE_18_4SUM_H
