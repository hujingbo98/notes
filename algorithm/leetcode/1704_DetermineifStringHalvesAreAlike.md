<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-12
-->

Problem Source : <https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/>
Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp>

1704、判断字符串的两半是否相似

给你一个偶数长度的字符串 s。将其拆分成长度相同的两半，前一半为 a，后一半为 b。
两个字符串相似的前提是它们都含有相同数目的元音('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')。注意，s 可能同时含有大写和小写字母。如果 a 和 b 相似，返回 true，否则，返回 false。

示例1：

```txt
输入：s = "book"
输出：true
解释：a = "bo" 且 b = "ok"。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
```

示例2：

```txt
输入：s = "textbook"
输出：false
解释：a = "text" 且 b = "book"。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b
不相似。
注意，元音 o 在 b 中出现两次，记为 2 个。
```

示例 3：

```txt
输入：s = "MerryChristmas"
输出：false
```

示例 4：

```txt
输入：s = "AbCdEfGh"
输出：true
```

提示：

```txt
2 <= s.length <= 1000
s.length 是偶数
s 由 大写和小写 字母组成
```

方法一：哈希直接定址法

首先遍历字符串中的字符，然后判定每一个字符是否为元音。这样就可以得到字符串前一半和后一半中的元音的数量。
字符串是由 ASCII 组成的，ASCII 只有 128 种，因此，可以直接开辟一个大小为 128 的布尔类型的数组，将下标为 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' 的元素设置为 true，判断时直接将字符作为下标从数组中取出。

时间复杂度为 O(n)，其中 n 是字符串的长度。
空间复杂度为 O(1)。主要是长度为 128 的哈希数组。

```c++
bool halvesAreAlike(string s) {
    bool arr[128] = {false};
    arr['a'] = arr['e'] = arr['i'] = arr['o'] = arr['u'] = arr['A']
        = arr['E'] = arr['I'] = arr['O'] = arr['U'] = true;

    int ln = 0, rn = 0;
    int len = s.length();
    int len_l = len/2;
    int i;
    for (i = 0; i < len_l; ++i) {
        if (arr[static_cast<int>(s[i])])
            ++ln;
    }
    for (; i < len; ++i) {
        if (arr[static_cast<int>(s[i])])
            ++rn;
    }
    return ln == rn;
}
```
