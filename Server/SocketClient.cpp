#include <pthread.h>
#include "SocketClient.h"

void *thread(void *ptr);

SocketClient::SocketClient(int client_fd):sock(client_fd)
{
}

void SocketClient::ReceiveData()
{
    pthread_t id;
    int i,ret;
    ret=pthread_create(&id,NULL,thread,this);
    if(ret!=0)
    {
        cout<<"Create thread error!"<<endl;
        exit(1);
    }
}

void *thread(void *ptr)
{
    SocketClient *client=(SocketClient *)ptr;
    char buf[MAXLINE];  
    int len; 
    while(1)
        {  
            len = recv(client->sock, buf, MAXLINE, 0); 
            if(len==0)
            {
                break;
            }
            string recvStr=string(buf,len);
            cout<<recvStr<<endl;
            string sendStr("recv:");
            sendStr+=recvStr;
            send(client->sock, sendStr.c_str(), sendStr.length(),0);
        }
        client->CloseSocket();  
}

void SocketClient::CloseSocket()
{
    if(this->sock>0)
    {
        close(this->sock);  
    }
}

SocketClient::~SocketClient(void)
{
    CloseSocket();
}
