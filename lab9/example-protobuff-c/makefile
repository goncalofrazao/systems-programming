all: zmq-client zmq-server

LFLAG = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib
IFLAG = -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

LDFLAGS = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib
CFLAGS = -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include


example.pb-c.h: example.proto
	protoc --c_out=. example.proto

zmq-client: client/zmq-client.c example.pb-c.h
	gcc client/zmq-client.c example.pb-c.c -g -o zmq-client -lzmq -lprotobuf-c $(IFLAG) $(LFLAG) $(CFLAGS) $(LDFLAGS)

zmq-server: server/zmq-server.c example.pb-c.h
	gcc server/zmq-server.c example.pb-c.c -g -o zmq-server -lzmq -lprotobuf-c $(IFLAG) $(LFLAG) $(CFLAGS) $(LDFLAGS)

clean: 
	rm zmq-server zmq-client example.pb-c.h