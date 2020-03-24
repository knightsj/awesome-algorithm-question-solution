# Remove Linked List Elements   



## From

[LeetCode 203](https://leetcode.com/problems/remove-linked-list-elements/description/)





## Question





Remove all elements from a linked list of integers that have value **val**.

**Example:**

```
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
```



## Solution  

### C++

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode *head, int val){

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *cur = dummyHead;
        
        while (cur->next != NULL){
            
            if (cur->next->val == val){
                
                ListNode *delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                
            } else{
                
                cur = cur->next;
                
            }
        }

        ListNode *returnNode = dummyHead->next;
        delete dummyHead;

        return returnNode;
    }
};
```

### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public ListNode removeElements(ListNode head, int val) {
        
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode cur = dummyHead;
        
        while (cur.next != null){
            
            if (cur.next.val == val){
                
                ListNode delNode = cur.next;
                cur.next = delNode.next;
                
            } else{
                
                cur = cur.next;
                
            }
        }

        ListNode returnNode = dummyHead.next;

        return returnNode;
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

def del_node_value(node, value):
    if not node:
        return None
    fake_head = ListNode(-1)
    fake_head.next = node   
    cur = fake_head 
    while cur.next:
        if cur.next.value == value:
            cur.next = cur.next.next
        else:
            cur = cur.next
    return fake_head.next

```