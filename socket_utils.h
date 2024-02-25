#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <ws2spi.h>
    #include <io.h>
#endif
#ifdef __linux__   /* linux */
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/tcp.h>
    #include <arpa/inet.h>      /* https://pubs.opengroup.org/onlinepubs/7908799/xns/arpainet.h.html */
#endif

void exit_report(const char* msg);