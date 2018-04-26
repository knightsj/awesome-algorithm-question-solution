# Remove Nth From End Of Linkded List 



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
        
        ListNode * first = head;
        ListNode * second = head;
        
        for(int i = 0;i < n;i++){
            first = first->next;
        }
        
        //1,2,3,4,5 n = 4
        if(first == NULL){
            return head->next;
        }
        
        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return head;
    }
    
};
```

