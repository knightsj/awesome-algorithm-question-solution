# Delete Node in a Linked List 



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

