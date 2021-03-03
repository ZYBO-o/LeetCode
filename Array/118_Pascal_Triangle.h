//
// Created by 张永斌 on 2021/3/3.
//

#ifndef LEETCODE_118_PASCAL_TRIANGLE_H
#define LEETCODE_118_PASCAL_TRIANGLE_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; ++i) {
            triangle[i].resize(i+1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        return triangle;
    }
};




void Test() {
    Solution solution;
    vector<vector<int>> triangle = solution.generate(5);
    for (const auto &i : triangle) {
        for (auto j : i) {
            cout << j << " " ;
        }
        cout << endl;
    }

}
#endif //LEETCODE_118_PASCAL_TRIANGLE_H
