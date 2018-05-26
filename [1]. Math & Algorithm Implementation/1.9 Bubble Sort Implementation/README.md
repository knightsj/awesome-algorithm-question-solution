# Bubble Sort Implementation



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

