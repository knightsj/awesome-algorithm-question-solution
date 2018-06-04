# Merge Two Linked List



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
        
        ListNode *mergedHead = NULL;
        
        if(l1->val < l2->val){
            
            mergedHead = l1;
            mergedHead->next = mergeTwoLists(mergedHead->next,l2);
            
        }else{
            
            mergedHead = l2;
            mergedHead->next = mergeTwoLists(l1, mergedHead->next);
        }
        
        return mergedHead;
    }
};
```

