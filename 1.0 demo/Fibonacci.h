
class Fibonacci{

    public:

    long long fibonacci(unsigned n){

        int result[2] = {0,1};

        if (n < 2){
            return result[n];
        }

        long long fibM1 = 1;
        long long fibM2 = 0;
        long long fibN = 0;

        for (int i = 2; i <= n ; i++) {

            fibN  = fibM1 + fibM2;
            fibM2 = fibM1;
            fibM1 = fibN;
        }

        return fibN;
    }
};
