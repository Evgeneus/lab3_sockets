server_client_files: lab3_server.c lab3_client.c
	gcc -o lab3_server lab3_server.c
	gcc -o lab3_client lab3_client.c

clean:
	rm -f lab3_server
	rm -f lab3_client