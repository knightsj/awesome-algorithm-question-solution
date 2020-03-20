# Delete Node in a Linked List (删除某个值等于给定值的节点) 



## From 

[LeetCode 237](https://leetcode.com/problems/delete-node-in-a-linked-list/description)



## Question

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is `1 -> 2 -> 3 -> 4` and you are given the third node with value `3`, the linked list should become `1 -> 2 -> 4` after calling your function.



## Solution  

### C++

```c++
#include <stdio.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//1 2 3 4 5 -> //1 2 4 5
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if (!node || !node->next)  {
            return;
        }
                
        node->val = node->next->val;
        node->next = node->next->next;
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
    public void deleteNode(ListNode node) {
        
         if ( node == null || node.next == null)  {
            return;
        }
                
        node.val = node.next.val;
        node.next = node.next.next;       
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

def del_node_in(node):
    if not node or not node.next:
        return
    node.value = node.next.value
    node.next = node.next.next

```