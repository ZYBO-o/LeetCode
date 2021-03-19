//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_8_ZERO_MATRIX_H
#define LEETCODE_1_8_ZERO_MATRIX_H

#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> map;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0)
                    map[i] = j;
            }
        }

    }
};

void Test() {
    vector<vector<int>> matrix = { {1,0,3,0},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Solution solution;
    solution.setZeroes(matrix);
}

#endif //LEETCODE_1_8_ZERO_MATRIX_H
