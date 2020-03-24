# Partition Linked List (将小于和大于给定值的节点划分到链表两侧)   



## From

[LeetCode 86](https://leetcode.com/problems/partition-list/description/)



## Question



Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```



## Solution  

### C++

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *left = new ListNode(-1);
        ListNode *p = left;
        
        ListNode *right = new ListNode(-1);
        ListNode *q = right;
        
        while(head!= NULL){
            
            if(head->val < x){
                
                p->next = head;
                p = p->next;
                
            }else{
                
                q->next = head;
                q = q->next;
            }
            
            head = head->next;
        }
        
        q->next = NULL; //right end
        p->next = right->next;//left end
        return left->next;
        
    }
};
```

### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        
        
        if (head == null || head.next == null){
            return head;
        }
        
        ListNode left = new ListNode(-1);
        ListNode p = left;
        
        ListNode right = new ListNode(-1);
        ListNode q = right;
        
        while(head != null){
            
            if( head.val < x){
                
                p.next = head;
                p = p.next;
                
            }else{
                
                q.next = head;
                q = q.next;
            }
            
            head = head.next;
        }
        
        q.next = null; //right end
        p.next = right.next;//left end
        return left.next;

        
    }
}
```

### Python3.7

```

'''
class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None
'''

def partition_node_value(node, value):
    if not node:
        return
    l, l_pre = None, None
    h, h_pre = None, None
    cur = node
    while cur:
        if cur.value > value:
            if not h:
                h = cur
                h_pre = cur
            else:
                h_pre.next = cur
                h_pre = cur
        else:
            if not l:
                l = cur
                l_pre = cur
            else:
                l_pre.next = cur
                l_pre = cur
        cur = cur.next
    h_pre.next = None
    l_pre.next = h
    return l

```