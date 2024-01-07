all: human-client

LDFLAGS = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib
CFLAGS = -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

LFLAG = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib
IFLAG = -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

human-client: human-client.c
	gcc human-client.c ../balls.pb-c.c -o human-client -g -lzmq -lncurses $(CFLAGS) $(LDFLAGS) $(IFLAG) $(LFLAG) -lprotobuf-c