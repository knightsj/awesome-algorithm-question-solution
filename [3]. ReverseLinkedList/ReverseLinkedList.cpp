//
//  ReverseLinkedList.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/10.
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
    ListNode* reverseList(ListNode* head) {
        
        if (!head || !head->next) return head;
        
        ListNode *p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};

