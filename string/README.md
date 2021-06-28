## 字符串

字符串的主要解决问题方法有：

:one: 双指针

:two: 滑动窗口

:three: KMP算法

### 1.双指针

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

### 2.滑动窗口

分析见：[滑动窗口]()

### 3.KMP算法

