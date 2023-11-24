#include <stdio.h>
#include <zmq.h>
#include "zhelpers.h"

int main(){
    printf("Hello your Honor, the president of IST!");
    
    void *context = zmq_ctx_new ();
    // Connect to the server using ZMQ_REQ
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "ipc:///tmp/server-rep");
    
    char message[100];
    while(1){

        printf("Please write the message to your students and staff! ");
        fgets(message, 100, stdin);

        //send message to server
        s_sendmore(requester, "IST");
        s_send(requester, message);
        printf("Forwarding this message to all: %s", message);

        s_recv(requester);
        
    }
}