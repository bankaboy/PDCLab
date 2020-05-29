#include<stdio.h>
#include<stdlib.h>
#include "mpi.h"
#include "omp.h"

int main(int argc, char*argv[]) {
    int rank, omp_rank, mpi_support;

    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &mpi_support);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    #pragma omp parallel private(omp_rank)
    {
        omp_rank = omp_get_thread_num();
        printf("Hello. This is process %d, thread %d\n", rank, omp_rank);
    }
    MPI_Finalize();
}