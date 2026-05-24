# Lab 3 - Sockets Programming

import socket

HOST = socket.gethostbyname(socket.gethostname()) # automatically get IP address
PORT = 5050 # choose a server port number greater than 1023. To be safe, choose a number larger than 5000
ADDR = (HOST, PORT)

server_name = "my server"
server_num = 10

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # create an INET, STREAMing socket
s.bind(ADDR) # bind to host and port

s.listen() # listen for incoming connections from clinnts
print("Server: waiting for client...")
print("================================================================")

conn, addr = s.accept() # accept client
print(f"Server: Client connected by {addr}")

while True:
    data = conn.recv(1024).decode() # read up to 1024 bytes of data from socket and convert to str
    
    if not data: # check if client has disconnected
        break

    print("Server: received: ", data.split("|"))
    client_name, client_num = data.split("|")
    client_num = int(client_num) # convert to int

    msg = server_name + "|" + str(server_num)
    print("Server: number and server name sent")
    print("================================================================")


    conn.sendall(msg.encode()) # send server name to client over the socket

    print(server_name)
    print(client_name)

    print("Client's number: ", client_num)
    print("Server's number: ", server_num)

    total_sum = client_num + server_num
    print("Total sum of Client and Server number: ", total_sum)
    print("================================================================")
    
conn.close()
s.close()