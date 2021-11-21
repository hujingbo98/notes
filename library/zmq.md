<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-20
-->

# ZeroMQ

ZeroMQ 是 iMatix 开发的以消息为导向的开源中间件库，其核心由 C 编写，支持 C++、Java 等多种语言的 API，能在大部分现代平台上运行。它的运行速度很快，其异步模型具有高可扩展性。

ZeroMQ 中的零 (Zero) 代表简约并覆盖不同的目标：零代理、零延迟、零管理、零成本等。

## ZeroMQ 的功能

ZeroMQ 提供的功能有 I/O 复用模型、异步 C/S 模型、发布-订阅模型、请求-应答模型、分布式集群架构、代理路由服务、负载均衡等。

## ZeroMQ 的实现原理

### 负载均衡

ZeroMQ 只提供了使用最近最少使用 (Least recently used, LRU) 算法实现的负载均衡模式。