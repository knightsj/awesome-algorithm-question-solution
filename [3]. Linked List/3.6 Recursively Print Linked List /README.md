# Recursively Print Linked List (倒序打印链表) 



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
    if(pHead != NULL)
    {
        if (pHead->next != NULL)
        {
            PrintListReversingly(pHead->next);
        }
        
        printf("%d\t", pHead->val);
    }
}
```

