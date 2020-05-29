/* QUESTION  - 
Write a OpenMP program to find the count of prime numbers from the given 
input using appropriate constraint
 */

#include<stdio.h>
#include<omp.h>

int check_prime (int n) {
    int i, flag = 1;
    for(i = 2; i <= n/2; ++i)
    {
        if(n%i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;

}

int main () {
    const int N = 10;
    int a[N], n, local_count, total_count = 0;

    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Enter the elements : ");

    #pragma omp parallel private(local_count) shared(total_count)
    {
        local_count = 0;
        #pragma omp for  
            for (int i=2;i<=n;i++) {
                if (check_prime(i))
                    local_count+=1;
            }
        #pragma omp critical
            total_count += local_count;
    }
    printf("The count of the prime numbers from 1 to %d is %d\n",n, total_count);
    return 0 ;
}