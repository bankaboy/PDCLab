#include<mpi.h>
#include<stdio.h>

int main (int argc, char *argv[]) {

    MPI_Init(&argc, &argv);
    /* Initialize the MPI execution environment */
    printf("Hello world\n");
    /* This routine cleans up the MPI stat. Once this routine is called,
    no MPI routine may be called. The user must ensure that all pending
    communications involving a process completes before the process calls
    MPI_Finalize. All processes must call this routine before exiting. */
    MPI_Finalize();
    return 0;
}