<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-11
-->

Problem Source : <https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/>
Solution Source: <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0600_Non-negativeIntegersWithoutConsecutiveOnes.cpp>

600、不含连续1的非负整数

给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含连续的 1 的个数。

示例 1:

```txt
输入: 5
输出: 5
解释: 
下面是带有相应二进制表示的非负整数<= 5：
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。
```

说明: 1 <= n <= 109

方法：动态规划

非负整数中二进制不包含连续的 1 的数有如下特征：

- 如果此数的最高有效位是 0 位，则只有 0 满足条件，故有 1 个。
- 如果此数的最高有效位是 1 位，则只有 1 满足条件，故有 1 个。
- 如果次数的最高有效位是 2 位，则只有二进制数 10 满足条件，故有 1 个。
- 如果最高有效位为 n 位，则第 n 位必然为 1，第 n-1 必然为 0，则考虑第 n-2 位，有两种情况：
    1. 第 n-2 位为 1，此时，问题可以转化为最高有效位为 n-2 的情形。
    2. 第 n-2 位为 0，此时，问题可以转化为 n-2 之前所以情形的总和。也可以转化为 n-1 的情形，因为 n-1 的情形，第 n-2 位必然为 0。

因此，得到最高有效位为 n 位的二进制不包含连续 1 的数的个数 f(n) 的公式：

```txt
当 0 <= n <= 2 时：
        f(n) = 1
当 n > 2 时：
        f(n) = f(n-2) + f(n-3) + ... + f(0)
             = f(n-2) + f(n-1)
```

非负整数中小于或等于 n 的数的二进制有如下特征(令 n 的最高有效位为 max_max，
第二最高有效位为 max_2，...，最低有效位为 max_min)，令满足题目要求的数为 x：
开始

- 如果 x 的 max_max 小于 n 的 max_max，则 x 必然小于 n。因此，
     ans += f(max_max-1) + f(max_max-2) + ... + f(0) = f(max_max + 1)
- 如果相等，则比较第二有效位
    - 如果 n 的第二有效位与与第一有效位连续，题目要求不能有连续 1，所以 x 与 n 对应的这一位为 0，则 x 必然小于 n。因此，ans += f(max_2-1) + f(max_2-2) + ... + f(0) = f(max_2 + 1)，并且不需要计算后边的位了，也不需要考虑 x 与 n 相等的情况。
    - 如果 n 的第二有效位与与第一有效位不连续，则转换为开始时的处理方式。ans += f(max_2-1) + f(max_2-2) + ... + f(0) = f(max_2 + 1)，然后还需要比较第3有效位，以此类推，直到出现了连续 1 或者最低位比较完。
    - ...
    - 如果最低位比较完还没有出现连续 1 的情况，x 等于 n 则满足题目要求。
       因此，ans += 1

结束

时间复杂度 O(log n)，时间复杂度实际上是 n 的位数，即 log(n)。
空间复杂度 O(log n)，我们需要一个长度为 log n 的数组保存 f(n)。

```c++
int findIntegers(int n) {
    int arr[34] = {1, 1, 1};
    for (int i = 3; i < 34; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int i = 32;
    int ans = 0;
    bool pre = false;
    unsigned int n2 = n;
    while (n2 <<= 1){
        --i;
        if (n2 & 0x80000000) {
            ans += arr[i+1];
            if (pre) {
                return ans;
            }
            pre = true;
            continue;
        }
        pre = false;
    }
    ++ans;
    return ans;
}
```
