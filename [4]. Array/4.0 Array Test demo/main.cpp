#include <iostream>
#include "ArrayQ.cpp"

void binarySearchTest(){

    printf("Test for binary search:\n");

    int arr [] = {3,4,6,8};
    int length = sizeof(arr)/ sizeof(int);
    int target = 8;
    int index = ArrayQuestion().binarySearch(arr,length,target);
    printf("index of %d is %d",target,index);

}

void moveZerosTest(){

    printf("Test for moving zeros:\n");

//    int arr [] = {0,3,4,6,8,0,20};
    int arr [] = {0,0,0,0,0,0,0,1};
    int length = sizeof(arr)/ sizeof(int);
    vector<int> vec(arr, arr + length);
    ArrayQuestion().moveZeroes(vec);

    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

}

void removeElementsTest(){

    printf("Test for removing element:\n");

    int arr [] = {0,3,4,6,8,0,20};
    int length = sizeof(arr)/ sizeof(int);
    vector<int> vec(arr, arr + length);
    int val = 3;

    printf("\nOriginal vector is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    printf("\nOriginal length is %d:\n",length);



    int newLength = ArrayQuestion().removeElement(vec,val);

    printf("\nAfter removing value:%d....",val);
    printf("\nNew vector is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    printf("\nNew length is %d\n",newLength);


}


void sortColorTest(){

    printf("Test for sorting colors:\n");

    int arr [] = {0,1,1,2,0,2,1};
    int length = sizeof(arr)/ sizeof(int);
    vector<int> vec(arr, arr + length);
    printf("\nOriginal vector is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

    ArrayQuestion().sortColors(vec);

    printf("\nAfter sorting color is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

}


void removeDuplicatesTest(){

    printf("Test for removing Duplicates:\n");

//    int arr [] = {0,1,1,2,3,3,4,5,6,6,7};
    int arr [] = {1,1,2};
    int length = sizeof(arr)/ sizeof(int);
    vector<int> vec(arr, arr + length);
    printf("\nOriginal vector is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

    ArrayQuestion().removeDuplicates(vec);

    printf("\nAfter removing duplicates:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

}


void reorderEvenOddTest(){

    printf("Test for reorderEvenOdd\n");

    int arr [] = {5,3,7,9,1,2,6};
//    int arr [] = {1,1,2};
    int length = sizeof(arr)/ sizeof(int);
    vector<int> vec(arr, arr + length);
    printf("\nOriginal vector is:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

    ArrayQuestion().reorderEvenOdd(vec,length);

    printf("\nAfter reorder:\n");
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }

}

int main() {

//    binarySearchTest();
//    moveZerosTest();
//    removeElementsTest();
//    sortColorTest();
//    removeDuplicatesTest();
    reorderEvenOddTest();

    return 0;
}