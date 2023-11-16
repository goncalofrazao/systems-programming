#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int n;
    char str[100];
    int fd;

    while((fd = open("/tmp/ex3", O_WRONLY)) == -1) {
        if (mkfifo("/tmp/ex3", 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    printf("fifo just opened for writing\n");

    while (1) {
        printf("function to call: ");
        fgets(str, 100, stdin);
        str[2] = '\0';
        write(fd, str, 3);
    }

}