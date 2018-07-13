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

