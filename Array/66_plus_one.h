//
// Created by 张永斌 on 2021/3/9.
//

#ifndef LEETCODE_66_PLUS_ONE_H
#define LEETCODE_66_PLUS_ONE_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while(i >= 0 && (digits[i] + 1) % 10 ==  0) {
            digits[i] = 0;
            -- i;
        }

        if( i == -1 && digits[0] == 0) {
            digits[0] = 1;
            digits.push_back(0);
        } else {
            ++ digits[i];
        }
        return digits;
    }
};

void Test() {
    Solution solution;
    vector<int> digits {9,9};
    vector<int> plusOne = solution.plusOne(digits);
    for (const int i : plusOne) {
        cout << i << " ";
    }
    cout << endl;
}

#endif //LEETCODE_66_PLUS_ONE_H
