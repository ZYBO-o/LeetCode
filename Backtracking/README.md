# 回溯算法

## 一.回溯法概要

### 1.算法介绍

**回溯法（back tracking）**（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。

> 白话：回溯法可以理解为通过选择不同的岔路口寻找目的地，一个岔路口一个岔路口的去尝试找到目的地。如果走错了路，继续返回来找到岔路口的另一条路，直到找到目的地。

**「回溯法解决的问题都可以抽象为树形结构」**，回溯法解决的都是在集合中递归查找子集，**「集合的大小就构成了树的宽度，递归的深度，都构成的树的深度」**。

递归就要有终止条件，所以必然是一颗高度有限的树（N叉树）。

### 2.算法效率

回溯法的性能如何呢，这里要和大家说清楚了，**「虽然回溯法很难，很不好理解，但是回溯法并不是什么高效的算法」**。

**「因为回溯的本质是穷举，穷举所有可能，然后选出我们想要的答案」**，如果想让回溯法高效一些，可以加一些剪枝的操作，但也改不了回溯法就是穷举的本质。

### 3.解决问题

回溯法，一般可以解决如下几种问题：

- 组合问题：N个数里面按一定规则找出k个数的集合
- 排列问题：N个数按一定规则全排列，有几种排列方式
- 切割问题：一个字符串按一定规则有几种切割方式
- 子集问题：一个N个数的集合里有多少符合条件的子集
- 棋盘问题：N皇后，解数独等等

## 二.算法框架

### 1.回溯三部曲

#### 回溯函数模板返回值以及参数

+ 在回溯算法中习惯是函数起名字为backtracking。
+ 回溯算法中函数返回值一般为void。

+ 再来看一下参数，因为回溯算法需要的参数可不像二叉树递归的时候那么容易一次性确定下来，所以一般是先写逻辑，然后需要什么参数，就填什么参数。

回溯函数伪代码如下：

```c++
void backtracking(参数) 
```

####回溯函数终止条件 

+ 既然是树形结构，那么在讲解二叉树的递归的时候，就知道遍历树形结构一定要有终止条件。所以回溯也有要终止条件。

+ 什么时候达到了终止条件，树中就可以看出，一般来说搜到叶子节点了，也就找到了满足条件的一条答案，把这个答案存放起来，并结束本层递归。

所以回溯函数终止条件伪代码如下：

```c++
if (终止条件) {
    存放结果;
    return;
}
```

####  回溯搜索的遍历过程

**==最重要的就是把遍历过程的树状图画出来==**

在上面提到了，回溯法一般是在集合中递归搜索，集合的大小构成了树的宽度，递归的深度构成的树的深度。

<div align = center><img src="../images/Tree38.png" width="650px"/></div>

注意图中，举例集合大小和孩子的数量是相等的！回溯函数遍历过程伪代码如下：

```c++
for (选择：本层集合中元素(树中节点孩子的数量就是集合的大小)) {
    处理节点;
    backtracking(路径，选择列表); // 递归
    回溯，撤销处理结果
}
```

+ **for循环就是遍历集合区间，可以理解一个节点有多少个孩子，这个for循环就执行多少次。**

+ **backtracking这里自己调用自己，实现递归。**

大家可以从图中看出**「for循环可以理解是横向遍历，backtracking（递归）就是纵向遍历」**，这样就把这棵树全遍历完了，一般来说，搜索叶子节点就是找的其中一个结果了。

分析完过程，回溯算法模板框架如下：

```c++
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```

**「这份模板很重要，后面做回溯法的题目都靠它了！」**



## 三.刷题积累

### 1.组合(77)

> 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

+ **示例：**

  <div align = center><img src="../images/Tree39.png" width="500px" /></div>

+ **思路：**

  + **「在关于算法框架中说道回溯法解决的问题都可以抽象为树形结构（N叉树），用树形结构来理解回溯就容易多了」**。

  + 把组合问题抽象为如下树形结构：

    <div align = center><img src="../images/backtraversal1.png" width="700px"/></div>

    + 可以看出这个棵树，一开始集合是 1，2，3，4， 从左向右取数，取过的数，不在重复取。
    + **「每次从集合中选取元素，可选择的范围随着选择的进行而收缩，调整可选择的范围」**。
    + **「图中可以发现n相当于树的宽度，k相当于树的深度」**。

  + 那么如何在这个树上遍历，然后收集到我们要的结果集呢？

    + **「图中每次搜索到了叶子节点，我们就找到了一个结果」**。相当于只需要把达到叶子节点的结果收集起来，就可以求得 n个数中k个数的组合集合。

