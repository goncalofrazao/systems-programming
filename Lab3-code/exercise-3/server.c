
#include <ncurses.h>
#include "remote-char.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#define WINDOW_SIZE 15

direction_t random_direction(){
    return  random()%4;
}

void new_position(int* x, int *y, direction_t direction){
    switch (direction)
    {
    case UP:
        (*x) --;
        if(*x ==0)
            *x = 2;
        break;
    case DOWN:
        (*x) ++;
        if(*x ==WINDOW_SIZE-1)
            *x = WINDOW_SIZE-3;
        break;
    case LEFT:
        (*y) --;
        if(*y ==0)
            *y = 2;
        break;
    case RIGHT:
        (*y) ++;
        if(*y ==WINDOW_SIZE-1)
            *y = WINDOW_SIZE-3;
        break;
    default:
        break;
    }
}

int get_ch_index(ch_t ch_info[], int n, char ch) {
    for (int i = 0; i < n; i++) {
        if (ch_info[i].ch == ch) {
            return i;
        }
    }
    return -1;
}

int main()
{	
	// TODO_3
    // create and open the FIFO for reading
    int fd;
    while ((fd = open(FIFO_LOCATION, O_RDONLY)) == -1) {
        if (mkfifo(FIFO_LOCATION, 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    // ncurses initialization
	initscr();		    	
	cbreak();				
    keypad(stdscr, TRUE);   
	noecho();			    


    /* creates a window and draws a border */
    WINDOW * my_win = newwin(WINDOW_SIZE, WINDOW_SIZE, 0, 0);
    box(my_win, 0 , 0);	
	wrefresh(my_win);

    /* information about the character */
    int ch;
    int pos_x;
    int pos_y;
    message_t m;


    direction_t  direction;

    // STEP 2
    ch_t ch_info[10];
    int n = 0;
    int index = 0;
    while (1)
    {
        // TODO_7
        // receive message from the clients
        read(fd, &m, sizeof(message_t));

        //TODO_8
        // process connection messages
        if (m.msg_type == 0 && n < 10) {
            ch = m.ch;
            pos_x = WINDOW_SIZE/2;
            pos_y = WINDOW_SIZE/2;
            ch_info[n].ch = ch;
            ch_info[n].x = pos_x;
            ch_info[n].y = pos_y;
            index = n;
            n++;
        }
        else {
            // TODO_11
            // process the movement message
            ch = m.ch;
            direction = m.direction;
            index = get_ch_index(ch_info, n, ch);

            wmove(my_win, ch_info[index].x, ch_info[index].y);
            waddch(my_win, ' ');
            new_position(&ch_info[index].x, &ch_info[index].y, direction);
        }

        /* draw mark on new position */
        wmove(my_win, ch_info[index].x, ch_info[index].y);
        waddch(my_win,ch| A_BOLD);
        wrefresh(my_win);			
    }
  	endwin();			/* End curses mode		  */

	return 0;
}