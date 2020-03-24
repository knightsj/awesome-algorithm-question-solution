# Binary Search （二分查找）



## From

One of common searching algorithm problems



## Question

Binary search implementation.



## Solution  



### C++

```c++
int binary_search(int* a, int len, int goal) {
    
    int low = 0;
    int high = len - 1;
    
    while (low <= high) {
        
        int middle = (high - low) / 2 + low;
        
        if (a[middle] == goal) {
          
            return middle;
            
        }else if (a[middle] > goal) {
            
            high = middle - 1;
            
        }else {
            
            low = middle + 1;
        }
    }
    return -1;
}
```


### Java

```java
public static int binary_search( int[] array, int target){

        if (array.length == 0){
            return -1;
        }
    
        int low = 0;
        int high = array.length - 1;
    
        while ( low <= high ) {
    
            int middle = (high - low) / 2 + low;
    
            if (array[middle] == target) {
    
                return middle;
    
            }else if ( array[middle] > target){
    
                high = middle - 1;
    
            }else {
    
                low = middle + 1;
            }
        }
    
        return -1;
    }

}
```

### Python

```
def binary_search(nums, low, high, key):
    if not nums or low > high:
        return -1
    if key < nums[low] or key > nums[high]:
        return -1        
    mid = (low + high)//2
    if nums[mid] == key:
        return mid
    elif nums[mid] > key:
        return binary_search(nums, low, mid-1, key)
    elif nums[mid] < key:
        return binary_search(nums, mid+1, high, key)
```