+ **回溯三部曲：**

  + **递归函数的返回值以及参数**

    + 在这里要定义两个全局变量，一个用来存放符合条件单一结果，一个用来存放符合条件结果的集合。

      ```c++
      vector<vector<int>> result; // 存放符合条件结果的集合
      vector<int> path; // 用来存放符合条件结果
      ```

    + 函数里一定有两个参数，既然是集合n里面取k的数，那么n和k是两个int型的参数。然后还需要一个参数，为int型变量startIndex，这个参数用来记录本层递归的中，集合从哪里开始遍历（集合就是[1,...,n] ）。

    + 为什么要有这个startIndex呢？**「每次从集合中选取元素，可选择的范围随着选择的进行而收缩，调整可选择的范围，就是要靠startIndex」**。从下图中红线部分可以看出，在集合[1,2,3,4]取1之后，下一层递归，就要在[2,3,4]中取数了，那么下一层递归如何知道从[2,3,4]中取数呢，靠的就是startIndex。

      <div align = center><img src="../images/Backtraversal2.png" width="600px" /></div>

    + 所以需要startIndex来记录下一层递归，搜索的起始位置。

      ```c++
      vector<vector<int>> result; // 存放符合条件结果的集合
      vector<int> path; // 用来存放符合条件单一结果
      void backtracking(int n, int k, int startIndex) 
      ```

  + **回溯函数终止条件**

    + path这个数组的大小如果达到k，说明我们找到了一个子集大小为k的组合了，在图中path存的就是根节点到叶子节点的路径。

      <div align = center><img src="../images/Backtrackinf3.png" width="600px"/></div>

    + 此时用result二维数组，把path保存起来，并终止本层递归。

      ```c++
      if (path.size() == k) {
          result.push_back(path);
          return;
      }
      ```

  + **单层搜索的过程**

    + 回溯法的搜索过程就是一个树型结构的遍历过程，在如下图中，可以看出for循环用来横向遍历，递归的过程是纵向遍历。

      <div align = center><img src="../images/Backtracking4.png" width="600px" /></div>

    + 如此才遍历完图中的这棵树。for循环每次从startIndex开始遍历，然后用path保存取到的节点i。

      ```c++
      for (int i = startIndex; i <= n; i++) { // 控制树的横向遍历
          path.push_back(i); // 处理节点 
          backtracking(n, k, i + 1); // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
          path.pop_back(); // 回溯，撤销处理的节点
      }
      ```

    + 可以看出backtracking（递归函数）通过不断调用自己一直往深处遍历，总会遇到叶子节点，遇到了叶子节点就要返回。backtracking的下面部分就是回溯的操作了，撤销本次处理的结果。

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result; // 存放符合条件结果的集合
      vector<int> path; // 用来存放符合条件结果
      void backtracking(int n, int k, int startIndex) {
          if (path.size() == k) {
              result.push_back(path);
              return;
          }
          for (int i = startIndex; i <= n; i++) {
              path.push_back(i); // 处理节点 
              backtracking(n, k, i + 1); // 递归
              path.pop_back(); // 回溯，撤销处理的节点
          }
      }
  public:
      vector<vector<int>> combine(int n, int k) {
          result.clear(); // 可以不写
          path.clear();   // 可以不写
          backtracking(n, k, 1);
          return result;
      }
  };
  ```

#### 剪枝优化

回溯法虽然是暴力搜索，但也有时候可以有点剪枝优化一下的。

在遍历的过程中有如下代码：

```c++
for (int i = startIndex; i <= n; i++) { 
    path.push_back(i); 
    backtracking(n, k, i + 1); 
    path.pop_back(); 
}
```

这个遍历的范围是可以剪枝优化的，怎么优化呢？来举一个例子，n = 4，k = 4的话，那么第一层for循环的时候，从元素2开始的遍历都没有意义了。在第二层for循环，从元素3开始的遍历都没有意义了。

<div align = center><img src="../images/Backtracking5.png" width="600px" /></div>

图中每一个节点（图中为矩形），就代表本层的一个for循环，那么每一层的for循环从第二个数开始遍历的话，都没有意义，都是无效遍历。

**「所以，可以剪枝的地方就在递归中每一层的for循环所选择的起始位置」**。

**「如果for循环选择的起始位置之后的元素个数 已经不足 我们需要的元素个数了，那么就没有必要搜索了」**。

接下来看一下优化过程如下：

1. **已经选择的元素个数：path.size();**
2. **还需要的元素个数为: k - path.size();**
3. **在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历**

为什么有个+1呢，因为包括起始位置，我们要是一个左闭的集合。

举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。从2开始搜索都是合理的，可以是组合[2, 3, 4]。

所以优化之后的for循环是：

```c++
for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) // i为本次搜索的起始位置
```

### :diamond_shape_with_a_dot_inside: 2.电话号码的字母组合(17)

> 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
>
> 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

+ **示例：**

  <div align = center><img src="../images/Backtracking6.png" width="600px" /></div>

+ **思路：**

  + 理解本题后，要解决如下三个问题：

    1. 数字和字母如何映射
    2. 两个字母就两个for循环，三个字符我就三个for循环，以此类推，然后发现代码根本写不出来
    3. 输入1 * #按键等等异常情况

  + 对于问题1，可以使用map或者定义一个二位数组，例如：string letterMap[10]，来做映射，我这里定义一个二维数组

    ```c++
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    ```

  + 对于问题2，用 回溯法来解决n个for循环的问题。

    <div align = center><img src="../images/Backtracking7.png" width="600px" /></div>

  + 对于问题3，映射确保了输入0,1为空

+ **回溯三部曲：**

  + **确定回溯函数参数**
    + 首先需要一个字符串s来收集叶子节点的结果，然后用一个字符串数组result保存起来，这两个变量定义为全局。
    + 再来看参数，参数指定是有题目中给的string digits，然后还要有一个参数就是int型的index。
    + 注意这个index可不是 回溯算法：求组合问题！ 和 回溯算法：求组合总和！中的startIndex了。 **这个index是记录遍历第几个数字了，就是用来遍历digits的（题目中给出数字字符串），同时index也表示树的深度。**
  + **确定终止条件**
    + 例如输入用例"23"，两个数字，那么根节点往下递归两层就可以了，叶子节点就是要收集的结果集。那么终止条件就是如果index 等于 输入的数字个数（digits.size）了（本来index就是用来遍历digits的）。
    + 然后收集结果，结束本层递归。
  + **确定单层遍历逻辑**
    + 首先要取index指向的数字，并找到对应的字符集（手机键盘的字符集）。
    + 然后for循环来处理这个字符集。

+ **代码实现：**

  ```c++
  class Solution {
  private:
      const string letterMap[10] = {
          "", // 0
          "", // 1
          "abc", // 2
          "def", // 3
          "ghi", // 4
          "jkl", // 5
          "mno", // 6
          "pqrs", // 7
          "tuv", // 8
          "wxyz", // 9
      };
  public:
      vector<string> result;
      string s;
      void backtracking(const string& digits, int index) {
          if (index == digits.size()) {
              result.push_back(s);
              return;
          }
          int digit = digits[index] - '0';        // 将index指向的数字转为int
          string letters = letterMap[digit];      // 取数字对应的字符集
          for (int i = 0; i < letters.size(); i++) {
              s.push_back(letters[i]);            // 处理
              backtracking(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
              s.pop_back();                       // 回溯
          }
      }
      vector<string> letterCombinations(string digits) {
          s.clear();
          result.clear();
          if (digits.size() == 0) {
              return result;
          }
          backtracking(digits, 0);
          return result;
      }
  };
  ```

### 3.组合总和III(216)

> 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
>
> 说明：
>
> - 所有数字都是正整数。
> - 解集不能包含重复的组合。

+ **示例：**

  <div align = center><img src="../images/Backtrack8.png" width="400px" /></div>

+ **思路：**

  + 本题就是在[1,2,3,4,5,6,7,8,9]这个集合中找到和为n的k个数的组合。
  + 相对于 求组合问题！ ，无非就是多了一个限制，本题是要找到和为n的k个数的组合，而整个集合已经是固定的了[1,...,9]。
  + 本题k相当于了树的深度，9（因为整个集合就是9个数）就是树的宽度。

  <div align = center><img src="../images/Backtracking8.png" width="700px" /></div>

+ **回溯三部曲：**

  + **「确定递归函数参数」**

    + 和 回溯算法：求组合问题！一样，依然需要一维数组path来存放符合条件的结果，二维数组result来存放结果集，定义sum存储求和结果。

    ```c++
    int sum;
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k, int n, int startIndex)
    ```

  + **确定终止条件**

    + k其实就已经限制树的深度，因为就取k个元素，树再往下深了没有意义。所以如果path.size() 和 k相等了，就终止。
    + 如果此时path里收集到的元素和（sum） 和 n 相同了，就用result收集当前的结果

    ```c++
    if(path.size() == k) {
    		if(sum == n)
    				result.push_back(path);
    		return;
    }
    ```

  + **「单层搜索过程」**

    + 本题和 求组合问题！ 区别之一就是集合固定的就是9个数[1,...,9]，所以for循环固定i<=9

    <div align = center><img src="../images/Backtracking9.png" width="700px" /></div>

    + 处理过程就是 path收集每次选取的元素，相当于树型结构里的边，sum来统计path里元素的总和。

    ```c++
    for(int i = startIndex; i <= 9; ++i) {
    		sum += i;
    		path.push_back(i);
    		backtracking(k, n, i + 1);
    		path.pop_back();
    		sum -= i;
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
      int sum;
      vector<int> path;
      vector<vector<int>> result;
      void backtracking(int k, int n, int startIndex) {
          //回溯结束条件
          if(path.size() == k) {
              if(sum == n)
                  result.push_back(path);
              return;
          }
          for(int i = startIndex; i <= 9; ++i) {
              sum += i;
              path.push_back(i);
              backtracking(k, n, i + 1);
              path.pop_back();
              sum -= i;
          }
      }
  public:
      vector<vector<int>> combinationSum3(int k, int n) {
          path.clear();
          result.clear();
          sum = 0;
          backtracking(k, n, 1);
          return result;
      }
  };
  ```

### 4.组合总和(39)

> 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
>
> candidates 中的数字可以无限制重复被选取。
>
> 说明：
>
> - 所有数字（包括 target）都是正整数。
> - 解集不能包含重复的组合。

+ **示例：**

  <div align = center><img src="../images/Backtracking10.png" width="450px" /></div>

+ **思路：**

  + 本题和 求组合问题！ ，回溯算法：求组合总和！区别是：本题没有数量要求，可以无限重复，但是有总和的限制，所以间接的也是有个数的限制。

    <div align = center><img src="../images/Backtrack11.png" width="700px" /></div>

  + 注意图中叶子节点的返回条件，因为本题没有组合数量要求，仅仅是总和的限制，所以递归没有层数的限制，只要选取的元素总和超过target，就返回！

+ **回溯三部曲：**

  + **递归函数参数**

    + 这里依然是定义三个全局变量，二维数组result存放结果集，数组path存放符合条件的结果，sum存放求和结果。

    ```c++
    vector<vector<int>> result;
    vector<int> path;
    int sum;
    void backtracking(vector<int>& candidates, int target, int startIndex);
    ```

    + **「本题还需要startIndex来控制for循环的起始位置，对于组合问题，什么时候需要startIndex呢？」**
    + 如果是一个集合来求组合的话，就需要startIndex，例如：求组合问题！，回溯算法：求组合总和！。
    + 如果是多个集合取组合，各个集合之间相互不影响，那么就不用startIndex，例如：电话号码的字母组合

  + **递归终止条件**

    <div align = center><img src="../images/Backtrack12.png" width="700px" /></div>

    + 从叶子节点可以清晰看到，终止只有两种情况，sum大于target和sum等于target。

    ```c++
    if(sum == target) {
    		result.push_back(path);
    		return;
    }
    if(sum > target) 
    		return;
    ```

  + 单层搜索的逻辑

    + 单层for循环依然是从startIndex开始，搜索candidates集合。
    + 如何重复选取呢，看代码，注释部分：

    ```c++
    for (int i = startIndex; i < candidates.size(); i++) {
        sum += candidates[i];
        path.push_back(candidates[i]);
        backtracking(candidates, target, sum, i); // 关键点:不用i+1了，表示可以重复读取当前的数
        sum -= candidates[i];   // 回溯
        path.pop_back();        // 回溯
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      int sum;
      void backtracking(vector<int>& candidates, int target, int startIndex) {
          if(sum == target) {
              result.push_back(path);
              return;
          } else if(sum > target) 
              return;
          for(int i = startIndex; i < candidates.size(); ++i) {
              path.push_back(candidates[i]);
              sum += candidates[i];
              backtracking(candidates, target, i);
              sum -= candidates[i];
              path.pop_back();
          }
      }
  public:
      vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          result.clear();
          path.clear();
          sum = 0;
          backtracking(candidates, target , 0);
          return result;
      }
  };
  ```

### :diamond_shape_with_a_dot_inside: 5.组合总和II (40)

> 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
>
> candidates 中的每个数字在每个组合中只能使用一次。
>
> 说明：
> 所有数字（包括目标数）都是正整数。
> 解集不能包含重复的组合。

+ **示例：**

  <div align = center><img src="../images/Backtrack13.png" width="500px"/></div>

+ **思路：**

  + 这道题目和 39.组合总和 如下区别：
    1. 本题candidates 中的每个数字在每个组合中只能使用一次。
    2. 本题数组candidates的元素是有重复的，而 39.组合总和 是无重复元素的数组candidates
  + 最后本题和 39.组合总和 要求一样，解集不能包含重复的组合。
  + **「本题的难点在于区别2中：集合（数组candidates）有重复元素，但还不能有重复的组合」**。
  + **「所谓去重，其实就是使用过的元素不能重复选取。」** 组合问题可以抽象为树形结构，那么“使用过”在这个树形结构上是有两个维度的，一个维度是同一树枝上使用过，一个维度是同一树层上使用过。**「没有理解这两个层面上的“使用过” 是造成大家没有彻底理解去重的根本原因。」**
  + 问题中元素在同一个组合内是可以重复的，怎么重复都没事，但两个组合不能相同。**「所以要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重」**。

+ **回溯三部曲：**

  + **「递归函数参数」**

    + 与 39.组合总和 套路相同，此题还需要加一个bool型数组used，用来记录同一树枝上的元素是否使用过。
    + 这个集合去重的重任就是used来完成的。

    ```c++
    vector<vector<int>> result; // 存放组合集合
    vector<int> path;           // 符合条件的组合
    int sum;										//求和
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used) 
    ```

  + **「递归终止条件」**

    + 终止条件为 `sum > target` 和 `sum == target`。

    ```c
    if (sum > target) { // 这个条件其实可以省略 
        return;
    }
    if (sum == target) {
        result.push_back(path);
        return;
    }
    ```

  + **「单层搜索的逻辑」**

    + 前面提到：要去重的是“同一树层上的使用过”。**「如果`candidates[i] == candidates[i - 1]` 并且 `used[i - 1] == false`，就说明：前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]」**。

    + 此时for循环里就应该做continue的操作。如图：

      <div align = center><img src="../images/Backtrack14.png"width="700px"/></div>

    + 在图中将used的变化用橘黄色标注上，可以看出在candidates[i] == candidates[i - 1]相同的情况下：

      - **used[i - 1] == true，说明同一树支candidates[i - 1]使用过，**
      - **used[i - 1] == false，说明同一树层candidates[i - 1]使用过，从上一个函数返回而来。**

    ```c++
    for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
        // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
        // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        // 要对同一树层使用过的元素进行跳过
        if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
            continue;
        }
        sum += candidates[i];
        path.push_back(candidates[i]);
        used[i] = true;
        backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1：这里是i+1，每个数字在每个组合中只能使用一次
        used[i] = false;
        sum -= candidates[i];
        path.pop_back();
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
          if (sum == target) {
              result.push_back(path);
              return;
          }
          for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
              // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
              // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
              // 要对同一树层使用过的元素进行跳过
              if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                  continue;
              }
              sum += candidates[i];
              path.push_back(candidates[i]);
              used[i] = true;
              backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
              used[i] = false;
              sum -= candidates[i];
              path.pop_back();
          }
      }
  
  public:
      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          vector<bool> used(candidates.size(), false);
          path.clear();
          result.clear();
          // 首先把给candidates排序，让其相同的元素都挨在一起。
          sort(candidates.begin(), candidates.end());
          backtracking(candidates, target, 0, 0, used);
          return result;
      }
  };
  ```

### :diamond_shape_with_a_dot_inside: 6.分割回文串(131)

> 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
>
> 返回 s 所有可能的分割方案。

+ **示例：**

  <div align = center><img src="../images/Backtrack15.png" width="300x" /></div>

+ **思路：**

  + 本题涉及到两个关键问题：

    1. 切割问题，有不同的切割方式
    2. 判断回文

  + 切割问题，也可以抽象为一颗树形结构，如图：

    <div align = center><img src="../images/Backtrack16.png" width="600px" /></div>

  + 递归用来纵向遍历，for循环用来横向遍历，切割线（就是图中的红线）切割到字符串的结尾位置，说明找到了一个切割方法。此时可以发现，切割问题的回溯搜索的过程和组合问题的回溯搜索的过程是差不多的。

+ **回溯三部曲：**

  + **递归函数参数**

    + 全局变量数组path存放切割后回文的子串，二维数组result存放结果集。（这两个参数可以放到函数参数里）
    + 本题递归函数参数还需要startIndex，因为切割过的地方，不能重复切割，和组合问题也是保持一致的。

  + **递归函数终止条件**

    <div align = center><img src="../images/Backtrack17.png" width="600px"/></div>

    + 从树形结构的图中可以看出：切割线切到了字符串最后面，说明找到了一种切割方法，此时就是本层递归的终止终止条件。
    + **「那么在代码里什么是切割线呢？」**在处理组合问题的时候，递归参数需要传入startIndex，表示下一轮递归遍历的起始位置，这个startIndex就是切割线。

  + **单层搜索的逻辑**

    + **「来看看在递归循环，中如何截取子串呢？」**

    + 在`for (int i = startIndex; i < s.size(); i++)`循环中，定义了起始位置startIndex，那么 [startIndex, i] 就是要截取的子串。

      首先判断这个子串是不是回文，如果是回文，就加入在`vector<string> path`中，path用来记录切割过的回文子串。

    ```c++
    for (int i = startIndex; i < s.size(); i++) {
        if (isPalindrome(s, startIndex, i)) { // 是回文子串
            // 获取[startIndex,i]在s中的子串
            string str = s.substr(startIndex, i - startIndex + 1);
            path.push_back(str);
        } else {                // 如果不是则直接跳过
            continue;
        }
        backtracking(s, i + 1); // 寻找i+1为起始位置的子串
        path.pop_back();        // 回溯过程，弹出本次已经填在的子串
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<string>> result;
      vector<string> path; // 放已经回文的子串
      void backtracking (const string& s, int startIndex) {
          // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
          if (startIndex >= s.size()) {
              result.push_back(path);
              return;
          }
          for (int i = startIndex; i < s.size(); i++) {
              if (isPalindrome(s, startIndex, i)) {   // 是回文子串
                  // 获取[startIndex,i]在s中的子串
                  string str = s.substr(startIndex, i - startIndex + 1);
                  path.push_back(str);
              } else {                                // 不是回文，跳过
                  continue;
              }
              backtracking(s, i + 1); // 寻找i+1为起始位置的子串
              path.pop_back(); // 回溯过程，弹出本次已经填在的子串
          }
      }
      bool isPalindrome(const string& s, int start, int end) {
          for (int i = start, j = end; i < j; i++, j--) {
              if (s[i] != s[j]) {
                  return false;
              }
          }
          return true;
      }
  public:
      vector<vector<string>> partition(string s) {
          result.clear();
          path.clear();
          backtracking(s, 0);
          return result;
      }
  };
  ```

### :diamond_shape_with_a_dot_inside: 7.复原IP地址(93)

> 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
>
> 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
>
> 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

+ **示例：**

  <div align = center><img src="../images/Backtrack18.png" width="500px" /></div>

+ **思路：**

  + **「切割问题就可以使用回溯搜索法把所有可能性搜出来」**，和上一题 分割回文串 就十分类似了。

+ **回溯三部曲：**

  + **递归参数**
    + startIndex一定是需要的，因为不能重复分割，记录下一层递归分割的起始位置。
    + 本题还需要一个变量pointNum，记录添加逗点的数量。

  + **递归终止条件**

    + 终止条件和 分割回文串 情况就不同了，本题明确要求只会分成4段，所以不能用切割线切到最后作为终止条件，而是分割的段数作为终止条件。
    + pointNum表示逗点数量，pointNum为3说明字符串分成了4段了。
    + 然后验证一下第四段是否合法，如果合法就加入到结果集里

    ```c++
    if (pointNum == 3) { // 逗点数量为3时，分隔结束
        // 判断第四段子字符串是否合法，如果合法就放进result中
        if (isValid(s, startIndex, s.size() - 1)) {
            result.push_back(s);
        }
        return;
    }
    ```

  + **单层搜索的逻辑**

    + 在`for (int i = startIndex; i < s.size(); i++)`循环中 [startIndex, i]这个区间就是截取的子串，需要判断这个子串是否合法。
    + 如果合法就在字符串后面加上符号`.`表示已经分割。
    + 如果不合法就结束本层循环，如图中剪掉的分支：

    <div align = center><img src="../images/Backtrack19.png" width="800px" /></div>

    + 递归调用时，下一层递归的startIndex要从i+2开始（因为需要在字符串中加入了分隔符`.`），同时记录分割符的数量pointNum 要 +1。
    + 回溯的时候，就将刚刚加入的分隔符`.` 删掉就可以了，pointNum也要-1。

    ```c++
    for (int i = startIndex; i < s.size(); i++) {
        if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
            s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
            pointNum++;
            backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
            pointNum--;                         // 回溯
            s.erase(s.begin() + i + 1);         // 回溯删掉逗点
        } else break; // 不合法，直接结束本层循环
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<string> result;// 记录结果
      // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
      void backtracking(string& s, int startIndex, int pointNum) {
          if (pointNum == 3) { // 逗点数量为3时，分隔结束
              // 判断第四段子字符串是否合法，如果合法就放进result中
              if (isValid(s, startIndex, s.size() - 1)) {
                  result.push_back(s);
              }
              return;
          }
          for (int i = startIndex; i < s.size(); i++) {
              if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                  s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                  pointNum++;
                  backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                  pointNum--;                         // 回溯
                  s.erase(s.begin() + i + 1);         // 回溯删掉逗点
              } else break; // 不合法，直接结束本层循环
          }
      }
      // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
      bool isValid(const string& s, int start, int end) {
          if (start > end) {//这是最后一次的判断，防止start到达end()
              return false;
          }
          if (s[start] == '0' && start != end) { // 0开头的数字不合法
                  return false;
          }
          int num = 0;
          for (int i = start; i <= end; i++) {
              if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                  return false;
              }
              num = num * 10 + (s[i] - '0');
              if (num > 255) { // 如果大于255了不合法
                  return false;
              }
          }
          return true;
      }
  public:
      vector<string> restoreIpAddresses(string s) {
          result.clear();
          backtracking(s, 0, 0);
          return result;
      }
  };
  
  ```



### 8.子集(78)

> 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
>
> 说明：解集不能包含重复的子集。

+ **示例：**

  <div align = center><img src="../images/Backtrack20.png" width="500px" /></div>

+ **思路：**

  + 如果把 子集问题、组合问题、分割问题都抽象为一棵树的话，**「那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点！」**

  + 其实子集也是一种组合问题，因为它的集合是无序的，子集{1,2} 和 子集{2,1}是一样的。**「那么既然是无序，取过的元素不会重复取，写回溯算法的时候，for就要从startIndex开始，而不是从0开始！」**

  + 求排列问题的时候，就要从0开始，因为集合是有序的，{1, 2} 和{2, 1}是两个集合。

    <div align = center><img src="../images/Backtrack21.png" width="600px" /></div>

  + 从图中红线部分，可以看出**「遍历这个树的时候，把所有节点都记录下来，就是要求的子集集合」**。

+ **回溯三部曲：**

  + **递归函数参数**
    + 全局变量数组path为子集收集元素，二维数组result存放子集组合。（也可以放到递归函数参数里）
    + 递归函数参数在上面讲到了，需要startIndex。
  + **递归终止条件**
    + 剩余集合为空的时候，就是叶子节点。
    + 剩余集合为空就是startIndex已经大于数组的长度，就终止了，因为没有元素可取了
  + **单层搜索逻辑**
    + **「求取子集问题，不需要任何剪枝！因为子集就是要遍历整棵树」**。

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking(vector<int>& nums, int startIndex) {
          result.push_back(path); // 收集子集
          if (startIndex >= nums.size()) { // 终止条件可以不加
              return;
          }
          for (int i = startIndex; i < nums.size(); i++) {
              path.push_back(nums[i]);
              backtracking(nums, i + 1);
              path.pop_back();
          }
      }
  public:
      vector<vector<int>> subsets(vector<int>& nums) {
          result.clear();
          path.clear();
          backtracking(nums, 0);
          return result;
      }
  };
  ```


