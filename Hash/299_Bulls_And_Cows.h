//
// Created by 张永斌 on 2021/4/6.
//

#ifndef LEETCODE_299_BULLS_AND_COWS_H
#define LEETCODE_299_BULLS_AND_COWS_H

#include "Hash.h"

class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0;
        int y = 0;
        int count = secret.size();
        int i = 0;
        unordered_map<char,int> hash1;
        unordered_map<char,int> hash2;
        while(i < count) {
            if(secret[i] == guess[i]) {
                ++ x;
            }
            hash1[secret[i]]++;
            hash2[guess[i]]++;
            ++i;
        }

        for(auto iter=hash1.begin();iter!=hash1.end();iter++)
        {
            //统计母牛，关注点为什么用了min
            if(hash2.find((*iter).first)!=hash2.end())
                y += min((*iter).second,hash2[(*iter).first]);
        }


        string ans = to_string(x) + "A" + to_string(y-x) + "B";
        return ans;
    }
};

void Test() {
    string secret = "1123";
    string guess = "0111";
    Solution solution;
    cout << solution.getHint(secret,guess) << endl;
}


#endif //LEETCODE_299_BULLS_AND_COWS_H
