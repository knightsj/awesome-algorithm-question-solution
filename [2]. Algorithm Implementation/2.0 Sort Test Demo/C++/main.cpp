#include <iostream>

#include "ArrayUtil.h"
#include "Sorting.cpp"
int main() {


    int N = 10;
    int arr[] = {3,1,3,5,6,7,91,2,3,4};

    printf("\n after quick sort:");
    Sorting().quickSort(arr,N);
    ArrayUtil::printArray(arr,N);

    printf("\n after bubble sort:");
    Sorting().bubbleSort(arr,N);
    ArrayUtil::printArray(arr,N);

    printf("\n after selection sort:");
    Sorting().selectionSort(arr,N);
    ArrayUtil::printArray(arr,N);

    printf("\n after insertion sort:");
    Sorting().insertionSort(arr,N);
    ArrayUtil::printArray(arr,N);


    return 0;
}