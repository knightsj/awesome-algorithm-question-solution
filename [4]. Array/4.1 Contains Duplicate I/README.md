# Contains Duplicate I (检测数组中是否包含重复的元素)



## From

[LeetCode 217](https://leetcode.com/problems/contains-duplicate/description/)



## Question

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.



## Solution  



### C++

Using sorting:

```c++
class Solution {  
public:  
    bool containsDuplicate(std::vector<int>& nums) {  
        
        std::sort(nums.begin(), nums.end());
        
        for (i = 1; i < nums.size(); ++i){
            if (nums[i] == nums[i-1]){
                return ture;
            }
        }
        return false;
    }  
}; 
```



Using set:

```cpp
class Solution {  
public:  
    bool containsDuplicate(vector<int>& nums) {  

        if(nums.size() == 0) return false;  
        if(nums.size() == 1) return false;  
          
        set<int> uniqueNums;  
        for(int i = 0; i < nums.size(); i ++){  
            if(uniqueNums.find(nums[i]) != uniqueNums.end())  
                return true;  
            else{  
                uniqueNums.insert(nums[i]);  
            }  
        }  
        return false;  
    }  
}; 
```



Using map:

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> storedElements;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (storedElements.find(nums[i]) != storedElements.end()) {
                return true;
            }
            ++storedElements[nums[i]];
        }
        return false;
    }
};
```

### Java

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        if (nums == null || nums.length <= 1) {
             return false;
         }
        
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        
        for (int i=0; i < nums.length; i++) {
            if (map.put(nums[i], i) != null) {
                return true;
            }  
        }
        
        return false;  
    }
}
```

### Python

```

```