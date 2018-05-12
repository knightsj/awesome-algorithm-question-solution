# Find The Kth Node To Tail in Linked List



## Question

Given a linked list and a int value k, return the Kth node to tail in it.



## Solution  



### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0)
        return nullptr;
    
    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;
    
    for(unsigned int i = 0; i < k - 1; ++ i)
    {
        if(pAhead->next != nullptr)
            pAhead = pAhead->next;
        else
        {
            return nullptr;
        }
    }
    
    pBehind = pListHead;
    
    while(pAhead->next != nullptr)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    
    return pBehind;
}
```
