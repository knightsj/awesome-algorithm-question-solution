# Is Power Of Two （是否是2的幂）



## From 

 [LeetCode 231](https://leetcode.com/problems/power-of-two/description/)



## Question

Given an integer, write a function to determine if it is a power of two.




## Solution  



### C++

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if ( n == 1){
            return true;
        }
        
        if ( n >= 2 && n%2 == 0){
            return isPowerOfTwo(n/2);
        }
        
        return false;
    }
};
```

### Java

```java
// time O(1) space O(1)
// 解释：2的N次方用二进制可表示为：10，100，1000...，首先他们是大于等于1的，
// 其次，n-1为01，011，0111，因此，n & (n - 1) == 0.
boolean isPowerOfTwo(int n) {
    return (n >= 1) && (n & (n - 1)) == 0;
}
```

