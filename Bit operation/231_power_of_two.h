//
// Created by 张永斌 on 2021/4/16.
//

#ifndef LEETCODE_231_POWER_OF_TWO_H
#define LEETCODE_231_POWER_OF_TWO_H

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }
        long x = n;
        return (x & (-x) == x)
    }
};

#endif //LEETCODE_231_POWER_OF_TWO_H
