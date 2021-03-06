//
// Created by 张永斌 on 2021/3/6.
//

#ifndef LEETCODE_59_SPIRAL_MATRIX_II_H
#define LEETCODE_59_SPIRAL_MATRIX_II_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for (int j = 0; j < n; ++j) {
            matrix[j].resize(n);
        }
        int numLen = n*n;
        int right = n - 1;
        int bottom = n - 1;
        int top = 0;
        int left = 0;
        int count = 1;
        while (count <= numLen) {
            for (int i = left; i <= right ; ++i) {
                matrix[top][i] = count;
                ++ count;
            }
            ++ top;
            for (int i = top; i <= bottom ; ++i) {
                matrix[i][right] = count;
                ++ count;
            }
            -- right;
            for (int i = right; i >= left ; --i) {
                matrix[bottom][i] = count;
                ++ count;
            }
            -- bottom;
            for (int i = bottom; i >= top ; --i) {
                matrix[i][left] = count;
                ++ count;
            }
            ++ left;
        }
        return matrix;
    }
};


void Test() {
    Solution solution;
    vector<vector<int>> matrix = solution.generateMatrix(3);
    for (const auto & i : matrix) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
};


#endif //LEETCODE_59_SPIRAL_MATRIX_II_H
