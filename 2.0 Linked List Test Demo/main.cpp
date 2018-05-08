
#include <iostream>
#import "LinkedList.h"


void reverseLinkedListTest(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/ sizeof(int);

    ListNode *head = LinkedList().createLinkedList(arr,n);
    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    ListNode *newHead = LinkedList().reverseLinkedList(head);
    printf("\nAfter reversing:\n");
    LinkedList().printLinkedList(newHead);
}

void interSectionOfTwoListsTest(){

    int arr1[] = {1,2,4,5};
    int n1 = sizeof(arr1)/ sizeof(int);

    int arr2[] = {2,4,5};
    int n2 = sizeof(arr2)/ sizeof(int);

    ListNode *head1 = LinkedList().createLinkedList(arr1,n1);
    ListNode *head2 = LinkedList().createLinkedList(arr2,n2);

    printf("\nLinked List 1:\n");
    LinkedList().printLinkedList(head1);

    printf("\nLinked List 2:\n");
    LinkedList().printLinkedList(head2);


    ListNode *interNode = LinkedList().findIntersectionNode(head1,head2);

    printf("\nIntersection:\n");
    printf("%d",interNode->val);
}


void mergeTwoListsTest(){

    int arr1[] = {1,2,4,15};
    int n1 = sizeof(arr1)/ sizeof(int);

    int arr2[] = {3,7,10};
    int n2 = sizeof(arr2)/ sizeof(int);

    ListNode *head1 = LinkedList().createLinkedList(arr1,n1);
    ListNode *head2 = LinkedList().createLinkedList(arr2,n2);

    printf("\nLinked List 1:\n");
    LinkedList().printLinkedList(head1);

    printf("\nLinked List 2:\n");
    LinkedList().printLinkedList(head2);

    ListNode *newHead = LinkedList().mergeTwoLists(head1,head2);

    printf("\nAfter Merging:\n");
    LinkedList().printLinkedList(newHead);

}

void findKthNodeToTailTest(){

    int arr[] = {1,2,4,5,1,2};
    int n = sizeof(arr)/ sizeof(int);
    int k = 0;

    ListNode *head = LinkedList().createLinkedList(arr,n);

    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    ListNode *targetNode =  LinkedList().findKthNodeToTail(head,k);
    printf("The %dth to tail node's value is:%d",k,targetNode->val);

}

void printLinkedListReverselyTest(){

    int arr[] = {1,2,4,5,8,11};
    int n = sizeof(arr)/ sizeof(int);

    ListNode *head = LinkedList().createLinkedList(arr,n);
    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    printf("\nReversely print linked list:\n");
    LinkedList().printLinkedListReversely(head);

}

void removeNthFromEndText(){

    int arr[] = {1,2,4,5,1,2};
    int n = sizeof(arr)/ sizeof(int);
    int k = 3;

    ListNode *head = LinkedList().createLinkedList(arr,n);

    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    ListNode *newHead = LinkedList().removeNthFromEnd(head,k);
    printf("\nAfter removing %dth node:\n",k);
    LinkedList().printLinkedList(newHead);

}

void deleteDuplicatesTest(){

    printf("\n========== Delete Duplicates Test ========== \n");

    int arr[] = {1,1,4,5,6,6};
    int n = sizeof(arr)/ sizeof(int);

    ListNode *head = LinkedList().createLinkedList(arr,n);
    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    ListNode *newNode = LinkedList().deleteDuplicates(head);
    printf("\nAfter deleting duplicates:\n");
    LinkedList().printLinkedList(newNode);
}


void deleteAllDuplicatesTest(){

    printf("\n========== Delete All Duplicates Test ========== \n");

    int arr[] = {1,1,1,4,5,6,6,7,8,8,8,9};
    int n = sizeof(arr)/ sizeof(int);

    ListNode *head = LinkedList().createLinkedList(arr,n);
    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    ListNode *newNode = LinkedList().deleteAllDuplicates(head);
    printf("\nAfter deleting all duplicates:\n");
    LinkedList().printLinkedList(newNode);

}


void removeElementsTest(){

    printf("\n========== Remove Elements Test ========== \n");

    int arr[] = {1,1,4,5,6,6};
    int n = sizeof(arr)/ sizeof(int);

    ListNode *head = LinkedList().createLinkedList(arr,n);
    printf("\nCreate new linked list:\n");
    LinkedList().printLinkedList(head);

    int val = 4;
    ListNode *newNode = LinkedList().removeElements(head,val);
    printf("\nAfter removing all elements equal to value %d:\n",val);
    LinkedList().printLinkedList(newNode);

}

int main() {

    //反转链表
//    reverseLinkedListTest();

    //两个链表的交叉点
//    interSectionOfTwoListsTest();

    //合并两个有序链表
//    mergeTwoListsTest();

    //找到倒数第k个节点
//    findKthNodeToTailTest();

    //逆序打印链表
//    printLinkedListReverselyTest();

    //删除倒数第n个节点
//    removeNthFromEndText();

    //删除值重复的节点
//    deleteDuplicatesTest();

    //删除所有重复的节点
//    deleteAllDuplicatesTest();


    //删除等于某个值的所有节点
//    removeElementsTest();

    return 0;


}