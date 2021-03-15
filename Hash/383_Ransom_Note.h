//
// Created by 张永斌 on 2021/3/15.
//

#ifndef LEETCODE_383_RANSOM_NOTE_H
#define LEETCODE_383_RANSOM_NOTE_H

#include "Hash.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int word[26] = {0};

        for (int i = 0; i < magazine.size(); ++i) {
            ++ word[magazine[i] - 'a'];
        }

        for (int i = 0; i < ransomNote.size(); ++i) {
            -- word[ransomNote[i] - 'a'];
        }

        for (int i = 0; i < ransomNote.size(); ++i) {
            if(word[ransomNote[i] - 'a'] < 0)
                return false;
        }

        return true;
    }
};


void Test() {
    string ransomNote {"fihjjjjei"};
    string magazine {"hjibagacbhadfaefdjaeaebgi"};
    Solution solution;
    cout << solution.canConstruct(ransomNote,magazine) << endl;
}


#endif //LEETCODE_383_RANSOM_NOTE_H
