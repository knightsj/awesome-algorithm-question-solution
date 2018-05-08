

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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