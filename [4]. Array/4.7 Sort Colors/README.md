# Sort Colors (三色旗问题)



## From

 [LeetCode 75](https://leetcode.com/problems/sort-colors/description/)



## Question

Given an array with *n* objects colored red, white or blue, sort them **in-place **so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

**Example:**

```
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Follow up:**

- A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
- Could you come up with a one-pass algorithm using only constant space?




## Solution  

### C++

```c++
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {

    int low=0; //0..low:0
    int mid=0; 
    int high = nums.size()-1; //high...end

    while(mid<=high){

        switch(nums[mid]){

            case 0:
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(nums[mid], nums[high]);
                high--;
                break;
        }
    }
}
```

### Java

```java
class Solution {
    
    public void sortColors(int[] nums) {
        
        int low=0; //0..low:0
        int mid=0; 
        int high = nums.length-1; //high...end

         while(mid<=high){

            switch(nums[mid]){

             case 0:
                
                    int tmp1;
                    tmp1 = nums[low];
                    nums[low] = nums[mid];
                    nums[mid]= tmp1;
                    
                    low++;
                    mid++;
                    break;

                case 1:
                    mid++;
                    break;
    
                case 2:
                    
                    int tmp;
                    tmp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high]= tmp;
                    
                    
                    high--;
                    break;
             }
         }  
    }
}
```

### Python

```
def sort_colors(arr):
    if not len(arr):
        return
    low, mid = 0, 0
    high = len(arr) - 1
    while mid < high:
        if arr[mid] == 0:
            temp = arr[mid]
            arr[mid] = arr[low]
            arr[low] = temp
            mid += 1
            low += 1
        elif arr[mid] == 1:
            mid += 1
        elif arr[mid] == 2:
            temp = arr[high]
            arr[high] = arr[mid]
            arr[mid] = temp
            high -= 1
```