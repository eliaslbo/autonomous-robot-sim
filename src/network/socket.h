#pragma once
#include <winsock2.h>
#include <string>


class Socket{
    public:
        Socket(const std::string& host, int port);
        void sendData(const std::string& data);
        void close();
    private:
        int port;
        SOCKET sock;
        std::string host;
};