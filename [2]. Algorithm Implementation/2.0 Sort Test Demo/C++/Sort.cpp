
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>

using namespace std;


class Sort {


public:

    //冒泡排序
    void bubbleSort(int arr[], int n){

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    __swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    //选择排序
    void selectionSort(int arr[], int n){

        for (int i = 0; i < n; i++){

            int min = i;
            for (int j = i + 1; j < n ; ++j) {

                if (arr[j] < arr[min]){
                    min = j;
                }
            }

            if (min != i){
                __swap(arr[i],arr[min]);
            }
        }

    }


    //插入排序
    void insertionSort(int arr[], int n){

        for (int i = 1; i < n; ++i) {
            for (int j = i; j > 0  ; j--) {
                if (arr[j] < arr[j - 1]){
                    __swap(arr[j],arr[j -1]);
                } else{
                    break;
                }
            }
        }
    }



    //快速排序
    void quickSort(int arr[], int n){

        __quickSort(arr,0,n - 1);

    }


    void __quickSort(int arr[], int low, int high){

        if ( low >= high){
            return;
        }

        int p = __partition(arr, low, high);
        __quickSort(arr,low,p-1);
        __quickSort(arr,p+1,high);
    }


    int __partition(int arr[], int low, int high){

        int randomIndex = rand()%(high - low + 1) + low;
        __swap(arr[randomIndex], arr[low]);

        int i = low + 1;
        int j = high;
        int pivot = arr[low];

        while (true){

            while ( i <= high && arr[i] < pivot){
                i++;
            }

            while ( j >= low + 1 && arr[j] > pivot){
                j--;
            }

            if ( i > j){
                break;
            }

            __swap(arr[i], arr[j]);

            i++;
            j--;


        }

        __swap(arr[low], arr[j]);

        return j;

    }

    void __swap(int &a, int &b){

        int temp = a;
        a = b;
        b = temp;
    }


};