### :diamond_shape_with_a_dot_inside: 9.子集II(90)

> 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
>
> 说明：解集不能包含重复的子集。

+ **示例：**

  <div align = center><img src="../images/Backtrack22.png" width="400px" /></div>

+ **思路：**

  + 这道题目和 求子集问题！ 区别就是集合里有重复元素了，而且求取的子集要去重。

    <div align = center><img src="../images/Backtrack23.png" width="700px" /></div>

  + 从图中可以看出，同一树层上重复取2 就要过滤掉，同一树枝上就可以重复取2，因为同一树枝上元素的集合才是唯一子集！

  + 本题就是其实就是 求子集问题！ 的基础上加上了去重

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
          result.push_back(path);
          for (int i = startIndex; i < nums.size(); i++) {
              // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
              // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
              // 而我们要对同一树层使用过的元素进行跳过
              if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                  continue;
              }
              path.push_back(nums[i]);
              used[i] = true;
              backtracking(nums, i + 1, used);
              used[i] = false;
              path.pop_back();
          }
      }
  
  public:
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          result.clear();
          path.clear();
          vector<bool> used(nums.size(), false);
          sort(nums.begin(), nums.end()); // 去重需要排序
          backtracking(nums, 0, used);
          return result;
      }
  };
  ```



### :diamond_shape_with_a_dot_inside: 10.递增子序列(491)

> 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

+ **示例：**

  <div align = center><img src="../images/Backtrack24.png" width="600px" /></div>

+ **思路：**

  + 在 求子集问题（二 ）中我们是通过排序，再加一个标记数组来达到去重的目的。而本题求自增子序列，是不能对原数组进行排序的，排完序的数组都是自增子序列了。 **「所以不能使用之前的去重逻辑！」**

  + 用[4, 7, 6, 7]这个数组来举例，抽象为树形结构如图：

    <div align = center><img src="../images/Backtrack25.png" width="700px" /></div>

+ **回溯三部曲：**

  + **递归函数参数**

    + 本题求子序列，很明显一个元素不能重复使用，所以需要startIndex，调整下一层递归的起始位置。

  + **终止条件**

    + 本题其实类似求子集问题，也是要遍历树形结构找每一个节点，所以和 求子集问题！ 一样，可以不加终止条件，startIndex每次都会加1，并不会无限递归。
    + 但本题收集结果有所不同，题目要求递增子序列大小至少为2。

    ```c++
    if (path.size() > 1) {
        result.push_back(path);
        // 注意这里不要加return，因为要取树上的所有节点
    }
    ```

  + **单层搜索逻辑**

    + 在图中可以看出，同层上使用过的元素就不能在使用了，**「注意这里和 求子集问题（二） 中去重的区别」**。 
    +  **「本题只要同层重复使用元素，递增子序列就会重复」**，而 求子集问题（二） 中是排序之后看相邻元素是否重复使用。
    + 还有一种情况就是如果选取的元素小于子序列最后一个元素，那么就不能是递增的，所以也要pass掉。

    ```c++
    if ((!path.empty() && nums[i] < path.back())
            || uset.find(nums[i]) != uset.end()) {
            continue;
    }
    ```

    + 判断`nums[i] < path.back()`之前一定要判断path是否为空，所以是`!path.empty() && nums[i] < path.back()`。
    + `uset.find(nums[i]) != uset.end()`判断nums[i]在本层是否使用过。

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking(vector<int>& nums, int startIndex) {
          if (path.size() > 1) {
              result.push_back(path);
              // 注意这里不要加return，要取树上的节点
          }
          unordered_set<int> uset; // 使用set对本层元素进行去重
          for (int i = startIndex; i < nums.size(); i++) {
              if ((!path.empty() && nums[i] < path.back())
                      || uset.find(nums[i]) != uset.end()) {
                      continue;
              }
            //unordered_set<int> uset; 是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道uset只负责本层！
              uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
              path.push_back(nums[i]);
              backtracking(nums, i + 1);
              path.pop_back();
          }
      }
  public:
      vector<vector<int>> findSubsequences(vector<int>& nums) {
          result.clear();
          path.clear();
          backtracking(nums, 0);
          return result;
      }
  };
  ```



