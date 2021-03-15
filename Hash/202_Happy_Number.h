//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_202_HAPPY_NUMBER_H
#define LEETCODE_202_HAPPY_NUMBER_H

#include "Hash.h"

class Solution {
public:
    //求和
    int getSum(int n) {
        int sum = 0;
        while(n) {
            sum +=  (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> nums ;
        while(1) {
            int sum = getSum(n);
            if(sum == 1) {
                return true;
            } else {
                if(nums.find(sum) != nums.end()) {
                    return false;
                } else {
                    nums.insert(sum);
                };
                n = sum;
            }
        }
    }
};

void Test() {
    Solution solution;
    cout << solution.isHappy(19) << endl;
}


#endif //LEETCODE_202_HAPPY_NUMBER_H
