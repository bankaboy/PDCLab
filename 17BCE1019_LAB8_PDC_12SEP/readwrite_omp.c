#include<stdio.h>
#include <time.h>
#include <unistd.h>
#include <omp.h>

int main()
{
 int i=0,NumberofReaderThread=0,NumberofWriterThread;



omp_lock_t writelock;
omp_init_lock(&writelock);

int readCount=0;

 printf("Enter number of Readers thread: ");
 scanf("%d",&NumberofReaderThread); 
 printf("Enter number of Writers thread: ");
 scanf("%d",&NumberofWriterThread); 

int tid=0;
#pragma omp parallel
#pragma omp for

 for(i=0;i<NumberofReaderThread;i++)
 {
    printf("Reader %d is trying to enter into the Database for reading the data\n",i);


    omp_set_lock(&writelock);
    readCount++;
    if(readCount==1)
    {

      printf("Reader %d is reading the database\n",i); 
    }

    omp_unset_lock(&writelock);
    readCount--;
    if(readCount==0)
    {
      printf("Reader %d is leaving the database\n",i);  
    }
 }

#pragma omp parallel shared(tid)// Specifies that one or more variables should be shared among all threads.
#pragma omp for nowait     //If there are multiple independent loops within a parallel region
 for(i=0;i<NumberofWriterThread;i++)
 { 


    printf("Writer %d is trying to enter into database for modifying the data\n",i);

    omp_set_lock(&writelock);

    printf("Writer %d is writting into the database\n",i); 
    printf("Writer %d is leaving the database\n",i); 

    omp_unset_lock(&writelock);
 }

  omp_destroy_lock(&writelock); 
 return 0;
}