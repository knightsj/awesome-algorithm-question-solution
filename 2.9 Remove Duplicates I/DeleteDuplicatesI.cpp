
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