### 11.全排列(46)

> 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

+ **示例：**

  <div align = center><img src="../images/Backtrack26.png" width="500px" /></div>

+ **思路：**

  + 以[1,2,3]为例，抽象成树形结构如下：

    <div align = center><img src="../images/Backtrack27.png" width="700px" /></div>

+ **回溯三部曲：**

  + **递归函数参数**

    + **「首先排列是有序的，也就是说[1,2] 和[2,1] 是两个集合，这和之前分析的子集以及组合所不同的地方」**。
    + 可以看出元素1在[1,2]中已经使用过了，但是在[2,1]中还要在使用一次1，所以处理排列问题就不用使用startIndex了。但排列问题需要一个used数组，标记已经选择的元素，如图橘黄色部分所示

    ```c++
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used)
    ```

  + **递归终止条件**

    + 当收集元素的数组path的大小达到和nums数组一样大的时候，说明找到了一个全排列，也表示到达了叶子节点。

  + **单层搜索的逻辑**

    + 这里和 组合问题 、 切割问题 和 子集问题 最大的不同就是for循环里不用startIndex了。
    + 因为排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。
    + **「而used数组，其实就是记录此时path里都有哪些元素使用了，一个排列里一个元素只能使用一次」**。

    ```c++
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true) continue; // path里已经收录的元素，直接跳过
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
    }
    ```

