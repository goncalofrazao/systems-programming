all: pa_server


pa_server: pa_server.c
	gcc pa_server.c -o pa_server -g -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

clean:
	rm -rf pa_server *.dSYM