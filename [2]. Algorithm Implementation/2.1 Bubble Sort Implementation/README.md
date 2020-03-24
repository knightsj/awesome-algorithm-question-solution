# Bubble Sort Implementation (冒泡排序算法实现)



## From

Bubble sort



## Question

Bubble sort implementation



## Solution  



### C++

```c++
void bubbleSort(int arr[], int n){

    for ( int i =0; i < n - 1; i++){
      
        for (int j = 0; j < n - 1 - i; j++){
          
            if (arr[j] > arr[j + 1]){
                __swap(arr[j], arr[j + 1]);
            }
        }
    }

}
```

### Java

```java
public static void BubbleSort(int[] arr) {

    int n = arr.length;

    for( int i = 0; i < n-1; i++ ){

        for( int j = 0; j < n - i - 1; j++ ){

            if( arr[j+1] < arr[j] ){

                int tmp;

                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}
```

### Python

```
def bubble_sort(nums):
    if len(nums) == 0:
        return
    count = len(nums)
    for i in range(0, count):
        for j in range(count-1, i, -1):
            last = nums[count-j]
            last_two = nums[count-j-1]
            if last < last_two:
                temp = nums[count-j]
                nums[count-j] = last_two
                nums[count-j-1] = temp
```
