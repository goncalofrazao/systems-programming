
typedef enum direction_t {UP, DOWN, LEFT, RIGHT} direction_t;

typedef struct remote_char_t
{   
    int msg_type; /* 0 join   1 - move */
    char ch; 
    direction_t direction ;
    /* data */
}remote_char_t;

typedef struct display_info_t
{
    int pos_x, pos_y;
    char ch;
} display_info_t;

#define FIFO_NAME "/tmp/fifo_snail"
