
import java.lang.*;

public class Main {

    public static void main(String[] args) {

        System.out.println("Hello World!");


        //============ test for binary search ============

        int[] array = {1,3,6,9,10};
        int index = binary_search(array,9);
        System.out.println("index: " + index);


        //============ test for is Prime

        boolean res = is_prime_1(32);
        System.out.println("is prime: " + res);


        //============ test for is power of two
        boolean pw1 = isPowerOfTwo(16);
        System.out.println("is power of two 1: " + pw1);

        boolean pw2 = isPowerOfTwo(18);
        System.out.println("is power of two 2: " + pw2);


        //============ test for is power of three

        boolean pw11 = isPowerOfThree(9);
        System.out.println("is power of three 1: " + pw11);

        boolean pw22 = isPowerOfThree(12);
        System.out.println("is power of three 2: " + pw22);


        //============ test for is count primes

        int int1 = 9;
        int cp1 = countPrimes(int1);
        System.out.println("count of prime of"  + int1 + " is " + cp1);

        int int2 = 19;
        int cp2 = countPrimes(int2);
        System.out.println("count of prime of"  + int2 + " is " + cp2);




    }



    public static int Fibonacci(int n){

        if( n==0 || n==1 ){

                return 1;
        }
        else if(n>1){

            return Fibonacci(n-1)+Fibonacci(n-2);
        }
        else{
            return 0;
        }

    }


    public static int binary_search( int[] array, int target){

        if (array.length == 0){
            return -1;
        }

        int low = 0;
        int high = array.length - 1;

        while ( low <= high ) {

            int middle = (high - low) / 2 + low;

            if (array[middle] == target) {

                return middle;

            }else if ( array[middle] > target){

                high = middle - 1;

            }else {

                low = middle + 1;
            }
        }

        return -1;
    }



    public static  boolean is_prime_1 ( int num){

        int tmp =num - 1;

        for(int i= 2;i <=tmp; i++){

            if(num %i== 0){
                return false;
            }
        }
        return true ;

    }


    public static boolean isPowerOfTwo(int n) {

        if ( n == 1){
            return true;
        }

        if ( n >= 2 && n%2 == 0){

            return isPowerOfTwo(n/2);
        }

        return false;
    }

    public static boolean isUgly(int num) {

        if(num == 0){

            return false;

        }else if(num == 1){

            return true;

        }else{

            while(num % 2 == 0){

                num /= 2;

            }

            while(num % 3 == 0){

                num /= 3;

            }

            while(num % 5 == 0){

                num /= 5;
            }

            if(num == 1){

                return true;

            }else{

                return false;

            }
        }
    }

    public static boolean isPowerOfThree(int n) {

        if( n > 1 ){

            while( n%3 == 0){

                n = n/3;
            }
        }

        return n == 1;
    }


    public static int countPrimes(int n) {

        int count = 0;

        if(n > 2){
            count ++;
        }

        for(int i = 3; i < n; i +=2 ){

            if(_isPrime(i)){
                count ++;
            }
        }
        return count;
    }

    static boolean  _isPrime(int n){

        if(n == 1){
            return false;
        }

        //only odd number
        for(int i = 3; i <= Math.sqrt(n); i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

}
