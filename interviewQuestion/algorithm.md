<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-19
-->

# TODO 算法

### 列举出你所知道的算法？他们之间有什么区别？每种算法的优缺点是什么？分别在什么时候用？怎么优化？

回溯、动态规划、贪心、模拟

回溯法也可以叫做回溯搜索法，它是一种搜索的方式。回溯的本质是穷举，穷举所有可能，然后选出我们想要的答案，如果想让回溯法高效一些，可以加一些剪枝的操作，但也改不了回溯法就是穷举的本质。一般回溯的时间复杂度是 O(k^n)。

贪心的本质是选择每一阶段的局部最优，从而达到全局最优，一般的步骤是将问题分解为若干子问题，找出合适的贪心策略，求解每一个子问题的最优解，将局部最优解堆叠成全局最优解。

动态规划是将问题分解为若干重叠子问题，每个子问题称为状态，每一个状态一定是有上一个状态推导出来的。一般的步骤是先确定动态规划的含义，然后确定递推公式，初始化起始状态，确定推到顺序 (遍历顺序)，然后得到解。

### 动态规划可以得到全局最优解吗？

### 动态规划和贪心的区别？

贪心中每一步最优解一定包含上一步的最优解，上一步之前的最优解则不作保留。整个过程是线性的推到过程。

动态规划有递推公式，他的最优解一定包含某个局部最优解，但不一定是上一个最优解，因此要记录之前的所有的局部最优解。整个过程是树状的搜索过程。

### 动态规划的时间复杂度和空间复杂度？

动态规划一般是通过 n 步迭代计算局部最优解，每一步迭代需要计算 m 个子项，那么时间复杂度是 O(mn)。如果只保存一步迭代的结果，空间复杂度就是 O(m)；如果需要保存 k 步迭代的结果，空间复杂度就是 O(km)。

## 排序？

列举你所知道的排序算法，它们分别的时间、空间、是否稳定？

常考的排序按频率考排序为：快速排序 > 冒泡排序 > 归并排序 > 桶排序

数据量大和数据量小都适用于快排吗？

快速排序的时间复杂度不是稳定的 nlogn，最坏情况会变成 n^2，什么情况下会变为 n^2？怎么解决复杂度恶化问题？

快速排序递归实现时，递归过深会引发什么问题？怎么解决递归层次过深的问题？怎么控制递归深度？如果达到递归深度了还没排完序怎么办？

## 手撕

### 排序

