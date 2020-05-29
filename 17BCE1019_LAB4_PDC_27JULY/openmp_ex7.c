#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <mpi.h>

#define _NUM_THREADS 4

/* Each MPI process spawns a distinct OpenMP master thread; 
   so limit the number of MPI processes to one per node
*/

int main (int argc, char *argv[]) {
    int p, my_rank;

    /* set the number of threads to spawn */
    omp_set_num_threads(_NUM_THREADS);

    /* Initalize the MPI stuff */
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int c;
    /* the following is a parallel OpenMP executed by each MPI process */
    #pragma omp parallel reduction(+:c)
    {
        c = omp_get_num_threads();
    }

    /* expect a number to get printed for each MPI process */
    printf("%d\n", c);
    /* finalize MPI */
    MPI_Finalize();
    return 0;
}