#include <stdio.h>
#include "collatz.h"


int main(){
//    printf("%d\n", collatz_conjecture(10));
//    printf("%d\n", test_collatz_convergence(15, 100));
    int numbers[] = {10, 15, 27, 65537};
    int max_iterations = 100;

    for (int i = 0; i < 4; i++) {
        int number = numbers[i];
        int iterations = test_collatz_convergence(number, max_iterations);

        if (iterations == -1) {
            printf("The number %d does not converge to 1 in %d iterations.\n", number, max_iterations);
        } else {
            printf("The number %d converges to 1 after %d iterations.\n", number, iterations);
        }
    }

}
