#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "data_struct.h"

int main() {

    int n;
    char str[100];
    message_type msg;
    int output;
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
        n = sscanf(str, "%d %s %d", &msg.funct_type, msg.f_name, &msg.arg);
        if ((n != 3 && n != 2) || (msg.funct_type != 1 && msg.funct_type != 0) || (n == 3 && msg.funct_type == 0) || (n == 2 && msg.funct_type == 1)) {
            printf("invalid input\n");
            continue;
        }
        write(fd_wr, &msg, sizeof(message_type));

        n = read(fd_rd, &output, sizeof(int));
        if (n <= 0) {
            perror("read ");
            exit(-1);
        }

        printf("result: %d\n", output);
    }

}