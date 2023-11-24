#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>
#include "zhelpers.h"

int main (void){

    void *context = zmq_ctx_new ();
    // Bind a ZMQ_REP socket
    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_bind (responder, "ipc:///tmp/server-rep");

    // Bind a ZMQ_PUB socket
    void *publisher = zmq_socket (context, ZMQ_PUB);
    zmq_bind (publisher, "ipc:///tmp/server-pub");
    
    char *dpt;
    char *s;
    while (1) {

        // receive messages from the microphones
        dpt = s_recv(responder);
        s = s_recv(responder);
        
        s_send(responder, "OK");
        
        printf("department %s message %s", dpt, s);

        // publish message to speakers
        s_sendmore(publisher, dpt);
        s_send(publisher, s);

        free(dpt);
        free(s);
    }
    return 0;
}