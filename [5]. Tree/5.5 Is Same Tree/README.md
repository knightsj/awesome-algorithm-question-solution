# Is Same Tree (树是否相等)


## From

[LeetCode 100](https://leetcode.com/problems/same-tree/)


## Question

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

**Example 1:**

```
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

```

**Example 2:**

```
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

```

**Example 3:**

```
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

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
    bool isSameTree(TreeNode* p,TreeNode* q){
        
        if(p == NULL && q != NULL){
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
        else{
            return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
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
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        
        if ( p == null && q != null){
            
            return false;
            
        }else if ( p != null && q == null){
            return false;
            
        }else if ( p == null && q == null){
            return true;
            
        }else if (( p != null && q != null) && (p.val != q.val) ){
            
           return false;
            
        }else{
            
             return (isSameTree(p.left, q.left) && isSameTree(p.right,q. right));
        }
    }
}
```
