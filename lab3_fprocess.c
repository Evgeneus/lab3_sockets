#include "stdafx.h"

int fprocess () {
	int fresult = fork();

        if (fresult == -1){
                fprintf(stderr, "fork() error\n");
                return 1;
        }

        if (fresult == 0) {
                printf("I'm Child Server with PID=%d\n", getpid());
        } else printf("I'm Parent Server with PID=%d\n", getpid());

        return 0;
}