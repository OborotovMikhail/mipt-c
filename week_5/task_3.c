#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

// Task 3 from presentation 5
// Like the example but 3 threads instead of 2

// Needed on git

// NOT DONE (maybe done)

int a = 0;

void *mythread(void *dummy)

	/*
	 *   Parameter void *dummy is used only for type compatibility, and will not be used
	 *   at the function now. At the same reason the return value of function has type 
	 *   void *, but it wiil be not used at this program.
	 */

	{

	   pthread_t mythid;
	   
	   mythid = pthread_self();

	   a = a + 1;

	   printf("Thread %u, Calculation result = %d\n", mythid, a);

	   return NULL;
	}

int main() {
	   pthread_t thid1, thid2, mythid; 
	   int       result;

	   result = pthread_create( &thid1, (pthread_attr_t *)NULL, mythread, NULL);
	   result = pthread_create( &thid2, (pthread_attr_t *)NULL, mythread, NULL);
	   
	   if(result != 0){
	      printf ("Error on thread create, return value = %d\n", result);
	      exit(-1);
	   }   
	   
	   printf("Thread created, thid = %u\n", thid1);
	   printf("Thread created, thid = %u\n", thid2);



	   mythid = pthread_self();
	   
	   a = a + 1;
	   
	   printf("Thread %u, Calculation result = %d\n", mythid, a);



	   pthread_join(thid1, (void **)NULL);
	   pthread_join(thid2, (void **)NULL);

	   // printf("Thread %u, Calculation result = %d\n", mythid, a);

	   return 0;
}