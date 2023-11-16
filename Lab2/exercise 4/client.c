#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int n;
    char str[100];
    int fd_rd, fd_wr;

    while((fd_wr = open("/tmp/ex4_question", O_WRONLY)) == -1) {
        if (mkfifo("/tmp/ex4_question", 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    while((fd_rd = open("/tmp/ex4_answer", O_RDONLY)) == -1) {
        if (mkfifo("/tmp/ex4_answer", 0666) != 0) {
            printf("problem creating the reading fifo\n");
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
        write(fd_wr, str, 3);

        n = read(fd_rd, str, 100);
        if (n <= 0) {
            perror("read ");
            exit(-1);
        }

        printf("result: %s\n", str);
    }

}