//
//  Delete Node in a Linked List.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



//1 2 3 4 5 -> //1 2 4 5
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if (!node || !node->next)  {
            return;
        }
                
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
