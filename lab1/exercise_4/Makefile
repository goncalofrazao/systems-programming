EXEC = prog

all: lib1 lib2 main

main: main.c
	gcc -g -o $(EXEC) main.c

lib1: lib1.c
	gcc lib1.c -o lib1.so -ldl -shared -fPIC

lib2: lib2.c
	gcc lib2.c -o lib2.so -ldl -shared -fPIC

clean:
	rm -rf $(EXEC) *.so *.dSYM