+ **代码实现：**

  ```c++
  class Solution {
  public:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking (vector<int>& nums, vector<bool>& used) {
          // 此时说明找到了一组
          if (path.size() == nums.size()) {
              result.push_back(path);
              return;
          }
          for (int i = 0; i < nums.size(); i++) {
              if (used[i] == true) continue; // path里已经收录的元素，直接跳过
              used[i] = true;
              path.push_back(nums[i]);
              backtracking(nums, used);
              path.pop_back();
              used[i] = false;
          }
      }
      vector<vector<int>> permute(vector<int>& nums) {
          result.clear();
          path.clear();
          vector<bool> used(nums.size(), false);
          backtracking(nums, used);
          return result;
      }
  };
  ```



### 12.全排列 II(47)

> 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

+ **示例：**

  <div align = center><img src="../images/Backtrack28.png" width="550px" /></div>

+ **思路：**

  + 这道题目和 上一题 的区别在于**「给定一个可包含重复数字的序列」**，要返回**「所有不重复的全排列」**。

  + 排列问题其实之前的去重也是一样的套路。 **「还要强调的是去重一定要对元素进行排序，这样我们才方便通过相邻的节点来判断是否重复使用了」**。

  + 以示例中的 [1,1,2]为例 （为了方便举例，已经排序）抽象为一棵树，去重过程如图：

    <div align = center><img src="../images/Backtrack29.png" width="700px" /></div>

  + 图中我们对同一树层，前一位（也就是nums[i-1]）如果使用过，那么就进行去重。

  + **「一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，而子集问题就是取树上所有节点的结果」**。

