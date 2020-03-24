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

### Java

```java
public static void PrintListReversingly(ListNode pHead){

    if(pHead != null){
    
        if (pHead.next != null){
        
            PrintListReversingly(pHead.next);
        }

        System.out.println(pHead.val);
    }
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

def print_reverse_node(node):
    if node:
        if node.next:
            print_reverse_node(node.next)
        print(node.value)

```
