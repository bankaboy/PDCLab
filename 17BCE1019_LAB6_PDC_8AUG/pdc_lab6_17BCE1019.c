#include "mpi.h"
#include<stdio.h>
#include<stdlib.h>

int isprime(int n) {
    int i;
    if (n>10) {
        for (i=2; i<=n/2; i=i+2)
        if ((n%i)==0)
            return 0;
        return 1;
   }
    else
        return 0;
}

int is_odd(int n) {
    if (n%2) 
        return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    int ntasks, rank, n; 
    MPI_Init(NULL, NULL);

    printf("Enter the number : ");
    scanf("%d", &n);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&ntasks);

    if (rank==0) {
        if (isprime(n))
            printf("%d is a prime number \n",n);
    }

    if (rank>0) {
        if (is_odd)
            printf("%d is an odd number \n" );
        else
            printf("%d is an even number \n" );        
    }
    MPI_Finalize();
    return 0;
}