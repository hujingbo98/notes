<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-23
-->

Problem Source : <https://leetcode-cn.com/problems/power-of-three/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0326_PowerOfThree.cpp>

## 326、3的幂

给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true；否则，返回 false。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

示例 1：

```txt
输入：n = 27
输出：true
```

示例 2：

```txt
输入：n = 0
输出：false
```

示例 3：

```txt
输入：n = 9
输出：true
```

示例 4：

```txt
输入：n = 45
输出：false
```

提示：

```txt
-2^31 <= n <= 2^31 - 1
```

## 方法一：试除法

我们可以不断的将 n 除以 3，直到 n = 1。如果此过程中 n 无法被 3 整除，就说明 n 不是 3 的幂。

本题中的 n 可以为负数或 0，可以提前判断该情况并返回 false，也可以进行试除，因为负数或 0 也无法通过多次除以 3 得到 1。

时间复杂度是 O(log n)。当 n 是 3 的幂时，需要除以 3 的次数为 log3(n) = O(log n)；当 n 不是 3 的幂时，需要除以 3 的次数小于该值。

空间复杂度是 O(1)。

```c++
bool isPowerOfThree(int n) {
    while (n && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}
```

## 方法二：判断是否为最大 3 的幂的约数

在题目给定的 32 位有符号整数的范围内，最大的 3 的幂为 3^19 = 1162261467。我们只需判断 n 是否为 3^19 的约数即可。

注意，这里需要特殊判断 n 是负数或 0 的情况。

时间复杂度是 O(1)。

空间复杂度是 O(1)。

```c++
bool isPowerOfThree_V2(int n) {
    return n > 0 && 1162261467 % n == 0;
}
```
