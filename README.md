# LeetCode刷题积累

### Array

#### 双指针方法

+ [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/)

> 很典型的双指针，但是自己没有想出来；答案方法：
>
> 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。(这样就把0自然而然的向后面移动了)
>
> 注意到以下性质：
>
> [0,left)为非0数，
>
> [left,right]为0。
>
> 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
```

+ [[56. 合并区间]](https://leetcode-cn.com/problems/insert-interval/)

  > 排序

  ```c++
  class Solution {
  public:
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
  
          if (intervals.size() == 0) {
              return {};
          }
          sort(intervals.begin(), intervals.end());
          vector<vector<int>> merged;
  
          for (int i = 0; i < intervals.size(); ++i) {
              int left = intervals[i][0], right = intervals[i][1];
              if (!merged.size() || merged.back()[1] < left) {
                  merged.push_back({left, right});
              } else {
                  merged.back()[1] = max(merged.back()[1], right);
              }
          }
          return merged;
      }
  };
  ```



#### 数学推导与概念

+ [54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)

  > 有关图形转换，这也是一道数学推导题
  >
  > 设置left,right,top,bottom四个变量，在遍历过程中查看四个变量的变换过程。

  ```c++
  int numEle = matrix.size() * matrix[0].size();
  while (numEle > 0) {
  	for (int i = left; i <= right && numEle > 0; ++i) {
  		nums.push_back(matrix[top][i]);
  		-- numEle;
  	}
  	++ top;
  	for (int i = top; i <= bottom && numEle > 0; ++i) {
  		nums.push_back(matrix[i][right]);
  		-- numEle;
  	}
  	-- right;
  	for (int i = right; i >= left && numEle > 0; --i) {
  		nums.push_back(matrix[bottom][i]);
  		-- numEle;
  	}
  	-- bottom;
  	for (int i = bottom; i >= top && numEle > 0; --i) {
  		nums.push_back(matrix[i][left]);
  		-- numEle;
  	}
  	++ left;
  }
  ```





+ [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)

  > **有关数学推导**
  >
  > 可以看出需要移动四个方位的内容：
  >
  > int temp = matrix [ i ] [ j ];
  > matrix [ i ] [ j ]  = matrix [ n - j - 1 ] [ i ];
  > matrix[ n - j - 1 ] [ i ] = matrix[ n - i - 1 ] [ n - j - 1 ];
  > matrix[ n - i - 1 ] [ n - j - 1 ] = matrix[ j ] [ n - i - 1 ];
  > matrix[ j ] [ n - i - 1 ] = temp;

  ```c++
  class Solution {
  public:
      void rotate(vector<vector<int>>& matrix) {
          int n = matrix.size();
          for (int i = 0; i < n / 2; ++i) {
              for (int j = 0; j < (n + 1) / 2; ++j) {
                  int temp = matrix[i][j];
                  matrix[i][j] = matrix[n - j - 1][i];
                  matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                  matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                  matrix[j][n - i - 1] = temp;
              }
  
          }
      }
  };
  ```



+ [66. 加一](https://leetcode-cn.com/problems/plus-one/)

  > **有关数学进位**
  >
  > 主要是注意遇到9时需要进位，如果最后进位到最高位，需要加一个长度。

  ```c++
  class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int i = digits.size() - 1;
        	//进位
          while(i >= 0 && (digits[i] + 1) % 10 ==  0) {
              digits[i] = 0;
              -- i;
          }
  				//如果最高位是9，赋0，增位
          if( i == -1 && digits[0] == 0) {
              digits[0] = 1;
              digits.push_back(0);
          //如果最高位不是9，直接+1
          } else {
              ++ digits[i];
          }
          return digits;
      }
  };
  ```

---

### Hash

哈希表是 **根据关键码的值而直接进行访问的数据结构。**

> 哈希表（英文名字为Hash table，国内也有一些算法书籍翻译为散列表，大家看到这两个名称知道都是指hash table就可以了）

其实直白来讲其实数组就是一张哈希表。 **哈希表中关键码就是数组的索引下表，然后通过下表直接访问数组中的元素，** 如下图所示：

<div align="center">  
  <img src="https://github.com/ZYBO-o/C-plus-plus-Series/blob/main/images/50.png"  width="300"/> 
</div>

