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
// #warning 这个解法可能不太对，题干的第二个例子都 ac 不过
ListNode* deleteDuplicates(ListNode* head){

    if (head == NULL || head->next == NULL){
        return  NULL;
    };

    ListNode *newHead = head;

    while (head->next){

        if(head->val == head->next->val){

            head->next = head->next->next;

        } else{
            
            head = head->next;
            
        }
    }
    return newHead;
}
```

### Java

```java
ListNode deleteDuplicates(ListNode head) {
    head = deleteHead(head);
	
    if (head == null || head.next == null) return head;
	
    ListNode temp = head.next, pre = head;
	
    while (temp != null && temp.next != null) {
        if (temp.next.val != temp.val) {
            temp = temp.next;
            pre = pre.next;
        } else {
            pre.next = deleteHead(temp);
            temp = pre.next;
        }
    }

    return head;
}

// 删除所有出现超过两次的结点
ListNode deleteHead(ListNode head) {
    if (head == null || head.next == null) return head;

    int cnt = 0;
    while (head.next != null && head.next.val == head.val) {
        head = head.next;
        cnt ++;
    }

    if (cnt != 0) {
        head = head.next;
        return deleteHead(head);
    } else {
        return head;
    }
}
```

