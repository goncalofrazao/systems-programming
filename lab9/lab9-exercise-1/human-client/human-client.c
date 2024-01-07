#include <ncurses.h>
#include "../remote-char.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
 #include <ctype.h> 
 #include <stdlib.h>
 
#include <zmq.h>
#include "zhelpers.h"
#include "../balls.pb-c.h"

int main()
{




    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    int rc = zmq_connect (requester, "tcp://localhost:55555");
    if (rc!=0){
        printf("error connecting REQ socket");
        exit(-1);
    }
	printf("socket connected\n");

    char ch;
    do{
        printf("what is your character(a..z)?: ");
        ch = getchar();
        ch = tolower(ch);  
    }while(!isalpha(ch));



    int msg_type = 0;
    zmq_send(requester, &msg_type, sizeof(msg_type), ZMQ_SNDMORE);

    // TODO 7 - create and fill a message of type client_connection_req   
    //           and send the packed message to the server
    // remote_char_t m;
    // m.ch = ch;
    ClientConnectionReq m;
    m.ch.data = malloc(sizeof(ch));
    memcpy(m.ch.data, &ch, sizeof(ch));
    m.ch.len = sizeof(ch);

    int size_bin_msg = client_connection_req__get_packed_size(&m);
    char * pb_m_bin = malloc(size_bin_msg);
    client_connection_req__pack(&m, (uint8_t*)pb_m_bin);

    zmq_send (requester, pb_m_bin, size_bin_msg, 0);
    free(pb_m_bin);
    // TODO 7

    char * str = s_recv(requester);
    free(str);   


	initscr();			/* Start curses mode 		*/
	cbreak();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    int n = 0;
    MovementReq move = MOVEMENT_REQ__INIT;
    move.ch.data = malloc(sizeof(ch));
    memcpy(move.ch.data, &ch, sizeof(ch));
    move.ch.len = sizeof(ch);
    
    int key;
    do
    {
    	key = getch();		
        n++;
        switch (key)
        {
        case KEY_LEFT:
            mvprintw(0,0,"%d Left arrow is pressed", n);
           move.direction = LEFT;
            break;
        case KEY_RIGHT:
            mvprintw(0,0,"%d Right arrow is pressed", n);
            move.direction = RIGHT;
            break;
        case KEY_DOWN:
            mvprintw(0,0,"%d Down arrow is pressed", n);
           move.direction = DOWN;
            break;
        case KEY_UP:
            mvprintw(0,0,"%d :Up arrow is pressed", n);
            move.direction = UP;
            break;

        default:
            key = 'x'; 
            break;
        }

         if (key != 'x'){
            int msg_type = 1;
            zmq_send(requester, &msg_type, sizeof(msg_type), ZMQ_SNDMORE);

            // TODO 10 - create and fill a message of type  movement_req  
            //           and send the packed message to the server
            int size_bin_msg = movement_req__get_packed_size(&move);
            char * pb = malloc(size_bin_msg);
            movement_req__pack(&move, (uint8_t*)pb);

            zmq_send (requester, pb, size_bin_msg, 0);
            // TODO 10
            free(pb);


            char * str = s_recv(requester);
            free(str);   
        }
        refresh();			/* Print it on to the real screen */
    }while(key != 27);
    
    
  	endwin();			/* End curses mode		  */

	return 0;
}