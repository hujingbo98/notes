<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-20
-->

# Libevent

Libevent 是 C 语言编写的高速可移植非阻塞 I/O 应用的开源库。

## Libevent 的特点

* 轻量级，专注于网络；

* 高性能，Reactor 事件驱动；

* 跨平台，可移植，支持 Windows、Linux、Mac Os等；

* 支持多种 I/O多路复用技术，epoll、poll、dev/poll、select 和 kqueue 等；

* 支持 I/O，定时器和信号等事件；

## Libevent 的实现

### 定时器

Libevent 的定时器使用最小堆实现。