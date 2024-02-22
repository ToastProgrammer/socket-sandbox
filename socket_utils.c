#include "socket_utils.h"

void exit_report(const char* msg) {
    perror(msg);
    exit(-1);
}