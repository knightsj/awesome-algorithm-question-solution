//
//  BalancedBinaryTree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/17.
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
    int height(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }else{
            int l=height(root->left);
            int r=height(root->right);
            return 1+((l>r)?l:r);
        }
    }
    
    bool isBalanced(TreeNode *root) {
        
        if(root==NULL){
            
            return true;
            
        }else{
            
            int l,r;
            l=height(root->left);
            r=height(root->right);
            
            if((l>r+1)||(r>l+1)){
                return false;
            }else{
                return isBalanced(root->left)&&isBalanced(root->right);
            }
        }
    }
};

