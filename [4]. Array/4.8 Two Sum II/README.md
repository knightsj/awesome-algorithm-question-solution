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
int[] twoSumII(int[] nums, int target) {
    if (nums == null || nums.length < 2) return null;

    // If nums is not sorted, you can sort it, time complexity is O(N * lgN)
    Arrays.sort(nums);
	// If nums is sorted, time complexity is O(lg N)
    for (int i = 0; i < nums.length; ++i) {
        int idx = Arrays.binarySearch(nums, target - nums[i]);
        if (idx >= 0 && idx != i) return new int[]{i, idx};
    }
    return null;
}
```



```java
/* If nums is not sorted, you can use map, time complexity will be
* O(N), but space complexity will be O(N), use O(N) space exchange 
* O(lgN) time
* If nums is sorted, use binary search!!!
*/
int[] twoSumII(int[] nums, int target) {
    if (nums == null || nums.length < 2) return null;
	
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; ++i) {
        map.put(nums[i], i);
        if (map.keySet().contains(target - nums[i])) {
            return new int[]{i, map.get(nums[i])};
        }
    }
    return null;
}
```



