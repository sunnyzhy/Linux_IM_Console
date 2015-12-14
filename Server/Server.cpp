#include <netinet/in.h> 
#include <errno.h> 
#include "SocketClient.h"
#define DEFAULT_PORT 8000  

int main(int argc, char** argv)  
{  
    int socket_fd, client_fd;  
    struct sockaddr_in addrServer;  
    char buf[MAXLINE];  
    int len;  

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if( socket_fd == -1 )
    {  
        cout<<"初始化socket失败！errmsg:"<<strerror(errno)<<endl;  
        exit(0);  
    }  
 
    memset(&addrServer, 0, sizeof(addrServer));  
    addrServer.sin_family = AF_INET;  
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY);
    addrServer.sin_port = htons(DEFAULT_PORT);
  
    len=bind(socket_fd, (struct sockaddr*)&addrServer, sizeof(addrServer));
    if(len== -1)
    {  
        cout<<"绑定socket失败！errmsg:"<<strerror(errno)<<endl;  
        exit(0);  
    }  

    len=listen(socket_fd, 10);
    if(len== -1)
    {  
        cout<<"监听socket失败！errmsg:"<<strerror(errno)<<endl;   
        exit(0);  
    }  

    while(1)
    {  
        client_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL);
        if( client_fd >0)
        {
            SocketClient *sock=new SocketClient(client_fd);
            sock->ReceiveData();
        }  
    }
    close(socket_fd);  
    return 0;
}  
