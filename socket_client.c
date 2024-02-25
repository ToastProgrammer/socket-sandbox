#include "socket_utils.h"

int main() {
    // create socket 
    /* In Unix-like file systems, everything is treated as a file; regular files, directories, devices, sockets, etc.*/
    /*  socket() returns a file descriptor that can be used to refer to that socket, or -1 if it fails */
    int client_sock_fd = socket(
        AF_INET,        /* Address family */
        SOCK_STREAM,    /* type will be socket stream */
        0               /* use default (TCP) */
        );           
    
    if (client_sock_fd < 0) exit_report("Could not create client socket");

    // specify address for the socket
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9002);
    
    #ifdef _WIN32
    server_addr.sin_addr.S_un.S_addr = INADDR_ANY;
    #else
    server_addr.sin_addr.s_addr = INADDR_ANY;
    #endif

    // Connect to server address (IP and Port)
    /* connect() returns -1 if connection fails */
    if (connect(client_sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) exit_report("Client could not connect to server address.");

    // Recieve data from server
    puts("Client connection was successful.");

    char in_buf[256];
    recv(client_sock_fd, in_buf, sizeof(in_buf), 0);

    puts("Client completed successfully and the connection will now close.");
    close(client_sock_fd);      /* close the connection */

    return 0;
}