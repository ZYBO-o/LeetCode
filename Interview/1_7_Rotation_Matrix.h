//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_7_ROTATION_MATRIX_H
#define LEETCODE_1_7_ROTATION_MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for (int i = 0; i <  n/2 ; ++i) {
            for (int j = 0; j < (n+1)/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }


        for (auto i : matrix) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

void Test() {
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution solution;
    solution.rotate(matrix);
}

#endif //LEETCODE_1_7_ROTATION_MATRIX_H
