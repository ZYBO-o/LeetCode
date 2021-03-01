//
// Created by 张永斌 on 2021/3/1.
//

#ifndef LEETCODE_15_3SUM_H
#define LEETCODE_15_3SUM_H

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;

        sort(nums.begin(),nums.end());

        if(nums[0] > 0)
            return result;
        if(nums.size() == 3 && accumulate(nums.begin(),nums.end(),0) == 0)
            result.push_back({nums[0],nums[1],nums[2]});

        auto i = nums.begin();
        while (i != nums.end() - 3)
        {
            //防止重复
            if(*i == *(i-1))
            {
                ++i;
                continue;
            }
            auto L = i + 1, R = nums.end() - 1;

            while(L < R )
            {
                if(*L + *i + *R < 0)
                    ++L;
                else if(*L + *i + *R > 0)
                    --R;
                else if(*L + *i + *R ==0){
                    result.push_back({*i,*L,*R});
                    //防止有重复发生
                    while(L < R && *L == *(L+1))
                        ++L;
                    while(L < R && *R == *(R-1))
                        --R;
                    ++L;
                    --R;
                }
            }
            ++i;
        }
        return result;
    }
};

/*
 *
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int N = nums.size();
        if(N < 3)
            return {};

        const int target = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < N - 2; ++i)
        {
            if(nums[i] > target)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = N - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;

                    while(left < right && nums[left + 1] == nums[left])
                        left++;
                    while(left < right && nums[right - 1] == nums[right])
                        right--;

                    left++;
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] > target)
                    right--;
                else
                    left++;
            }

        }
        return res;
    }
};
 */
void Test()
{
    vector<int> nums {-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);
    if (!result.empty()){
        for (vector<int> i : result) {
            for (int j : i) {
                cout << j << " " ;
            }
            cout << endl;
        }
    }
}

#endif //LEETCODE_15_3SUM_H
