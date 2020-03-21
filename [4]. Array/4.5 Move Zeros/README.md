# Move Zeros (将所有的0移动到数组末尾)



## From

[LeetCode 283](https://leetcode.com/problems/move-zeroes/description/)



## Question

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

For example, given `nums = [0, 1, 0, 3, 12]`, after calling your function, `nums` should be `[1, 3, 12, 0, 0]`.

**Note**:

1. You must do this **in-place** without making a copy of the array.
2. Minimize the total number of operations.



## Solution  

### C++

```c++
void moveZeroes(vector<int>& nums) {

    int k = 0;
    
    for ( int i = 0; i < nums.size(); i++){

        if(nums[i] != 0){

            if ( i != k){
                
                swap(nums[k++],nums[i]);
                
            } else{
                k++;
            }
        };

    }
}
```

### Java

```java
class Solution {
    
    public void moveZeroes(int[] nums) {
        
        int index = 0;
        
        for(int i = 0; i < nums.length; i++ ){
            
            if( nums[i] != 0 ){
                nums[index++] =  nums[i];
            }
        }
        
        for( int i = index; i < nums.length; i++ ){
            nums[i]=0;
        }
    }
}
```
### Python

```
def find_missing(arr):
    if not len(arr):
        return
    n = len(arr)
    sum = n * (n+1)/2
    for num in arr:
        sum -= num
    return sum
```
