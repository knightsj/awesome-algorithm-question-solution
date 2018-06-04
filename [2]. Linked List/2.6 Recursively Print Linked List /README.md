# Recursively Print Linked List 



## From

《剑指offer》Question No.5





## Question

Recursively print a given linked list.



## Solution  



### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void PrintListReversingly(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if (pHead->next != nullptr)
        {
            PrintListReversingly(pHead->next);
        }
        
        printf("%d\t", pHead->val);
    }
}
```

