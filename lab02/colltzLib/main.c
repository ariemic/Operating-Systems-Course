#include "collatz.h"
#include <stdio.h>
#include <dlfcn.h>

int main(){

    void *handler = dlopen("./libcollatz.so", RTLD_LAZY);
    if(!handler){printf("Opening library error\n");}

    int(*convergence)(int, int);
    convergence = dlsym(handler, "test_collatz_convergence");

    if(dlerror() != NULL){ printf("Function error occured \n");};


    int numbers[] = {10, 15, 27, 65537};
    int max_iterations = 100;

    for (int i = 0; i < 4; i++) {
        int number = numbers[i];
        int iterations = convergence(number, max_iterations);

        if (iterations == -1) {
            printf("The number %d does not converge to 1 in %d iterations.\n", number, max_iterations);
        } else {
            printf("The number %d converges to 1 after %d iterations.\n", number, iterations);
        }
    }





    dlclose(handler);


};