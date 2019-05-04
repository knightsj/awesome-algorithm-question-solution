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
public static void QuickSort(int[] array,int low ,int high){

    if(low>=high){

        return ;
    }

    int index=partition(array,low,high);

    QuickSort(array,low,index-1);
    QuickSort(array,index+1,high);
}

public static int partition(int []array,int low,int high){

    int mid = low + (high - low)/2;

    if( array[mid] > array[high] ){

        swap(array[mid],array[high]);
    }

    if( array[low] > array[high] ){
        swap(array[low],array[high]);
    }

    if( array[mid] > array[low] ){
        swap(array[mid],array[low]);
    }

    int key = array[low];

    while(low < high){

        while( array[high] >= key && high > low ){
            high--;
        }

        array[low] = array[high];

        while( array[low] <= key && high > low ){
            low++;
        }

        array[high] = array[low];
    }

    array[high] = key;

    return high;
}

public static void swap(int a,int b){

    int temp=a;
    a = b;
    b = temp;
}
```

