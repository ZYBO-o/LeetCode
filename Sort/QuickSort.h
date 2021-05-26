//
// Created by 张永斌 on 2021/5/25.
//

#ifndef LEETCODE_QUICKSORT_H
#define LEETCODE_QUICKSORT_H

//把数组分成两部分
template<typename T>
int Partition(vector<T>& nums, int begin, int end) {

    T pv = nums[begin];

    while (begin < end) {
        //换成pv < nums[end]会导致有多数pv值的情况下会停住
        while ((begin < end) && (pv <= nums[end] ))
            --end;
        nums[begin] = nums[end];

        while ((begin < end) && (pv >= nums[begin]))
            ++ begin;
        nums[end] = nums[begin];
    }
    nums[begin] = pv;
    return begin;
}

//进行递归快速排序
template<typename T>
void Quick(vector<T>& nums, int begin, int end) {
    if(begin >= end)
        return;

    int pivot = Partition(nums, begin, end);

    Quick(nums, begin, pivot - 1);
    Quick(nums, pivot + 1, end);
}

template<typename T>
void QuickSort(vector<T>& nums) {
    Quick(nums, 0, nums.size() - 1);
    for(auto i : nums)
        cout << i << " ";
    cout << endl;
}


#endif //LEETCODE_QUICKSORT_H
