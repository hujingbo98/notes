<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-14
-->

Problem Source : <https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/>
Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0524_LongestWordInDictionaryThroughDeleting.cpp>

524、通过删除字母匹配到字典里最长单词

给你一个字符串 s 和一个字符串数组 dictionary 作为字典，找出并返回字典中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字典序最小的字符串。如果答案不存在，则返回空字符串。

示例 1：

```txt
输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
```

示例 2：

```txt
输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
```

提示：

```txt
1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s 和 dictionary[i] 仅由小写英文字母组成
```

方法一：双指针

根据题意，我们需要解决两个问题：

- 如何判断 dictionary 中的字符串 t 是否可以通过删除 s 中的某些字符得到；
- 如何找到长度最长且字典序最小的字符串。

第 1 个问题实际上就是判断 t 是否是 s 的子序列。因此只要能找到任意一种 t 在 s
中出现的方式，即可认为 t 是 s 的子序列。而当我们从前往后匹配时，可以发现每次
贪心地匹配最靠前的字符是最优决策。

第 2 个问题可以通过遍历 dictionary 中的字符串，并维护当前长度最长且字典序最
小的字符串来找到。

```c++
string findLongestWord(string s, vector<string>& dictionary) {
    int n = s.length();
    int m = 0;
    int i = 0;
    int j = 0;
    string ans = "";
    for (const auto& it : dictionary) {
        m = it.length();
        i = 0;
        j = 0;
        while (i < m && j < n) {
            if (it[i] == s[j]) {
                ++i;
            }
            ++j;
        }
        if (i == m) {
            if (ans.length() < it.length() || (ans.length() == it.length()
                && ans > it)) {
                ans = it;
            }
        }
    }
    return ans;
}
```
