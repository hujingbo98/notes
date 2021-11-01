<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-03
-->

Problem Source : <https://leetcode-cn.com/problems/fraction-to-recurring-decimal/>

Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0166_FractionToRecurringDecimal.cpp>

## 166、分数到小数

给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。
如果存在多个答案，只需返回任意一个 。
对于所有给定的输入，保证答案字符串的长度小于 10^4。

示例 1：

```txt
输入：numerator = 1, denominator = 2
输出："0.5"
```

示例 2：

```txt
输入：numerator = 2, denominator = 1
输出："2"
```

示例 3：

```txt
输入：numerator = 2, denominator = 3
输出："0.(6)"
```

示例 4：

```txt
输入：numerator = 4, denominator = 333
输出："0.(012)"
```

示例 5：

```txt
输入：numerator = 1, denominator = 5
输出："0.2"
```

提示：

```txt
-2^31 <= numerator, denominator <= 2^31 - 1
denominator != 0
```

## 方法一：长除法 + 哈希表

将分数转换成整数或小数，做法是计算分子和分母相除的结果。可能的结果有三种，整数、有限小数、无限循环小数。

如果分子可以被分母整除，则结果是整数，将分子除以分母的商以字符串形式返回即可。

如果分子不能被分母整除，则结果是有限小数或无限循环小数，需要通过模拟长除法的方式计算结果。为了方便处理，首先根据分子和分母的正负确定答案的正负（注意此时分子和分母都不为 0），然后将分子和分母都转成正数，再计算长除法。

计算长除法时，首先计算结果的整数部分，将以下部分拼接到结果中：

1. 如果结果是负数则将负号拼接到结果中，如果结果是正数则跳过这一步。
2. 将整数部分拼接到结果中。
3. 将小数点拼接到结果中。

完成上述拼接之后，根据余数计算小数部分。

计算小数部分时，每次将余数乘以 10，然后计算小数的下一位数字，并得到新的余数。重复上述操作知道余数为 0 或找到循环节。

* 如果余数为 0，则结果是有限小数。
* 如果找到循环节，则在循环节的开始位置和结束位置插入括号。

如何找到循环节？ 对于相同的余数，得到的小数的下一位数字一定是相同的，因此如果计算过程中发现某一位的余数在之前已经出现过，则为找到循环节。为了记录每个余数是否出现过，需要使用哈希表存储每个余数在小数部分第一次出现的下标。

在每次得到余数时，判断该余数之前是否出现过，如果出现过则在第一次出现的位置加上左括号，在末尾加上右括号返回即可。

时间复杂度是 O(k)，其中 k 是结果字符串的长度，该题中 k <= 10^4。

空间复杂度是 O(k)。主要是哈希表所用的空间，哈希表最多存 10^4 个键值对。

```c++
string fractionToDecimal(int numerator, int denominator) {
    string ans;
    long long numeratorLL = numerator;
    long long denominatorLL = denominator;

    if (0 == numeratorLL % denominatorLL)
        return to_string(numeratorLL / denominatorLL);

    if ((numeratorLL < 0) ^ (denominatorLL < 0))
        ans.push_back('-');
    numeratorLL = abs(numeratorLL);
    denominatorLL = abs(denominatorLL);

    int nbit = numeratorLL / denominatorLL;
    ans.append(to_string(nbit));
    long long nextNumeratorLL = numeratorLL % denominatorLL * 10;
    ans.push_back('.');

    unordered_map<long long, int> cache;
    while (ans.length() < 10000 && 0 != nextNumeratorLL) {
        auto it = cache.find(nextNumeratorLL);
        if (it == cache.end()) {
            cache.insert(std::pair(nextNumeratorLL, ans.length()));
        } else {
            ans.insert(it->second, 1, '(');
            ans.push_back(')');
            break;
        }
        nbit = nextNumeratorLL / denominatorLL;
        ans.append(to_string(nbit));
        nextNumeratorLL = nextNumeratorLL % denominatorLL * 10;
    }
    return ans;
}
```
