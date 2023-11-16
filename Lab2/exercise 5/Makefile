all: funcs-ex5 execution-server client

client: client.c data_struct.h
	gcc -g -o client client.c

execution-server: execution-server.c data_struct.h
	gcc -g -o execution-server execution-server.c

funcs-ex5: funcs-ex5.c data_struct.h
	gcc funcs-ex5.c -o funcs-ex5.so -ldl -shared -fPIC

clean:
	rm -rf client execution-server funcs-ex5.so *.dSYM
