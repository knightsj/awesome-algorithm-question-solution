#include <iostream>

#include "CountPrimes.h"
#include "Fibonacci.h"

//=========== TestForCountPrimes ===========

void __countPrimes(int n){

    CountPrimes cp;
    int res = cp.countPrimes(n);
    printf("\n\nTotal count of prime number less than %d is %d",n, res);
}

void testForCountPrimes(){

    printf("\n\n =========== TestForCountPrimes ===========\n\n");
    int arr[] = {2,10,11,20};

    for (int i = 0; i < 4; ++i) {
        __countPrimes(arr[i]);
    }
}

//========================================



// =========== TestForFibnacci ===========
void __fibonacci(unsigned n){

    Fibonacci fib;
    int res = fib.fibonacci(n);
    printf("Fibonacci of %d is %d\n",n, res);
}


void testForFibonacci(){

    printf("\n\n =========== TestForFibonacci ===========\n\n");
    int arr[] = {0,1,2,3,4,5,6,7};

    for (int i = 0; i < 8; ++i) {
        __fibonacci(arr[i]);
    }
}

//========================================

int main() {

//    testForCountPrimes();
//    testForFibonacci();


    return 0;
}

