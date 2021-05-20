//
// Created by 张永斌 on 2021/5/8.
//

#ifndef LEETCODE_TEST_BACKTRACKING_H
#define LEETCODE_TEST_BACKTRACKING_H
#include <iostream>
#include <vector>
#include "491_increasing_subsequences.h"

using namespace std;

void Test_Backtracking() {
    vector<int> nums {4,4, 6};
    Increasing_subsequences increasingSubsequences;
    vector<vector<int>> res = increasingSubsequences.findSubsequences(nums);
    for (auto line : res) {
        for (auto  i : line) {
            cout << i << " ";
        }
        cout << endl;
    }

}


#endif //LEETCODE_TEST_BACKTRACKING_H
