# IntersectionOfTwoLists


## Solution in C++ 

```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//length of linked list
int calculateListLength(ListNode *head){
    
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    int lengthA = calculateListLength(headA);
    int lengthB = calculateListLength(headB);
    
    int n = lengthA - lengthB;
    
    ListNode *pA = headA, *pB = headB;
    
    //move node pointer
    for(int i=0; i < abs(n); i++){
        
        //a is longer
        if( n > 0){
            
            pA = pA->next;
            
        }else{
            //b is longer
            pB = pB->next;
            
        }
    }
    
    while (pA && pB) {
        
        //found intersection node
        if (pA == pB) {
            return pB;
        }
        
        pA = pA->next;
        pB = pB->next;
        
    }
    
    return NULL;
    
}
```

