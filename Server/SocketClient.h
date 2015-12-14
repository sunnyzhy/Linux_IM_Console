#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/socket.h> 
using namespace std;

#define MAXLINE 4096  

class SocketClient
{
public:
    SocketClient(int sock);
    void ReceiveData();
    void CloseSocket();
    friend void *thread(void *ptr);
    ~SocketClient(void);
private:
    int sock;
};
