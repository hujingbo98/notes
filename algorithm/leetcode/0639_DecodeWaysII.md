<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-05
-->

Problem Source : <https://leetcode-cn.com/problems/decode-ways-ii/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0639_DecodeWaysII.cpp>

## 639、解码方法 II

一条包含字母 A-Z 的消息通过以下的方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
要解码一条已编码的消息，所有的数字都必须分组，然后按原来的编码方案反向映射回字母（可能存在多种方式）。例如，"11106" 可以映射为：

"AAJF" 对应分组 (1 1 10 6)
"KJF" 对应分组 (11 10 6)
注意，像 (1 11 06) 这样的分组是无效的，因为 "06" 不可以映射为 'F' ，因为 "6" 与 "06" 不同。

除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符，可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）。例如，编码字符串 "1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19" 中的任意一条消息。对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息。

给你一个字符串 s ，由数字和 '*' 字符组成，返回解码该字符串的方法数目。

由于答案数目可能非常大，返回对 10^9 + 7 取余的结果。

示例 1：

```txt
输入：s = "*"
输出：9
解释：这一条编码消息可以表示 "1"、"2"、"3"、"4"、"5"、"6"、"7"、"8" 或 "9" 中的
任意一条。可以分别解码成字符串 "A"、"B"、"C"、"D"、"E"、"F"、"G"、"H" 和 "I" 。
因此，"*" 总共有 9 种解码方法。
```

示例 2：

```txt
输入：s = "1*"
输出：18
解释：这一条编码消息可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或
"19" 中的任意一条。每种消息都可以由 2 种方法解码（例如，"11" 可以解码成 "AA" 或
"K"）。因此，"1*" 共有 9 * 2 = 18 种解码方法。
```

示例 3：

```txt
输入：s = "2*"
输出：15
解释：这一条编码消息可以表示 "21"、"22"、"23"、"24"、"25"、"26"、"27"、"28" 或
"29" 中的任意一条。"21"、"22"、"23"、"24"、"25" 和 "26" 由 2 种解码方法，但
"27"、"28" 和 "29" 仅有 1 种解码方法。
因此，"2*" 共有 (6 * 2) + (3 * 1) = 12 + 3 = 15 种解码方法。
```

提示：

```txt
1 <= s.length <= 10^5
s[i] 是 0 - 9 中的一位数字或字符 '*'
```

## 方法一：动态规划

对于给定字符串 s，设它的长度是 n，其中的字符从左到右依次是 s[1], s[2], ... , s[n]。我们可以使用动态规划的方法计算出字符串 s 的解码方法数。

具体地，设 f[i] 表示字符串 s 的前 i 个字符的解码方法数。在进行状态转移时，我们考虑最后一次解码使用了 s 中的哪些字符，那么会有下面的两种情况:

1. 我们使用了一个字符对 s[i] 进行解码，那么
   - 如果 s[i] 是 *，那么它对应 [1, 9] 中任意一种编码，有 9 种方案。因此

     ```txt
     f[i] = 9 * f[i-1]
     ```

   - 如果 s[i] 是 0，那么它无法被解码。因此

     ```txt
     f[i] = 0
     ```

   - 如果 s[i] 是 [1, 9]，分别对应一种编码。因此

     ```txt
     f[i] = f[i-1]
     ```

2. 我们使用了两个字符，即 s[i-1] 和 s[i] 进行编码。那么
   - 如果 s[i-1] 和 s[i] 均为 *，那么它们对应这 [11, 19] 以及 [21, 26] 中任意一种编码，共有 15 种方案。因此

     ```txt
     f[i] = 15 * f[i-2]
     ```

   - 如果 s[i-1] 为 *，当 0 <= s[i] <= 6 时，s[i-1] 可以选择 1 和 2；当 7 <= s[i] <= 9 时，s[i-1] 只能选择 1。因此

     ```txt
     f[i] = 2 * f[i-2],       0 <= s[i-1] <= 6
            f[i-2],           7 <= s[i-1] <= 9
     ```

   - 如果 s[i] 为 *，当 s[i-1] = 1 时，s[i] 可以在 [1, 9] 中选择；当 s[i-1] 为 2 时，s[i] 可以在 [1, 6] 中选择；对于其它情况，它们无法解码，因此

     ```txt
            9 * f[i-2]       s[i] = 1
     f[i] = 6 * f[i-2]       s[i] = 2
            0                其它
     ```

   - 如果 s[i-1] 和 s[i] 均不为 *，那么只有 s[i-1] 不为 0 并且 s[i-1] 和 s[i] 组成的数字小于等于 26 时，它们才能被解码。因此

     ```txt
     f[i] = f(i-2)       s[i-1] != 0 and 0 <= s[i-1]s[i] <= 26
          = 0            其它
     ```

将上述结果累加，即可得到 f[i] 的值。在动态规划完成后，最终答案为 f[n]。

动态规划的边界：f[0] = 1，即空字符串有一种解码方法。

时间复杂度是 O(n)，其中 n 是字符串的长度。

空间复杂度是 O(1)。

```c++
int numDecodings(string s) {
    int mod = 1000000007;
    auto case1 = [](char c) {
        if ('*' == c)
            return 9;
        else if ('0' == c)
            return 0;
        return 1;
    };

    auto case2 = [](char c1, char c2) {
        if ('*' == c1 && '*' == c2) {
            return 15;
        } else if ('*' == c1) {
            return c2 <= '6' ? 2 : 1;
        } else if ('*' == c2) {
            if ('1' == c1)
                return 9;
            else if ('2' == c1)
                return 6;
            return 0;
        }
        if (c1 != '0' && (c1 - '0') * 10 + (c2 - '0') <= 26)
            return 1;
        return 0;
    };

    int n = s.size();
    int a = 0, b = 1, c = 1;
    for (int i = 1; i <= n; ++i) {
        c = (long long)b * case1(s[i-1]) % mod;
        if (i > 1)
            c = (c + (long long)a * case2(s[i-2], s[i-1])) % mod;
        a = b;
        b = c;
    }
    return c;
}
```