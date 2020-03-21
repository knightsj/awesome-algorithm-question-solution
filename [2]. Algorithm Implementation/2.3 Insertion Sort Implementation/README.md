# Insertion Sort Implementation (插入排序算法实现)



## From

Insertion sort



## Question

Insertion sort implementation



## Solution  



### C++

```c++
void insertionSort(int arr[], int n){

    for ( int i = 1; i < n; i ++){

        for (int j = i; j > 0; j --){

            if (arr[j] < arr[j - 1]){

                __swap(arr[j], arr[j-1]);

            }else{

                break;

            }
        }
    }
}
```


### Java

```java
public static void InsertionSort(int[] arr) {

    int n = arr.length;

    for ( int i = 1; i < n; i ++){

        for (int j = i; j > 0; j --){

            if (arr[j] < arr[j - 1]){

                int tmp;
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;

            }else{

                break;

            }
        }
    }
}
```

### Python

```
def insert_sort_2(nums):
    count = len(nums)
    if count == 0:
        return
    for i in range(1,count):
        for j in range(i,0, -1):
            if nums[j] < nums[j-1]:
                temp = nums[j-1]
                nums[j-1] = nums[j]
                nums[j] = temp
```