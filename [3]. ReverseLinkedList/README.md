# ReverseLinkedList


## Solution in C++ 

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};
```

