<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-07
-->

Problem Source : <https://leetcode-cn.com/problems/number-of-segments-in-a-string/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0434_NumberOfSegmentsInAString.cpp>

## 434、字符串中的单词数

统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

```txt
输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
```

## 方法一：遍历字符串

在遍历字符串的过程中，遇到非空格字符 s[i]，如果 i = 0，答案加一，如果 s[i-1] 是空格，答案加一。其它情况跳过。

时间复杂度是 O(n)，其中 n 是字符串的长度。

空间复杂度是 O(1)。

```c++
int countSegments(string s) {
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ' && (0 == i || ' ' == s[i-1]))
            ++ans;
    }
    return ans;
}
```
