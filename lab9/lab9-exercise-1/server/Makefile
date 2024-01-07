all: server

LDFLAGS = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib
CFLAGS = -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

LFLAG = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib
IFLAG = -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

server: server.c ../balls.pb-c.c
	gcc server.c ../balls.pb-c.c  -o server -g -lzmq -lncurses -lprotobuf-c $(CFLAGS) $(LDFLAGS) $(IFLAG) $(LFLAG)