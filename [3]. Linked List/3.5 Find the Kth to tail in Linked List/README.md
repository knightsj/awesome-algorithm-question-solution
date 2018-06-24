# Find The Kth Node To Tail in Linked List (找到倒数第k个节点)





## From

《剑指offer》Question No.14



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
    ListNode *pBehind = NULL;
    
    for(unsigned int i = 0; i < k - 1; ++ i)
    {
        if(pAhead->next != NULL)
            pAhead = pAhead->next;
        else
        {
            return NULL;
        }
    }
    
    pBehind = pListHead;
    
    while(pAhead->next != NULL)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    
    return pBehind;
}
```
