# Reverse Linked List



## From

[LeetCode 206](https://leetcode.com/problems/reverse-linked-list/description/)



## Question

Reverse a singly linked list.



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

