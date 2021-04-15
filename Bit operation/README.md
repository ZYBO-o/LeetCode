## 位运算

### 一.位操作符运算介绍

#### 1. 位操作实现乘除法

数 a 向右移一位，相当于将 a 除以 2；数 a 向左移一位，相当于将 a 乘以 2

```c++
int a = 2;
a >> 1; ---> 1
a << 1; ---> 4
```

#### 2. 位操作交货两数

位操作交换两数可以不需要第三个临时变量，虽然普通操作也可以做到，但是没有其效率高

```c++
//普通操作
void swap(int &a, int &b) {
  a = a + b;
  b = a - b;
  a = a - b;
}

//位与操作
void swap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
```

> 位与操作解释：第一步：a ^= b ---> a = (a^b);
>
> 第二步：b ^= a ---> b = b^(a^b) ---> b = (b^b)^a = a
>
> 第三步：a ^= b ---> a = (a^b)^a = (a^a)^b = b

#### 3.位操作判断奇偶数

只要根据数的最后一位是 0 还是 1 来决定即可，为 0 就是偶数，为 1 就是奇数。

```c++
if(0 == (a & 1)) {
 //偶数
}
```

#### 4. 位操作交换符号

交换符号将正数变成负数，负数变成正数

```c++
int reversal(int a) {
  return ~a + 1;
}
```

> 整数取反加1，正好变成其对应的负数(补码表示)；负数取反加一，则变为其原码，即正数

#### 5. 位操作求绝对值

整数的绝对值是其本身，负数的绝对值正好可以对其进行取反加一求得，即我们首先判断其符号位（整数右移 31 位得到 0，负数右移 31 位得到 -1,即 0xffffffff），然后根据符号进行相应的操作

```c++
int abs(int a) {
  int i = a >> 31;
  return i == 0 ? a : (~a + 1);
}
```

上面的操作可以进行优化，可以将 i == 0 的条件判断语句去掉。我们都知道符号位 i 只有两种情况，即 i = 0 为正，i = -1 为负。对于任何数与 0 异或都会保持不变，与 -1 即 0xffffffff 进行异或就相当于对此数进行取反,因此可以将上面三目元算符转换为((a^i)-i)，即整数时 a 与 0 异或得到本身，再减去 0，负数时与 0xffffffff 异或将 a 进行取反，然后在加上 1，即减去 i(i =-1)

```c++
int abs2(int a) {
  int i = a >> 31;
  return ((a^i) - i);
}
```

#### 6. 位操作进行高低位交换

给定一个 16 位的无符号整数，将其高 8 位与低 8 位进行交换，求出交换后的值，如：

```text
34520的二进制表示：
10000110 11011000

将其高8位与低8位进行交换，得到一个新的二进制数：
11011000 10000110
其十进制为55430
```

从上面移位操作我们可以知道，只要将无符号数 a>>8 即可得到其高 8 位移到低 8 位，高位补 0；将 a<<8 即可将 低 8 位移到高 8 位，低 8 位补 0，然后将 a>>8 和 a<<8 进行或操作既可求得交换后的结果。

```c++
unsigned short a = 34520;
a = (a >> 8) | (a << 8);
```

#### 7. 位操作统计二进制中 1 的个数

统计二进制1的个数可以分别获取每个二进制位数，然后再统计其1的个数，此方法效率比较低。这里介绍另外一种高效的方法，同样以 34520 为例，我们计算其 a &= (a-1)的结果：

- 第一次：计算前：1000 0110 1101 1000 计算后：1000 0110 1101 0000
- 第二次：计算前：1000 0110 1101 0000 计算后：1000 0110 1100 0000
- 第二次：计算前：1000 0110 1100 0000 计算后：1000 0110 1000 0000 我们发现，没计算一次二进制中就少了一个 1，则我们可以通过下面方法去统计：

```c++
count = 0  
while(a){  
  a = a & (a - 1);  
  count++;  
}  
```

#### 8. 如果要将整数A转换为B，需要改变多少个bit位？

这个应用是上面一个应用的拓展：思考将整数A转换为B，如果A和B在第i（0 <=i < 32）个位上相等，则不需要改变这个BIT位，如果在第i位上不相等，则需要改变这个BIT位。

联想到位运算有一个`异或操作`，相同为0，相异为1，所以问题转变成了计算A异或B之后这个数中1的个数!

```c++
class Solution {
    /**
     *@param a, b: Two integer
     *return: An integer
     */
public:
    int countOnes(int num) {
        int count = 0;
        while (num != 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }

    int bitSwapRequired(int a, int b) {
        // write your code here
        return countOnes(a ^ b);
    }
};
```



---

### 二.题目积累

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

> 给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};
```

#### [137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)

> 给你一个整数数组 `nums` ，除某个元素仅出现 **一次** 外，其余每个元素都恰出现 **三次 。**请你找出并返回那个只出现了一次的元素。

异或用于检测出现奇数次的位：1、3、5 等。

+ 0 与任何数 XOR 结果为该数。
+ 两个相同的数 XOR 结果为 0。
+ 以此类推，只有某个位置的数字出现奇数次时，该位的掩码才不为 0。

<div align="center">  
  <img src="https://github.com/ZYBO-o/LeetCode/blob/main/images/8.png"  width="500"/> 
</div>

因此，可以检测出出现一次的位和出现三次的位，但是要注意区分这两种情况。

为了区分出现一次的数字和出现三次的数字，使用两个位掩码：seen_once 和 seen_twice。

思路是：

+ 仅当 `seen_twice` 未变时，改变 `seen_once`。

+ 仅当 `seen_once` 未变时，改变 `seen_twice`。

<div align="center">  
  <img src="https://github.com/ZYBO-o/LeetCode/blob/main/images/9.png"  width="500"/> 
</div>

位掩码 `seen_once` 仅保留出现一次的数字，不保留出现三次的数字。

```c++
class Solution {
    public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0;
        int seen_twice = 0;

