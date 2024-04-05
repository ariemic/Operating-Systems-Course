#include "collatz.h"


int collatz_conjecture(int n){
    if(n % 2 == 0){
        return n/2;
    }
    return 3*n + 1;
}

int test_collatz_convergence(int input, int max_iter){
    int i = 1;
    while(i < max_iter){
        input = collatz_conjecture(input);
        if(input == 1){
            return i;
        }
        i++;
    }
    return -1;
}
