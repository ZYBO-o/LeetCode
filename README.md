# 数据结构与算法积累

> 例题为《剑指offer》与一些典型问题。

## 程序分析



## 一.数组​ :a:

🔹 [利用题目意境](https://github.com/ZYBO-o/LeetCode/tree/main/Array#1%E5%88%A9%E7%94%A8%E9%A2%98%E7%9B%AE)

🔸 [双指针](https://github.com/ZYBO-o/LeetCode/tree/main/Array#2%E5%8F%8C%E6%8C%87%E9%92%88)

🔹[数学推导](https://github.com/ZYBO-o/LeetCode/tree/main/Array#3%E6%95%B0%E5%AD%A6%E5%88%86%E6%9E%90)

## 二.字符串 :star2:





## 三.链表 :shinto_shrine:

🔹 [链表操作](https://github.com/ZYBO-o/LeetCode/tree/main/List#%E4%B8%80%E5%8D%95%E9%93%BE%E8%A1%A8%E6%93%8D%E4%BD%9C)

🔸[例题解剖](https://github.com/ZYBO-o/LeetCode/tree/main/List#leetcode%E7%A7%AF%E7%B4%AF)



## 四.哈希表 :balance_scale:



### 2.剑指offer原题

#### [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

+  **算法流程**

  1. 初始化： 新建无序哈希表maps ；

  2. 遍历数组 nums 中的每个数字 num ：
     + 当 num 在 maps 中，说明重复，直接返回 num ；
     + 不在 maps ，则将 num 添加至 maps 中；

  3. 返回 -1 。本题中一定有重复数字，因此这里返回多少都可以。

+  **复杂度分析：**

  + 时间复杂度 O(N) ： 遍历数组使用 O(N) ，maps 添加与查找元素皆为 O(1) 。
  + 空间复杂度 O(N) ： maps 占用 O(N) 大小的额外空间。

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> maps;
        for(auto num : nums) {
            if(maps[num] < 1)
                maps[num] ++;
            else
                return num;
        }
        return -1;
    }
};
```



## 五.双指针和滑动窗口 :dolls:

### 1.双指针
🔹 [快慢指针](https://github.com/ZYBO-o/LeetCode/tree/main/Double%20Pointer#1%E5%BF%AB%E6%85%A2%E6%8C%87%E9%92%88)

🔸[左右指针](https://github.com/ZYBO-o/LeetCode/tree/main/Double%20Pointer#2%E5%B7%A6%E5%8F%B3%E6%8C%87%E9%92%88)

🔹 [额外趣题](https://github.com/ZYBO-o/LeetCode/tree/main/Double%20Pointer#3%E9%A2%9D%E5%A4%96%E8%B6%A3%E9%A2%98)

### 2.滑动窗口

🔹 [框架构建](https://github.com/ZYBO-o/LeetCode/tree/main/Double%20Pointer#1%E6%A1%86%E6%9E%B6%E6%9E%84%E5%BB%BA)

🔸[例题解剖](https://github.com/ZYBO-o/LeetCode/tree/main/Double%20Pointer#2%E4%BE%8B%E9%A2%98%E8%A7%A3%E5%89%96)

## 六.位运算



## 七.栈和队列





## 八.二叉树





## 九.递归与回溯



## 十.贪心



## 十一.动态规划





## 十二.排序与查找 :dolls:

### 排序

:one: [冒泡排序]()

:two: [选择排序]() 

:three: [插入排序]()

:four: [希尔]()

:five: [归并]()

:six: [快速排序]()

:seven: [堆排序]()

:eight: [计数排序]()

:nine: [桶排序]()

:keycap_ten: [基数排序]()

### 查找





## 十三.二分搜索算法

二分搜索（binary search），也称折半搜索（half-interval search）、对数搜索（logarithmic search），是一种在 **有序数组** 中查找某一特定元素的搜索算法。

### 1.二分搜索框架：

```c++
int binarySearch(int[] nums, int target) { 
    int left = 0, right = ...;
    while(...) {
        int mid = left + (right - left) / 2; 
        if (nums[mid] == target) {
          	...
        } else if (nums[mid] < target) { 
          	left = ...
        } else if (nums[mid] > target) { 
          	right = ...
        }
    }
    return ...; 
}
```

+ **不要出现** **else**，而是把所有情况用 **else if** **写清 楚，这样可以清楚地展现所有细节**

+ 其中`...`标记的部分，就是可能出现细节问题的地方，⻅到一个二分查找的代码时，首先注意这几个地方。做到具体问题具体分析。
+ 计算mid时需要防止溢出，代码中 `left + (right - left) / 2` 就和 `(left + right) / 2` 的结果相同，但是有效防止了 left 和 right 太大直接相加导致溢出。



### 2.基本的二分搜索(寻找一个数)

> 搜索一个数，如果存在， 返回其索引，否则返回 -1。

```c++
int  binary_search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2 ;
        if(nums[mid] == target) {
            return result;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}
```

+ **为什么 while 循环的条件中是 <=，而不是 < ?**

  > + 因为初始化 right 的赋值是 nums.length - 1 ，即最后一个元素的索引，而不是 nums.length。前者相当于两端都闭区间 [left, right] ，后者相当于左闭右开区间 [left, right) ，而索引大小为 nums.length 是越界的。
  >
  > + 而终止的条件是找到直接返回，或者最后没有找到target，while终止。
  >
  >   + 其中，`while(left <= right)` 的终止条件是 `left == right + 1 `，写成区间的形式就是` [right + 1, right]` ，或者带个具体的数字进去 [3, 2] 。
  >
  >   + `while(left < right)` 的终止条件是 `left == right` ，写成区间的形式就是
  >
  >     `[left, right]` ，或者带个具体的数字进去 [2, 2] ，**这时候区间非空**，有遗漏。

+ **此算法的缺陷：**

  > 比如说给你有序数组 nums = [1,2,2,2,3] ， target 为 2，此算法返回的索引是 2，没错。但是如果我想得到 target 的左侧边界，即索引 1，或者我 想得到 target 的右侧边界，即索引 3，这样的话此算法是无法处理的。



### 3.寻找左侧边界的二分查找

```c++
void left_bound(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();//注意

    while (left < right) {//注意
        int mid = left + (right - left) / 2 ;
        if(nums[mid] == target) {
            right =  mid;//注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;//注意
        }
    }
    return left;
}
```

+  **为什么 while 循环的条件中是 <，而不是 <= ?**

  > + 因为 `right = nums.length` 而不是 `nums.length - 1` 。因此每次循环的「搜索区间」是 [left, right) 左闭右开。
  >
  > + `while(left < right) `终止的条件是 `left == right` ，此时搜索区间` [left, left)` 为空，所以可以正确终止。

+ **为什么** **left = mid + 1** **，** **right = mid** **?和之前的算法不一样**?

  > + 因为我们的「搜索区间」是` [left, right)`左闭右 开，所以当` nums[mid]` 被检测之后，下一步的搜索区间应该去掉 mid 分 割成两个区间，即 `[left, mid)` 或 `[mid + 1, right) `。

+ **为什么该算法能够搜索左侧边界**?

  > + 关键在于对于 nums[mid] == target 这种情况的处理:
  >
  >   ```c++
  >   if(nums[mid] == target) 
  >   		right =  mid;
  >   ```
  >
  >   可⻅，找到 target 时不要立即返回，而是缩小「搜索区间」的上界 right ，在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左侧边界的目的。



### 4.逻辑统一的查找

```c++
int  binary_search(std::vector<int>& nums, int target) {
    int left = 0;
  	int right = nums.size() - 1;
  
    while(left <= right) {
        int mid = left + (right - left) / 2 ;
        if(nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

int left_bound(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2 ;
        if(nums[mid] == target) {
            right =  mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return left;
}

int right_bound(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2 ;
        if(nums[mid] == target) {
            left =  mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return right ;
}
```



## 十四.广度优先遍历





## 十五.并查集



