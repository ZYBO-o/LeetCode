//
// Created by 张永斌 on 2021/3/8.
//

#ifndef LEETCODE_57_INSERT_INTERVAL_H
#define LEETCODE_57_INSERT_INTERVAL_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if ( newInterval.size() == 0&&intervals.size() == 0) {
            return {};
        }


        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); ++i) {
            int left = intervals[i][0],right = intervals[i][1], nextLeft = intervals[i + 1][0];
            if(newInterval[i] > left && newInterval[i] > right) {
                merged.push_back({left, right});
                continue;
            }

//            if (!merged.size() || merged.back()[1] < left) {
//                merged.push_back({left, middle});
//            } else {
//                merged.back()[1] = max(merged.back()[1], right);
//            }
        }
        return merged;


    }
};

void Test() {
    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval {4,8};
    Solution solution;
    vector<vector<int>> interval = solution.insert(intervals,newInterval);
    for (const auto &i : interval) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


#endif //LEETCODE_57_INSERT_INTERVAL_H
