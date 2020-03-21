# Minimum Size Subarray Sum (无序数组和大于或等于某值的最小子数组)



## From

[LeetCode 209](https://leetcode.com/problems/minimum-size-subarray-sum/description/)



## Question

Given an array of **n** positive integers and a positive integer **s**, find the minimal length of a **contiguous** subarray of which the sum ≥ **s**. If there isn't one, return 0 instead.

**Example: **

```
Input: [2,3,1,2,4,3], s = 7
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
```



## Solution  

### C++

```c++
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {

    //using moving window

    int l = 0;  //left end
    int r = -1; //right end
    int sum = 0;
    int res = nums.size() + 1;

    while (l < nums.size()){
        if ( r+1 < nums.size() && sum < s){
            r++;
            sum += nums[r];
        }else{
            sum -= nums[l];
            l++;
        }

        if(sum>=s){
            res = min(res,r-l+1);
        }
    }

    if (res == nums.size() + 1){
        return 0;
    }

    return res;

}
```


### Java

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        
         int l = 0;  //left end
         int r = -1; //right end
         int sum = 0;
         int n = nums.length;
         int res = n + 1;

    while (l < n){
        
        if ( r+1 < n && sum < s){
            
            r++;
            sum += nums[r];
            
        }else{
            sum -= nums[l];
            l++;
        }

        if(sum >= s){
            
            res = Math.min(res, r-l+1);
        }
    }

    if (res == n + 1){
        
        return 0;
    }

    return res;

    }
}

```


### Python

```
def min_length_target(arr, target):
    if not len(arr):
        return 0
    dic = {}
    sum = 0
    count = 0
    for i in arr:
        sum += i
        count+=1
        if sum == target:
            if target in dic:
                if dic[target] > count:
                    dic[target] = count
            else:
                dic[target] = count
            sum = 0
            count = 0
        elif sum > target:
            sum = 0
            count = 0
    if target in dic:
        return dic[target]            
    return 0

def min_lenght_2(arr, target):
    if not len(arr):
        return 0
    l, r = 0, -1
    sum = 0
    count = len(arr)
    res = count+1
    while l < count:
        if sum < target:
            r += 1
            sum += arr[r]
        else:
            sum -= arr[l]
            l += 1
        if sum == target:
            res = min(res, r-l+1)
    if res == count + 1:
        return 0
    return res
```