排序方法/源地址|平均时间复杂度|最坏时间复杂度|最好时间复杂度|空间复杂度|稳定性
:-:|:-:|:-:|:-:|:-:|:-:
[冒泡排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/bubbleSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/bubbleSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定
[选择排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/selectionSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/selectionSort.cpp)|O(n^2)|O(n^2)|O(n^2)|O(1)|不稳定
[插入排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/insertionSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/insertionSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定
[希尔排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/shellSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/shellSort.cpp)|O(n^1.3)|O(n^2)|O(n)|O(1)|不稳定
[归并排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/mergeSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/mergeSort.cpp)|O(nlogn)|O(nlogn)|O(nlogn)|O(n)|稳定
[快速排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/quickSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/quickSort.cpp)|O(nlogn)|O(n^2)|O(nlogn)|O(logn)|不稳定

其中 n 表示数列的长度。稳定表示排序后 2 个相等键值的顺序和排序之前它们的顺序相同，反之，则不稳定。

### 数组

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[704](https://leetcode-cn.com/problems/binary-search/)|[二分查找](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0704_BinarySearch.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0704_BinarySearch.cpp)|二分查找|简单
[27](https://leetcode-cn.com/problems/remove-element/)|[移除元素](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0027_RemoveElement.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0027_RemoveElement.cpp)|双指针|简单
[209](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)|[长度最小的子数组](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0209_MinimumSizeSubarraySum.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0209_MinimumSizeSubarraySum.cpp)|滑动窗口|中等

### 字符串

反转字符串：<https://leetcode-cn.com/problems/reverse-string/>

替换空格: <https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/>

[647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

字符串切割

KMP

### 链表

增删改查: <https://leetcode-cn.com/problems/design-linked-list/>

反转链表：<https://leetcode-cn.com/problems/reverse-linked-list/>

相交链表：<https://leetcode-cn.com/problems/intersection-of-two-linked-lists/>

判断链表是否有环：<https://leetcode-cn.com/problems/linked-list-cycle/>

环的入口: <https://leetcode-cn.com/problems/linked-list-cycle-ii/>

### 栈与队列

实现一个栈模板类

实现一个队列模板类

用栈实现队列：<https://leetcode-cn.com/problems/implement-queue-using-stacks/>

用队列实现栈: <https://leetcode-cn.com/problems/implement-stack-using-queues/>

括号匹配: <https://leetcode-cn.com/problems/valid-parentheses/>

### 二叉树

前序遍历：<https://leetcode-cn.com/problems/binary-tree-preorder-traversal/>

中序遍历：<https://leetcode-cn.com/problems/binary-tree-inorder-traversal/>

后序遍历：<https://leetcode-cn.com/problems/binary-tree-postorder-traversal/>

层序遍历：<https://leetcode-cn.com/problems/binary-tree-level-order-traversal/>

二叉树的最大深度: <https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/>

二叉树的最小深度: <https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/>

从前序与中序遍历序列构造二叉树：<https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/>

根据前序和后序遍历构造二叉树：<https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/>

二叉树的最近公共祖先 : <https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/>

对称的二叉树: <https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/>

翻转二叉树：<https://leetcode-cn.com/problems/invert-binary-tree/solution/fan-zhuan-er-cha-shu-by-leetcode-solution/>

### 图

DFS

BFS

最短路径

### 数学

[319. 灯泡开关](https://leetcode-cn.com/problems/bulb-switcher/)

### 其它

[146. LRU 缓存](https://leetcode-cn.com/problems/lru-cache/)

## 哈希什么时候性能不好？

## 哈希表？哈希冲突的解决方案？

## 二叉树？先序中序后序层序遍历？最小深度？最大深度？是否对称？翻转二叉树？公共祖先？前序中序构造二叉树？中序后序构造二叉树？

## 二叉搜索树？平衡二叉树？红黑树？B 树？B+ 树？跳表？

## 红黑树AVL树区别？

## B树和AVL树区别?（两个子树和多个子树）

## B树和B+树区别？B+树优点是什么？B+树的非叶节点上存的什么？（key）所以优点其实是B+占用内存更少（我答了其他优点并不买账）

## LRU？单调栈？图论？数论？博弈论？并查集？最小生成树？线段树？树状数组？字典树？位运算？最小栈？

## 海量数据处理

1. 给定 a、b 两个文件，各存放 50 亿个 url，每个 url 各占 64 字节，内存限制是 4G，让你找出 a、b 文件共同的 url？

答：每个文件的总大小是 5*64G = 320G，4G 内存远远不够，可以对 a 文件的每个 url 哈希取模 512，分别存储到 512 个小文件里，这样每个小文件大概 625 M。如果分布不均衡，换个哈希算法，继续取模即可。文件 b 采取同样的操作，共得到 512 对小文件。不对应的小文件不可能有相同的 url，只需求每对小文件里相同的 url 即可。求每对小文件共同的 url 时，可以将其中一个文件中的 url 存入哈希表中，然后遍历另一个小文件中的 url 查找是否在哈希表中，如果在，那么就是共同的 url，存入 ans 文件即可。

100 亿个 qq 号，找出出现次数最多的 100 个 qq 号，大数问题，hash分块统计再用堆合并；

超过一亿个节点的平衡二叉树（非排序），树节点除了有左右孩子指针，还有父节点指针，树中任取两个节点，向上走肯定相遇于根节点，求他们第一个相遇的节点（口述）

有一亿个数据，分别存在4个服务器里，4个服务器的内存都存满了，用什么办法能排序？（这题跪了）

1到100的和写出能想到的所有算法（写了等差求和、循环和递归实现）

实现memcpy函数（后来面试官说节约时间说下思路，就说了就双指针，然后判断下目标地址和源地址的关系来设置双指针是从头部开始还是从尾部开始，从而避免重叠空间可能导致的问题）

10亿个数怎么排序，口述思路（说了多路归并加堆，堆优化成败者树也行，还好没问败者树的原理）

有5000w行数据，要怎么快速查询？

你刚说的set是按照序进行存储，重载了小于号就可以了，那怎么知道找到相等的元素？（想了一会，没想出来，面试官给提示，关键点在于如何利用小于来实现等于，瞬间领悟，a<b和b<a都是false，那就是等于）

最长回文子串

找两个字符串的相同子串

一个有序数组，如何优化插入。数组贼大，不可以变成链表。