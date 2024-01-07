all: remote-display-client human-client machine-client server

human-client: human-client.c zhelpers.h
	gcc human-client.c -o human-client -lncurses -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include
	
machine-client: machine-client.c zhelpers.h
	gcc machine-client.c -o machine-client -lncurses -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

remote-display-client: remote-display-client.c zhelpers.h
	gcc remote-display-client.c -o remote-display-client -lncurses -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

server: server-exercise-3.c zhelpers.h
	gcc server-exercise-3.c -o server -lncurses -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

clean:
	rm -rf machine-client human-client remote-display-client server *.dSYM