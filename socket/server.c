#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


int main(){

    int server_fd, client_fd, opt=1;
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
    address.sin_family = AF_INET;
    address.sin_port = htons(9876); //Byte order convert


    if( bind(server_fd,(const struct sockaddr *)&address, sizeof(address)) == -1){
        perror("cannot bind (privcliage or busy)");
        exit(1);
    }

    if(listen(server_fd, 10) == -1){ //for 10 req we have backlog 
        perror("Cannot listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    int clientsize = sizeof(client_addr);

    while(1){
        printf("\nwainting for connection ...\n");
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&clientsize);
        printf("New Connection received\n\n");
        char buf[5];
        size_t len;
        send(client_fd, "\n", 1, 0);
        while(1){
            int error = 0;
            socklen_t slen = sizeof(error);
            int ret = getsockopt(client_fd, SOL_SOCKET, SO_ERROR, &error, &slen);
            if(ret != 0){
                perror("Error socket state");
                break;
            }
            len = read(client_fd, buf, 5);
            if(len <= 0)
                break;
            send(client_fd, buf, len, 0);
        }
        close(client_fd);
        
        // in tcp we don't have additional feature in layer 4
    }

    return 0;
    
}