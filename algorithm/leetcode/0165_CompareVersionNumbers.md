<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-09
-->

Problem Source : <https://leetcode-cn.com/problems/compare-version-numbers>
Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0165_CompareVersionNumbers.cpp>

165、比较版本号

给你两个版本号 version1 和 version2 ，请你比较它们。
版本号由一个或多个修订号组成，各修订号由一个'.'连接。每个修订号由多位数字组成，可能包含前导零。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0，下一个修订号下标为 1，以此类推。例如，2.5.33 和 0.1 都是有效的版本号。比较版本号时，请按从左到右的顺序依次比较它们的修订号。
比较修订号时，只需比较忽略任何前导零后的整数值。也就是说，修订号 1 和修订号 001 相等。如果版本号没有指定某个下标处的修订号，则该修订号视为 0。例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1，0 < 1。

返回规则如下：

* 如果 version1 > version2 返回 1，
* 如果 version1 < version2 返回 -1，
* 除此之外返回 0。

示例 1：

```txt
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，"01" 和 "001" 都表示相同的整数 "1"
```

示例 2：

```txt
输入：version1 = "1.0", version2 = "1.0.0"
输出：0
解释：version1 没有指定下标为 2 的修订号，即视为 "0"
```

示例 3：

```txt
输入：version1 = "0.1", version2 = "1.1"
输出：-1
解释：version1 中下标为 0 的修订号是 "0"，version2 中下标为 0 的修订号是 "1" 。0 < 1，所以 version1 < version2
```

示例 4：

```txt
输入：version1 = "1.0.1", version2 = "1"
输出：1
```

示例 5：

```txt
输入：version1 = "7.5.2.4", version2 = "7.5.3"
输出：-1
```

提示：

* 1 <= version1.length, version2.length <= 500
* version1 和 version2 仅包含数字和 '.'
* version1 和 version2 都是有效版本号
* version1 和 version2 的所有修订号都可以存储在 32 位整数 中

方法一：字符串分割

可以将版本号按照点号分割成修订号，然后从左到右比较两个版本号下标相同的修订号，在比较修订号时，需要将字符串转换成整数进行比较。注意根据题目要求，如果版本号不存在某个下标处的修订号，则该修订号视为 0。

时间复杂度为 O(m + n)，其中 m 是字符串 version1 的长度，n 是字符串 version2 的长度。
空间复杂度为 O(m + n)，需要 O(m + n) 的空间存储分割后的修订号列表。

```c++
int compareVersion(string version1, string version2) {
    size_t mlPos = 0, mrPos, nlPos = 0, nrPos;
    std::vector<int> mv;
    std::vector<int> nv;
    while (true) {
        mrPos = version1.find(".", mlPos);
        if (mrPos == std::string::npos)
            break;
        mv.push_back(atoi(version1.substr(mlPos, mrPos - mlPos).c_str()));
        mlPos = mrPos + 1;
    }
    mv.push_back(
        atoi(version1.substr(mlPos, version1.size() - mlPos).c_str()));
    while (true) {
        nrPos = version2.find(".", nlPos);
        if (nrPos == std::string::npos)
            break;
        nv.push_back(atoi(version2.substr(nlPos, nrPos - nlPos).c_str()));
        nlPos = nrPos + 1;
    }
    nv.push_back(
        atoi(version2.substr(nlPos, version2.size() - nlPos).c_str()));
    int mvSize = mv.size();
    int nvSize = nv.size();
    for (int i = 0; i < mvSize && i < nvSize; ++i) {
        if (mv[i] > nv[i]) {
            return 1;
        } else if (mv[i] < nv[i]) {
            return -1;
        }
    }
    if (mvSize > nvSize) {
        for (int i = nvSize; i < mvSize; ++i) {
            if (mv[i] > 0)
                return 1;
        }
    } else if (mvSize < nvSize) {
        for (int i = mvSize; i < nvSize; ++i) {
            if (nv[i] > 0)
                return -1;
        }
    }
    return 0;
}
```

方法二：双指针

方法一需要存储分割后的修订号，为了优化空间复杂度，可以在分割版本号的同时解析出修订号进行比较。

时间复杂度为 O(m + n)，其中 m 是字符串 version1 的长度，n 是字符串 version2 的长度。
空间复杂度为 O(1)。

```c++
int compareVersion_V2(string version1, string version2) {
    int m = version1.length(), n = version2.length();
    int i = 0, j = 0;
    int x, y;
    while (i < m || j < n) {
        x = 0;
        for (; i < m && version1[i] != '.'; ++i) {
            x += version1[i] - '0';
            x *= 10;
        }
        ++i;
        y = 0;
        for (; j < n && version2[j] != '.'; ++j) {
            y += version2[j] - '0';
            y *= 10;
        }
        ++j;
        if (x != y)
            return x > y ? 1 : -1;
    }
    return 0;
}
```
