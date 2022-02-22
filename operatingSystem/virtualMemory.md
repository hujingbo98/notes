<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-19
-->

# 虚拟存储器

虚拟存储器是硬件异常 、硬件地址翻译、主存、磁盘文件和内核软件的完美交互，它提供了一个大的、一致的和私有的地址空间。

虚拟存储器提供了三个重要的能力：

1. 它将主存看成是一个存储在磁盘上的地址空间的高速缓存，在主存中只保存活动区域，并根据需要在磁盘和主存之间来回传送数据，通过这种方式，它高效地使用了主存。

2. 它为每个金成功提供了一致的地址空间，从而简化了存储器管理。

3. 它保护了每个进程的地址空间不被其它进程破坏。