all: zmq-fan-in

ZEROMQ = -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

zmq-fan-in: zmq-fan-in.c
	gcc zmq-fan-in.c -o zmq-fan-in -g -lzmq $(ZEROMQ) -lpthread

