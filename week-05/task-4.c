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

// Task 4 from presentation 5
// Threads racing

// Not needed on git

// DONE

int a[] = {0, 0, 0};

void *mythread1(void *dummy) {

	   pthread_t mythid;
	   
	   mythid = pthread_self();

	   for (int i = 0; i < 10000000; i++) {
	   		a[0] = a[0] + 1;
	   		a[2] = a[2] + 1;
	   }

	   printf("\nThread %u\na[0] = %d, a[2] = %d\n\n", mythid, a[0], a[2]);

	   return NULL;
	}

void *mythread2(void *dummy) {

	   pthread_t mythid;
	   
	   mythid = pthread_self();

	   for (int i = 0; i < 10000000; i++) {
	   		a[1] = a[1] + 1;
	   		a[2] = a[2] + 1;
	   }

	   printf("\nThread %u\na[1] = %d, a[2] = %d\n\n", mythid, a[1], a[2]);

	   return NULL;
	}

int main() {
	   pthread_t thid1, thid2, mythid;
	   int result;

	   if(pthread_create( &thid1, (pthread_attr_t *)NULL, mythread1, NULL) != 0){
	      printf ("Error on thread create, return value = %d\n", result);
	      exit(-1);
	   }    

	   if(pthread_create( &thid2, (pthread_attr_t *)NULL, mythread2, NULL) != 0){
	      printf ("Error on thread create, return value = %d\n", result);
	      exit(-1);
	   }
	   
	   printf("Thread created, thid = %u\n", thid1);
	   printf("Thread created, thid = %u\n", thid2);


	   pthread_join(thid1, (void **)NULL);
	   pthread_join(thid2, (void **)NULL);

	   return 0;
}