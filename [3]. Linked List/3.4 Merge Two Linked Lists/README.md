# Merge Two Linked List（合并两个有序链表）



## From

[LeetCode 21](https://leetcode.com/problems/merge-two-sorted-lists/description/)



## Question

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.



**Example:**

```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL){
            
            return l2;
            
        }else if(l2 == NULL){
            
            return l1;
            
        }
        
        ListNode *mergedNode = NULL;
        
        if(l1->val < l2->val){
            
            mergedNode = l1;
            mergedNode->next = mergeTwoLists(mergedNode->next,l2);
            
        }else{
            
            mergedNode = l2;
            mergedNode->next = mergeTwoLists(l1, mergedNode->next);
        }
        
        return mergedNode;
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
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
        if ( l1 == null ){
            return l2;
        }
        
        if ( l2 == null ){
            return l1;
        }
        
        ListNode mergedNode = null;
        
        if ( l1.val < l2.val ){
            
            mergedNode = l1;
            mergedNode.next = mergeTwoLists(mergedNode.next, l2);
            
        }else{
            
            mergedNode = l2;
            mergedNode.next = mergeTwoLists(l1, mergedNode.next);
        }
        
        return mergedNode;       
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

def merge_node(node1, node2):
    if not node1:
        return node2
    if not node2:
        return node1
    res = None
    if node1.value < node2.value:
        res = node1
        res.next = merge_node(node1.next, node2)
    else:
        res = node2
        res.next = merge_node(node2.next,node1)
    return res

```