# Quick Sort Implementation



## Question

Quick sort implementation




## Solution  



### C++

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





