# Two Sum II (有序数组内部的两个元素的和为目标值)





## From

[LeetCode 167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)



## Question

Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

- Your returned answers (both index1 and index2) are not zero-based.
- You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

**Example:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```



## Solution  

### C++

```c++
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> twoSumII(vector<int>& numbers, int target) {

//    assert(numbers.size()>=2);

    int l = 0;
    int r = numbers.size() - 1;

    while ( l < r){

        if (numbers[l] + numbers[r] == target){
            int res[] = {l+1,r+1};
            return vector<int>(res,res+2);

        }else if (numbers[l] + numbers[r] < target){
            l++;
        } else{
            r--;
        }
    }
    throw invalid_argument("The input has no solution");

}
```

### Java

```java
class Solution {

    public int[] twoSum(int[] numbers, int target) {
        
        int[] result = new int[2];
        
        int n = numbers.length;
        
        if (n < 2) {
            return result;
        }
        
        
        int small  = numbers[0];
        int big    = numbers[n-1];
        
        for (int i = 0, j = n-1; i < n && j > 0 && j > i; ) {
 
            if (small + big == target) {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }
            
            if (small + big > target) {
                j--;
            }
            
            if (small + big < target) {
                i++;
            }
            
            small = numbers[i];
            big = numbers[j];
        }
        
        return result;
    }
}
```

### Python

```
def target_index(arr, target):
    if len(arr) < 2:
        return None
    count = len(arr)
    l,h = 0,count-1
    res = []
    while l<h:
        sum = arr[l]+arr[h]
        if (sum==target):
            res.append(l+1)
            res.append(h+1)
            break
        elif sum < target:
            l += 1
        else:
            h -= 1
    return res 
```