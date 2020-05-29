/*Execute simple MPI program for finding the employee payroll 
processing by providing no.of Hours worked and pay rate as input. 
Assume the number of employees to be 4. Observe the time taken for 
calculating payroll of each employee. SERIAL TEST */

#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

float return_sal(int hours, float rate) {
    float sal;
    sal = rate*hours;
}

int main (int argc, char** argv) {
    int emps[4], payrate = atoi(argv[1]);
    printf("%d\n", payrate);
    for (int i=1;i<argc;i++)
        emps[i-1] = atoi(argv[i]);
    for(int i=1;i<argc-1;i++)
        printf("Hours of emp %d : %d\n",i,emps[i]);

}