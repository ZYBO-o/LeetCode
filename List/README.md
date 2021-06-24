## 链表

### 一.单链表操作

#### 1.单链表结构

![image-20210421173229883](../images/List1.png)

#### 2.单链表创建与实现

```c++
//List_LeetCode.h
// Created by 张永斌 on 2021/4/22.
//
#ifndef DATASTRUCTURE_LIST_LEETCODE_H
#define DATASTRUCTURE_LIST_LEETCODE_H

#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int val) : value(val), next(nullptr) {}
    ListNode(int val, ListNode* node) : value(val), next(node) {}
};

//创建链表
ListNode* CreateList(std::vector<int> nums);
//打印链表
void PrintList(ListNode* head);
//插入结点
bool InsertNode(ListNode* head, ListNode* node, const int& index);
//插入数据元素
bool InsertNode(ListNode* head, const int& val, const int& index);
//删除数据元素
bool DeleteNode(ListNode* head, const int& val);
//查找数据元素
int FindNode(ListNode* head, const int& val);
//返回链表长度
int ListLength(ListNode* head);
//清除链表
void clear(ListNode* head);

#endif //DATASTRUCTURE_LIST_LEETCODE_H
```

```c++
//List_LeetCode.cpp
//
// Created by 张永斌 on 2021/4/22.
//

#include "List_LeetCode.h"
#include <vector>

//创建链表
ListNode* CreateList(std::vector<int> nums) {
    ListNode* dummeryNode = new ListNode(0);
    ListNode* p = dummeryNode;
    for (auto num : nums) {
        ListNode* temp = new ListNode(num);
        p->next = temp;
        p = temp;
    }
    return dummeryNode->next;
}

//打印链表
void PrintList(ListNode* head) {
    ListNode* p = head;
    while(p != nullptr) {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

//插入结点
bool InsertNode(ListNode* head, ListNode* node, const int& index) {
    bool ret = true;
    if (head == nullptr)
    {
        std::cout << "list is null.." << std::endl;
        ret = false;
    }
    else if(index < 0 && index >= ListLength(head))
    {
        std::cout << "insert index is invalid.." << std::endl;
        ret = false;
    }
    else
    {
        auto dummeryNode = new ListNode(0);
        dummeryNode->next = head;
        ListNode* p = dummeryNode;

        for (int i = 0; i < index - 1; ++i) {
            p = p->next;
        }
        node->next = p->next;
        p->next = node;

    }
    return ret;
}

//插入数据元素
bool InsertNode(ListNode* head, const int& val, const int& index) {
    auto node = new ListNode(val);
    return InsertNode(head, node, index);
}

//删除数据元素
bool DeleteNode(ListNode* head, const int& val) {
    bool ret = false;

    auto dummeryNode = new ListNode(0);
    dummeryNode->next = head;
    ListNode* p = dummeryNode;

    for (int i = 0; i < ListLength(head) && p->next != nullptr; ++i) {
        if(p->next->value != val)
            p = p->next;
        else
        {
            ret = true;
            break;
        }
    }

    if(ret) {
        ListNode* temp = p->next;
        p->next = temp->next;
        free(temp);
    } else {
        std::cout << "Error ! No value = " << val << " in this list.." << std::endl;
    }
    return ret;
}

//搜索结点
int FindNode(ListNode* head, const int& val) {
    int index = 0;
    bool ret = false;
    auto dummeryNode = new ListNode(0);
    dummeryNode->next = head;
    ListNode* p = dummeryNode;

    for (int i = 0; i < ListLength(head) && p->next != nullptr; ++i) {
        if(p->next->value != val) {
            p = p->next;
            ++ index;
        } else {
            ret = true;
            break;
        }
    }
    if(!ret) {
        std::cout << "Error ! Cannot find value = " << val << " in this list.." << std::endl;
    }
    return index;
}

//链表长度
int ListLength(ListNode * head) {
    ListNode* p = head;
    int len = 0;
    while(p != nullptr) {
        ++ len;
        p = p->next;
    }
    return len;
}

//清除结点
void clear(ListNode* head) {
    ListNode* p = head;
    while(p != nullptr) {
        DeleteNode(head,p->value);
        p = p->next;
    }
}
```

---

### LeetCode积累

#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

> 给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

如果再定义一个新的链表，实现链表元素的反转，其实这是对内存空间的浪费。

其实只需要改变链表的next指针的指向，直接将链表反转 ，而不用重新定义一个新的链表，如图所示:

<div align = center><img src="../images/List2.png" width="600px" /></div>

+ 双指针方法：

  ```c++
  ListNode* reverseList(ListNode* head) {
      ListNode* pre = nullptr;
      ListNode* cur = head;
      ListNode* temp;
      while(cur != nullptr) {
          temp = cur->next
          cur->next = pre;
          pre = cur;
          cur = temp;
      }
      return pre;
  }
  ```
  
