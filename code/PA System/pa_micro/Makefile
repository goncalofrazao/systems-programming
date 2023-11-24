all: pa_micro


pa_micro : pa_micro.c
	gcc pa_micro.c -o pa_micro -lzmq -L /opt/homebrew/Cellar/zeromq/4.3.5_1/lib -I /opt/homebrew/Cellar/zeromq/4.3.5_1/include

clean:
	rm -rf pa_micro *.dSYM