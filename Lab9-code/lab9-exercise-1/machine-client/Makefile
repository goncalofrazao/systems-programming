all: machine-client

LDFLAGS = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib
CFLAGS = -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

LFLAG = -L /opt/homebrew/Cellar/protobuf-c/1.5.0/lib
IFLAG = -I /opt/homebrew/Cellar/protobuf-c/1.5.0/include

machine-client: machine-client.c
	gcc machine-client.c ../balls.pb-c.c -o machine-client -g -lzmq -lprotobuf-c $(CFLAGS) $(LDFLAGS) $(IFLAG) $(LFLAG)