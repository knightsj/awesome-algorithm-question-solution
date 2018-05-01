//
//  IsSameTree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/1.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p,TreeNode* q){
        
        if(p ==NULL && q != NULL){
            return false;
        }
        else if(p !=NULL && q ==NULL){
            return false;
        }
        else if(p == NULL && q == NULL){
            return true;
        }
        else if((p != NULL && q != NULL)&& (p->val !=q->val)){
            return false;
        }
        else
        {
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
    }
};