+ **代码实现：**

  ```c++
  class Solution {
  private:
      vector<vector<int>> result;
      vector<int> path;
      void backtracking (vector<int>& nums, vector<bool>& used) {
          // 此时说明找到了一组
          if (path.size() == nums.size()) {
              result.push_back(path);
              return;
          }
          for (int i = 0; i < nums.size(); i++) {
              // used[i - 1] == true，说明同一树支nums[i - 1]使用过
              // used[i - 1] == false，说明同一树层nums[i - 1]使用过
              // 如果同一树层nums[i - 1]使用过则直接跳过
              if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                  continue;
              }
              if (used[i] == false) {
                  used[i] = true;
                  path.push_back(nums[i]);
                  backtracking(nums, used);
                  path.pop_back();
                  used[i] = false;
              }
          }
      }
  public:
      vector<vector<int>> permuteUnique(vector<int>& nums) {
          result.clear();
          path.clear();
          sort(nums.begin(), nums.end()); // 排序
          vector<bool> used(nums.size(), false);
          backtracking(nums, used);
          return result;
      }
  };
  ```

  

### 13.重新安排行程(332)



### 14.N皇后问题(51)

> n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

+ **示例：**

  <div align = center><img src="../images/Backtrack30.png" width="400px" /></div>

+ **思路：**

  + 首先来看一下皇后们的约束条件：

    1. 不能同行
    2. 不能同列
    3. 不能同斜线

  + 确定完约束条件，来看看究竟要怎么去搜索皇后们的位置，其实搜索皇后的位置，可以抽象为一棵树：

    <div align = center><img src="../images/Backtrack31.png" width="500px" /></div>

  + 从图中，可以看出，二维矩阵中矩阵的高就是这颗树的高度，矩阵的宽就是树型结构中每一个节点的宽度。

  + 那么我们用皇后们的约束条件，来回溯搜索这颗树，**「只要搜索到了树的叶子节点，说明就找到了皇后们的合理位置了」**。

