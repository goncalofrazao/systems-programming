all: client-sub client-sub-even

client-sub : client-sub.c
	gcc client-sub.c -o client-sub -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include
	
client-sub-even: client-sub-even.c
	gcc client-sub-even.c -o client-sub-even -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

clean:
	rm -rf client-sub client-sub-even