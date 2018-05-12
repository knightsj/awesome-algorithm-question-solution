
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* partition(ListNode* head, int x) {

    if (head == NULL || head->next == NULL){
        return head;
    }

    ListNode *left = new ListNode(-1);
    ListNode *p = left;

    ListNode *right = new ListNode(-1);
    ListNode *q = right;

    while(head!= NULL){

        if(head->val < x){
            p->next = head;
            p = p->next;
        }else{
            q->next = head;
            q = q->next;
        }

        head = head->next;
    }

    q->next = NULL; //right end
    p->next = right->next;//left end
    return left->next;

}
