#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <dlfcn.h>

int main() {
    void *handle;
    int (*func)(void);
    int fd_rd, fd_wr;

    handle = dlopen("./funcs.so", RTLD_LAZY);

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
    char str[100];

    while (1) {
        n = read(fd_rd, str, 100);
        if (n <= 0) {
            perror("read ");
            exit(-1);
        }
        
        func = dlsym(handle, str);
        if (!func) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        sprintf(str, "%d", func());
        write(fd_wr, str, 3);
    }
}