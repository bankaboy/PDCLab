#include<stdio.h>
#include<stdlib.h>
#include "omp.h"

static int fib(int);

int main() {
    int nthreads, tid, n=8;
    #pragma omp parallel num_threads(4) private(tid)
    {
        #pragma omp single
        {
            tid = omp_get_thread_num();
            printf("hello world from (%d)\n", tid);
            printf("Fib(%d) = %d by %d\n",n,fib(n),tid);
        }
    }
}

static int fib(int n) {
    int i,j,id;
    if (n<2)
        return n;
    #pragma omp task shared(i) private(id)
    {
        i = fib(n-1);
    }
    #pragma omp task shared(j) private(id)
    {
        j = fib(n-2);
    }
    return (i+j);
}