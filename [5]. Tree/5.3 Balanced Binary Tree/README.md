# Balanced Binary Tree (是否是平衡二叉树)



## From



[LeetCode 110](https://leetcode.com/problems/balanced-binary-tree/description/)





## Question

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

**Example 1:**

Given the following tree `[3,9,20,null,null,15,7]`:

```
    3
   / \
  9  20
    /  \
   15   7
```

Return true.
**Example 2:**

Given the following tree `[1,2,2,3,3,null,null,4,4]`:

```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

```

Return false.



## Solution  



### C++

```c++
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
            
            if((l > r+1)||(r > l+1)){
                return false;
            }else{
                return isBalanced(root->left)&&isBalanced(root->right);
            }
        }
    }
};

```

