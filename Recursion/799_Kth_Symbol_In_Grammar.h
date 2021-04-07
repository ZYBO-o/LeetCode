//
// Created by 张永斌 on 2021/4/7.
//

#ifndef LEETCODE_799_KTH_SYMBOL_IN_GRAMMAR_H
#define LEETCODE_799_KTH_SYMBOL_IN_GRAMMAR_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> kthGrammar(int N, int K) {
        vector<int> ans;
        if(N == 1) {
            return ans;
        } else {
            return kthGrammar(N-1,K);
        }
    }
};

void Test () {
    Solution solution;
    vector<int>ans = solution.kthGrammar(4,5) ;
    for (int i : ans) {
        cout << i << " ";
    }
}


#endif //LEETCODE_799_KTH_SYMBOL_IN_GRAMMAR_H
