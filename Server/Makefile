Server : SocketClient.o Server.o
	g++ SocketClient.o Server.o -o Server -lpthread
SocketClient.o : SocketClient.cpp
	g++ -c SocketClient.cpp -o SocketClient.o
Server.o : Server.cpp
	g++ -c Server.cpp -o Server.o
clean : 
	rm SocketClient.o Server.o
