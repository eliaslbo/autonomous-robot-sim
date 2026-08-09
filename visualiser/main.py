import socket
import pygame

HOST = '127.0.0.1'
PORT = 65432

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # This creates a socket. AF_INET = use IPv4 adresses, and SOCK_STREAM = use a TCP connection
server.bind((HOST, PORT)) #Attaches the socket to the address and port
server.listen(1) #Start listening to incoming conections, the 1 means accept only one connection at a time

print("Waiting for C++ to connect")
conn, addr = server.accept() #Blocks the program here and waits for C++ to connect. conn = the connection object we use, addr = the adress the C++ program
print("Connected!")

# Constants
CELL_SIZE = 15
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Receive and parse maze
maze_data = conn.recv(65536).decode()
maze_data = maze_data.split('POS:')[0]  
parts = maze_data.split(':')[1]
sections = parts.split(',', 2)
height = int(sections[0])
width = int(sections[1])
rows = sections[2].split('|')
grid = []
for row in rows:
    cells = row.split(',')
    grid.append([int(c) for c in cells if c != ''])

# Set up pygame
pygame.init()
screen = pygame.display.set_mode((width * CELL_SIZE, height * CELL_SIZE))
pygame.display.set_caption("Robot Simulator")

robot_y, robot_x = 1, 1
running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Receive position
    try:
        conn.settimeout(0.01)
        pos_data = conn.recv(1024).decode()
        if pos_data.startswith('POS:'):
            coords = pos_data.split(':')[1].split(',')
            robot_y = int(coords[0])
            robot_x = int(coords[1])
    except:
        pass

    # Draw maze
    for i in range(height):
        for j in range(width):
            color = BLACK if grid[i][j] == 1 else WHITE
            pygame.draw.rect(screen, color, (j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE))

    # Draw goal and robot
    pygame.draw.rect(screen, GREEN, (39 * CELL_SIZE, 39 * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    pygame.draw.rect(screen, RED, (robot_x * CELL_SIZE, robot_y * CELL_SIZE, CELL_SIZE, CELL_SIZE))
    pygame.display.flip()

conn.close()
server.close()
pygame.quit()

