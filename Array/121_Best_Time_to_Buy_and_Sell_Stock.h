//
// Created by 张永斌 on 2021/3/5.
//

#ifndef LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
#define LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H

#include <iostream>
#include <vector>

using namespace std;

//显然，如果我们真的在买卖股票，我们肯定会想：如果我是在历史最低点买的股票就好了！
// 太好了，在题目中，我们只要用一个变量记录一个历史最低价格 minprice，
// 我们就可以假设自己的股票是在那天买的。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        for(int p = 0; p <= prices.size() - 1; ++p) {
            if(min > prices[p])
                min = prices[p];
            else if(prices[p] - min > max){
                max = prices[p] - min;
            }
        }

        return max;
    }
};

void Test(){
    Solution solution;
    vector<int> prices {7,1,5,3,6};
    cout << solution.maxProfit(prices) << endl;
}
#endif //LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
