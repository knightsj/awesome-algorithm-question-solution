# Remove Duplicates I（删除重复节点）   



## From 

 [LeetCode 83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)



## Question

Given a sorted linked list, delete all duplicates such that each element appear only *once*.

**Example 1:**

```
Input: 1->1->2
Output: 1->2
```

**Example 2:**

```
Input: 1->1->2->3->3
Output: 1->2->3
```



## Solution  

### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head){

    ListNode *curNode = head;
    
    while (curNode->next != NULL){
        
        if (curNode->val == curNode->next->val){
            
			//delNode is the node to delete
            ListNode *delNode = curNode->next;
            curNode->next = delNode->next;
            delete delNode;
            
        } else{
            
            curNode = curNode->next;
            
        }
    }

    return head;
}
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
    
    public ListNode deleteDuplicates(ListNode head) {
        
        
        if ( head == null || head.next == null){
            return head;
        }
        
        ListNode curNode = head;
    
        while (curNode.next != null){
        
            if (curNode.val == curNode.next.val){
            
			    //delNode is the node to delete
                ListNode delNode = curNode.next;
                curNode.next = delNode.next;
            
            } else{
            
                curNode = curNode.next;
            
            }
        }

        return head;
        
    }
}
```