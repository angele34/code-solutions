import socket

HOST = socket.gethostbyname(socket.gethostname()) # automatically get IP address
PORT = 5050 # choose a server port number greater than 1023. To be safe, choose a number larger than 5000
ADDR = (HOST, PORT)

client_name = "my server"

c = socket.socket() # create communication endpoint
print("Client: connecting to server...")
print("================================================================")


c.connect(ADDR)

while True:
    client_num = input("Enter a number between 1 and 100\n")

    try:
        num = int(client_num)

        if 1 <= num <= 100: # accept an integer between 1 and 100
            msg = client_name + "|" + client_num
            c.send(msg.encode())
            print("Client: number and client name sent")
            print("================================================================")


            res = c.recv(1024).decode()
            print("Client: received: ", res.split("|"))
            
            server_name, server_num = res.split("|")
            server_num = int(server_num)

            print(client_name)
            print(server_name)

            print("Client's number: ", num)
            print("Server's number: ", server_num)

            total_sum = num + server_num
            print("Total sum of Client and Server number: ", total_sum)
            print("================================================================")

            break
        else:
            break # terminate program (out of range)

    except ValueError:
        print("Please input a valid integer")

c.close()