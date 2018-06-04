# Intersection Of Two Linked Lists



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
int calculateListLength(ListNode *head){
    
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int lengthA = calculateListLength(headA);
    int lengthB = calculateListLength(headB);
    
    int n = lengthA - lengthB;
    
    ListNode *pA = headA, *pB = headB;
    
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

