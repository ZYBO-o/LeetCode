//
// Created by 张永斌 on 2021/3/4.
//

#ifndef LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
#define LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        if(nums.size() <= 2) return nums.size();
//        for (int i = 0; i < nums.size() - 1; ) {
//            int p = i + 1;
//            int count = 1; // 计数器，记录重复数
//            while(nums[p] == nums[i] && p < nums.size()) {
//                ++ count;
//                if(count > 2) {
//                    for (int j = p; j < nums.size() - 1; ++j) {
//                        nums[j] = nums[j + 1];
//                    }
//                    nums.resize(nums.size() - 1);
//
//                }
//                if(count > 2)
//                    -- count;
//                else
//                    ++p;
//            }
//            i = p;
//        }
//        return nums.size();
//    }
//};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int ipx = 0, cnt = 0;//ipx为指向下一个要覆盖元素的位置，cnt记录重复元素的数量

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){//如果跟前一项重复，cnt增加
                cnt++;
                if(cnt < 2){//如果出现次数少于2，覆盖
                    nums[ipx++] = nums[i];
                }
            }else{//如果不重复，则覆盖
                cnt = 0;
                nums[ipx++] = nums[i];
            }
        }
        return ipx;//返回数组长度
    }
};

void Test()
{
    vector<int> nums {1,1,2,2};
    Solution solution;
    int len = solution.removeDuplicates(nums);
    cout << len << endl;
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}


#endif //LEETCODE_80_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_II_H
