//
// Created by 张永斌 on 2021/6/21.
//

#ifndef LEETCODE_TEST_STRING_H
#define LEETCODE_TEST_STRING_H

#include "Reverse_Words_In_A_String.h"

void Test_String() {
    //string result = reverseWords("  hello world  ");
    string result = removeSpace("  hello  world  ");
    std::cout << result << std::endl;
}

#endif //LEETCODE_TEST_STRING_H
