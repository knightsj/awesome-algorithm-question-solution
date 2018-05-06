

#include <math.h>
#include <iostream>


class CountPrimes {

     public:

     int countPrimes(int n){

         int count = 0;

         if(n > 2){
             count ++;
         }

         for(int i = 3; i < n; i +=2 ){

             if(__isPrime(i)){
                 count ++;
             }
         }
         return count;
     }

     private:

     bool __isPrime(int n){

         if(n == 1){
             return false;
         }

         //only odd number
         for(int i = 3; i <= sqrt(n); i += 2){
             if(n % i == 0){
                 return false;
             }
         }
         return true;
     }
};
