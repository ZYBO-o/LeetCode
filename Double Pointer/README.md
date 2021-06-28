## 一.双指针

> 双指针主要分为两类：
>
> + 快慢指针 ： 解决链表中的问题，如判断是否有环
> + 左右指针 ： 解决数组或者字符串中的问题，如二分查找

### 1.快慢指针

快慢指针一般都初始化指向链表的头结点 head，前进时快指针 fast 在前， 慢指针 slow 在后，巧妙解决一些链表中的问题。

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

经典解法就是用两个指针，一个跑得快，一个跑得慢。

+ 如果不含有环，跑得快的那个指针最终会遇到 null，说明链表不含环;
+ 如果含有环，快指针最终 会超慢指针一圈，和慢指针相遇，说明链表含有环。

```c++
bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr ) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}
```

#### [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

<div align = center><img src="../images/Double Pointer1.png" width="500px" /></div>

当快慢指针相遇时，让其中任一个指针指向头节点，然后让它俩 以相同速度前进，再次相遇时所在的节点位置就是环开始的位置。

+ 设链表中环外部分的长度为 a。slow 指针进入环后，又走了 b 的距离与 fast 相遇。此时，fast 指针已经走完了环的 n 圈，因此它走过的总距离为 `a+n(b+c)+b=a+(n+1)b+nc`。
+ 根据题意，任意时刻，fast 指针走过的距离都为 slow 指针的 2 倍。因此，我们有
  `a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)`
+ 有了 `a=c+(n-1)(b+c)` 的等量关系，我们会发现：从相遇点到入环点的距离加上 n−1 圈的环长，恰好等于从链表头部到入环点的距离。
+ 因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 current。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。

```c++
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            ListNode* current = head;
            while(current != slow) {
                current = current->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}
```

#### [876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

类似上面的思路，我们还可以让快指针一次前进两步，慢指针一次前进一步，当快指针到达链表尽头时，慢指针就处于链表的中间位置。

```c++
ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
```

#### [剑指 Offer 22. 链表中倒数第k个节点](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)

创建快慢指针，让快指针先走 k 步，然后快慢指针开始同速 前进。这样当快指针走到链表末尾 null 时，慢指针所在的位置就是倒数第 k 个链表节点(为了简化，假设 k 不会超过链表⻓度)。

```c++
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(k--) 
        fast =fast->next;

    while(fast != nullptr ) {
        fast =fast->next;
        slow = slow->next;
    }

    return slow;
}
```

#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

<div align = center><img src="../images/Double Pointer3.gif" width="500px" /></div>

+ 首先定义 cur指针 指向 head结点，然后定义 pre指针 指针指向 nullptr；
+ 定义 temp 指针 指向 cur->next结点，保证不被丢失
+ cur重新指向pre进行翻转
+ 翻转后，pre，cur，cur->next 全部向前迭代直至链表尾部

```c++
ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* temp;
    while(cur) {
        //保存一下 cur的下一个节点，因为接下来要改变cur->next
        temp = cur->next;
        //翻转操作
        cur->next = pre;
        //更新pre 和 cur指针
        pre = cur;
        cur = temp;
    }
    return pre;
}
```



### 2.左右指针

左右指针在数组中实际是指两个索引值，一般初始化为 `left = 0, right = nums.length - 1` 。

#### [704. 二分查找](https://leetcode-cn.com/problems/binary-search/)

解析间二分搜索专题

```c++
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) /2;
        if(nums[mid] == target) 
            return mid;
        else if(nums[mid] > target) 
            right = mid - 1;
        else if(nums[mid] < target) 
            left = mid + 1;
    }
    return -1;
}
```

#### [167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

> 前提是已经升序的数组

只要数组有序，就应该想到双指针技巧。这道题的解法有点类似二分查找， 通过调节 left 和 right 可以调整 所求和 的大小:

```c++
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while(left <= right) {
        if(numbers[left] + numbers[right] < target)
            ++ left;
        else if(numbers[left] + numbers[right] > target)
            -- right;
        else if(numbers[left] + numbers[right] == target) {
            return {left + 1,right + 1};
        }      
    }
    return {-1,-1};
}
```

#### [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

类似二分查找， 通过调节 left 和 right 来交换字符:

```c++
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while(left <= right) {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
}
```

#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

<div align = center><img src="../images/Double Pointer4.gif" width="400px" /></div>