+ **回溯三部曲：**

  + **递归函数参数**

    + 定义全局变量二维数组result来记录最终结果。
    + 参数n是棋牌的大小，然后用row来记录当前遍历到棋盘的第几层了。

  + **递归终止条件**

    + 当递归到棋盘最底层（也就是叶子节点）的时候，就可以收集结果并返回了。

  + 单层搜索的逻辑

    + **递归深度就是row控制棋盘的行，每一层里for循环的col控制棋盘的列，一行一列，确定了放置皇后的位置。**
    + 每次都是要从新的一行的起始位置开始搜，所以都是从0开始。

    ```c++
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
            chessboard[row][col] = 'Q'; // 放置皇后
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.'; // 回溯，撤销皇后
        }
    }
    ```

+ **判断是否合法：**

  +  按照如下标准去重：
    1. 不能同行
    2. 不能同列
    3. 不能同斜线 （45度和135度角）

  ```c++
  bool isValid(int row, int col, vector<string>& chessboard, int n) {
      int count = 0;
      // 检查列
      for (int i = 0; i < row; i++) { // 这是一个剪枝
          if (chessboard[i][col] == 'Q') {
              return false;
          }
      }
      // 检查 45度角是否有皇后
      for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
          if (chessboard[i][j] == 'Q') {
              return false;
          }
      }
      // 检查 135度角是否有皇后
      for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
          if (chessboard[i][j] == 'Q') {
              return false;
          }
      }
      return true;
  }
  ```

