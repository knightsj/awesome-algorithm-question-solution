# Reverse Linked List（反转链表）



## From

[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/description/)



## Question

Reverse a singly linked list.

```
input: 1->2->3->4->5->NULL
output: 5->4->3->2->1->NULL
```

## Solution  

### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode *head){

        ListNode *preNode = NULL;
        ListNode *curNode = head;

        while ( curNode != NULL){

            ListNode *nextNode = curNode->next;
           
            //change pointer direction
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }

        //pre will be the first node after reversing
        return preNode;
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
    public ListNode reverseList(ListNode head) {
        
        ListNode preNode = null;
        ListNode curNode = head;
        
        while ( curNode != null ){
            
            ListNode nextNode = curNode.next;
            
            curNode.next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }
        
        return preNode;
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

def reverse_node(node):
    if not node:
        return
    pre = None
    cur = node
    while cur:           
        node_next = cur.next
        cur.next = pre
        pre = cur
        cur = node_next
    return pre

```