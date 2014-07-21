#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/un.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_LENGTH	10
#define BUF_LEN		256
#define SOCK_NAME 	"mysocket"
#define MAX_LEN 256
#define T "fprocess" //fprocess or fthread

void fprocess (int client_sock);
void fsend (int client_sock);
void freadshow (int sock);