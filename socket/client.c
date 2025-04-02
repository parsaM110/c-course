#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

int main(){

    struct sockaddr_in address;
    int sock_fd;


    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Error creating socket");
        exit(1);
    }

    memset(&address, 0, sizeof(address)); //because it is dynamic 
    address.sin_family = AF_INET;
    address.sin_port = htons(9876);
    //inet_pton : printable 2 network address
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    if(connect(sock_fd, (const struct sockaddr *)&address,sizeof(address)) < 0){
        perror("Failed to connect");
        exit(1);
    }

    // send(sock_fd, "Hello World!\n",15,0);
    char *data = "Hello world\n";
    send(sock_fd, data, strlen(data),0);

    char buf[1024];
    int len = read(sock_fd, buf,1024);
    fwrite(buf, len,1,stdout);

    close(sock_fd);


    return 0;
}