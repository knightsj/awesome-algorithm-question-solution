# The Kth largest element in array (数组中第k大的元素)



## From

[LeetCode 215](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)



## Question

- Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

  **Example 1:**

  ```
  Input: [3,2,1,5,6,4] and k = 2
  Output: 5

  ```

  **Example 2:**

  ```
  Input: [3,2,3,1,2,4,5,5,6] and k = 4
  Output: 4
  ```




## Solution  

### C++

```c++
#include <queue>
#include <vector>

using namespace std;


//heap
int findKthLargest1(vector<int>& nums, int k) {

    make_heap(nums.begin(), nums.end());//heap sort

    for (int i=0; i<k-1; i++){
        pop_heap(nums.begin(), nums.end());//将front放在end前部，剩下的元素构成新的heap，堆排序
        nums.pop_back();//删除最后一个元素
    }
    return nums[0];
}
```



solution 2:

```c++
//sort
int findKthLargest2(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}
```





solution 3:

```c++
//priority_queue
int findKthLargest3(vector<int>& nums, int k) {

    priority_queue<int> q(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i) {
        q.pop();
    }
    return q.top();
}
```



solution 4:



```c++


//partition
int findKthLargest4(vector<int>& nums, int k) {

    k--;//eg. the second large number's index is 1
    int l = 0;
    int r = nums.size() - 1;
    int index= 0;

    while ( l < r){

        index = __partition(nums,l,r);

        if ( k < index ){
            r = index - 1;
        }else if ( k > index ){
            l = index + 1;
        }else {
            return nums[index];
        }
    }

    return nums[l];
}

int __partition(vector<int>& nums, int low, int high){

    int l = low;
    int r = high;
    int pivot = nums[low];

    while (l < r){

        //smaller than pivot is on the right
        while (l < r && nums[r] <= pivot){
            r--;
        }
        nums[l] = nums[r];

        //bigger than pivot is on the left
        while (l < r && nums[l] >= pivot){
            l++;
        }
        nums[r] = nums[l];

    }
    nums[l] = pivot;
    return l;
}
```

### Java


solution1：

```java
public class Solution {

    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}
```

solution 2:

```java
class Solution {
    
    public int findKthLargest(int[] nums, int k) {
        
        PriorityQueue<Integer> q = new PriorityQueue<Integer>(k+1);
        
          for(int n : nums){
              q.offer(n);
              if(q.size() > k) q.poll();
          }
        
          return q.poll();
    }

}
```

