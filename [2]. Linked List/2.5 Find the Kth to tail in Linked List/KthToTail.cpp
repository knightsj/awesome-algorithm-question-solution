//
//  KthToTail.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/14.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0)
        return nullptr;
    
    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;
    
    for(unsigned int i = 0; i < k - 1; ++ i)
    {
        if(pAhead->next != nullptr)
            pAhead = pAhead->next;
        else
        {
            return nullptr;
        }
    }
    
    pBehind = pListHead;
    
    while(pAhead->next != nullptr)
    {
        pAhead = pAhead->next;
        pBehind = pBehind->next;
    }
    
    return pBehind;
}

