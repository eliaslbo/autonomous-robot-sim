#include "socket.h"
#include <iostream>
#pragma comment(lib, "ws2_32.lib")


// This function creates a TCP socket, and connects to the python program at a given port and host.
Socket::Socket(const std::string& host, int port) : host(host), port(port) {
    // Initialize Winsock
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set up address
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host.c_str());

    // Connect to Python
    connect(sock, (sockaddr*)&server, sizeof(server));
    std::cout << "Connected to Python!" << std::endl;
}

void Socket::sendData(const std::string& data){
    send(sock, data.c_str(), data.size(), 0);
}

void Socket::close(){
    closesocket(sock);
    WSACleanup();
}
