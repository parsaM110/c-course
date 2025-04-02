#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


int main(){

    int server_fd, client_socketrt_fd, opt=1;
    struct sockaddr_in address;  
    if( (server_fd = socket(AF_INET, SOCK_STREAM, 0 )) < 0){
        perror("Error creating socket"); 
        exit(1);
    }
    printf("socket_fd  = %d\n", server_fd);
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1){
        exit(1);
    }
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(80); //Byte order convert


    if( bind(server_fd,(const struct sockaddr *)&address, sizeof(address)) == -1){
        perror("cannot bind (privcliage or busy)");
        exit(1);
    }


    return 0;
    
}