+ **代码实现：**

  ```c++
  class Solution {
  private:
  vector<vector<string>> result;
  // n 为输入的棋盘大小
  // row 是当前递归到棋牌的第几行了
  void backtracking(int n, int row, vector<string>& chessboard) {
      if (row == n) {
          result.push_back(chessboard);
          return;
      }
      for (int col = 0; col < n; col++) {
          if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
              chessboard[row][col] = 'Q'; // 放置皇后
              backtracking(n, row + 1, chessboard);
              chessboard[row][col] = '.'; // 回溯，撤销皇后
          }
      }
  }
  bool isValid(int row, int col, vector<string>& chessboard, int n) {
      // 检查列
      for (int i = 0; i < row; i++) { // 这是一个剪枝
          if (chessboard[i][col] == 'Q') {
              return false;
          }
      }
      // 检查 45度角是否有皇后
      for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
          if (chessboard[i][j] == 'Q') {
              return false;
          }
      }
      // 检查 135度角是否有皇后
      for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
          if (chessboard[i][j] == 'Q') {
              return false;
          }
      }
      return true;
  }
  public:
      vector<vector<string>> solveNQueens(int n) {
          result.clear();
          vector<string> chessboard(n, string(n, '.'));
          backtracking(n, 0, chessboard);
          return result;
      }
  };
  ```

  

### 15.解数独(37)

```c++
bool backtraversal(vector<vector<char>>& board) {
  	for (int i = 0; i < board.size(); i++) {        // 遍历行
        for (int j = 0; j < board[0].size(); j++) { // 遍历列
            if (board[i][j] != '.') continue;
            for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
                if (isValid(i, j, k, board)) { 
                    board[i][j] = k;                // 放置k
                    if (backtraversal(board)) return true; // 如果找到合适一组立刻返回
                    board[i][j] = '.';              // 回溯，撤销k
                }
            }
            return false;                           // 9个数都试完了，都不行，那么就返回false
        }
   }
  return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}

bool isValid(int row, int col, char val, vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
        if (board[row][i] == val) {
          	return false;
        }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
        if (board[j][col] == val) {
          	return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
              	return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
  	backtraversal(board);
}
```

