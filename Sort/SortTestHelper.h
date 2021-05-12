//
// Created by 张永斌 on 2021/5/11.
//

#ifndef LEETCODE_SORTTESTHELPER_H
#define LEETCODE_SORTTESTHELPER_H

#include<iostream>
#include<ctime>
#include<cassert>
#include<vector>

namespace SortTestHelper {
    //生成有N个元素的随机数组，每个元素的随机范围是[rangeL, rangeR]
    std::vector<int> generateRandomVector(int n, int rangeL,int  rangeR) {
        assert(rangeL <= rangeR);

        std::vector<int> res;
        srand(time(nullptr));

        for(int i = 0; i < n; ++i)
            res.push_back(rand() % (rangeR - rangeL + 1) + rangeL );

        return res;
    }
}

#endif //LEETCODE_SORTTESTHELPER_H
