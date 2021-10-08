<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-08
-->

Problem Source : <https://leetcode-cn.com/problems/repeated-dna-sequences/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0187_RepeatedDNASequences.cpp>

## 187、重复的DNA序列

所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。
在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例 1：

```txt
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
```

示例 2：

```txt
输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]
```

提示：

```txt
0 <= s.length <= 10^5
s[i] 为 'A'、'C'、'G' 或 'T'
```

## 方法一：哈希表

我们可以使用哈希表统计 s 所有长度为 10 的子串的出现次数，在统计的过程中，将出现次数等于两次的子串存入答案中返回。

时间复杂度是 O(nl)，其中 n 是 s 的长度，l = 10 是子串的长度。我们需要截取出 n - l + 1 个子串，截取每个子串的时间为 O(l)。

空间复杂度是 O(nl)。

```c++
vector<string> findRepeatedDnaSequences(string s) {
    const int l = 10;
    unordered_map<string, int> m;
    vector<string> ans;
    int n = s.length();
    for (int i = 0; i <= n - l; ++i) {
        string sub = s.substr(i, l);
        if (++m[sub] == 2)
            ans.push_back(sub);
    }
    return ans;
}
```

## 方法二：哈希表 + 滑动窗口 + 位运算

由于 s 中只有 4 个字符，我们可以将每个字符用 2 个比特表示，即：

- A 表示为二进制 00；
- C 表示为二进制 01；
- G 表示为二进制 10；
- T 表示为二进制 11。

如此一来，一个长度为 10 的字符串就可以用 20 个比特表示，我们可以使用一个 32 比特的 int 类型的低 20 位来表示一个长度为 10 子串。

因此，我们可以将方法一中的哈希表改为存储每个长为 10 的子串的整数表示。

如果我们对每个长为 10 的子串都单独计算其整数表示，那么时间复杂度仍和方法一一样为 O(nl)。为了优化时间复杂度，我们可以用一个大小固定为 10 的滑动窗口来计算子串的整数表示。

设当前滑动窗口对应的整数表示为 x，我们需要计算下一个子串时，就将滑动窗口向右移动一位，此时会有一个新的字符进入窗口，以及窗口最左边的字符离开窗口，这些操作对应的位运算，按计算顺序表示如下：

- 滑动窗口向右移动一位：x = x << 2，由于每个字符用 2 个比特表示，所以要左移 2 位。
- 一个新的字符 c 进入窗口：x = x | bin[c]，这里 bin[c] 为字符 c 的对应二进制。
- 窗口最左边的字符离开窗口：x = x & ((1 << 20) - 1)，由于我们只考虑 x 的低 20 位比特，需要将其余位置零。

这三步合并，就可以用 O(1) 的时间计算出下一个子串的整数表示，即 `x = ((x << 2) | bin[c]) & ((1 << 20) - 1)`

时间复杂度是 O(n)，其中 n 是 s 的长度。

空间复杂度是 O(n)。

```c++
vector<string> findRepeatedDnaSequences_V2(string s) {
    const int l = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int n = s.length();
    vector<string> ans;

    int x = 0;
    for (int i = 0; i < n && i < l - 1; ++i) {
        x = (x << 2) | bin[s[i]];
    }
    unordered_map<int, int> m;
    for (int i = 0; i <= n - l; ++i) {
        x = ((x << 2) | bin[s[i + l - 1]]) & ((1 << 20) - 1);
        if (++m[x] == 2)
            ans.push_back(s.substr(i, l));
    }
    return ans;
}
```