+ 递归方法：

  ```c++
  ListNode* reverse(ListNode* pre, ListNode* cur) {
      if(cur == nullptr) 
          return pre;
      ListNode* temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
      return reverse(pre, cur);
  }
  ListNode* reverseList(ListNode* head) {
      return reverse(nullptr, head);
  }
  ```

#### [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

> 给定一个链表，判断链表中是否有环。
>
> 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
>
> 如果链表中存在环，则返回 true 。 否则，返回 false 。

定义两个指针，一快一满。慢指针每次只移动一步，而快指针每次移动两步。初始时，慢指针在位置 head，而快指针在位置 head.next。这样一来，如果在移动的过程中，快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。

+ 快慢指针

  ```c++
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
  ```

#### [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

> 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
>
> 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

使用两个指针，fast 和 slow，它们起始都位于链表的头部。随后，slow 指针每次向后移动一个位置，而 fast 指针向后移动两个位置。如果链表中存在环，则 fast 指针最终将再次与 slow 指针在环中相遇。

当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。

+ 快慢指针

```c++
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
    return NULL;
}
```

#### [面试题 02.07. 链表相交](https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/)

> 给定两个（单向）链表，判定它们是否相交并返回交点。请注意相交的定义基于节点的引用，而不是基于节点的值。换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。

+ 设长链表A长度为LA，短链表长度LB；
+ 由于速度相同，则在长链表A走完LA长度时，短链表B已经反过头在A上走了LA-LB的长度，剩余要走的长度为LA-(LA-LB) = LB；
+ 之后长链表A要反过头在B上走，剩余要走的长度也是LB；
+ 也就是说目前两个链表“对齐”了。因此，接下来遇到的第一个相同节点便是两个链表的交点。

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* list1 = headA;
    ListNode* list2 = headB;

    while(list1 != list2) {
        list1 = (list1 != nullptr ? list1->next : headB);
        list2 = (list2 != nullptr ? list2->next : headA);
    }
    return list1;
}
```

#### [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

> 给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

由于我们需要找到倒数第 n 个节点，因此我们可以使用两个指针 first 和 second 同时对链表进行遍历，并且 first 比 second 超前 n 个节点。当 first 遍历到链表的末尾时，second 就恰好处于倒数第 n 个节点。

+ 快慢指针

  ```c++
  ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummyHead = new ListNode(0);
      dummyHead->next = head;
      ListNode* slow = dummyHead;
      ListNode* fast = dummyHead;
      while(n-- && fast != NULL) {
          fast = fast->next;
      }
      fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
      while (fast != NULL) {
          fast = fast->next;
          slow = slow->next;
      }
      slow->next = slow->next->next;
      return dummyHead->next;
  }
  ```

#### [143. 重排链表](https://leetcode-cn.com/problems/reorder-list/)

> 给定一个单链表 *L*：*L*0→*L*1→…→*L**n*-1→*L*n ，
> 将其重新排列后变为： *L*0→*L**n*→*L*1→*L**n*-1→*L*2→*L**n*-2→…

注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：

+ 找到原链表的中点（参考「876. 链表的中间结点」）。
  + 我们可以使用快慢指针来 O(N)地找到链表的中间节点。

+ 将原链表的右半端反转（参考「206. 反转链表」）。
  + 我们可以使用迭代法实现链表的反转。将原链表的两端合并。

+ 因为两链表长度相差不超过 1，因此直接合并即可。

```c++
//1.找到各自中间结点
 //2.将后半链表进行反转
 //3.合并成新的链表
class Solution {
public:
    //反转链表
    ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* p = nullptr;
        while(current != nullptr) {
            ListNode* node = current->next;
            current->next = p;
            p = current;
            current = node;
        }
        return p;
    }
		//找到中间结点
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
		//合并链表
    ListNode* Reorder(ListNode* list1, ListNode* list2) {
        ListNode* list1_temp = nullptr;
        ListNode* list2_temp = nullptr;
        ListNode* reorder_list = list1;
        while(list1 != nullptr && list2 != nullptr) {
            //先把list1_temp1指向list1的下一结点
            list1_temp = list1->next;
            //list1指向list2
            list1->next = list2;
            //list1变为后面的链表
            list1 = list1_temp;
            //list2_temp指向list2的下一结点
            list2_temp = list2->next;
            //list2指向新的list1
            list2->next = list1;
            //list2变为后面的链表
            list2 = list2_temp;
        }
        return reorder_list;
    }
    
    void reorderList(ListNode* head) {
        ListNode* list = head;
        ListNode* reverselist = reverse(middleNode(head));
        ListNode* reorder_list = Reorder(list,reverselist);
    }
};
```





