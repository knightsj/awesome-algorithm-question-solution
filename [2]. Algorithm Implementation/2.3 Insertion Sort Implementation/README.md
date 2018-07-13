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

