//
// Created by 张永斌 on 2021/5/17.
//

#ifndef LEETCODE_MERGESORT_H
#define LEETCODE_MERGESORT_H

template<typename T>
void merge(std::vector<T>& nums,int* temp, int left, int mid, int right) {
    int i = left;//左序列指针
    int j = mid + 1;//右序列指针
    int t = 0;//临时数组指针
    while (i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[t++] = nums[i++];
        }else {
            temp[t++] = nums[j++];
        }
    }
    while(i <= mid){//将左边剩余元素填充进temp中
        temp[t++] =  nums[i++];
    }
    while(j <= right){//将右序列剩余元素填充进temp中
        temp[t++] = nums[j++];
    }

    t = 0;
    //将temp中的元素全部拷贝到原数组中
    for (int l = 0; l <= right; ++l) {
        nums[l] = temp[l];
    }
}

template<typename T>
void sort(std::vector<T>& nums,int* temp, int left, int right) {
    if(left < right){
        int mid = (left + right)/2;
        sort(nums, temp, left, mid);//左边归并排序，使得左子序列有序
        sort(nums, temp, mid+1,right);//右边归并排序，使得右子序列有序
        merge(nums, temp, left, mid, right);//将两个有序子数组合并操作
    }
}

template<typename T>
void MergeSort(std::vector<T> nums) {
    int* temp = new int(nums.size());

    sort(nums, temp, 0, nums.size()-1);

    for(int i = 0; i < nums.size(); ++i ) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}


#endif //LEETCODE_MERGESORT_H
