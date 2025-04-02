#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include <sys/socket.h> // General socket datatypes and fucntions
#include <netinet/in.h> // Address (ip, port)
#include <arpa/inet.h> // Internet protocol for working with IP and Tcp
// arpanet was before internet (DARPA)


int main(){

//create a fd(file descriptor) everything in linux is file
    int server_fd, client_socketrt_fd, opt=1;
// each user connect to you, create a new port for them
    struct sockaddr_in address;  //in means internet : and we store ip in here
    // in linux and c, everything is number
    // layer 3 means network : IP
    // now layer 4 TCP or UDP
    // now variation of layer 4 like TCPv1, TCPv2

    // we don't have that for tcp or udp
    if(server_fd = socket(AF_INET, SOCK_STREAM, 0 ) < 0){
        perror("Error creating socket"); //use errno and the detail is there
        exit(1);
    }
    // SOL_SOCKET is level, you are setting for socket or lower layer
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1){
        // socket is for both writing and listening and is generic  
        perror("Error setting socket options");
        exit(1);
    }
    // localhost 127.0.0.1
    // for each network card : <net interface IP>
    // quad zero : 0.0.0.0 for all network interfaces
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(80); //Byte order convert
    // htons (host to network short) 2 Byte (2**16 65536) -> ports are from 0 to 65535 so port is 2Byte
    // all files are big endian previously and still in network mostly not little endian



    // really register socket on linux kernel, given address and memory
    if( bind(server_fd,(const struct sockaddr *)&address, sizeof(address)) == -1){
        perror("cannot bind (privcliage or busy)");
        exit(1);
    }




    return 0;
    
}