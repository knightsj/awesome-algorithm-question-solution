//
//  RecursivelyPrintLinkedList.cpp
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


void PrintListReversingly(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if (pHead->next != nullptr)
        {
            PrintListReversingly(pHead->next);
        }
        
        printf("%d\t", pHead->val);
    }
}
