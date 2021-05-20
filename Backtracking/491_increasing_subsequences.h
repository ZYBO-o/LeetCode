//
// Created by 张永斌 on 2021/5/20.
//

#ifndef LEETCODE_491_INCREASING_SUBSEQUENCES_H
#define LEETCODE_491_INCREASING_SUBSEQUENCES_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Increasing_subsequences {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {


        if (path.size() > 1)
            result.push_back(path);


        unordered_set<int> uset; // 使用set对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i++) {

            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end() )
                continue;

            //unordered_set<int> uset 是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道uset只负责本层！
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

#endif //LEETCODE_491_INCREASING_SUBSEQUENCES_H