+ 首先将数组排序，然后有一层for循环，i从下表0的地方开始，同时定一个下表left 定义在i+1的位置上，定义下表right 在数组结尾的位置上。
+ 依然还是在数组中找到 abc 使得a + b +c =0，我们这里相当于  a = nums[i] ，b = nums[left] ， c = nums[right]。
+ 使用二分搜索的方式进行移动 left 和 right。

> 注意去重

```c++
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i) {
        //如果排序后第一个数已经大于0，则不可能再等于0了
        if(nums[i] > 0)
            return result;
        //去重
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        //定义双向指针
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            //二分搜索
            if(nums[i] + nums[left] + nums[right] > 0)
                --right;
            else if(nums[i] + nums[left] + nums[right] < 0)
                ++ left;
            else {
                //推入结果
                result.push_back({nums[i], nums[left], nums[right]});
                // 去重逻辑应该放在找到一个三元组之后
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;

                // 找到答案时，双指针同时收缩
                right--;
                left++;
            } 
        }

        
    }
    return result;
}
```

### 3.额外趣题

#### [剑指 Offer 05. 替换空格](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/)

+ **先预先给数组扩容带填充后的大小，然后在从后向前进行操作。**
  + 不用申请新数组。
  + 从后向前填充元素，避免了从前先后填充元素要来的 每次添加元素都要将添加元素之后的所有元素向后移动。

<div align = center><img src="../images/Double Pointer2.gif" width="500px" /></div>

```c++
string replaceSpace(string s) {
    //统计空格的个数
    int spacecount = 0;
    for(auto temp : s) 
        if(temp == ' ')
            ++spacecount;
    //原来字符串的个数
    int sptr = s.size() - 1;
    //空充后字符串的个数
    s.resize(s.size() + 2 * spacecount);
    int resultptr = s.size() - 1;
    //填充字符串
    while(sptr >= 0 && resultptr >= 0) {
        if(s[sptr] == ' ') {
            s[resultptr] = '0';
            s[--resultptr] = '2';
            s[--resultptr] = '%';
            --sptr;
            --resultptr;
        } else {
            s[resultptr] = s[sptr];
            --sptr;
            --resultptr;
        }
    }
    return s;
}
```





## 二.滑动窗口

### 1.框架构建

滑动窗口是一种**双指针技巧**。该算法的思路非常简单，就是维护一个窗口，不断滑动，然后更新答案。该算法的大致逻辑如下：

```c++
int left = 0, right = 0;
while (right < s.size()) {
    // 增大窗口
    window.add(s[right]);
    right++;
    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```

该算法技巧的时间复杂度是 O(N)，比字符串暴力算法要高效得多。

**框架如下：**

```c++
void slidingWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for(char c : t)
        need[c]++;
    
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...
        /*** debug 输出的位置 ***/
        printf("window:[%d, %d)\n", left, right);
        /**********************/
        
        //判断左侧窗口是否收缩
        while (window needs shrink) {
            // d 是将移除窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```

**其中两处 ... 表示更新窗口数据的地方，直接填即可。**

### 2.例题解剖

#### [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

