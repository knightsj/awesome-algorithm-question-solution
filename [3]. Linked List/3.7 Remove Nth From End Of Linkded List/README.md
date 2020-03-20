# Remove Nth From End Of Linkded List (删除倒数第N个节点) 



## From

[LeetCode 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)





## Question

Given a linked list, remove the *n*-th node from the end of list and return its head.

**Example:**

```
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
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
    
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if( head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode * firstNode = head;
        ListNode * secondNode = head;
        
        for(int i = 0;i < n; i++){
            firstNode = firstNode->next;
        }
        
        //1,2,3,4,5 n = 4
        if(firstNode == NULL){
            return head->next;
        }
        
        while(firstNode->next != NULL)
        {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
        
        secondNode->next = secondNode->next->next;
        
        return head;
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
       if( head == null || head.next == null){
            return null;
        }
        
        ListNode firstNode = head;
        ListNode secondNode = head;
        
        for(int i = 0; i < n; i++){
            firstNode = firstNode.next;
        }
        
        //1,2,3,4,5 n = 4
        if(firstNode == null){
            return head.next;
        }
        
        while(firstNode.next != null)
        {
            firstNode = firstNode.next;
            secondNode = secondNode.next;
        }
        
        secondNode.next = secondNode.next.next;
        
        return head;
        
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

def del_node_reverse_k(node, k):
    if not node or k <= 0:
        return
    head1 = node
    for _ in range(k):
        if not head1:
            return
        head1 = head1.next
    if head1 == None:
        node = node.next
        return node
    head2 = node
    while head1.next:
        head1 = head1.next
        pre = head2
        head2 = head2.next
    head2.next = head2.next.next
    return node

```