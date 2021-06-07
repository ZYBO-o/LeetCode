//
// Created by 张永斌 on 2021/6/7.
//

#ifndef LEETCODE_BUCKETSORT_H
#define LEETCODE_BUCKETSORT_H


#include <cmath>

void BucketSort(vector<int>& nums ){

    //设置桶的个数
    int count = (int)sqrt(nums.size()) + 1;
    vector<int> Bucket[count] ;
    memset(Bucket, 0, sizeof (Bucket));

    // 将每个元素插入到相应的桶中
    int pos;
    for (auto temp : nums) {
        pos = temp / 10 ;  // 求出该元素在哪个桶
        Bucket[pos].push_back(temp);  // 把该元素放入某个桶中
    }

    for (int i = 0; i < count; ++i) {
        sort(Bucket[i].begin(), Bucket[i].end());
    }

    for( auto  bucket : Bucket) {
        for (auto temp : bucket) {
            cout << temp << " ";
        }
    }
    cout << endl;
}



#endif //LEETCODE_BUCKETSORT_H
