//
// Created by 张永斌 on 2021/3/3.
//

#ifndef LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size() + 1,count,sum;

        for (auto p1 = nums.begin(); p1 != nums.end() ; ++p1) {
            if(*p1 >= target) return 1;
            sum = *p1;
            count = 1;
            for (auto p2 = p1 + 1;  p2 != nums.end(); ++p2) {
                sum += *p2;
                ++ count;
                if(sum >= target) {
                    break;
                }
            }

            if(count < minLen && sum >= target)
                minLen = count;
        }

        if(minLen == nums.size() + 1)
            return 0;
        else
            return minLen;
    }
};

void Test()
{
    Solution solution;
    vector<int> nums {1,1,1,1,7};
    cout << solution.minSubArrayLen(7,nums) << endl;

}

#endif //LEETCODE_209_MINIMUM_SIZE_SUBARRAY_SUM_H
