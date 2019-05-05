# Linked List Cycle (链表是否有环)



## From

 [LeetCode 141](https://leetcode.com/problems/linked-list-cycle/description/)





## Question

Given a linked list, determine if it has a cycle in it.



## Solution 



### C++

```c++
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    
    ListNode* slowerNode = head;
    ListNode* fasterNode = head;
    
    while(slowerNode != NULL && fasterNode != NULL && fasterNode->next != NULL){
        
        slowerNode = slowerNode->next;
        fasterNode = fasterNode->next->next;
        
        if(slowerNode == fasterNode){
            return true;
        }
    }
    
    return false;
}
```


### Java

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    
    public boolean hasCycle(ListNode head) {
        
        ListNode slowerNode = head;
        ListNode fasterNode = head;
        
        while ( slowerNode != null && fasterNode != null && fasterNode.next != null ){
            
            slowerNode = slowerNode.next;
            fasterNode = fasterNode.next.next;
            
             if (slowerNode == fasterNode){
                return true;
            }
        }
        
        return false;
        
    }
}
```
