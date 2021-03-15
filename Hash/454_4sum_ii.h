//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_454_4SUM_II_H
#define LEETCODE_454_4SUM_II_H


#include "Hash.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> result_map ;
        for(auto a : A)
            for(auto b : B) {
                ++ result_map[a + b];
            }

        int count = 0;
        for(auto c : C)
            for(auto d : D) {
                if(result_map.find(0 - (c + d)) != result_map.end()) {
                    count += result_map[0 - (c + d)];
                }
            }
        return count;
    }
};

void Test() {
    vector<int> A {1,2};
    vector<int> B {-2,-1};
    vector<int> C {-1,2};
    vector<int> D {0,2};

    Solution solution;
    cout << solution.fourSumCount(A,B,C,D);
}

#endif //LEETCODE_454_4SUM_II_H
