<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-10
-->

Problem Source : <https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk>
Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1894_FindTheStudentThatWillReplaceTheChalk.cpp>

1894、找到需要补充粉笔的学生编号

一个班级里有 n 个学生，编号为 0 到 n - 1 。每个学生会依次回答问题，编号为 0 的学生先回答，然后是编号为 1 的学生，以此类推，直到编号为 n - 1 的学生，然后老师会重复这个过程，重新从编号为 0 的学生开始回答问题。

给你一个长度为 n 且下标从 0 开始的整数数组 chalk 和一个整数 k 。一开始粉笔盒里总共有 k 支粉笔。当编号为 i 的学生回答问题时，他会消耗 chalk[i] 支粉笔。如果剩余粉笔数量 严格小于 chalk[i]，那么学生 i 需要补充粉笔。

请你返回需要补充粉笔的学生编号。

示例 1：

```txt
输入：chalk = [5,1,5], k = 22
输出：0
解释：学生消耗粉笔情况如下：
- 编号为 0 的学生使用 5 支粉笔，然后 k = 17 。
- 编号为 1 的学生使用 1 支粉笔，然后 k = 16 。
- 编号为 2 的学生使用 5 支粉笔，然后 k = 11 。
- 编号为 0 的学生使用 5 支粉笔，然后 k = 6 。
- 编号为 1 的学生使用 1 支粉笔，然后 k = 5 。
- 编号为 2 的学生使用 5 支粉笔，然后 k = 0 。
编号为 0 的学生没有足够的粉笔，所以他需要补充粉笔。
```

示例 2：

```txt
输入：chalk = [3,4,1,2], k = 25
输出：1
解释：学生消耗粉笔情况如下：
- 编号为 0 的学生使用 3 支粉笔，然后 k = 22 。
- 编号为 1 的学生使用 4 支粉笔，然后 k = 18 。
- 编号为 2 的学生使用 1 支粉笔，然后 k = 17 。
- 编号为 3 的学生使用 2 支粉笔，然后 k = 15 。
- 编号为 0 的学生使用 3 支粉笔，然后 k = 12 。
- 编号为 1 的学生使用 4 支粉笔，然后 k = 8 。
- 编号为 2 的学生使用 1 支粉笔，然后 k = 7 。
- 编号为 3 的学生使用 2 支粉笔，然后 k = 5 。
- 编号为 0 的学生使用 3 支粉笔，然后 k = 2 。
编号为 1 的学生没有足够的粉笔，所以他需要补充粉笔。
```

提示：

```txt
chalk.length == n
1 <= n <= 10^5
1 <= chalk[i] <= 10^5
1 <= k <= 10^9
```

方法一：优化的模拟

我们可以先遍历一遍 chalk，遍历的过程中维护一个变量 n 累加遍历过得学生消耗粉笔的总和，同时比较一下 n 和 k，如果 n > k，则说明该学生需要填充粉笔，直接返回当前遍历的下标即可。

如果第一轮没有学生需要填充粉笔，那么我们已经得到了每个学生都消耗一次粉笔的数量的总和 n。

第二轮遍历时可以比较 n 和 (k mod n)，如果 n > (k mod n)，则说明该学生需要填充粉笔。

注意：n 可能会超过 32 位有符号整数的范围，因此，为了避免溢出，需要使用 64 位的整数存储 n。

时间复杂度 O(n)，其中 n 为 chalk 的长度。
空间复杂度为 O(1)。

```cpp
int chalkReplacer(vector<int>& chalk, int k) {
    long long n = 0;
    int len = chalk.size();
    for (int i = 0; i < len; ++i) {
        n += chalk[i];
        if (n > k) {
            return i;
        }
    }
    k %= n;
    n = 0;
    for (int i = 0; i < len; ++i) {
        n += chalk[i];
        if (n > k) {
            return i;
        }
    }
    return -1;
}
```

方法二：前缀和 + 二分查找

在方法一中我们第一次遍历求出了所有同学消耗一次粉笔的总和 n，对于方法一中的第二次遍历，可以使用二分查找进行优化。

在对数组 chalk 的遍历过程中，我们可以求出前缀和，存入数组 pre。那么需要补充粉笔的学生编号 i，是最小满足 pre[i] < (k mod n) 的下标 i。可以通过二分查找在 O(log n) 的时间内找出。

注意：由于前缀和可能超过 32 位整数范围，因此我们不能再原数组上保存前缀和。但是，本题中 k < 10^9，chalk[i] < 10^5，因此在计算前缀和的过程中，如果超过了 k，说明已经找到了需要添加粉笔的学生编号，此时就无需计算下去，那么也就不会
超过 32 位整数的范围。

时间复杂度为 O(n)。其中 n 为 chalk 的长度。
空间复杂度为 O(1)。

```cpp
int chalkReplacer_V2(vector<int>& chalk, int k) {
    if (chalk[0] > k)
        return 0;
    int len = chalk.size();
    for (int i = 1; i < len; ++i) {
        chalk[i] += chalk[i - 1];
        if (chalk[i] > k)
            return i;
    }
    k %= chalk[len - 1];
    int i = upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    return i;
}
```
