//
// Created by 张永斌 on 2021/3/2.
//

#ifndef LEETCODE_16_3SUM_CLOSET_H
#define LEETCODE_16_3SUM_CLOSET_H

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int min = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            int start = i + 1;
            auto end = nums.size() - 1;

            while( start < end )
            {
                int sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum) < abs(target - min))
                    min = sum;
                if(sum > target)
                    end--;
                else if(sum < target)
                    start++;
                else
                    return min;
            }
        }
        
        return min;
    }
};

void Test()
{
    vector<int> nums {1,1,1,0};
    int target = 100;
    Solution solution;
    cout << solution.threeSumClosest(nums, target) << endl;
}

#endif //LEETCODE_16_3SUM_CLOSET_H
