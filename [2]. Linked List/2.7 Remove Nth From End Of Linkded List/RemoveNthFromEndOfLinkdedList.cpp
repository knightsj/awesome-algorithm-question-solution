//
//  RemoveNthFromEndOfLinkdedList.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

//  Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if( head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode * first = head;
        ListNode * second = head;
        
        for(int i = 0;i < n;i++){
            first = first->next;
        }
        
        //1,2,3,4,5 n = 4
        if(first == NULL){
            return head->next;
        }
        
        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return head;
    }
    
};
