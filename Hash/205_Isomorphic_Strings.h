//
// Created by 张永斌 on 2021/3/17.
//

#ifndef LEETCODE_205_ISOMORPHIC_STRINGS_H
#define LEETCODE_205_ISOMORPHIC_STRINGS_H

#include "Hash.h"

//Map的应用，要熟练
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};


void Test() {
    string s = "bbbaaaba";
    string t = "aaabbbba";
    Solution solution;
    cout << solution.isIsomorphic(s,t) << endl;
}


#endif //LEETCODE_205_ISOMORPHIC_STRINGS_H
