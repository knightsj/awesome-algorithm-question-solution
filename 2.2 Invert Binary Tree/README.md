# Invert Binary Tree


## Question


Invert a binary tree.

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

to

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```


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
```

