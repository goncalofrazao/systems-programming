all: remote-display-client

LDFLAGS = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib
CFLAGS = -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

LFLAG = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib
IFLAG = -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

remote-display-client: remote-display-client.c ../balls.pb-c.c
	gcc remote-display-client.c ../balls.pb-c.c -o remote-display-client -g -lzmq -lncurses -lprotobuf-c $(CFLAGS) $(LDFLAGS) $(IFLAG) $(LFLAG)