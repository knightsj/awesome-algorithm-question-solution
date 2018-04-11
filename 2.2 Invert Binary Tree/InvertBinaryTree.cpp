//
//  InvertBinaryTree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/11.
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
    TreeNode* invertTree(TreeNode* root) {
        
        if ( root == NULL){
            return NULL;
        }
        
        //change left node and right node
        TreeNode *tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
