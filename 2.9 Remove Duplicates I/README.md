# Remove Duplicates I   



## Question

Given a sorted linked list, delete all duplicates such that each element appear only *once*.

**Example 1:**

```
Input: 1->1->2
Output: 1->2
```

**Example 2:**

```
Input: 1->1->2->3->3
Output: 1->2->3
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

