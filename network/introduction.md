<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-04
-->

# Introduction

## OSI 七层协议

OSI 七层协议包括：物理层，数据链路层，网络层，传输层，会话层，表示层，应用层。

物理层主要解决两台物理机之间的通信，通过二进制比特流的传输来实现，二进制数据表现为电流电压上的强弱，到达目的地再转化为二进制机器码。网卡、集线器工作在这一层。

数据链路层在不可靠的物理介质上提供可靠的传输，接收来自物理层的比特流形式的数据，并封装成帧，传送到上一层；同样，也将来自上层的数据帧，拆装为比特流形式的数据转发到物理层。这一层在物理层提供的比特流的基础上，通过差错控制、流量控制方法，使有差错的物理线路变为无差错的数据链路。提供物理地址寻址功能。交换机工作在这一层。

网络层将网络地址翻译成对应的物理地址，并决定如何将数据从发送方路由到接收方，通过路由选择算法为分组通过通信子网选择最佳路径。路由器工作在这一层。

传输层提供了进程间的逻辑通信，传输层向高层用户屏蔽了下面网络层的核心细节，使应用程序看起来像是在两个传输层实体之间有一条端到端的逻辑通信信道。

会话层建立会话：身份验证，权限鉴定等； 保持会话：对该会话进行维护，在会话维持期间两者可以随时使用这条会话传输局； 断开会话：当应用程序或应用层规定的超时时间到期后，OSI会话层才会释放这条会话。

表示层对数据格式进行编译，对收到或发出的数据根据应用层的特征进行处理，如处理为文字、图片、音频、视频、文档等，还可以对压缩文件进行解压缩、对加密文件进行解密等。

应用层提供应用层协议，如HTTP协议，FTP协议等等，方便应用程序之间进行通信。

## TCP/IP 协议族

TCP/IP 协议族包括四层，分别是链路层、网络层、传输层、应用层。

链路层对应 OSI 的物理层和数据链路层，通常包括操作系统中的设备驱动程序和计算机中对应的网络接口卡。

网络层协议包括 IP 协议（网际协议），ICMP 协议（Internet 互联网控制报文协议），以及 IGMP 协议（Internet 组管理协议）。

传输层协议包括 TCP 协议（传输控制协议），UDP 协议（用户数据报协议）。

应用层协议包括 Telenet 远程登录，FTP 文件传输协议，HTTP 超文本协议，SMTP 简单邮件传输协议，SNMP 简单网络管理协议。

## 字节序

字节序(Byte order)是指多字节数据在内存中存储或在网络传输中时的存储顺序，低地址存低位为小端(Little endian)，高地址存低位为大端(Big endian)。

### 判断字节序

让一个short类型数据i=0x0001，假设i的两个字节地址为0x4000和0x4001，此时0x01称为低位字节，0x00称为高位字节，0x4000称为低地址，0x4001称为高地址。如果0x01存储到地址0x4000处，则是小端，否则是大端。

使用c++判断字节序，如下所示。

```c++
#include <stdio.h>

bool is_little_endian()
{
    union tt
    {
        short a;
        char b;
    } c;
    c.a = 1;
    return 1 == c.b ? true : false;
}

int main(int argc, char const *argv[])
{
    if (is_little_endian)
        printf("Little endian.\n");
    else
        printf("Big endian.\n");

    return 0;
}
```

### 网络字节序

网络字节序标准规定为大端字节序，不同平台上会对主机字节序进行转换后再进行传送，到主机后再转换为主机字节序，这样数据的传输就不会产生字节序不对的问题了。

### 字节序转换

字节序转换函数:

```c++
#include <arpa/inet.h>
/* h--host, n--network, s--short, l--long */
unit32_t htonl (unit32_t hostlong);
unit16_t htons (unit16_t hostshort);
unit32_t ntohl (unit32_t netlong);
unit16_t ntohs (unit16_t netshort);
```

Example:

```c++
#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;
    printf("%0x_%0x_%0x_%0x\n",p[0],p[1],p[2],p[3]);

    unsigned int y = htonl(x);
    p = (unsigned char*)&y;
    printf("%0x_%0x_%0x_%0x\n",p[0],p[1],p[2],p[3]);

    return 0;
}
```

Output:

```base
78_56_34_12
12_34_56_78
```