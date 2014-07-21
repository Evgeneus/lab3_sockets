#include "stdafx.h"

void fThread () 
{
	//printf("Hell, I'm thread func\n");
	pthread_t thread;
	if (pthread_create (&thread, NULL, threadFunc, NULL) < 0) {
		fprintf(stderr, "pthread_create() error\n");
		exit (1);
	}
}

void * threadFunc (void * arg)
{ 
 	fSend (client_sock);
 	
//free the socket pointer
 	pthread_exit(NULL);
}