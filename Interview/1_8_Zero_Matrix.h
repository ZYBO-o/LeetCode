//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_8_ZERO_MATRIX_H
#define LEETCODE_1_8_ZERO_MATRIX_H

#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        //判空
        if (matrix.size() == 0) return ;
        //计算M * N
        int m = matrix.size();
        int n = matrix[0].size();
        //定义标记数组
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        //标记“0”的行和列
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        //清零
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
            }
        }
    }

};

void Test() {
    vector<vector<int>> matrix = { {1,0,3,0},{5,6,7,8},{9,10,11,12}};
    Solution solution;
    solution.setZeroes(matrix);
    for (auto i : matrix) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

#endif //LEETCODE_1_8_ZERO_MATRIX_H
