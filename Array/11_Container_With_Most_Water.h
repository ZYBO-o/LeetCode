//
// Created by 张永斌 on 2021/3/1.
//

#ifndef LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
#define LEETCODE_11_CONTAINER_WITH_MOST_WATER_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto begin = height.begin();
        auto end = height.end();
        --end;
        int maxArea = min(*begin,*end) * (end - begin);
        while (begin != end){
            if(*begin < *end){
                ++begin;
                int temp = min(*begin,*end) * (end - begin);
                if(temp > maxArea)
                    maxArea = temp;
            } else {
                --end;
                int temp = min(*begin,*end) * (end - begin);
                if(temp > maxArea)
                    maxArea = temp;
            }
        }
        return maxArea;

    }
};

void Test()
{
    Solution solution;
    vector<int> height {4,3,2,1,4};
    cout << solution.maxArea(height) << endl;


}

#endif //LEETCODE_11_CONTAINER_WITH_MOST_WATER_H
