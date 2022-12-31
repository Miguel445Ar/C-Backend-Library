#ifndef __HTTP_SERVER__
#define __HTTP_SERVER__


#include <iostream>
#include <winsock2.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string>

class HTTPServer {
public:
    HTTPServer(const unsigned int port);
    void run();
private:
    WSADATA _wsa;
    SOCKET _serverListener;
    SOCKET _client;
    sockaddr_in _serverListenerAddress;
private:
    void _serverListenerInit(const unsigned int port);
    std::pair<std::string, std::string> _getPath(std::string message);
};



HTTPServer::HTTPServer(const unsigned int port) {
    using std::cout;
    if(WSAStartup(MAKEWORD(2, 2), &_wsa) != 0){
		cout << "Winsock initialization failed\n";
		exit(-1);
	}
    cout << "Winsock initialization successful\n";
    this->_serverListenerInit(port);
}

void HTTPServer::_serverListenerInit(const unsigned int port) {
    using std::cout;
    cout << "Creating server listener socket...\n";
	if((_serverListener = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
		cout << "Error occurred while creating socket\n";
		exit(-1);
	}
	cout << "Server listener socket created successfully\n";
    /**********************CONFIGURACION SOCKADDR_IN**********************/	
	this->_serverListenerAddress.sin_family = AF_INET; // Familia TCP/IP
	this->_serverListenerAddress.sin_port = htons(port); // Puerto
	this->_serverListenerAddress.sin_addr.s_addr = INADDR_ANY; // Cualquier cliente puede conectarse

    if(bind(_serverListener, (struct sockaddr*)&_serverListenerAddress, sizeof(_serverListenerAddress)) == SOCKET_ERROR){
		cout << "Error occurred while binding the server listener socket\n";
		exit(-1);
	}
    cout << "Bind was successfully made\n";
    listen(_serverListener,5);
}

void HTTPServer::run() {
    char httpHeader[22] = "HTTP/1.1 200 OK\r\n\n";
    while(1) {
        char msg[4096] = "";
        int recv_size;
        std::cout << "\nWaiting for requests...\n";
        _client = accept(_serverListener,NULL,NULL);
        std::cout << "Request Accepted from " << _client << "\n";
        if((recv_size = recv(_client, msg, 4095, 0)) == SOCKET_ERROR)
		    printf("Recepcion fallida\n");
	    msg[recv_size] = '\0';
	    std::cout << msg << "\n";
        send(_client,httpHeader,sizeof(httpHeader),0);
        closesocket(_client);
    }
}

/*std::pair<std::string, std::string> HTTPServer::_getPath(std::string message) {

} */

#endif