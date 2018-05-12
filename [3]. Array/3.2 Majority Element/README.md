# Majority Element



## Question

Given an array of size *n*, find the majority element. The majority element is the element that appears **more than** `⌊ n/2 ⌋` times.

You may assume that the array is non-empty and the majority element always exist in the array.



## Solution  



### C++

```c++
class Solution {
public:
    int majorityElement(std::vector<int> &num){
        
        int targetElem = 0;
        int count = 0;
        
        for(int i = 0; i < num.size(); i++){
            
            if(count == 0){
                
                targetElem = num[i];
                count = 1;
                
            }else{
                
                if(targetElem == num[i]){
                    count++;
                }else{
                    count--;
                }
            }
        }
        
        return targetElem;
    }
};
```

