#include "stdafx.h"

int main(void)
{
        int sock;
        int client_sock;
        struct sockaddr_un saddr;
        int fresult;

//create socket
        sock = socket(PF_UNIX, SOCK_STREAM, 0);
        if (sock == -1) {
                fprintf(stderr, "soccket() error\n");
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
        printf("Server waiting\n");
        	client_sock = accept (sock, NULL, NULL);                
                if (client_sock == -1){
                        fprintf (stderr, "accept() error\n");
                        return 1;
                }
//definition of implementation: threads or processes
                if (T == "fProcess") fProcess (client_sock);
                else 
                        if (T == "fThread") {
                                fThread ();
                                fSend (client_sock);
                        }
                        else return 1; 
        }
        //free (buf);
        close (sock);
        unlink (SOCK_NAME);
        return 0;

}