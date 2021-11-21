<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-21
-->

# 反应器模式

反应器 (Reactor) 模式是一种事件处理模式，用于处理由一个或多个输入并发传递给服务处理程序的服务请求。然后，服务处理程序对传入的请求进行多路分解，并将它们同步分派到相关联的请求处理程序。

它和普通函数调用的不同之处在于，应用程序不是主动的调用某个 API 完成处理，而是恰恰相反，Reactor 逆置了事件处理流程，应用程序需要提供相应的接口并注册到 Reactor 上，如果相应的事件发生，Reactor 将主动调用应用程序注册的接口，这些接口又称为回调函数 (callback function)。

从 C/C++ 的 Libevent 到 Java 的 Netty 再到 Python 的 Twisted 等，使用的都是 Reactor 模式。

## Reactor 的优点

Reactor 模式是编写高性能网络服务器的必备技术之一，它具有如下的优点：

1. 响应快，不必为单个同步时间所阻塞，虽然 Reactor 本身依然是同步的；

2. 实现简单，可以最大程度的避免多线程的成本和同步互斥问题；

3. 可扩展性，可以方便的通过增加 Reactor 实例个数来充分利用 CPU 资源；

4. 可复用性，reactor 框架本身与具体事件处理逻辑无关，具有很高的复用性；

## Reactor 框架

使用 Reactor 模型，必备的几个组件：事件源、多路复用机制、反应器、事件处理程序。

1. 事件源 (Event Source)

Linux 上是文件描述符，Windows 上就是 Socket 或者 Handle。这里统称句柄，程序在指定的句柄上注册关心的事件，比如 I/O 事件。

2. 事件多路分发器 (Event Demultiplexer)

程序首先将其关心的事件源及其事件注册到事件多路分发器上，当有事件到达时，事件多路分发器会发出通知在已经注册的句柄中，一个或多个句柄的事件已经就绪，程序收到通知后，就可以在非阻塞的情况下对事件进行处理了。例如，由操作系统提供的 I/O 多路复用机制，比如 select 和 epoll。

3. 反应器 (Reactor)

Reactor 提供事件管理的接口，内部使用事件多路分发器注册、注销事件，并运行事件循环，当有事件进入就绪时，调用注册事件的回调函数处理事件。

4. 事件处理程序 (Event Handler)

事件处理程序提供了一组接口，每个接口对应了一种类型的事件，供 Reactor 在相应的事件发生时调用，执行相应的事件处理。通常它会绑定一个有效的句柄。

下面是两种典型的 Event Handler 类声明方式，二者互有优缺点。

```cpp
class Event_Handler 
{ 
public: 
    virtual void handle_read() = 0; 
    virtual void handle_write() = 0; 
    virtual void handle_timeout() = 0; 
    virtual void handle_close() = 0; 
    virtual HANDLE get_handle() = 0; 
    // ...
}; 
class Event_Handler 
{ 
public: 
    // events maybe read/write/timeout/close .etc 
    virtual void handle_events(int events) = 0; 
    virtual HANDLE get_handle() = 0; 
    // ... 
};
```