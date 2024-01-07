#ifndef REMOTE_CHAR_H
#define REMOTE_CHAR_H
// TODO_1 
// declaration the struct corresponding to the exchanged messages
typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct message_t {
    int msg_type;
    char ch;
    direction_t direction;
} message_t;


// TODO_2
//declaration of the FIFO location
#define FIFO_LOCATION "/tmp/fifo-lab3-3"

// STEP 1
typedef struct ch_t {
    char ch;
    int x;
    int y;
} ch_t;

#endif