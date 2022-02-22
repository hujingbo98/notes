<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-19
-->

## C 语言

### 描述一下 GCC 的编译过程?

gcc编译过程分为4个阶段：预处理、编译、汇编、链接。

预处理：头⽂件包含、宏替换、条件编译、删除注释。

编译：主要进⾏词法、语法、语义分析等，检查⽆误后将预处理好的⽂件编译成汇编⽂件。

汇编：将汇编⽂件转换成⼆进制⽬标⽂件。

链接：将项⽬中的各个⼆进制⽂件+所需的库+启动代码链接成可执⾏⽂件。

### 内存的最小存储单位以及内存的最小计量单位分别是?

内存的最小存储单位是二进制位，最小计量单位是字节。

### 描述一下变量的命名规则?

变量名可以由字母、数字和下划线组成，但不能以数字开头。

### 变量的声明和定义有什么区别？

声明变量不需要建立存储空间，变量的定义需要建立存储空间。

### 谈谈 C 语言中有符号和无符号的区别?

有符号：数据的最高位为符号位，0 表示正数，1 表示负数。

无符号：数据的最高位不是符号位，而是数据的一部分。

### 谈谈计算机中补码的意义?

1. 统一了零的编码

2. 将符号位与其它位统一处理

3. 将减法运算换成加法运算

### 数组的分类?

数组可以分为静态数组和动态数组。

静态数组：在程序运行前就确定了数组的大小，运行过程中不能更改数组的大小。

动态数组：主要是在堆区申请的空间，数组的大小是在程序运行过程中确定，可以更改数组的大小。

### 描述一下一维数组不初始化、部分初始化、完全初始化的不同点?

不初始化：如果是局部数组，数组元素的内容随机，如果是全局数组，数组的元素内容为 0。

部分初始化：未初始化的部分自动补 0。

完全初始化：如果一个数组全部初始化，可以省略元素的个数，数组的大小有初始化的个数确定。

### 谈谈数组名作为类型、作为地址、对数组名取地址的区别？

数组名作为类型：代表的是整个数组的大小。

数组名作为地址：代表的是数组的首元素地址。

对数组名取地址：代表的是数组的首地址。

### 谈谈你对二维数组在物理上以及在逻辑上的数组维度理解

二维数组在逻辑上市二维的，在物理上是一维的。

### 描述一下函数的定义与函数的声明的区别

函数的定义：是指对函数功能的确立，包括指定函数名、函数类型、形参及其类型、函数体等，它是一个完整的、独立的函数单位。

函数的声明：是把函数的名字、函数类型、以及形参的个数、类型和顺序通知编译系统，以便在对包含函数调用的语句时，据此对其进行对照检查。

### 描述一下指针与指针变量的区别

指针：内存中的每一个字节都会分配一个 32 位或 64 位的编号，这个编号就是地址，而指针就是内存单元的编号。

指针变量：本质是变量，只是该变量存放的是空间的地址编号。

### 描述一下 32 位或 64 位平台下指针的大小

32 位平台：任意类型的指针大小为 4 字节。

64 位平台：任意类型的指针大小为 8 字节。

### 描述一下指针数组的概念

指针数组本质是数组，只是数组的每一个元素都是一个指针（地址）。

### 描述一下普通局部变量、普通全局变量、静态局部变量、静态全局变量的区别

普通局部变量存在栈区，不初始化内容随机，只在定义所在的复合语句中有效，复合语句结束变量空间释放。

普通全局变量存在全局区，不初始化内容为 0，进程结束空间才被释放，能被当前源⽂件或其他源⽂件使⽤，只是其他源⽂件使⽤的时候，需要使⽤ extern 声明。

静态局部变量存在全局区，不初始化内容为 0，进程结束空间才被释放，只能在定义所在的复合语句中有效

静态全局变量存在全局区，不初始化内容为 0，进程结束空间才被释放，只能被当前源⽂件使⽤。

### 描述一下内存分区

