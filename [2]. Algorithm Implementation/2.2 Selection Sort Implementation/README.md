# Selection Sort Implementation (选择排序算法实现)



## From 

Selection sort



## Question

Selection sort implementation



## Solution  



### C++

```c++
void selectionSort(int arr[], int n){

    for ( int i = 0; i < n; i++){

        int min = i;

        for ( int j = i + 1; j < n; j++){

            if (arr[min] > arr[j]){
                min = j;
            }
        }

        if (min != i){
            __swap(arr[i], arr[min]);
        }

    }

}
```

### Java

```java
public static void SelectionSort(int[] arr) {

    int n = arr.length;

    for ( int i = 0; i < n; i++){

        int min = i;

        for ( int j = i + 1; j < n; j++){

            if (arr[min] > arr[j]){
                min = j;
            }
        }

        if (min != i){

            int tmp;
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }

    }
}
```

### Python

```
def select_sort(nums):
    if len(nums) == 0: 
        return
    count = len(nums)
    for i in range(0, count):
        for j in range(i+1, count):
            if nums[i] > nums[j]:
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
```
