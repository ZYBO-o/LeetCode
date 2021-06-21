//
// Created by 张永斌 on 2021/6/21.
//

#ifndef LEETCODE_REVERSE_WORDS_IN_A_STRING_H
#define LEETCODE_REVERSE_WORDS_IN_A_STRING_H

string removeSpace(string s) {
    int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
    // 去掉字符串前面的空格
    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
        fastIndex++;
    }
    for (; fastIndex < s.size(); fastIndex++) {
        // 去掉字符串中间部分的冗余空格
        if (fastIndex - 1 > 0
            && s[fastIndex - 1] == s[fastIndex]
            && s[fastIndex] == ' ') {
            continue;
        } else {
            s[slowIndex++] = s[fastIndex];
        }
    }
    if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
        s.resize(slowIndex - 1);
    } else {
        s.resize(slowIndex); // 重新设置字符串大小
    }
    return s;
}

string reverseWords(string s) {

}

#endif //LEETCODE_REVERSE_WORDS_IN_A_STRING_H
