/**
 * Author : Hu Jingbo
 * Date   : 2021-12-04
 */

#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int fd = socket(AF_IENT, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.
    bind(fd, &addr, sizeof(addr));
    return 0;
}
