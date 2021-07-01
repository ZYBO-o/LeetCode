//
// Created by 张永斌 on 2021/7/1.
//

#ifndef LEETCODE_OFFER_48_H
#define LEETCODE_OFFER_48_H

#include <unordered_map>

class LengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dir;
        int i = -1, res = 0;

        for(int j = 0;j<s.size();++j){
            if(dir.count(s[j])){
                i = max(dir[s[j]],i);
            }
            dir[s[j]]=j ;
            res = max(res, j-i);
        }
        return res;
    }
};


#endif //LEETCODE_OFFER_48_H
