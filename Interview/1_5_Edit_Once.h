//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_5_EDIT_ONCE_H
#define LEETCODE_1_5_EDIT_ONCE_H

#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <algorithm>
#include <cmath>


using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.size(), len2 = second.size();
        if (abs(len1 - len2) >= 2) {
            return false;
        }

        if (len2 > len1) {  //为了方便保证first更长
            return oneEditAway(second, first);
        }

        for (int i = 0; i < len2; ++i) {
            if (first[i] != second[i]) {
                return first.substr(i + 1) == second.substr(len1 == len2 ? i+1 : i);
            }
        }
        return true;
    }
};

void Test() {
    string first = "bc";
    string second = "ab";
    Solution solution;
    cout << solution.oneEditAway(first,second) << endl;
}

#endif //LEETCODE_1_5_EDIT_ONCE_H
