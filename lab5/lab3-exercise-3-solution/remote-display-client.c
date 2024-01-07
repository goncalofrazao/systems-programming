#include "zhelpers.h"
#include "remote-char.h"
#include <curses.h>

#define WINDOW_SIZE 15

int main() {
    
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://127.0.0.1:5556");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);
    
    initscr();		    	
	cbreak();				
    keypad(stdscr, TRUE);   
	noecho();

    /* creates a window and draws a border */
    WINDOW * my_win = newwin(WINDOW_SIZE, WINDOW_SIZE, 0, 0);
    box(my_win, 0 , 0);
	wrefresh(my_win);

    display_info_t display_info;

    while (1) {
        zmq_recv(subscriber, &display_info, sizeof(display_info_t), 0);
        wmove(my_win, display_info.pos_x, display_info.pos_y);
        waddch(my_win, display_info.ch | A_BOLD);
        wrefresh(my_win);
    }
    endwin();
    return 0;
}