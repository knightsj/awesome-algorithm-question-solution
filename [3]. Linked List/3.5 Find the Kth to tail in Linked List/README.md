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

### Java

```java
public ListNode FindKthToTail(ListNode pListHead,  int k) {

    if (pListHead == null){
        return null;
    }
    
    ListNode pHead = pListHead;
    ListNode pBehind = null;
    
    for ( int i = 0; i < k -1; i++){
        
        if (pHead.next != null){
            pHead = pHead.next;
        }else {
            return null;
        }
    }
    
    pBehind = pListHead;
    
    while(pHead.next != null){
        pHead = pHead.next;
        pBehind = pBehind.next;
    }
    
    return pBehind;
}
```
### Python3.7

```

'''
class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None
'''

def get_node_k_reverse(node, k):
    if not node or k <= 0:
        return None
    head1 = node
    for _ in range(k):
        if not head1:
            return None
        head1 = head1.next
    head2 = node
    while head1:
        head1 = head1.next
        head2 = head2.next
    return head2

```
