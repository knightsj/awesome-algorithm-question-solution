# Missing Number (寻找数组中缺失的数字)



## From

[LeetCode 268](https://leetcode.com/problems/missing-number/description/)



## Question

Given an array containing *n* distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.

**Example 1**

```
Input: [3,0,1]
Output: 2

```

**Example 2**

```
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
```



## Solution  

### C++



solution 1:

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        long long sum = static_cast<long long>(len) * (len + 1) / 2;
        for(auto val: nums) {
            sum -= val;
        }
        return static_cast<int>(sum);
    }
};
```



solution 2:

```c++
class Solution {
public:
	    int missingNumber(vector<int>& nums) {
	        int n = nums.size();
	        int ret = (n + 1)*n/2;
	        for (int i = 0; i < n; i++){
	            ret -= nums[i];
	        }
	        return ret;
	    }
    
};
```



solution 3:

```c++

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int result = 0;
        
        for(auto num:nums){
            result ^= num;
        }
        
        int n = nums.size();
        
        for(int i = 0; i < nums.size() + 1; i++){
            result ^= i;
        }
        
        return result;
    }
};


```

