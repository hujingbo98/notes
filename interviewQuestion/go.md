<!--
 * @Author : Hu Jingbo
 * @Date   : 2022-01-05
-->

### 协程是什么？为什么要有协程？

协程运行在线程之上，当一个协程执行完成后，可以选择主动让出，让另一个协程运行在当前线程之上。协程并没有增加线程数量，只是在线程的基础之上通过分时复用的方式运行多个协程，而且协程的切换在用户态完成，切换的代价比线程从用户态到内核态的代价小很多。

### TODO:什么是对称协程和非对称协程？

go语言的协程就是对称线程，而腾讯的libco提供的协议就是非对称协程。

### TODO: 协程切换的具体过程？