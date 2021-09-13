<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-12
-->

Problem Source : <https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/>
Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp>

1221、分割平衡字符串

在一个平衡字符串 中，'L' 和 'R' 字符的数量是相同的。
给你一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
注意：分割得到的每个字符串都必须是平衡字符串。
返回可以通过分割得到的平衡字符串的最大数量。

示例 1：

```txt
输入：s = "RLRRLLRLRL"
输出：4
解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL"，每个子字符串中都包含相同数量的
'L' 和 'R' 。
```

示例 2：

```txt
输入：s = "RLLLLRRRLR"
输出：3
解释：s 可以分割为 "RL"、"LLLRRR"、"LR"，每个子字符串中都包含相同数量的 'L' 
和 'R'。
```

示例 3：

```txt
输入：s = "LLLLRRRR"
输出：1
解释：s 只能保持原样 "LLLLRRRR".
```

示例 4：

```txt
输入：s = "RLRRRLLRLL"
输出：2
解释：s 可以分割为 "RL"、"RRRLLRLL"，每个子字符串中都包含相同数量的 'L' 和 'R'。
```

提示：

```txt
1 <= s.length <= 1000
s[i] = 'L' 或 'R'
s 是一个 平衡 字符串
```

方法：贪心

由题意知，对于一个平衡字符串 s，如果分割成两个非空子串，若其中一个是平衡字符串，则另一个的 L 和 R 字符的数量必然是相同的，所以也一定是一个平衡字符串。为了最大化分割数量，可以不断循环，每次中字符串中分割出一个最短的平衡字符串，由于剩下的字符串也是平衡字符串，可以将其当作 s 继续分割，直至 s 为空时，结
束循环。

代码实现中，可以在遍历 s 时，维护一个 lCount 保存已遍历的字符串中 L 的数量，rCount 保存已遍历的字符串中 R 的数量，当 lCount 和 rCount 非零并相等时，就说明找到了一个平衡字符串。
注意：判断 lCount 和 rCount 非零是因为题目没说明字符串 s 中是否有其它字符。

时间复杂度为 O(n)，空间复杂度为 O(1)。

```c++
int balancedStringSplit(string s) {
    int ans = 0;
    int lCount = 0, rCount = 0;
    int sLen = s.length();
    for (int i = 0; i < sLen; ++i) {
        if ('L' == s[i])
            ++lCount;
        else if ('R' == s[i])
            ++rCount;
        if (lCount && lCount == rCount) {
            ++ans;
            lCount = rCount = 0;
        }
    }
    return ans;
}
```
