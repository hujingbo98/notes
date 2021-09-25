<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-25
-->

Problem Source : <https://leetcode-cn.com/problems/longest-common-subsequence/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1143_LongestCommonSubsequence.cpp>

## 1143、最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。如果不存在公共子序列，返回 0。

一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。

两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：

```txt
输入：text1 = "abcde", text2 = "ace"
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
```

示例 2：

```txt
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
```

示例 3：

```txt
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
```

提示：

```txt
1 <= text1.length, text2.length <= 1000
text1 和 text2 仅由小写英文字符组成。
```

## 方法一：动态规划

假设 text1 和 test2 的长度为 m 和 n，创建 m+1 行 n+1 列的二维数组 dp，其中 dp[i][j] 表示 text1[0:i] 和 text2[0:j] 的最长公共子序列的长度。

上述表示中，text1[0:i] 表示 text1 的长度为 i 的前缀，text2[0:j] 表示 text2 的长度为 j 的前缀。

考虑动态规划的边界情况：

- 当 i = 0 时，text1[0:i] 为空，空字符串和任意字符串的最长公共子序列的长度都是 0，因此，对于任意 0 <= j <= n，有 dp[0][j] = 0。
- 当 j = 0 时，text2[0:j] 为空，同理可得，对任意 0 <= i <= m，有 dp[i][0] = 0。

因此动态规划的边界是：当 i = 0 或 j = 0 时，有 dp[i][j] = 0。

当 i > 0 且 j > 0 时，考虑 dp[i][j] 的计算：

- 当 text1[i-1] 等于 text2[j-1] 时，将这两个相同的字符称为公共字符，考虑 text1[0:i-1] 和 text2[0:j-1] 的最长公共子序列，再增加一个字符（即公共字符）即可得到 text1[0:i] 和 text2[0:j] 的最长公共子序列，因此 dp[i][j] = dp[i-1][j-1] + 1。
- 当 text1[i-1] 不等于 text2[j-1] 时，dp[i][j] 应取 dp[i-1][j] 和 dp[i][j-1] 中较大的一项。

因此，可得到状态转移方程：

```txt
            0                            i = 0 或 j = 0
 dp[i][j] = dp[i-1][j-1] + 1             text1[i-1] = text2[j-1]
            max(dp[i-1][j], dp[i][j-1])  text1[i-1] != text2[j-1]
```

最终计算得到 dp[m][n] 即为 text1 和 text2 的最长公共子序列的长度。

```c++
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; ++i) {
        char c1 = text1[i-1];
        for (int j = 1; j <= n; ++j) {
            char c2 = text2[j-1];
            if (c1 == c2) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```
