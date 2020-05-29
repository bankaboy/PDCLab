/* QUESTION - 
Write a OpenMP program to find factorial of a 3 different numbers in separate
code block. The output of all 3 factorial values should share a same variable
through the critical section constraint. 
*/

#include<stdio.h>
#include<omp.h>

int factorial (int n) {
    if (n==0)
        return 1;
    return n*factorial(n-1);
}
int main () {
    int local_fact, inputs[3], number;
    //int *final_fact;
    printf("Enter three numbers : ");
    for (int i=0;i<3;i++) {
        scanf("%d", &inputs[i]);
    }
    #pragma omp parallel private(local_fact, number) 
    {
        #pragma omp for 
            for (int i=0;i<3;i++) {
                number = inputs[i];
                local_fact = factorial(number);
            }
                

        #pragma omp critical
            printf("%d is the factorial of %d\n", local_fact, number);
    }
    return 0;
}