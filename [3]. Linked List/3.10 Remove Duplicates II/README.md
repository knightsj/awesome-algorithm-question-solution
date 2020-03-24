# Remove Duplicates II （删除值等于给定值的所有节点）   



## From 

[LeetCode 82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/)



## Question

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only *distinct* numbers from the original list.

**Example 1:**

```
Input: 1->2->3->3->4->4->5
Output: 1->2->5
```

**Example 2:**

```
Input: 1->1->1->2->3
Output: 2->3
```



## Solution  

### C++

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head){

    if (head == NULL){
            return NULL;
        }

        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *pre = fakeHead;
        ListNode *cur = head;

        while (cur != NULL) {

            while (cur->next != NULL && cur->val == cur->next->val ) {
                cur = cur->next;
            }

            if (pre->next == cur ){
                //pre is next to cur
                pre = pre->next;

            }else {

                pre->next = cur->next;

            }
            //move cur
            cur = cur->next;
        }
        return fakeHead->next;
}
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
    
    public ListNode deleteDuplicates(ListNode head) {
        
        if (head == null){
            return null;
        }

        ListNode fakeHead = new ListNode(0);
        fakeHead.next = head;
        ListNode pre = fakeHead;
        ListNode cur = head;

        while (cur != null) {

            while (cur.next != null && cur.val == cur.next.val ) {
                cur = cur.next;
            }

            if (pre.next == cur ){
                //pre is next to cur
                pre = pre.next;

            }else {

                pre.next = cur.next;

            }
            //move cur
            cur = cur.next;
        }
        return fakeHead.next;
        
        
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

def del_dup_node_2(node):
    if not node:
        return
    fake_head = ListNode(0)
    fake_head.next = node
    pre = fake_head
    cur = node
    while cur.next:
        while cur.next.value == cur.value:
            cur = cur.next
        if pre.next == cur:
            pre = pre.next
        else:
            pre.next = cur.next
        cur = cur.next
    return fake_head.next

```