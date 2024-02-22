#include "socket_utils.h"

int main() {
    char out_buf[256] = "Client has connected to server!";

    int server_sock_fd = socket(
        AF_INET,        /* Address family */
        SOCK_STREAM,    /* type will be socket stream */
        0               /* use default (TCP) */
        );           
    if (server_sock_fd < 0) exit_report("Could not create server socket");

    // specify address for the socket
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9002); 
    server_addr.sin_addr.S_un.S_addr = INADDR_ANY;

    // Bind server socket to address (IP and Port)
    /* bind() returns -1 if binding fails */
    if (bind(server_sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) exit_report("Server could not bind to address.");

    puts("Server binding was successful.");
    listen(server_sock_fd, 5);

    int client_sock_fd;
    client_sock_fd = accept(server_sock_fd, NULL, NULL);

    send(client_sock_fd, out_buf, sizeof(out_buf), 0);
    // Recieve data from server

    char in_buf[256];
    recv(server_sock_fd, in_buf, sizeof(in_buf), 0);

    puts("Client completed successfully and the connection will now close.");
    close(server_sock_fd);      /* close the connection */

    return 0;
  return 0;
}