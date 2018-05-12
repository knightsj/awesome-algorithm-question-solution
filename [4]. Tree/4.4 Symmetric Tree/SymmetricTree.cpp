//
//  Symmetric Tree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/26.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if (root == NULL){
            return true;
        }
        
        return checkLeftAndRightNodes(root->left,root->right);
    }
    
    bool checkLeftAndRightNodes(TreeNode *leftNode, TreeNode *rightNode){
        
        if (leftNode == NULL && rightNode == NULL){
            return true;
        }
        
        if (leftNode == NULL || rightNode == NULL){
            return false;
        }
        
        if (leftNode->val !=  rightNode -> val){
            return false;
        }else {
            return checkLeftAndRightNodes(leftNode -> left, rightNode->right)
            &&  checkLeftAndRightNodes(leftNode -> right, rightNode->left);
        }
    }
};
