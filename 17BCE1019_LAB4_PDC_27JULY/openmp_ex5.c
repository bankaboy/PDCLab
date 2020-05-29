#include<stdio.h>
#include<stdlib.h>
#include "omp.h"

# define N 10

int main () {
    int i;
    double a[N], b[N], c[N], d[N];
    for (i=0;i<N;i++) {
        a[i] = i*2.0;
        b[i] = i + a[i]*22.5;
    }
    #pragma omp parallel shared(a,b,c,d) private(i)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
                for (i=0;i<N;i++)
                    c[i] = a[i]+b[i];
            #pragma omp section
                for (i=0;i<N;i++)
                    d[i] = a[i]*b[i];
        }
    }
    printf("The value of array c: \n");
    for (i=0;i<N;i++)
        printf("%d\n", c[i]);
    printf("The value of array d: \n");
    for (i=0;i<N;i++)
        printf("%d\n", d[i]);
}