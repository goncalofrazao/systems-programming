#include "remote-char.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

int main()
{	
    //TODO_4
    int fd;

    while ((fd = open(FIFO_LOCATION, O_WRONLY)) == -1) {
        if (mkfifo(FIFO_LOCATION, 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }
	printf("fifo just opened\n");

    //TODO_5
    message_t m;
    m.msg_type = 0;
    scanf("%c", &m.ch);
    
    // TODO_6
    write(fd, &m, sizeof(message_t));
    
    int sleep_delay;
    direction_t direction;
    int n = 0;
    m.msg_type = 1;
    while (1)
    {
        sleep_delay = random()%700000;
        usleep(sleep_delay);
        direction = random()%4;
        n++;
        switch (direction)
        {
        case LEFT:
            printf("%d Going Left   ", n);
            m.direction = LEFT;
            break;
        case RIGHT:
            printf("%d Going Right   ", n);
            m.direction = RIGHT;
           break;
        case DOWN:
            printf("%d Going Down   ", n);
            m.direction = DOWN;
            break;
        case UP:
            printf("%d Going Up    ", n);
            m.direction = UP;
            break;
        }
        //TODO_9
        //TODO_10
        write(fd, &m, sizeof(message_t));
    }

 
	return 0;
}