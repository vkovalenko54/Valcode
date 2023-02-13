#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



void *print_message_function( void *ptr);

int main()
{

	pthread_t thread1, thread2;
	char *message1 = "Thread 1";
	char *message2 = "Thread 2";

	unsigned long int iret1, iret2;

/* create independent threads each of whic_h will execute */


iret1 = pthread_create ( &thread1, NULL, print_message_function, (void *) message1);
iret2 = pthread_create ( &thread2, NULL, print_message_function, (void *) message2);

/* wait till threads are complete beforee main continues. Unless we */
/* wait we run the risk of executing an exit which will terminate */
/* the process and all threads before the threads have completed. */

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);

	printf("pthread 1 returns : %lu\n", iret1);
	printf("pthread 2 returns : %lu\n", iret2);
	exit(0);

}

void * print_message_function(void *ptr)
{
	char *message;
	message = (char * ) ptr;
	printf("%s\n", message);
}
