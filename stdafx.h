#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/un.h>
#include <stdlib.h>

#define QUEUE_LENGTH	10
#define BUF_LEN		256
#define SOCK_NAME 	"mysocket"

int fprocess ();