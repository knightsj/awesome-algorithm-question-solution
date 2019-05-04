# Maximum Depth of Binary Tree (二叉树的深度)



## From

[LeetCode 104](https://leetcode.com/problems/maximum-depth-of-binary-tree/)



## Question

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its depth = 3.



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
    int maxDepth(TreeNode* root) {
        
        if (root == NULL){
            return 0;
        }
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        
        return l > r ? l + 1:r + 1;
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
    
    public int maxDepth(TreeNode root) {
        
        if ( root == null){
            return 0;
        }
        
        int l = maxDepth(root.left);
        int r = maxDepth(root.right);
        
        return l > r ? l + 1 : r + 1;
    }
}
```
