/*
2. Create 4 threads for performing the below matrix operations using omp barrier.
i. Addition
ii. Subtraction
iii. Multiplication
iv. Division
*/

#include<stdio.h>
#include<omp.h>

int results1[3][3], results2[3][3], results3[3][3], results4[3][3];

void addition(int a[3][3], int n) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            results1[i][j] = a[i][j]+n;
}

void subtraction(int a[3][3], int n) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            results2[i][j] = a[i][j]-n;
}

void multiplication(int a[3][3], int n) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            results3[i][j] = a[i][j]*n;
}

void division(int a[3][3], int n) {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            results4[i][j] = a[i][j]/n;
}

void print_matrix (int a[3][3]) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}
int main () {
    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}, n=2;
    #pragma omp parallel num_threads(4) shared(a,n,results1,results2,results3,results4)
    {
        if (omp_get_thread_num() == 0)
            addition(a,n);
        else if (omp_get_thread_num() == 1)
            subtraction(a,n);
        else if (omp_get_thread_num() == 2)
            multiplication(a,n);
        else if (omp_get_thread_num() == 3)
            division(a,n);

        #pragma omp barrier
        if ( omp_get_thread_num() == 0 ) {
            printf("Matrix after addition: \n");
            print_matrix(results1);
        }
        else if ( omp_get_thread_num() == 1 ) {
            printf("Matrix after subtraction: \n");
            print_matrix(results2);
        }
        else if ( omp_get_thread_num() == 2 ) {
            printf("Matrix after multiplication: \n");
            print_matrix(results3);
        }
        else if ( omp_get_thread_num() == 3 ) {
            printf("Matrix after division: \n");
            print_matrix(results4);
        }
    }

    
    return 0;
}