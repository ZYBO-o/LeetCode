字符串的主要解决问题方法有：

:one: 双指针

:two: 滑动窗口

:three: KMP算法

## 一.双指针

分析见：[双指针]()

#### [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

> 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
>
> + 如果剩余字符少于 k 个，则将剩余字符全部反转。
> + 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

:one: 遍历字符串的过程中，只要让 `i += (2 * k)` ，i  每次移动 2 * k 就可以了，然后判断是否需要有反转的区间。

:two: 如果 `i + k <= s.size()` ，则将 `[i, i + k - 1]` 范围的字符串进行反转

:three: 最后反转 `[i, s.size() - 1]` 范围的字符串

```c++
void reverse(string& s, int left, int right) {
    while(left <= right ) {
        swap(s[left], s[right]);
        ++ left;  -- right;
    }
}
string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= s.size()) {
            reverse(s, i, i + k - 1);
            continue;
        }
        // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
        reverse(s, i, s.size() - 1);
    }    
    return s;
}
```

#### [剑指 Offer 58 - II. 左旋转字符串](https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/)

> 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

:one: 反转区间为前n的子串

:two: 反转区间为n到末尾的子串

:three: 反转这个字符串

<div align = center><img src="../images/String1.png" width="500px" /></div>

---

## 二.滑动窗口

分析见：[滑动窗口]()

---



## 三.KMP算法

### 1.暴力匹配

以往匹配字符串的方法都是暴力匹配，模拟 Brute-Force 算法，对主串 “AAAAAABC” 和模式串 “AAAB” 做匹配：

<div align = center><img src="../images/String2.png" width="600px" /></div>

考虑“字符串比较”这个小任务的复杂度。最坏情况发生在：两个字符串唯一的差别在最后一个字符。这种情况下，字符串比较必须走完整个字符串，才能给出结果，因此复杂度是 O(len) 的。　

由此，不难想到 Brute-Force 算法所面对的最坏情况： Brute-Force 的复杂度是 O(|P| * |S|) ，也就是 O(nm)的。这太慢了！

### 2.优化线索

从图中可以看出：

+ P(a) != P(b) 且 P(b) == S(b) 

+ 所以 P(a) != S(b) ，所以右移一位的意义不大

所以要思考的就是右移几位，使得效率更高

### 3.优化规律

<div align = center><img src="../images/String3.png" width="600px" /></div>

:one: 匹配失败时右移位数 **与子串本身有关** ，与目标串无关

:two:  **移动位数 = 已匹配的字符串数 - 对应的部分匹配值**

:three:  任意子串都存在一个 **唯一的部分匹配表**

部分匹配表示例：

<div align = center><img src="../images/String4.png" width="500px" /></div>

可以看出：

+ 子串第七位匹配失败——> 前六位匹配成功
+ 差PMT表，PMT[6] = 2
+ 右移位数： 已匹配的字符串数  - PMT[6] = 6 - 2 = 4

### 4.部分匹配表的求解

:large_orange_diamond: 前缀

+ 除最后一个字符以外，一个字符串的全部头部组合

:large_orange_diamond: 后缀

+ 除第一个字符以外，一个字符串的全部尾部组合

:large_blue_diamond: 部分匹配值

+ 前缀和后缀最长共有元素的长度

<div align = center><img src="../images/String5.png" width="600px" /></div>



### 5.部分匹配表实现关键

:one: PMT[1] = 0

:two: 从第2个字符开始递推

:three: 假设PMT[n] = PMT[n - 1] + 1 (最长共有元素的长度)

:four: 当假设不成立，PMT[n] 在 PMT[n-1] 的基础上减

:large_blue_diamond: **代码实现：**

```c++
std::vector<int> PMT(std::string p) {
  	//创建pmt表
    std::vector<int> pmt (p.size(), 0);
    int ll = 0;
    
    for(int i = 1; i < p.size(); ++i) {
        //非理想情况下
        while (ll > 0 && p[ll] != p[i]){
            ll = pmt[ll - 1];
        }
        //理想情况下：直接在前一个共有元素长度上 + 1
        if(p[ll] == p[i]) {
            ++ll;
        }
        //部分匹配表存储对应长度
        pmt[i] = ll;
    }
    return pmt;
}
```

### 6.KMP算法实现

<div align = center><img src="../images/String6.png" width="500px" /></div>

<div align = center>在下标 j 处匹配失败 ——> 前 j 位匹配成功 ——> 查表 PMT[j-1] ——> 右移位数= j - PMT[j-1]</div>

:one: 因为 s[i] != p[j]

:two: 所以，查表， LL = PMT[j - 1]

:three: 右移， i 值不变， j 值改变， j = j - (j - LL) = LL = PMT[j - 1]

:large_blue_diamond: **代码实现**

```c++
int KMP(const std::string& s, const std::string& p) {
    int ret = -1;
    int s_len = s.size();
    int p_len = p.size();
    //求出子串的部分匹配表
    std::vector<int> pmt = PMT(p);
    //子串长度>0 且 子串长度小于目标串,这样才有查找的意义
    if(0 < p_len && p_len <= s_len) {
        //i 遍历 s, j 遍历 p
        for(int i = 0, j = 0; i < s_len; ++i) {
            //2.比对不成功
            while(j > 0 && s[i] != p[j]) {
                //j的位置进行改变
                j = pmt[j - 1];
            }
            //1.如果比对成功
            if(s[i] == p[j])
                ++j;
            //结束比对的条件
            if(j == p_len) {
                //成功查找的位置
                ret = i - p_len + 1;
            }
        }
    }
    return ret;
}
```

:diamond_shape_with_a_dot_inside: 算法复杂度 O(p_len + s_len).











