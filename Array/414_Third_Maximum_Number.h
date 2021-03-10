//
// Created by 张永斌 on 2021/3/9.
//

#ifndef LEETCODE_414_THIRD_MAXIMUM_NUMBER_H
#define LEETCODE_414_THIRD_MAXIMUM_NUMBER_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int answer;
        sort(nums.begin(),nums.end());
        auto end = unique(nums.begin(),nums.end());
        if(end - nums.begin() > 2)
            answer = *(end - 3);
        else
            answer = *(end - 1);

        return answer;
    }
};

void Test() {
    Solution solution;
    vector<int> nums {2, 2, 3, 1};
    int answer = solution.thirdMax(nums);
    cout << answer << endl;
}

#endif //LEETCODE_414_THIRD_MAXIMUM_NUMBER_H
