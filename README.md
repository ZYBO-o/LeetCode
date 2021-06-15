# 数据结构与算法积累

> 例题为《剑指offer》与一些典型问题。

## 程序分析



## 一.数组

#### [剑指 Offer 03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)

> 题目说明尚未被充分使用，即 **在一个长度为 n 的数组 nums 里的所有数字都在 0 ~ n-1 的范围内 。**  此说明含义：数组元素的 **索引 和 值 是 一对多 的关系。**
> 因此，可遍历数组并通过交换操作，使元素的 索引 与 值 一一对应（即 nums[i]=i ）。因而，就能通过索引映射对应的值，起到与字典等价的作用。

<img src="images/Array1.png" width="500px"/>

遍历中，第一次遇到数字 x 时，将其交换至索引 x 处；而当第二次遇到数字 x 时，一定有 nums[x] = x ，此时即可得到一组重复数字。

+ 算法流程：

  1. 遍历数组 nums ，设索引初始值为 i = 0 :
     + 若 nums[i] = i ： 说明此数字已在对应索引位置，无需交换，因此跳过；
     + 若 nums[nums[i]] = nums[i]： 代表索引 nums[i] 处和索引 i 处的元素值都为 nums[i] ，即找到一组重复值，返回此值 nums[i] ；
     + 否则： 交换索引为 i 和 nums[i] 的元素值，将此数字交换至对应索引位置。

  2. 若遍历完毕尚未返回，则返回 −1 。

+ 复杂度分析：

  + 时间复杂度 O(N) ： 遍历数组使用 O(N) ，每轮遍历的判断和交换操作使用 O(1) 。
  + 空间复杂度 O(1)： 使用常数复杂度的额外空间。

```c++
class Solution {
public:
    int duplicate(vector<int>& nums) {
        unsigned long i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};
```

#### [剑指 Offer 04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

如下图所示，我们将矩阵逆时针旋转 45° ，并将其转化为图形式，发现其类似于 二叉搜索树 ，即对于每个元素，其左分支元素更小、右分支元素更大。因此，通过从 “根节点” 开始搜索，遇到比 target 大的元素就向左，反之向右，即可找到目标值 target 。

<img src="images/Array2.png" width="500px"/>

“根节点” 对应的是矩阵的 “左下角” 和 “右上角” 元素，本文称之为 标志数 ，以 matrix 中的 左下角元素 为标志数 flag ，则有:

若 flag > target ，则 target 一定在 flag 所在 行的上方 ，即 flag 所在行可被消去。
若 flag < target ，则 target 一定在 flag 所在 列的右方 ，即 flag 所在列可被消去。

+ **算法流程**

  1. 从矩阵 matrix 左下角元素（索引设为 (i, j) ）开始遍历，并与目标值对比：
     + 当 matrix[i] [j] > target 时，执行 i-- ，即消去第 i 行元素；
     + 当 matrix[i] [j] < target 时，执行 j++ ，即消去第 j 列元素；
     + 当 matrix[i] [j] = target 时，返回 true ，代表找到目标值。
  2. 若行索引或列索引越界，则代表矩阵中无目标值，返回 false 。

  > 每轮 `i` 或 `j` 移动后，相当于生成了“消去一行（列）的新矩阵”， 索引`(i,j)` 指向新矩阵的左下角元素（标志数），因此可重复使用以上性质消去行（列）。

+ **复杂度分析：**
  + 时间复杂度 O(M+N) ：其中，N 和 M 分别为矩阵行数和列数，此算法最多循环 M+N 次。
  + 空间复杂度 O(1) : i, j 指针使用常数大小额外空间。

```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty() || array[0].empty())
            return false;
        int row = 0;
        int line = array[0].size() - 1;
        while(row < array.size() && line >= 0) {
            if(target < array[row][line])
                --line;
            else if(target > array[row][line])
                ++row;
            else if(target == array[row][line])
                return true;
        }
        return false;
    }
};
```

#### [剑指 Offer 29. 顺时针打印矩阵](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)

> 有关图形转换，这也是一道数学推导题
>
> 设置left,right,top,bottom四个变量，在遍历过程中查看四个变量的变换过程。

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result {};
        if(matrix.empty()) return result;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        int sum = matrix.size() * matrix[0].size();
        while(sum > 0) {
            //导出最上面一行
            for(int i = left; i <= right && sum > 0; ++i) {
                result.push_back(matrix[top][i]);
                -- sum;
            }
            ++ top;
            //导出最右边一行
            for(int i = top; i <= bottom && sum > 0; ++i) {
                result.push_back(matrix[i][right]);
                -- sum;
            }
            -- right;
            //导出最下面一行
            for(int i = right; i >= left && sum > 0; --i) {
                result.push_back(matrix[bottom][i]);
                -- sum;
            }
            -- bottom;
            //导出最上面一行
            for(int i = bottom; i >= top && sum > 0; --i) {
                result.push_back(matrix[i][left]);
                -- sum;
            }
            ++ left;
        }
        return result;
    }
};
```

## 二.字符串





## 三.链表





## 四.哈希表



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



## 五.双指针



## 六.位运算



## 七.栈和队列





## 八.二叉树





## 九.递归与回溯





## 十.贪心



## 十一.动态规划





## 十二.排序与查找







