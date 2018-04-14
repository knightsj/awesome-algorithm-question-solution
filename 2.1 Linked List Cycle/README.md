# Linked List Cycle



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

