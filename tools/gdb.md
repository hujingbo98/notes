<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-08-06
-->

# GDB: The GNU Project Debugger

GDB 官网：https://www.gnu.org/software/gdb/

## gdb command

command | comment
:-: | :-
ctrl+x+a | TUI
l (list) | 列出程序源码
r (run) | 运行程序
b (breakpoint) | 设置断点，格式: b [行号/函数名]
info b | 查看断点信息
clear [linenum] | 清除断点
c (continue) | 继续运行程序
s (step) | 单步运行，step into
n (next) | 单步运行，step over
finish | 跳出函数, step out
print <变量/表达式> | 显示变量或表达式的值
display <变量/表达式> | 每次程序停止运行是都显示变量或表达式的值
undisplay | 取消 display

## core dump

在linux下当应用程序发生异常中止退出或者发生崩溃的时候，linux内核会将应用程序在这段运行期间的内存状态等相关信息转存到磁盘，以供系统故障排查或者调试。这个转存的文件叫core dump文件。core dump文件中会记录程序当时的内存调用、堆栈引用、进程和线程调用等信息，可以帮助开发人员和维护人员了解异常发生当时的环境参数和信息，所以core dump对故障排查和bug调试具有重大的意义。

### 如何获得core dump

core dump 是程序发生异常时候，其内存使用副本的转存文件，当你需要调试程具体序出错时的信息时候，它非常有用。当程序发生段错误时，Linux 内核会向磁盘写入一个 core dump 文件。一般情况下系统设置不输出 core dump，所以没有生成 core dump 文件。

如果没有生成core dump文件，请按照以下步骤做设置：

1. 在linux终端执行以下命令 `ulimit -c unlimited`

2. 运行`sysctl -w kernel.core_pattern=/tmp/core-%e.%p.%h.%t`

### gdb 调试 core 文件

1. gdb xxx（应用程序） core ,打开core文件。

2. 输入bt ,就可以查看想要的错误信息了。

3. 输入quit退出gdb。
