#include "stdafx.h"

void fprocess (int client_sock) {
	int fresult = fork();

        if (fresult < 0){
                fprintf(stderr, "fork() error\n");
                exit (1);
        }

        if (fresult == 0) {
                printf("I'm Child Server with PID=%d\n", getpid());
                fsend (client_sock);
        } else printf("I'm Parent Server with PID=%d\n", getpid());

}