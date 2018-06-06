
#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList{

    public:

    //生成链表
    ListNode* createLinkedList(int arr[], int n){

        if ( n == 0){
            return NULL;
        }

        ListNode *head = new ListNode(arr[0]);
        ListNode *curNode = head;

        for (int i = 1; i < n; ++i) {
            curNode->next = new ListNode(arr[i]);
            curNode = curNode->next;
        }
        return head;
    }

    //反转链表
    ListNode* reverseLinkedList(ListNode *head){

        ListNode *pre = NULL;
        ListNode *cur = head;

        while ( cur != NULL){

            ListNode *next = cur->next;
            //change pointer direction
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        //pre will be the first node after reversing
        return pre;
    }

    //移除值为val的所有节点
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

    //合并两个有序的链表
    ListNode *mergeTwoLists(ListNode *headA, ListNode *headB){

        if (headA == NULL){
            return headB;
        } else if (headB == NULL){
            return headA;
        }

        ListNode *mergedHead = NULL;

        if (headA->val < headB->val){

            mergedHead = headA;
            mergedHead->next = mergeTwoLists(mergedHead->next,headB);

        } else {

            mergedHead = headB;
            mergedHead->next = mergeTwoLists(headA,mergedHead->next);

        }
        return mergedHead;
    }

    //找到两个链表的交点
    ListNode *findIntersectionNode(ListNode *headA, ListNode*headB){

        int lengthA = calculateLength(headA);
        int lengthB = calculateLength(headB);

        ListNode *pA = headA;
        ListNode *pB = headB;

        int n = lengthA - lengthB;

        for (int i = 0; i < abs(n); ++i) {

            if(n > 0){

                pA = pA->next;

            } else{

                pB = pB->next;
            }
        }

        while (pA && pB){

            //found first same value node
//            if (pA->val == pB->val){
//                return pB;
//            }

            //found first same address node(intersection node)
            if (pA->val == pB->val){
                return pB;
            }

            //move node
            pA = pA->next;
            pB = pB->next;
        }

        return NULL;
    }

    //找到倒数第n个节点
    ListNode *findKthNodeToTail(ListNode *head, unsigned k){

        if (head == NULL || k == 0){
            return NULL;
        }

        ListNode *aheadNode = head;
        ListNode *behindNode = NULL;

        for (int i = 0; i < k - 1; ++i) {

            if (aheadNode->next != NULL){
                aheadNode = aheadNode->next;
            } else{
                std::cout << "k is out of range" << std::endl;
                return NULL;
            }
        }

        behindNode = head;

        while (aheadNode->next != NULL){

            aheadNode = aheadNode->next;
            behindNode = behindNode->next;
        }
        return behindNode;
    }

    //移除倒数第n个节点
    ListNode *removeNthFromEnd(ListNode *head, int n){

        if (head == NULL || head->next == NULL){

            return NULL;
        }

        ListNode *aheadNode = head;
        ListNode *behindNode = head;

        for (int i = 0; i < n; ++i) {
            aheadNode = aheadNode->next;
        }

        if (aheadNode == NULL){
            return head->next;
        }

        while (aheadNode->next != NULL){
            aheadNode = aheadNode->next;
            behindNode = behindNode->next;
        }

        behindNode->next = behindNode->next->next;

        return head;
    }

    //移除重复的节点（保留单个节点）
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

    //移除所有重复的节点
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

    //链表是否有环
    bool hasCircle(ListNode *head){

        ListNode *slowerNode = head;
        ListNode *fasterNode = head;

        while (slowerNode->next != NULL && fasterNode->next != NULL &&
               fasterNode->next->next != NULL){

            //move in the first place
            slowerNode = slowerNode->next;
            fasterNode = fasterNode->next->next;

            //then, compare
            if (slowerNode == fasterNode){
                return true;
            }
        }

        return false;
    }

    //删除某个节点
    void deleteNode(ListNode *node){

        if(node == NULL || node->next == NULL){
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
    }

    //删除链表
    void deleteLinkedList(ListNode *head){

        ListNode *curNode = head;
        while (curNode != NULL){
            ListNode *delNode = curNode;
            curNode = curNode->next;
            delete delNode;
        }
        return;
    }

    //计算链表长度
    int calculateLength(ListNode *head){

        if (head == NULL){
            return 0;
        }

        int count = 0;
        while (head ->next){
            count++;
            head = head->next;
        }

        return count;
    }

    //打印链表
    void printLinkedList(ListNode *head) {

        ListNode *curNode = head;
        while (curNode != NULL) {
            std::cout << curNode->val << "->";
            //move to the next node
            curNode = curNode->next;
        }
        std::cout << "NULL" << std::endl;
    }

    //倒叙打印链表
    void printLinkedListReversely(ListNode *head){

        if (head != NULL){
            if (head->next != NULL){
                printLinkedListReversely(head->next);
            }
            std::cout << head->val << std::endl;
        }
    }



};


