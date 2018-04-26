# Missing Number



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

```c++
class Solution1 {  
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


class Solution2 {
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

