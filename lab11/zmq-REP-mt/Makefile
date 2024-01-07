all: client server

ZEROMQ = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

# PROTOC = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

client: zmq-client.c
	gcc zmq-client.c -o client -lzmq $(ZEROMQ)

server: zmq-mt-server.c
	gcc zmq-mt-server.c -o server -lzmq $(ZEROMQ) -lpthread