> 给你一个字符串 `s` 、一个字符串 `t` 。返回 `s` 中涵盖 `t` 所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""` 。

:diamonds: **整体思路：**

1.  我们在字符串 `S`  中使用双指针中的左右指针技巧，初始化`left = right = 0`，把索引**左闭右开**区间 `[left, right)` 称为一个窗口。
2.  我们先不断地增加 `right` 指针扩大窗口 `[left, right)`，直到窗口中的字符串符合要求 （包含了 `T` 中的所有字符）。
3.  此时，我们停止增加 `right`，转而不断增加 `left` 指针缩小窗口 `[left, right)`，直到窗口中的字符串不再符合要求（不包含 `T` 中所有字符了）。同时，每次增加 `left` 到达字符串 `s` 的尽头。
4.  重复第 2 步 和第 3 步，直到 `right` 到达字符串 `S` 的尽头。

整体思路其实不难，**第 2 步相当于在寻找一个可行解，然后第 3 步在优化这个可行解，最终找到最优解，**也就是最短的覆盖子串。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动，这就是滑动窗口名字的来历。

:diamond_shape_with_a_dot_inside: 下面画图理解一下，needs 和 window 相当于计数器，分别记录 T 中字符出现次数和窗口中的相应字符的出现次数。

:small_blue_diamond: **初试状态:**

<div align="center"><img src="../images/Double Pointer5.png" width="500px" /></div>

:small_blue_diamond: **增加 right，直到窗口 [left, right] 包含了 T 中所有字符：**

<div align="center"><img src="../images/Double Pointer6.png" width="500px" /></div>

:small_blue_diamond: **现在开始增加 left，缩小窗口 [left, right]。**

<div align="center"><img src="../images/Double Pointer7.png" width="500px" /></div>

:small_blue_diamond: **直到窗口中的字符串不再符合要求，left 不再继续移动。**

<div align="center"><img src="../images/Double Pointer8.png" width="500px" /></div>

:small_orange_diamond:  **之后重复上述过程，先移动 right，再移动 left…… 直到 right 指针到达字符串 S 的末端，算法结束。**



```c++
string minWindow(string s, string t) {
    //定义need,window两个哈希表，用于记录 需要凑齐的字符 和  窗口中的字符
    unordered_map<char,int> need,window;
    for(auto c : t) need[c] ++;
    //定义双指针变量初始化窗口的两端，区间为左闭右开
    int left = 0, right = 0;
    //记录最小覆盖子串的长度及其初始索引
    int len = INT_MAX, start = 0;
    //定义valid 变量表示窗口中满足need条件的字符个数，
    //如果valid和need.size()大小相同，则说明完全覆盖
    int valid = 0;
    //开始滑动
    while(right < s.size()) {
        //cs是将移入窗口的字符
        char c = s[right];
        //右移窗口
        ++ right;
        //进行窗口内的一系列更新
        if(need.count(c)) {
            //如果在need集合中，则放入窗口中
            window[c] ++;
            //如果窗口中字符个数与需凑齐字符的个数一致，则满足覆盖数+1
            if(window[c] == need[c])
                ++ valid;
        }

        //判断左侧窗口是否要收缩
        while(valid == need.size()) {
            //更新最小覆盖子串
            if(right - left < len) {
                //更新最小长度及其开始的索引
                len = right - left;
                start = left;
            }
            //d是移除窗口的字符
            char d = s[left];
            //左移窗口
            ++ left;
            //进行窗口内的一系列更新
            if(need.count(d)) {
                //如果在need集合中，则移除窗口
                if(window[d] == need[d]) 
                    //如果窗口中字符个数与需凑齐字符的个数一致，则满足覆盖数-1
                    valid--;
                //移除窗口
                window[d]--;
            }
        }
    }
    return len == INT_MAX ? "" : s.substr(start,len);
}
```

#### [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

> 给定一个字符串 **s** 和一个非空字符串 **p**，找到 **s** 中所有是 **p** 的字母异位词的子串，返回这些子串的起始索引。

```c++
vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> need,window;
    for(auto c : p) need[c]++;
    vector<int> result;
    int left = 0, right = 0;
    int valid = 0;
    while(right < s.size()) {
        char c = s[right];
        ++ right;
      	//如果在需要凑齐的集合中
        if(need.count(c)) {	
          	//录入窗口
            window[c]++;
          	//当录入窗口的字符个数与需要的字符个数相同时
            if(need[c] == window[c])
              	//窗口中满足need条件的字符个数+1
                ++ valid;
        }
				//缩小窗口的条件
        while(right - left >= p.size()) {
          	//窗口中满足need条件的字符个数满足时，输出
            if(valid == need.size())
                result.push_back(left);
            //缩小窗口
            char d = s[left];
            ++ left;
          	//如果是在需要凑齐的集合中
            if(need.count(d)) {
              	//当录入窗口的字符个数与需要的字符个数相同时
                if(need[d] == window[d])
                  	//窗口中满足need条件的字符个数 -1
                    --valid;
              	//窗口减小
                -- window[d];
            }
        }
    }
    return result;
}
```

#### [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。

```c++
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> window;
    int left = 0, right = 0;
    int maxlen = 0;
    while(right < s.size()) {
        char c = s[right];
        ++right;
      	//窗口数据更新
        window[c]++;
      	//出现重复字符时，进行缩减窗口
        while(window[c] > 1) {
            char d = s[left];
            ++left;
          	//窗口数据更新
            window[d]--;
        }
        maxlen = max(maxlen, right - left);
    }
    return maxlen;
}
```

