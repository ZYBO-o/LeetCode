//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_242_VALID_ANAGRAM_H
#define LEETCODE_242_VALID_ANAGRAM_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int find[26] {0};
        bool flag = true;
        for (auto i = 0; i < s.size(); ++i) {
            ++find[s[i] - 'a'];
        }
        for (auto i = 0; i < t.size(); ++i) {
            --find[t[i] - 'a'];
        }
        for (auto i : find) {
            if(i != 0) {
                flag = false;
            }
        }
        return flag;
    }
};

void Test() {
    string s {"anagram"};
    string t {"nagaram"};
    Solution solution;
    cout << solution.isAnagram(s,t) << endl;
}

#endif //LEETCODE_242_VALID_ANAGRAM_H
