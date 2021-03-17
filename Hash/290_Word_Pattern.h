//
// Created by 张永斌 on 2021/3/17.
//

#ifndef LEETCODE_290_WORD_PATTERN_H
#define LEETCODE_290_WORD_PATTERN_H

#include "Hash.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words {};
        string temp;
        //分割字符串
        for (int i = 0; i <= s.size(); ++i) {
            if(s[i] != ' ' && s[i] != '\0') {
                temp += s[i];
            } else {
                words.push_back(temp);
                temp = {};
            }
        }

        if(pattern.size() != words.size())
            return false;

        unordered_map<char,string> map1 ;
        unordered_map<string,char> map2 ;

        int len = pattern.length();
        for (int i = 0; i < len; ++i) {
            char x = pattern[i];
            string y = words[i];
            if ((map1.count(x) && map1[x] != y) || (map2.count(y) && map2[y] != x)) {
                return false;
            }
            map1[x] = y;
            map2[y] = x;
        }
        return true;


    }
};

void Test() {
    string pattern {"abbb"};
    string s {"dog cat cat dog"};
    Solution solution;
    cout << solution.wordPattern(pattern,s) << endl;
}

#endif //LEETCODE_290_WORD_PATTERN_H
