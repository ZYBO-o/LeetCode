//
// Created by 张永斌 on 2021/3/19.
//

#ifndef LEETCODE_1_4_PALINDROME_H
#define LEETCODE_1_4_PALINDROME_H

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> myMap;
        for(char c:s){
            myMap[c]++;
        }
        int cnt=0;
        for(auto &x:myMap){
            if(x.second%2==1){//奇数
                cnt++;
            }
            if(cnt==2)
                return false;
        }
        return true;
    }
};

void Test() {
    string s = "aaa";
    Solution solution;
    cout << solution.canPermutePalindrome(s) << endl;
}

#endif //LEETCODE_1_4_PALINDROME_H
