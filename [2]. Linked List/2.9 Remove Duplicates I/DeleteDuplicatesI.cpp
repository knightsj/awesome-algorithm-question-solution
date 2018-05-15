
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head){

    ListNode *curNode = head;
    
    while (curNode->next != NULL){
        if (curNode->val == curNode->next->val){

            ListNode *delNode = curNode->next;
            curNode->next = delNode->next;
            delete delNode;


        } else{
            curNode = curNode->next;
        }
    }

    return head;
}