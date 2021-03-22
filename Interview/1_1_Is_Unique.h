//
// Created by 张永斌 on 2021/3/22.
//

#ifndef LEETCODE_1_1_IS_UNIQUE_H
#define LEETCODE_1_1_IS_UNIQUE_H

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0, step = 0;
        for(const int letter:astr){
            step = letter-int('a');
            if(mask & (1<<step))
                return false;
            mask |= (1<<step);
        }
        return true;
    }
};

void Test() {
    string astr = "leetcode";
    Solution solution;
    cout << solution.isUnique(astr) << endl;
}


#endif //LEETCODE_1_1_IS_UNIQUE_H
