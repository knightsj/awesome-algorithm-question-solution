# Intersection Of Two Linked Lists (两个链表是否有交点)



## From 

[LeetCode 160](https://leetcode.com/problems/intersection-of-two-linked-lists/description/)





## Question

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

```
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
```



## Solution  



### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//length of linked list
int __calculateListLength(ListNode *head){
    
    int count = 0;
    
    while (head) {
        
        count++;
        head = head->next;
    }
    
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int lengthA = __calculateListLength(headA);
    int lengthB = __calculateListLength(headB);
    
    int n = lengthA - lengthB;
    
    ListNode *pA = headA;
    ListNode *pB = headB;
    
    //move node pointer
    for(int i=0; i < abs(n); i++){
        
        //a is longer
        if( n > 0){
            
            pA = pA->next;
            
        }else{
            //b is longer
            pB = pB->next;
            
        }
    }
    
    while (pA && pB) {
        
        //found intersection node
        if (pA == pB) {
            return pB;
        }
        
        pA = pA->next;
        pB = pB->next;
        
    }
    
    return NULL;
    
}
```

### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        int lengthA = _calculateLinkedListLength(headA);
        int lengthB = _calculateLinkedListLength(headB);
        
        int n = lengthA - lengthB;
        
        ListNode pA = headA;
        ListNode pB = headB;
        
        for ( int i = 0; i < Math.abs(n); i++){
            
            if (n > 0){
                pA = pA.next;
            }else {
                pB = pB.next;
            }
        }
        
        while (pA != null && pB != null){
            
            if ( pA == pB ){
                return pB;
            }
            
            pA = pA.next;
            pB = pB.next;
        }
        
        return null;
        
    }
    
    private int _calculateLinkedListLength( ListNode head ){
        
        int count = 0;
        
        while ( head != null ){
            
            count ++;
            
            head = head.next;
        }
        
        return count;
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

def get_intersection_begin(node1, node2):
    if not node1 or not node2:
        return None
    def get_length(node):
        if not node:
            return -1
        count = 0
        while node:
            count += 1
            node = node.next
        return count
    l1 = get_length(node1)
    l2 = get_length(node2)
    inter_count = l1 - l2
    n1,n2 = node1, node2
    for l in range(abs(inter_count)):
        if inter_count > 0:
            n1 = n1.next
        else:
            n2 = n2.next
    while n1 != n2:
        n1 = n1.next
        n2 = n2.next
    return n1

```