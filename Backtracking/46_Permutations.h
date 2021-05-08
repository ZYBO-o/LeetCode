//
// Created by 张永斌 on 2021/5/8.
//

#ifndef LEETCODE_46_PERMUTATIONS_H
#define LEETCODE_46_PERMUTATIONS_H
#include <vector>
#include <iostream>

using namespace  std;

class Permute {
public:


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track ;
        backtrack(res, nums, track);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> nums, vector<int> track) {
        // 触发结束条件
        if(nums.size() == track.size()) {
            res.push_back(track);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            // 排除不合法的选择
            if (find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            // 做选择
            track.push_back(nums[i]);
            // 进入下一层决策树
            backtrack(res, nums, track);
            // 取消选择
            track.pop_back();
        }


    }
};
#endif //LEETCODE_46_PERMUTATIONS_H
