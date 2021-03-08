//
// Created by 张永斌 on 2021/3/7.
//

#ifndef LEETCODE_228_SUMMARY_RANGES_H
#define LEETCODE_228_SUMMARY_RANGES_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> summaryRanges;
        int i = 0;
        int n = nums.size();
        while (i <n) {
            int low = i;
             i++;
            while((nums[i - 1] + 1 == nums[i]) && i  <n) {
               i ++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if(low < high) {
                temp.append( "->" );
                temp.append(to_string(nums[high]));
            }
            summaryRanges.push_back(move(temp));
        }
        return summaryRanges;
    }
};


void Test() {

    Solution solution;
    vector<int> nums {0,1};
    vector<string> summaryRanges = solution.summaryRanges(nums);
    for (const auto & i : summaryRanges) {
        cout << i << " ";
    }
    cout << endl;

}

#endif //LEETCODE_228_SUMMARY_RANGES_H
