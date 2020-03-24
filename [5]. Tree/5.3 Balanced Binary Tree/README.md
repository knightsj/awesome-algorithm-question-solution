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

### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public boolean isBalanced(TreeNode root) {
        
        if ( root == null){
            
            return true;
        
        }else{
            
            int l;
            int r;
            
            l = height(root.left);
            r = height(root.right);
            
            if ( (l > r + 1) || ( r > l + 1)){
                return false;
            }else{
                return isBalanced(root.left)&&isBalanced(root.right);
            }
        }                
    }
    
    public int height(TreeNode root){
        
        if ( root == null){
            return 0;
            
        }else{
            
            int l = height(root.left);
            int r = height(root.right);
            return 1 + ( (l > r)? l : r );
        }
    }
}
```

### Python3
```
'''
class TreeNode:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None
'''
def is_balance_tree(tree):
    if not tree:
        return True
    def depth_tree(tree):
        if not tree:
            return 0
        l = depth_tree(tree.left)
        r = depth_tree(tree.right)
        if l > r:
            return l + 1
        else:
            return r + 1
    l_depth = depth_tree(tree.left)
    r_depth = depth_tree(tree.right)
    if abs(l_depth - r_depth) > 1:
        return False
    else:
        return is_balance_tree(tree.left) and is_balance_tree(tree.right)

```