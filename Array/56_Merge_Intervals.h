//
// Created by 张永斌 on 2021/3/8.
//

#ifndef LEETCODE_56_MERGE_INTERVALS_H
#define LEETCODE_56_MERGE_INTERVALS_H

#include <iostream>
#include <vector>
#include <algorithm>

using  namespace  std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if (!merged.size() || merged.back()[1] < left) {
                merged.push_back({left, right});
            } else {
                merged.back()[1] = max(merged.back()[1], right);
            }
        }
        return merged;
    }

};


void Test() {
    vector<vector<int>> intervals{{1, 3},
                                  {5, 6},
                                  {8, 10},
                                  {3, 3}};
    Solution solution;
    for (const auto &i : solution.merge(intervals)) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}



#endif //LEETCODE_56_MERGE_INTERVALS_H
