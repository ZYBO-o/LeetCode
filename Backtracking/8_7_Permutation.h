//
// Created by 张永斌 on 2021/3/24.
//

#ifndef LEETCODE_8_7_PERMUTATION_H
#define LEETCODE_8_7_PERMUTATION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> permutation(string S) {
        int end = S.size();
        vector<string> ans ;
        dsf(ans, S, 0, end);
        return ans;
    }
    void dsf(vector<string>& ans, string S, int begin, int end) {
        if(begin == end) {
            ans.push_back(S);
            return;
        }

        for (int i = begin; i < end; ++i) {
            swap(S[i],S[begin]);
            dsf(ans, S, begin + 1, end);
            swap(S[i],S[begin]);
        }

    }
};


void Test() {
    string S = "abc";
    Solution solution;
    vector<string> ans = solution.permutation(S);
    for (auto  i : ans) {
        cout << i << " ";
    }
}
#endif //LEETCODE_8_7_PERMUTATION_H
