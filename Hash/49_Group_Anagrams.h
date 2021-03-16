//
// Created by 张永斌 on 2021/3/16.
//

#ifndef LEETCODE_49_GROUP_ANAGRAMS_H
#define LEETCODE_49_GROUP_ANAGRAMS_H

#include "Hash.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

    }
};

void Test() {
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    vector<vector<string>> ans = solution.groupAnagrams(strs);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << "";
        }
        cout << endl;
    }

}

#endif //LEETCODE_49_GROUP_ANAGRAMS_H
