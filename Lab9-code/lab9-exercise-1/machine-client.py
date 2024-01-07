import balls_pb2
import zmq
import random
import time

# create a socket and connect to the server
context = zmq.Context()
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5555")

# send the connect_msg to the server
msg_type = 0
msg_type = msg_type.to_bytes(4, byteorder='little')
socket.send(msg_type, zmq.SNDMORE)

connect_msg = balls_pb2.client_connection_req()
connect_msg.ch = b'a'
serialized = connect_msg.SerializeToString()
socket.send(serialized)

reply = socket.recv()
print(reply)

msg_type = 1
msg_type = msg_type.to_bytes(4, byteorder='little')

move_msg = balls_pb2.movement_req()
move_msg.ch = b'a'

while True:
    sleep_delay_in_usec = random.randint(0, 700000)
    sleep_delay_in_sec = sleep_delay_in_usec / 1000000
    time.sleep(sleep_delay_in_sec)

    direction = random.randint(0, 3)
    if direction == 2:
        print("left")
    elif direction == 3:
        print("right")
    elif direction == 1:
        print("up")
    else:
        print("down")
    
    # send the direction to the server
    move_msg.direction = direction
    serialized = move_msg.SerializeToString()
    socket.send(msg_type, zmq.SNDMORE)
    socket.send(serialized)

    # receive the reply from the server
    reply = socket.recv()

