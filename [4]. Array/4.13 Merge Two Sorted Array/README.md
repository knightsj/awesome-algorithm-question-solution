# Merge Two Sorted Array (合并两个有序的数组)



## From



[LeetCode 88](https://leetcode.com/problems/merge-sorted-array/description/)



## Question

Given two sorted integer arrays *nums1* and *nums2*, merge *nums2* into *nums1* as one sorted array.

**Note:**

- The number of elements initialized in *nums1* and *nums2* are *m* and *n* respectively.
- You may assume that *nums1* has enough space (size that is greater or equal to *m* + *n*) to hold additional elements from *nums2*.

**Example:**

```
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```



## Solution  

### C++

```c++
#include <vector>

using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int i = m + n - 1;

    //compare the element in the end of two vectors, put the bigger one into nums1
    while (m > 0 && n > 0) {

        if (nums1[m - 1] > nums2[n - 1]) {

            nums1[i] = nums1[m - 1];
            m--;

        } else {

            nums1[i] = nums2[n - 1];
            n--;
        }

        i--;
    }

    //if nums2 left, then put into nums1
    while (n > 0) {
        nums1[i] = nums2[n - 1];
        n--;
        i--;
    }
}
```

### Java

```java
class Solution {
    
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int i = m + n - 1;

    
        while (m > 0 && n > 0) {

            if (nums1[m - 1] > nums2[n - 1]) {

                nums1[i] = nums1[m - 1];
                m--;

            } else {

                nums1[i] = nums2[n - 1];
                n--;
            }

            i--;
        }

    
        while (n > 0) {
            nums1[i] = nums2[n - 1];
            n--;
            i--;
        }
        
    }
}
```


### Python

```
def merge_two_2(arr1, m, arr2, n):
    i = m + n - 1
    while m > 0 and n > 0:
        if arr1[m-1] > arr2[n-1]:
            arr1[i] = arr1[m-1]
            m -= 1
        else:
            arr1[i] = arr2[n-1]
            n -= 1
        i -= 1
    while n > 0:
        arr1[i] = arr2[n-1]
        i -= 1
        n -= 1
```