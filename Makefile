all: lab3_server lab3_client 

lab3_server: lab3_server.o lab3_fprocess.o lab3_fprocess.o lab3_fsend.o lab3_fthread.o
	gcc -o lab3_server lab3_server.c lab3_fprocess.c lab3_fsend.c lab3_fthread.c -lpthread

lab3_client: lab3_client.o
	gcc -o lab3_client lab3_client.c

clean:
	rm -f lab3_server
	rm -f lab3_client
	rm -f *.o