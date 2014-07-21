#include "stdafx.h"

int main(int argc, char ** argv)
{
	int sock;
	struct sockaddr_un addr;

	if (argc < 2) {
		fprintf(stderr, "Too few arguments\n");
		return 1;
	}

//create socket
	sock = socket(PF_UNIX, SOCK_STREAM, 0);
        if (sock == -1) {
                fprintf(stderr, "soccket() error\n");
                return 1;
        }

        addr.sun_family = AF_UNIX;
        strcpy (addr.sun_path, SOCK_NAME);

//connect to local server
        if (connect (sock, (struct sockaddr *) &addr, SUN_LEN (&addr)) == -1) {
        	fprintf(stderr, "connect() error\n");
        	return 1;
        }

//sending message to the server
	if (write (sock, argv[1], strlen (argv[1])) == -1) {
		fprintf(stderr, "write error\n");
	       return 1;
	}

	freadshow (sock);

	close (sock);
	return 0;
}

void freadshow (int sock) {
	char * buf;
	int fd;
	buf = (char *) malloc (BUF_LEN);
        if (buf == NULL) {
        	fprintf(stderr, "malloc() error\n");
        	exit (1);
        }

	int count;
	if ((count = read (sock, buf, BUF_LEN-1)) == -1) {
        	fprintf(stderr, "read() error\n");
        	exit (1);
    	}
   	buf[count] = '\0';
//creat file
   	fd = creat("myfile", S_IRUSR | S_IWUSR | S_IRGRP);
	if (fd == -1) {
		fprintf(stderr, "cannot creat 'myfile'\n");
		exit (1);
	}
//write to file
	if (write (fd, buf, strlen (buf)) == -1) {
		fprintf(stderr, "write to file error\n");
	        exit (1);
	}  	

   	//printf(">> %s\n", buf);
   	close (fd);
}