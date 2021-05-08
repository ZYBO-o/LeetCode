//
// Created by 张永斌 on 2021/5/8.
//

#ifndef LEETCODE_TEST_BACKTRACKING_H
#define LEETCODE_TEST_BACKTRACKING_H
#include <iostream>
#include <vector>
#include "46_Permutations.h"

void Test_Backtracking() {
    vector<int> nums {1,2,3,4};
    Permute permute;
    vector<vector<int>> res = permute.permute(nums);
    for (auto line : res) {
        for (auto  i : line) {
            cout << i << " ";
        }
        cout << endl;
    }

}


#endif //LEETCODE_TEST_BACKTRACKING_H
