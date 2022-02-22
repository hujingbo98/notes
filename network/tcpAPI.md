# Socket API

### close 函数

通常调用 close 函数来关闭套接字，并终止TCP连接。

```c++
#include "unistd.h"
int close(int fd);
```

close一个TCP套接字的默认行为是把该套接字标记成已关闭，然后立即返回的调用进程。该套接字描述符不能再由调用进程使用。然而TCP将尝试发送已排队等待发送到对端的任何数据，发送完毕后将执行正常的TCP连接终止序列。

**注意：** 多进程并发服务器中父进程关闭已连接套接字只是导致相应描述符的引用计数减1。既然引用计数大于0，这个close调用并不引发TCP的四分组连接终止序列。

如果我们确实想在某个TCP连接上发送FIN，那么可以调用shutdown函数。

### shutdown 函数

终止TCP连接的通常方法是close函数。不过close有两个限制，却可以使用shutdown函数来避免。

(1) close把描述符的引用计数减1，仅当该计数变为0时才执行TCP的正常连接终止序列。使用shutdown可以不管引用计数就激发TCP的正常连接终止序列。

(2) close终止读和写两个方向上的传输。既然TCP是全双工的，有时候我们需要告知对端我们已经完成了数据发送，但对端仍有数据发送给我们。这时可以使用shutdown函数，使连接处于半关闭状态。

```c
#include <sys/socket.h>
/* The following constants should be used for the second parameter of
   `shutdown'.  */
enum
{
  SHUT_RD = 0,		/* No more receptions.  */
#define SHUT_RD		SHUT_RD
  SHUT_WR,		/* No more transmissions.  */
#define SHUT_WR		SHUT_WR
  SHUT_RDWR		/* No more receptions or transmissions.  */
#define SHUT_RDWR	SHUT_RDWR
};
/* Shut down all or part of the connection open on socket FD.
   HOW determines what to shut down:
     SHUT_RD   = No more receptions;
     SHUT_WR   = No more transmissions;
     SHUT_RDWR = No more receptions or transmissions.
   Returns 0 on success, -1 for errors.  */
int shutdown (int fd, int how);
```

更多关于close和shutdown的说明：

1. 只要TCP栈的读缓冲里还有未读取（read）数据，则调用close时会直接向对端发送RST。

2. shutdown与socket描述符没有关系，即使调用shutdown(fd, SHUT_RDWR)也不会关闭fd，最终还需close(fd)。

3. 可以认为shutdown(fd, SHUT_RD)是空操作，因为shutdown后还可以继续从该socket读取数据，这点也许还需要进一步证实。在已发送FIN包后write该socket描述符会引发EPIPE/SIGPIPE。

4. 当有多个socket描述符指向同一socket对象时，调用close时首先会递减该对象的引用计数，计数为0时才会发送FIN包结束TCP连接。shutdown不同，只要以SHUT_WR/SHUT_RDWR方式调用即发送FIN包。

5. SO_LINGER与close，当SO_LINGER选项开启但超时值为0时，调用close直接发送RST（这样可以避免进入TIME_WAIT状态，但破坏了TCP协议的正常工作方式），SO_LINGER对shutdown无影响。

6. TCP连接上出现RST与随后可能的TIME_WAIT状态没有直接关系，主动发FIN包方必然会进入TIME_WAIT状态，除非不发送FIN而直接以发送RST结束连接。

应用场景：

1. 想要使用TCP来进行单向通信是需要使用shutdown函数。

2. 当我们想要确保所有写好的数据已经发送成功时。如果在发送数据的过程中，网络断开或出现异常，系统read函数不一定会返回异常。可以使用shutdown函数来确定数据是否发送成功，因为调用shutdown时，只有在缓冲区的数据全部发送成功后才会返回。

3. 当我们的程序使用了fork()或者使用多线程时，你想防止其他线程或进程访问到该资源，又或者你想立刻关闭这个socket，那么可以用shutdown()来实现。