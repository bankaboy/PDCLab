// Add all the elements in an array in parallel

#include<stdio.h>
#include<omp.h>

int main() {
    const int N=100;
    int a[N];

    //initialize
    for (int i=0; i<N; i++)
        a[i] = i;

    //compute sum
    int local_sum, sum=0;

    #pragma omp parallel private(local_sum) shared(sum)
    /* The omp parallel directive explicitly instructs the compiler to 
    parallelize the chosen block of code
    shared(list) - declares the scope of the comma separated data varibles in 
                   list to be shared across all threads
    private(list) - declares the scope of the comma separated data varibles in 
                    list to be private across all threads
    */
    {
        local_sum = 0;
        //This array is distributed statistically between threads
        #pragma omp for schedule(static,1)
            /* The omp for directive instructs the compiler to distbute loop
            iterations within the the team of threads that encounter this 
            work-sharing construct 
            schedule - specifies how iteration of the for loop are divided among
                        available threads. 
            static,n - iterations of a loop are divided into chunks of size n. 
                       Each chunk is assigned to a thread in round robin fashion.
                       n>=1. This scheduling policy is called block cyclic scheduling.
            */
            for (int i=0; i<N; i++) {
                local_sum += a[i];
            }
            // each thread calculated its local_sum. All threads have to 
            // the global sum. It is critical that this operation is atomic.
        #pragma omp critical
            sum+=local_sum;
            /* the omp critical directive identifies a section of code that 
            must be executed by a single thread at a time */
        
    }
    printf("sum = %d should be %d\n", sum, N*(N-1)/2);
    return 0;
}