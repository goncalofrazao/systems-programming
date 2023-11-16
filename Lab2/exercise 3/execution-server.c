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
    int fd;

    handle = dlopen("./funcs.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    while ((fd = open("/tmp/ex3", O_RDONLY)) == -1) {
        if (mkfifo("/tmp/ex3", 0666) != 0) {
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
        n = read(fd, str, 100);
        if (n <= 0) {
            perror("read ");
            exit(-1);
        }
        
        func = dlsym(handle, str);
        if (!func) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        printf("%d\n", func());
    }
}