

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* oddEvenList1(ListNode* head) {

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


ListNode* oddEvenList2(ListNode *head) {

    if (head == NULL || head->next == NULL){
        return head;
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
