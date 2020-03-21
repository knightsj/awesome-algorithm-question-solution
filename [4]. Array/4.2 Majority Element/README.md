# Majority Element (出现次数超过数组长度一半的元素)



## From

[LeetCode 169](https://leetcode.com/problems/majority-element/description/)





## Question

Given an array of size *n*, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.



## Solution  



### C++

```c++
class Solution {
public:
    int majorityElement(std::vector<int> &num){
        
        int targetElement = 0;
        int count = 0;
        
        for(int i = 0; i < num.size(); i++){
            
            if(count == 0){
                
                targetElement = num[i];
                count = 1;
                
            }else{
                
                if(targetElement == num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }
        
        return targetElement;
    }
};
```


### Java

```java
class Solution {
    
    public int majorityElement(int[] nums) {
        
        int targetElement = 0;
        int count = 0;
        
        for(int i = 0; i < nums.length; i++){
            
            if(count == 0){
                
                targetElement = nums[i];
                count = 1;
                
            }else{
                
                if(targetElement == nums[i]){
                    
                    count++;
                    
                }else{
                    
                    count--;
                    
                }
            }
        }
        
        return targetElement;
    
    }
}
```

### Python

```
def find_majority(arr):
    if not len(arr):
        return     
    count = len(arr)
    dict = {}
    res = None
    for i in arr:
        if i not in dict:
            dict[i] = 1
        else:  
            dict[i] += 1
            if dict[i] > math.floor(count/2):
                res = i
                break
    return res

def find_majority_2(arr):
    if not len(arr):
        return     
    count = 0
    res = None
    for i in arr:
        if count == 0:
            res = i
            count = 1
        else:  
            if i == res:
                count += 1
            else:
                count -= 1
    return res
```
