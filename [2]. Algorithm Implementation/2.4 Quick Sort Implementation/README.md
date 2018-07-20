# Quick Sort Implementation (快速排序算法实现)



## From

Quick sort



## Question

Quick sort implementation




## Solution  



### C++

fixed pivot in partition: 

```c++
int __partition(int arr[], int l , int r){
    
    //pivot is the first element in array
    int pivot = arr[l];
    
    int j = l;
    for (int i = l + 1; i <= r;  i++) {
        if (arr[i] < pivot) {
            swap(arr[j+1], arr[i]);
            j++;
        }
        
    }
    swap(arr[l], arr[j]);
    
    return j;
}


void __quickSort( int arr[], int l, int r){
    
    if ( l >= r){
        return;
    }
    
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}



void quickSort(int arr[], int n){
    __quickSort(arr, 0, n-1);
}
```



random pivot in partition: (conquer basicly sorted array)

```c++
int __partition(int arr[], int l , int r){
    
    //pivot is the random element in array
    swap(arr[l], arr[rand()%(r-l+1)+l]);     
    int pivot = arr[l];
    
    int j = l;
    for (int i = l + 1; i <= r;  i++) {
        if (arr[i] < pivot) {
            swap(arr[j+1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    
    return j;
}

```



2-way partitiion:

```c++
int __partition2Way(int arr[], int l , int r){
    
    //pivot is the random element in array
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    int pivot = arr[l];
    
    int i = l + 1, j = r;
    
    //l+1,i    j,r
    while (true) {
        
        while (i <= r && arr[i] < pivot) {
            i++;
        }
        
        while (j >= l + 1 && arr[j] > pivot) {
            j--;
        }
        
        if (i > j) {
            break;
        }
       
        swap(arr[i], arr[j]);
        
        i++;
        j--;
    }
    
    swap(arr[l], arr[j]);
      
    return j;
}
```

### Java

```java
int parttion(int[] nums) {
    if (nums == null || nums.length == 0) return -1;
    int len = nums.length;
    // 避免有序情况下，时间复杂度最坏 O(N^2)
    int idx = (int)(100 * Math.random() % nums.length);
    swap(nums, len - 1, idx);
    int pivot = nums[len - 1];
	
    idx = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (nums[i] < pivot) {
            swap(nums, i, idx ++);
        }
    }
    swap(nums, idx, len - 1);
    return idx;
}

void swap(int[] nums, int i, int j) {
    if (nums[i] == nums[j]) return;
    // 位操作比加减速度更快，减少临时变量的开销
    nums[i] ^= nums[j];
    nums[j] ^= nums[i];
    nums[i] ^= nums[j];
}
```



