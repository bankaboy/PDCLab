/*Exercise1 - Find the sum of 'n' integers using the omp  barrier*/

#include<stdio.h>
#include<omp.h>

int cum_sum (int i, int k) {
    int indi_sum = 0;
    for (int j=i;j<=k;j++)
        indi_sum+=j;
    return indi_sum;
}
int main () {
    int sum = 0, n, sum1, sum2, sum3, sum4;
    printf("Enter the number: ");
    scanf("%d", &n);
    #pragma omp parallel num_threads(4) shared(n) shared(sum) shared(sum1) shared(sum2) shared(sum3) shared(sum4)
    {
        if (omp_get_thread_num() == 0)
            sum1 = cum_sum(1,n/4);
        else if (omp_get_thread_num() == 1)
            sum2 = cum_sum(n/4+1, n/2);
        else if (omp_get_thread_num() == 2)
            sum3 = cum_sum(n/2+1, 3*n/4);
        else if (omp_get_thread_num() == 3)
            sum4 = cum_sum(3*n/4+1, n);

        #pragma omp barrier 
            if (omp_get_thread_num() == 0) {
                sum = sum1+sum2+sum3+sum4;
                printf("The sum of the first n integers is %d\n", sum);
            }
    }
    return 0;
}