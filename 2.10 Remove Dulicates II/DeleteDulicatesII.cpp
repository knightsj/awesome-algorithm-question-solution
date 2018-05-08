
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteAllDuplicates(ListNode* head) {

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