程序在运⾏前：分为代码区、BSS 段 (未初始化数据区)、data 段 (初始化数据区)

程序在运⾏后：堆区、栈区、全局区 (静态区)、⽂字常量区、代码区

### 函数参数的入栈顺序，函数栈帧内存的分布？

### 结构体和共用体的区别？

结构体的成员拥有独立的空间，共用体的成员共享同一块空间，但是每个共用体成员能访问共用区的空间大小是由成员自身的类型决定。

### 谈谈文件的分类

文件分为二进制文件和文本文件

二进制文件基于值编码，需要根据具体的应用才能知道某个值具体的含义。

文本文件基于字符编码，一个字节一个字符，可以通过记事本打开。

### 文件缓冲区刷新方式有几种？

行刷新、满刷新、强制刷新、关闭刷新

### 哪些情况下会出现野指针？

指针变量为初始化、指针释放空间后未置空、指针操作超越变量的作用域。

### 如何理解指针作为函数的输入和输出特性

输入特性：主调函数分配空间，被调函数使用该空间。

输出特性：被调函数分配空间，主调函数使用该空间。

### 如何理解结构体的浅拷贝和深拷贝

当结构体中出现指针成员的时候容易出现浅拷贝与深拷贝问题。

浅拷⻉就是，两个结构体变量的指针成员指向同⼀块堆区空间，在各个结构体变量释放的时候会出现多次释放同⼀段堆区空间。

深拷⻉就是，让两个结构体变量的指针成员分别指向不同的堆区空间，只是空间内容拷⻉⼀份，这样在各个结构体变量释放的时候就不会出现多次释放同⼀段堆区空间的问题。

### 字节对齐为什么会提高访问速度？

### 描述一下结构体字节对齐规则

结构体的对其值有，自身对其值、指定对齐值、有效对齐值。

自身对齐值：数据类型本身的对齐值，例如 char 类型的自身对齐值是 1， short 类型是 2。

指定对齐值：编译器或程序员指定的对齐值，32 位机器的指定对齐值默认是 4。程序员使用 #pargama pack(n) 来指定对齐值。

有效对齐值：自身对齐值和指定对齐值中较小的一个。

对齐有两个规则：

1. 不但结构体成员有有效对齐值，结构体本身也有有效对齐值，这主要是考虑结构体的数组，对于结构体或者类，要将其补齐为其有效对齐值的整数倍。结构体的有效对齐值是其最大数据成员的自身对齐值。

2. 存放成员的起始位置必须是该成员有效对齐值的整数倍。

### 什么是宏函数，以及其作用

在项⽬中，经常把⼀些短⼩⽽⼜频繁使⽤的函数写成宏函数，这是由于宏函数没有普通函数参数压栈、跳转、返回等的开销，可以调⾼程序的效率。 宏通过使⽤参数，可以创建外形和作⽤都与函数类似地类函数宏 (function-like macro)。宏的参数也⽤圆括号括起来，来保证宏函数的完整性。

### 如何理解库函数？

库是已经写好的、成熟的、可复⽤的代码。每个程序都需要依赖很多底层库，不可能每个⼈的代码从零开始编写代码，因此库的存在具有⾮常重要的意义。 在我们的开发的应⽤中经常有⼀些公共代码是需要反复使⽤的，就把这些代码编译为库⽂件。库可以简单看成⼀组⽬标⽂件的集合，将这些⽬标⽂件经过压缩打包之后形成的⼀个⽂件。

### strcat、strncat、strcpy、strncpy、memcpy、memset 的内部实现？

strcat 是连接两个字符串，内部实现是：

```c
/* Append SRC on the end of DEST.  */
char *
STRCAT (char *dest, const char *src)
{
  strcpy (dest + strlen (dest), src);
  return dest;
}
```

strncat 是连接两个字符串的一定数量的字符，内部实现是：

