#include "stdafx.h"

void fProcess ()
{
	int fresult = fork();

        if (fresult < 0){
                fprintf(stderr, "fork() error\n");
                exit (1);
        }

        if (fresult == 0) {
                printf("I'm Child Server with PID=%d\n", getpid());
                fSend ();
        } else printf("I'm Parent Server with PID=%d\n", getpid());

}