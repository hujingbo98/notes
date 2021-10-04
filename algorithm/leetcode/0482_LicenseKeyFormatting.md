<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-04
-->

Problem Source : <https://leetcode-cn.com/problems/license-key-formatting/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0482_LicenseKeyFormatting.cpp>

## 482、密钥格式化

有一个密钥字符串 S ，只包含字母，数字以及 '-'（破折号）。其中， N 个 '-' 将字符串分成了 N+1 组。

给你一个数字 K，请你重新格式化字符串，使每个分组恰好包含 K 个字符。特别地，第一个分组包含的字符个数必须小于等于 K，但至少要包含 1 个字符。两个分组之间需要用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。

给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。

示例 1：

```txt
输入：S = "5F3Z-2e-9-w", K = 4
输出："5F3Z-2E9W"
解释：字符串 S 被分成了两个部分，每部分 4 个字符；
     注意，两个额外的破折号需要删掉。
```

示例 2：

```txt
输入：S = "2-5g-3-J", K = 2
输出："2-5G-3J"
解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
```

提示:

```txt
S 的长度可能很长，请按需分配大小。K 为正整数。
S 只包含字母数字（a-z，A-Z，0-9）以及破折号'-'
S 非空
```

## 方法一：数学

首先我们遍历一遍秘钥字符串，可以得到破折号的数量 ndash。则不算破折号的字符串长度 len = s.length - ndash。

当 len mod k 大于 0 时，第一组的字符数量为 len mod k，其它组的字符数量为 k。否则每一组的字符数量都是 k。

遍历字符串，当枚举到 s[i] 时：

- 如果 s[i] = '-'，则跳过。
- 如果是新的一组，则在拼接前先追加一个破折号。
- 将当前字符转换为大写，并追加到答案中。

时间复杂度是 O(n)，其中 n 是字符串的长度。一共需要两次遍历，第一次是获取破折号的数量和非破折号字符的数量。第二次是拼接结果字符串。

空间复杂度是 O(1)，这里的空间复杂度是存储返回值以外的空间。

```c++
string licenseKeyFormatting(string s, int k) {
    int ndash = 0;
    int len;
    for (char c : s)
        if (c == '-')
            ++ndash;
    len = s.length() - ndash;

    int cnt = len % k;
    if (cnt == 0)
        cnt = k;
    string ans;
    for (char c : s) {
        if (c == '-')
            continue;
        if (cnt == 0) {
            ans.push_back('-');
            cnt = k - 1;
        } else {
            --cnt;
        }
        ans.push_back(toupper(c));
    }
    return ans;
}
```
