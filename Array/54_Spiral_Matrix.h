//
// Created by 张永斌 on 2021/3/6.
//

#ifndef LEETCODE_54_SPIRAL_MATRIX_H
#define LEETCODE_54_SPIRAL_MATRIX_H

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums {};
        if(matrix.empty()) return nums;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        int numEle = matrix.size() * matrix[0].size();
        while (numEle > 0) {
            for (int i = left; i <= right && numEle > 0; ++i) {
                nums.push_back(matrix[top][i]);
                -- numEle;
            }
            ++ top;
            for (int i = top; i <= bottom && numEle > 0; ++i) {
                nums.push_back(matrix[i][right]);
                -- numEle;
            }
            -- right;
            for (int i = right; i >= left && numEle > 0; --i) {
                nums.push_back(matrix[bottom][i]);
                -- numEle;
            }
            -- bottom;
            for (int i = bottom; i >= top && numEle > 0; --i) {
                nums.push_back(matrix[i][left]);
                -- numEle;
            }
            ++ left;
        }
        return nums;

    }
};


void Test() {
    vector<vector<int>> matrix {};
    Solution solution;
    vector<int> nums = solution.spiralOrder(matrix);
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

#endif //LEETCODE_54_SPIRAL_MATRIX_H

