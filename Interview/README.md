# 面试题积累

>  **不是很熟练的题目：**
>
> + [面试题 01.01. 判定字符是否唯一](https://leetcode-cn.com/problems/is-unique-lcci/)
> + [面试题 01.08. 零矩阵](https://leetcode-cn.com/problems/zero-matrix-lcci/)
> + [面试题 02.04. 分割链表](https://leetcode-cn.com/problems/partition-list-lcci/)
> + [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/)

### 位运算

+ [面试题 01.01. 判定字符是否唯一](https://leetcode-cn.com/problems/is-unique-lcci/)

  > **解题思路：**
  >
  > 可以使用一个int类型的变量(下文用mark表示)来代替长度为26的bool数组。假设这个变量占26个bit（在多数语言中，这个值一般不止26），那么我们可以把它看成000...00(26个0)，这26个bit对应着26个字符，对于一个字符c，检查对应下标的bit值即可判断是否重复。那么难点在于如何检查？这里我们可以通过位运算来完成。
  >
  > 首先计算出字符char离'a'这个字符的距离，即我们要位移的距离，用`move_bit`表示，那么使用左移运算符`1 << move_bit`则可以得到对应下标为1，其余下标为0的数，如字符char = 'c'，则得到的数为000...00100，将这个数跟mark做与运算，由于这个数只有一个位为1，其他位为0，那么与运算的结果中，其他位肯定是0，而对应的下标位是否0则取决于之前这个字符有没有出现过，若出现过则被标记为1，那么与运算的结果就不为0；若之前没有出现过，则对应位的与运算的结果也是0，那么整个结果也为0。对于没有出现过的字符，我们用或运算`mark | (1 << move_bit)`将对应下标位的值置为1。

  ```c++
  class Solution {
  public:
      bool isUnique(string astr) {
          int mask = 0, step = 0;
          for(const int letter:astr){
              step = letter-int('a');
              if(mask & (1<<step))
                  return false;
              mask |= (1<<step);
          }
          return true;
      }
  };
  ```



### 链表相交

> **解题思路：**
>
> 你变成我，我变成你，我们便相遇了。
>
> 那么为什么能相遇呢？
>
> 设长链表A长度为LA，短链表长度LB；
> 由于速度相同，则在长链表A走完LA长度时，短链表B已经反过头在A上走了LA-LB的长度，剩余要走的长度为LA-(LA-LB) = LB；
> 之后长链表A要反过头在B上走，剩余要走的长度也是LB；
> 也就是说目前两个链表“对齐”了。因此，接下来遇到的第一个相同节点便是两个链表的交点。
> 那如果两个链表不存在交点呢？
> 答：这样的话第4步就会一直执行到两个链表的末尾，la,lb都为null,也会跳出循环，返回null。

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* La = headA;
        ListNode* Lb = headB;
        while(La != Lb) {
            La = La == nullptr ? headB : La->next;
            Lb = Lb == nullptr ? headA : Lb->next;
        }
        return La;
    }
};
```



### 环路问题

> **环路存在问题描述：**
>
> 给定一个链表，判断链表中是否有环。
>
> 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
>
> 如果链表中存在环，则返回 true 。 否则，返回 false 。
>
> **解决思路：**
>
> 可以使用快慢指针法， 分别定义 fast 和 slow指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
>

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            fast = fast->next;
            if(fast != nullptr) {
                fast = fast->next;
            }
            if(fast == slow) {
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};
```

> **环路入口问题描述：**
>
> 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 `null`。
>
> 为了表示给定链表中的环，我们使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 `pos` 是 `-1`，则在该链表中没有环。**注意，`pos` 仅仅是用于标识环的情况，并不会作为参数传递到函数中。**
>
> **解决思路：**
>
> 1. 快针走的是慢针的两倍。
> 2. 慢针走过的路，快针走过一遍。
> 3. 快针走过的剩余路程，也就是和慢针走过的全部路程相等。(a+b = c+b)
> 4. 刨去快针追赶慢针的半圈(b)，剩余路程即为所求入环距离(a=c)

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return nullptr;
    }
};
```



### 双栈思路

> [面试题 03.02. 栈的最小值](https://leetcode-cn.com/problems/min-stack-lcci/)
>
> 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
>
> **解题思路：**
>
> 对于栈来说，如果一个元素 a 在入栈时，栈里有其它的元素 b, c, d，那么无论这个栈在之后经历了什么操作，只要 a 在栈中，b, c, d 就一定在栈中，因为在 a 被弹出之前，b, c, d 不会被弹出。
>
> 因此，在操作过程中的任意一个时刻，只要栈顶的元素是 a，那么我们就可以确定栈里面现在的元素一定是 a, b, c, d。
>
> 那么，我们可以在每个元素 a 入栈时把当前栈的最小值 m 存储起来。在这之后无论何时，如果栈顶元素是 a，我们就可以直接返回存储的最小值 m。
>

```c++
class MinStack {
    stack<int> min_stack;
    stack<int> stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        stack.push(val);
        min_stack.push(min(min_stack.top(),val));
    }
    
    void pop() {
        stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
```

