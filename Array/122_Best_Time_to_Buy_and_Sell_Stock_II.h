//
// Created by 张永斌 on 2021/3/6.
//

#ifndef LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
#define LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        int max = 0;
//        for (int p = 0; p < prices.size(); ++p) {
//            for (int i = p + 1; i < prices.size(); ++i) {
//                if(prices[p] > prices[i]) {
//                    ++ p;
//                    ++ i;
//                }
//
//                if (prices[p] < prices[i] && prices[i + 1] >= prices[i] && i < prices.size()) {
//                    continue;
//                } else if(prices[p] < prices[i] && prices[i + 1] < prices[i] && i < prices.size())  {
//                    max += prices[i] - prices[p];
//                    p = i + 1;
//                    ++ i;
//                }
//
//            }
//        }
//        return max;

        if (prices.empty() || prices.size() <= 1) return 0;

        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {  // 卖出有利可图
                ans += (prices[i] - prices[i-1]);
            }
        }

        return ans;
    }
};

void Test() {
    vector<int> prices {2,3,6,9};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
}


#endif //LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
