#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <dlfcn.h>
#include "data_struct.h"

int main() {
    void *handle;
    int (*func1)(void);
    int (*func2)(int);
    int fd_rd, fd_wr;
    message_type msg;

    handle = dlopen("./funcs-ex5.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    while ((fd_rd = open("/tmp/ex4_question", O_RDONLY)) == -1) {
        if (mkfifo("/tmp/ex4_question", 0666) != 0) {
            printf("problem creating the reading fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    while ((fd_wr = open("/tmp/ex4_answer", O_WRONLY)) == -1) {
        if (mkfifo("/tmp/ex4_answer", 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    printf("fifo just opened\n");

    int n;

    while (1) {
        n = read(fd_rd, &msg, sizeof(message_type));
        if (n <= 0) {
            perror("read ");
            exit(-1);
        }

        if (msg.funct_type) {
            func2 = dlsym(handle, msg.f_name);
            if (!func2) {
                fprintf(stderr, "%s\n", dlerror());
                exit(EXIT_FAILURE);
            }
            n = func2(msg.arg);
            write(fd_wr, &n, sizeof(int));
        }
        else {
            func1 = dlsym(handle, msg.f_name);
            if (!func1) {
                fprintf(stderr, "%s\n", dlerror());
                exit(EXIT_FAILURE);
            }
            n = func1();
            write(fd_wr, &n, sizeof(int));
        }
    }
}
