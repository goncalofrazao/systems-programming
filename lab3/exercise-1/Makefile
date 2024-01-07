all: server machine-control-client human-control-client

server: server.c
	gcc -g -o server server.c -lncurses

human-control-client: human-control-client.c
	gcc -g -o human-control-client human-control-client.c -lncurses

machine-control-client: machine-control-client.c
	gcc -g -o machine-control-client machine-control-client.c

clean:
	rm -rf server human-control-client machine-control-client *.dSYM