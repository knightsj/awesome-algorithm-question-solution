//
//  quickSort.cpp
//  interview-algorithm-question-solution
//
//  Created by Sun Shijie on 2018/5/2.
//  Copyright © 2018年 Shijie. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;


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


int main(){
    
    int arr[] = {3,5,1,2,6,4,10,6};
    
    printf("original array:\n");
    for(int i = 0; i<8 ;i++)
    {
        printf("%d ",arr[i]);
    }
    
    quickSort(arr, 8);
    printf("\nsorted array:\n");
    for(int i = 0; i<8 ;i++)
    {
        
        printf("%d ",arr[i]);
    }
    
    
    
    return 0;
}
