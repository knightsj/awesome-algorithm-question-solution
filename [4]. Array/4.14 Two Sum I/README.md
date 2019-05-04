# Two Sum I (无序数组内部的两个元素的和为目标值)





## From

[LeetCode 1](https://leetcode.com/problems/two-sum/description/)



## Question



Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```



## Solution  

### C++

```c++
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> record;
    for(int i = 0 ; i < nums.size() ; i ++){

        int complement = target - nums[i];
        if(record.find(complement) != record.end()){
            int res[] = {i, record[complement]};
            return vector<int>(res, res + 2);
        }

        record[nums[i]] = i;
    }

}
```

### Java

```java
class Solution {
    
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] result = new int[2];
         
        for (int i = 0; i < nums.length; i++) {
            
            if (map.containsKey(target - nums[i])) {
                
                 result[0] = map.get(target - nums[i]);
                 result[1] = i; 
                 return result;
                
            }
            map.put(nums[i], i);
            
         }
        
         return result;
    }
}
```

