all: funcs execution-server client

client: client.c
	gcc -g -o client client.c

funcs: funcs.c
	gcc funcs.c -o funcs.so -ldl -shared -fPIC

execution-server: execution-server.c
	gcc -g -o execution-server execution-server.c

clean:
	rm -rf client execution-server funcs.so *.dSYM
