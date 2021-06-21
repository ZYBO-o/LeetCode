

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

