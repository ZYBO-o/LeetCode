//
// Created by 张永斌 on 2021/6/2.
//

#ifndef LEETCODE_343_INTEGER_BREAK_H
#define LEETCODE_343_INTEGER_BREAK_H

class IntegerBreak {
public:
    int integerBreak(int n) {
        //确定dp数组及其下标含义
        vector<int> dp(n + 1);
        //递推公式
        //dp[i] = max(j * dp[i - j], j * (i - j))
        //dp数组初始化
        dp[2] = 1;
        //循环遍历
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j < i - 1; ++j) {
                dp[i] = max ( dp[i],max(j * dp[i - j], j * (i - j)));
            }
        }
        for (auto  i : dp) {
            cout << i << " ";
        }
        cout << endl;
        return dp[n];
    }
    int integerBreak1(int n) {
        //确定dp数组及其下标含义
        vector<int> dp(n + 1);
        //递推公式
        //dp[i] = max(j * dp[i - j], j * (i - j))
        //dp数组初始化
        dp[2] = 1;
        //循环遍历
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j < i - 1; ++j) {
                dp[i] = max(j * dp[i - j], j * (i - j));
            }
        }
        for (auto  i : dp) {
            cout << i << " ";
        }
        cout << endl;
        return dp[n];
    }
};


#endif //LEETCODE_343_INTEGER_BREAK_H
