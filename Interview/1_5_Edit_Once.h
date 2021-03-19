//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_5_EDIT_ONCE_H
#define LEETCODE_1_5_EDIT_ONCE_H

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        unordered_map<char,int>map;
        for(auto c : first)
            map[c] ++;
        for(auto c : second)
            map[c] --;

        int count = 0;
        for (auto n : map) {
            if(n.second > 1 || n.second < -1 )
                return false;
            else if(n.second == 1 || n.second == -1)
                ++ count;
        }
        if(count == 1 || count == 0)
            return true;
        else
            return false;
    }
};

void Test() {
    string first = "a";
    string second = "b";
    Solution solution;
    cout << solution.oneEditAway(first,second) << endl;
}

#endif //LEETCODE_1_5_EDIT_ONCE_H
