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

    }
};

void Test() {
    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval {4,8};
    Solution solution;
    for (const auto &i : solution.merge(intervals)) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}


#endif //LEETCODE_57_INSERT_INTERVAL_H
