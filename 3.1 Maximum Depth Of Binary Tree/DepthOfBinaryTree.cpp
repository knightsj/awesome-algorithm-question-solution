//
//  DepthOfBinaryTree.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/4/11.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include "DepthOfBinaryTree.hpp"


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if (root == NULL){
            return 0;
        }
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return l > r ? l + 1:r + 1;
    }
};
