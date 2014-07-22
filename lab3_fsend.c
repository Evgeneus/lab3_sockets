#include "stdafx.h"

void fSend () 
{
//allocation of free memoty
	struct stat stat_buf;
	char * buf;
        buf = (char *) malloc (BUF_LEN);
        if (buf == NULL) {
        	fprintf(stderr, "malloc() error\n");
        	exit (1);
        }

    int count;
	if ((count = read (client_sock, buf, BUF_LEN-1)) == -1) {
        	fprintf(stderr, "read() error\n");
        	exit (1);
        }
        buf[count] = '\0';

        if(!strcmp (buf, "exit")) {
        	write (client_sock, "exit comand\n", strlen ("exit comand"));
        	printf ("exit comand is received\n");
        	close (client_sock);
                exit (1);
        }
       	
//open file
       	int fd;
       	fd = open (buf, O_RDONLY);
        if (fd == -1) {
                fprintf(stderr, "unable to open '%s'\n", buf);
                write (client_sock, "file doesn't exist\n", strlen ("file doesn't exist\n"));
                exit (1);
        }
        off_t offset = 0;


        if (buf[count-1] == '\n') buf[count-1] = '\0';
        if (buf[count-1] == '\r') buf[count-1] = '\0';
        printf(">> %s\n", buf);
        fstat (fd, &stat_buf);
    
        if (sendfile (client_sock, fd, &offset, stat_buf.st_size) == -1) {
        	fprintf(stderr, "sendfile() error\n");
        	exit (1);
        }
        
        close (fd);
        close (client_sock);
}