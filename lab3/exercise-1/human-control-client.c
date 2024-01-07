#include <ncurses.h>
#include "remote-char.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <ctype.h> 
#include <stdlib.h>
 

int main() {
    //TODO_4
    // create and open the FIFO for writing
    int fd;

    while((fd = open(FIFO_LOCATION, O_WRONLY)) == -1) {
        if (mkfifo(FIFO_LOCATION, 0666) != 0) {
            printf("problem creating the writing fifo\n");
            exit(-1);
        } else {
            printf("fifo created\n");
        }
    }

    //TODO_5
    // read the character from the user
    message_t m;
    m.msg_type = 0;
    scanf("%c", &m.ch);

    // TODO_6
    // send connection message
    write(fd, &m, sizeof(message_t));


	initscr();			/* Start curses mode 		*/
	cbreak();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    
    int ch;
    m.msg_type = 1;
    int n = 0;
    do
    {
    	ch = getch();		
        n++;
        switch (ch)
        {
            case KEY_LEFT:
                mvprintw(0,0,"%d Left arrow is pressed", n);
                m.direction = LEFT;
                break;
            case KEY_RIGHT:
                mvprintw(0,0,"%d Right arrow is pressed", n);
                m.direction = RIGHT;
                break;
            case KEY_DOWN:
                mvprintw(0,0,"%d Down arrow is pressed", n);
                m.direction = DOWN;
                break;
            case KEY_UP:
                mvprintw(0,0,"%d :Up arrow is pressed", n);
                m.direction = UP;
                break;
            default:
                ch = 'x';
                    break;
        }
        refresh();			/* Print it on to the real screen */
        //TODO_9
        // prepare the movement message

        //TODO_10
        //send the movement message
        write(fd, &m, sizeof(message_t));
    }while(ch != 27);
    
    
  	endwin();			/* End curses mode		  */

	return 0;
}