```c
char *
STRNCAT (char *s1, const char *s2, size_t n)
{
  char *s = s1;

  /* Find the end of S1.  */
  s1 += strlen (s1);

  size_t ss = __strnlen (s2, n);

  s1[ss] = '\0';
  memcpy (s1, s2, ss);

  return s;
}
```

strcpy 的内部实现是：

```c
/* Copy SRC to DEST.  */
char *
STRCPY (char *dest, const char *src)
{
  return memcpy (dest, src, strlen (src) + 1);
}
```

strncpy 的内部实现是：

```c
char *
STRNCPY (char *s1, const char *s2, size_t n)
{
  size_t size = __strnlen (s2, n);
  if (size != n)
    memset (s1 + size, '\0', n - size);
  return memcpy (s1, s2, size);
}
```

memcpy 的内部实现是：

```c
void *
MEMCPY (void *dstpp, const void *srcpp, size_t len)
{
  unsigned long int dstp = (long int) dstpp;
  unsigned long int srcp = (long int) srcpp;

  /* Copy from the beginning to the end.  */

  /* If there not too few bytes to copy, use word copy.  */
  if (len >= OP_T_THRES)
    {
      /* Copy just a few bytes to make DSTP aligned.  */
      len -= (-dstp) % OPSIZ;
      BYTE_COPY_FWD (dstp, srcp, (-dstp) % OPSIZ);

      /* Copy whole pages from SRCP to DSTP by virtual address manipulation,
	 as much as possible.  */

      PAGE_COPY_FWD_MAYBE (dstp, srcp, len, len);

      /* Copy from SRCP to DSTP taking advantage of the known alignment of
	 DSTP.  Number of bytes remaining is put in the third argument,
	 i.e. in LEN.  This number may vary from machine to machine.  */

      WORD_COPY_FWD (dstp, srcp, len, len);

      /* Fall out and copy the tail.  */
    }

  /* There are just a few bytes to copy.  Use byte memory operations.  */
  BYTE_COPY_FWD (dstp, srcp, len);

  return dstpp;
}
```

memset 的内部实现是：

```c
void *
inhibit_loop_to_libcall
MEMSET (void *dstpp, int c, size_t len)
{
  long int dstp = (long int) dstpp;

  if (len >= 8)
    {
      size_t xlen;
      op_t cccc;

      cccc = (unsigned char) c;
      cccc |= cccc << 8;
      cccc |= cccc << 16;
      if (OPSIZ > 4)
	/* Do the shift in two steps to avoid warning if long has 32 bits.  */
	cccc |= (cccc << 16) << 16;

      /* There are at least some bytes to set.
	 No need to test for LEN == 0 in this alignment loop.  */
      while (dstp % OPSIZ != 0)
	{
	  ((byte *) dstp)[0] = c;
	  dstp += 1;
	  len -= 1;
	}

      /* Write 8 `op_t' per iteration until less than 8 `op_t' remain.  */
      xlen = len / (OPSIZ * 8);
      while (xlen > 0)
	{
	  ((op_t *) dstp)[0] = cccc;
	  ((op_t *) dstp)[1] = cccc;
	  ((op_t *) dstp)[2] = cccc;
	  ((op_t *) dstp)[3] = cccc;
	  ((op_t *) dstp)[4] = cccc;
	  ((op_t *) dstp)[5] = cccc;
	  ((op_t *) dstp)[6] = cccc;
	  ((op_t *) dstp)[7] = cccc;
	  dstp += 8 * OPSIZ;
	  xlen -= 1;
	}
      len %= OPSIZ * 8;

      /* Write 1 `op_t' per iteration until less than OPSIZ bytes remain.  */
      xlen = len / OPSIZ;
      while (xlen > 0)
	{
	  ((op_t *) dstp)[0] = cccc;
	  dstp += OPSIZ;
	  xlen -= 1;
	}
      len %= OPSIZ;
    }

  /* Write the last few bytes.  */
  while (len > 0)
    {
      ((byte *) dstp)[0] = c;
      dstp += 1;
      len -= 1;
    }

  return dstpp;
}
```
