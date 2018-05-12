# Remove Duplicates II   



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

    if (head == NULL || head->next == NULL){
        return  NULL;
    };

    ListNode *newNode = head;

    while (head->next){

        if(head->val == head->next->val){

            head->next = head->next->next;

        } else{
            head = head->next;
        }
    }
    return newNode;
}
```

