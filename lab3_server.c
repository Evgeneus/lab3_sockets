#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/un.h>
#include <stdlib.h>

#define QUEUE_LENGTH	10
#define BUF_LEN		256
#define SOCK_NAME 	"mysocket"
int main(void)
{
        int sock, client_sock;
        struct sockaddr_un saddr;
        char * buf;
        int count, fresult;

//create socket
        sock = socket(PF_UNIX, SOCK_STREAM, 0);
        if (sock == -1) {
                fprintf(stderr, "soccket() error\n");
                return 1;
        }

//allocation of free memoty
        buf = (char *) malloc (BUF_LEN);
        if (buf == NULL) {
        	fprintf(stderr, "malloc() error\n");
        	return 1;
        }

//socket address assignment
        saddr.sun_family = AF_UNIX;
        strcpy (saddr.sun_path, SOCK_NAME);
        if (bind (sock, (struct sockaddr *) &saddr, SUN_LEN (&saddr)) == -1) {
        	fprintf(stderr, "bind() error\n");
        	return 1;
        }
//listening of socket
        if (listen (sock, QUEUE_LENGTH) == -1) {
        	fprintf(stderr, "listen() error\n");
        	return 1;
        }

        while (1) {
                //printf("Server waiting\n");
        	client_sock = accept (sock, NULL, NULL);

                fresult = fork();
                if (fresult == -1){
                        fprintf(stderr, "fork() error\n");
                        return 1;
                }
                if (fresult == 0) {
                        printf("I'm Child Server with PID=%d\n", getpid());
                } else printf("I'm Parent Server with PID=%d\n", getpid());

        	if (client_sock == -1){
        		fprintf (stderr, "accept() error\n");
        		return 1;
        	}

        	if ((count = read (client_sock, buf, BUF_LEN-1)) == -1) {
        		fprintf(stderr, "read() error\n");
        		return 1;
        	}

        	buf[count] = '\0';
        	printf(">> %s\n", buf);
        	close (client_sock);

        	if(!strcmp (buf, "exit")) break;
        }

        free (buf);
        close (sock);
        unlink (SOCK_NAME);
        return 0;

}