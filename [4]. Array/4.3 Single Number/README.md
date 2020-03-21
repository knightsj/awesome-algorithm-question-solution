# Single Number (数组中只出现过一次的数字)





## From

[[LeetCode 136](https://leetcode.com/problems/single-number/description/)](https://leetcode.com/problems/majority-element/description/)







## Question

Given a **non-empty** array of integers, every element appears *twice* except for one. Find that single one.

**Note:**

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**Example 1:**

```
Input: [2,2,1]
Output: 1

```

**Example 2:**

```
Input: [4,1,2,1,2]
Output: 4
```



## Solution  



### C++

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int length = nums.size();
        int result = 0 ;
        
        for (int i=0; i<length; i++)  {
            result ^= nums[i];
        }
        return result;
    }
};

```

### Java

```java
class Solution {
    public int singleNumber(int[] nums) {
        
        int length = nums.length;
        int result = 0 ;
        
        for (int i = 0; i < length; i++)  {
            
            result ^= nums[i];
        }
        return result;
    }
}
```


### Python

```
def find_once(arr):
    if not len(arr):
        return     
    res = 0
    for i in arr:        
        res ^= i # 异或，按位取异或               
    return res
```