        for(auto i : nums) {
            seen_once = ~seen_twice & (seen_once ^ i);
            seen_twice = ~seen_once & (seen_twice ^ i);
        }
        return seen_once;
    }
};
```

#### [两数只出现一次](http://www.lintcode.com/en/problem/single-number/)

>  数组中，只有两个数出现一次，剩下都出现两次，找出出现一次的这两个数

有了第一题的基本的思路，我们可以将数组分成两个部分，每个部分里只有一个元素出现一次，其余元素都出现两次。那么使用这种方法就可以找出这两个元素了。不妨假设出现一个的两个元素是x，y，那么最终所有的元素异或的结果就是等价于`res = x^y`。
`并且res！=0`

**为什么呢？ 如果res 等于0，则说明x和y相等了！！！！**

因为res不等于0，那么我们可以**一定**可以找出res二进制表示中的某一位是1。

**对于x和y，一定是其中一个这一位是1，另一个这一位不是1！！！细细琢磨， 因为如果都是0或者都是1，怎么可能异或出1**

对于原来的数组，我们可以根据这个位置是不是1就可以将数组分成两个部分。`x，y一定在不同的两个子集中`。

**而且对于其他成对出现的元素，要么都在x所在的那个集合，要么在y所在的那个集合。对于这两个集合我们分别求出单个出现的x 和 单个出现的y即可。**

```c++
class SingleNumber {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //用于记录，区分“两个”数组
        int diff = 0;
        for(int i = 0; i < nums.size(); i ++) {
            diff ^= nums[i];
        }
        //取最后一位1
        //先介绍一下原码，反码和补码
        //原码，就是其二进制表示（注意，有一位符号位）
        //反码，正数的反码就是原码，负数的反码是符号位不变，其余位取反
        //补码，正数的补码就是原码，负数的补码是反码+1
        //在机器中都是采用补码形式存
        //diff & (-diff)就是取diff的最后一位1的位置
        cout << diff << endl;
        diff &= (-diff);
        cout << diff << endl;
        vector<int> rets = {0, 0};
        for(int i = 0; i < nums.size(); i ++) {
            //分属两个“不同”的数组
            if ((nums[i] & diff) == 0) {
                rets[0] ^= nums[i];
            }
            else {
                rets[1] ^= nums[i];
            }
        }
        return rets;
    }
};
```



#### [371. 两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)

>  **不使用**运算符 `+` 和 `-` ，计算两整数 `a` 、`b` 之和。

**位运算中的加法**

先来观察下位运算中的两数加法，其实来来回回就只有下面这四种：

```c++
0 + 0 = 0
0 + 1 = 1
1 + 0 = 1
1 + 1 = 0（进位 1）
```

仔细一看，这可不就是相同位为 0，不同位为 1 的异或运算结果嘛~

**异或和与运算操作**

我们知道，在位运算操作中，异或的一个重要特性是无进位加法。我们来看一个例子

```c++
a = 5 = 0101
b = 4 = 0100

a ^ b 如下：

0 1 0 1
0 1 0 0
-------
0 0 0 1
```

`a ^ b` 得到了一个**无进位加法**结果，如果要得到 `a + b` 的最终值，我们还要找到**进位**的数，把这二者相加。在位运算中，我们可以使用**与**操作获得进位：

```c++
a = 5 = 0101
b = 4 = 0100

a & b 如下：

0 1 0 1
0 1 0 0
-------
0 1 0 0
```

由计算结果可见，0100 并不是我们想要的进位，1 + 1 所获得的进位应该要放置在它的更高位，即左侧位上，因此我们还要把 0100 左移一位，才是我们所要的进位结果。

那么问题就容易了，总结一下：

+ `a + b` 的问题拆分为 `(a 和 b 的无进位结果)` + `(a 和 b 的进位结果)`
+ 无进位加法使用 **异或** 运算计算得出
+ 进位结果使用 **与运算** 和 **移位运算** 计算得出
+ 循环此过程，直到进位为 0

```c++
class Solution {
public:
int getSum(int a, int b){
    // 重复操作，直到进位值为0
    while(b!=0){
        //c++需要换成无符号数再进行与操作再左移（计算进位值），否则在leetcode平台会报runtime error: left shift of negative value
        unsigned int carry = (unsigned int) (a&b) << 1;
        // 异或操作相当于加
        a = a^b;
        b = carry;
    }
    return a;
} 
};
```

#### [201. 数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

> 给你两个整数 `left` 和 `right` ，表示区间 `[left, right]` ，返回此区间内所有数字 **按位与** 的结果（包含 `left` 、`right` 端点）。

目的是求出两个给定数字的二进制字符串的公共前缀，这里给出的第一个方法是采用位移操作。

我们的想法是将两个数字不断向右移动，直到数字相等，即数字被缩减为它们的公共前缀。然后，通过将公共前缀向左移动，将零添加到公共前缀的右边以获得最终结果。

<div align="center">  
  <img src="https://github.com/ZYBO-o/LeetCode/blob/main/images/10.png"  width="600"/> 
</div>

如上述所说，算法由两个步骤组成：

+ 我们通过右移，将两个数字压缩为它们的公共前缀。在迭代过程中，我们计算执行的右移操作数。
+ 将得到的公共前缀左移相同的操作数得到结果。

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // 找到公共前缀
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};
```

