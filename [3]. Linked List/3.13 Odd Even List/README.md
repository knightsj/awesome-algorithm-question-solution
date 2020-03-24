# Odd Even List （奇数偶数index的节点分在链表两侧）   



## From

[LeetCode 328](https://leetcode.com/problems/odd-even-linked-list/description/)





## Question



Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

**Example:**
Given `1->2->3->4->5->NULL`,
return `1->3->5->2->4->NULL`.



## Solution  

### C++



using partitionCondition:

```c++
ListNode* oddEvenList(ListNode* head) {

      if (head == NULL || head->next == NULL){
          return head;
      }

      ListNode *left = new ListNode(-1);
      ListNode *p = left;

      ListNode *right = new ListNode(-1);
      ListNode *q = right;

      int index = 1;

      while(head!= NULL){

          if(__partitionCondition(index)){

              p->next = head;
              p = p->next;
          }else{
              q->next = head;
              q = q->next;
          }

          head = head->next;

          index++;
      }

      q->next = NULL; //right end
      p->next = right->next;//left end
      return left->next;

  }

  bool __partitionCondition(int val){

      if (val % 2 == 1){
          return true;
      } else {
          return false;
      }
  }

```



using pointer operation:

```c++

ListNode* oddEvenList1(ListNode *head) {

    if (head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode *odd = head;
    ListNode *even = odd->next;
    ListNode *evenHead = even;

    while(even != NULL && even->next != NULL) {

        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
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
    public ListNode oddEvenList(ListNode head) {
        
      if (head == null || head.next == null){
          return head;
      }

      ListNode left = new ListNode(-1);
      ListNode p = left;

      ListNode right = new ListNode(-1);
      ListNode q = right;

      int index = 1;

      while( head != null ){

          if(__partitionCondition(index)){

              p.next = head;
              p = p.next;
              
          }else{
              q.next = head;
              q = q.next;
          }

          head = head.next;

          index++;
      }

      q.next = null; //right end
      p.next = right.next;//left end
      return left.next;
    }
    
    private boolean __partitionCondition(int val){

      if (val % 2 == 1){
          return true;
      } else {
          return false;
      }
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

def partition_node_value_odd(node):
    if not node:
        return
    l, l_pre = None, None
    h, h_pre = None, None
    cur = node
    while cur:
        if cur.value % 2 == 0:
            if not h:
                h = cur
                h_pre = cur
            else:
                h_pre.next = cur
                h_pre = cur
        else:
            if not l:
                l = cur
                l_pre = cur
            else:
                l_pre.next = cur
                l_pre = cur
        cur = cur.next
    h_pre.next = None
    l_pre.next = h
    return l

```