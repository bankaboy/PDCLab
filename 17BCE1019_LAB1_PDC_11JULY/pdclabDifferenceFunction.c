#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

int subtract (int a, int b) {
	int c = a-b;
	return c;
}

int main (int argc, char *argv[])
{
int nthreads, a=4, b=5, c, tid;

/*Fork a team of threads giving them their own copies of variables*/
#pragma omp parallel private (nthreads, tid)
{
/*Obtain thread number*/
tid = omp_get_thread_num();
c = subtract(a,b);
printf("Result of addition from thread = %d\n", tid);
printf("Result of addition = %d\n", c);
/*Only master thread does this*/
if (tid==0)
{
nthreads = omp_get_num_threads();
printf("Number of threads = %d\n",  nthreads);
}
}
/*All threads join the master and disband*/
}
