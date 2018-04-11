//
//  MergeTwoLinkedList.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/11.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL){
            
            return l2;
            
        }else if(l2 == NULL){
            
            return l1;
            
        }
        
        ListNode *mergedHead = NULL;
        
        if(l1->val < l2->val){
            
            mergedHead = l1;
            mergedHead->next = mergeTwoLists(mergedHead->next,l2);
            
        }else{
            
            mergedHead = l2;
            mergedHead->next = mergeTwoLists(l1, mergedHead->next);
        }
        
        return mergedHead;
    }
};
