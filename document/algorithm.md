<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-01
-->

# Algorithm

## Sort

排序方法/源地址|平均时间复杂度|最坏时间复杂度|最好时间复杂度|空间复杂度|稳定性
:-:|:-:|:-:|:-:|:-:|:-:
[冒泡排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/bubbleSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/bubbleSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定
[选择排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/selectionSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/selectionSort.cpp)|O(n^2)|O(n^2)|O(n^2)|O(1)|不稳定
[插入排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/insertionSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/insertionSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定
[希尔排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/shellSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/shellSort.cpp)|O(n^1.3)|O(n^2)|O(n)|O(1)|不稳定
[归并排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/mergeSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/mergeSort.cpp)|O(nlogn)|O(nlogn)|O(nlogn)|O(n)|稳定
[快速排序](https://github.com/hujingbo98/notes/blob/master/algorithm/sort/quickSort.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/quickSort.cpp)|O(nlogn)|O(n^2)|O(nlogn)|O(logn)|不稳定

其中 n 表示数列的长度。稳定表示排序后 2 个相等键值的顺序和排序之前它们的顺序相同，反之，则不稳定。

## 数组

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[704](https://leetcode-cn.com/problems/binary-search/)|[二分查找](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0704_BinarySearch.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0704_BinarySearch.cpp)|二分查找|简单
[27](https://leetcode-cn.com/problems/remove-element/)|[移除元素](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0027_RemoveElement.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0027_RemoveElement.cpp)|双指针|简单

## LeetCode

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[1894](https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk)|[找到需要补充粉笔的学生编号](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0001_TwoSum.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1894_FindTheStudentThatWillReplaceTheChalk.cpp)|模拟、前缀和、二分查找|中等
[1704](https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/)|[判断字符串的两半是否相似](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/leetcode/1704_DetermineifStringHalvesAreAlike.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp)|哈希直接定址|简单
[1436](https://leetcode-cn.com/problems/destination-city/)|[旅行终点站](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/1436_DestinationCity.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1436_DestinationCity.cpp)|哈希表|简单
[1221](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/)|[分割平衡字符串](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/1704_DetermineifStringHalvesAreAlike.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp)|贪心|简单
[1143](https://leetcode-cn.com/problems/longest-common-subsequence/)|[最长公共子序列](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/1143_LongestCommonSubsequence.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/1143_LongestCommonSubsequence.cpp)|动态规划|中等
[725](https://leetcode-cn.com/problems/split-linked-list-in-parts/)|[分隔链表](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0725_SplitLinkedListInParts.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0725_SplitLinkedListInParts.cpp)|分隔链表|中等
[704](https://leetcode-cn.com/problems/binary-search/)|[二分查找](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0704_BinarySearch.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0704_BinarySearch.cpp)|二分查找|简单
[678](https://leetcode-cn.com/problems/valid-parenthesis-string/)|[有效的括号字符串](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0678_ValidParenthesisString.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0678_ValidParenthesisString.cpp)|栈、贪心|中等
[673](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)|[最长递增子序列的个数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0673_NumberofLongestIncreasingSubsequence.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0673_NumberofLongestIncreasingSubsequence.cpp)|动态规划、贪心、前缀和、二分查找|中等
[650](https://leetcode-cn.com/problems/2-keys-keyboard/)|[只有两个键的键盘](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0650_2KeysKeyboard.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0650_2KeysKeyboard.cpp)|动态规划、分解质因数|中等
[639](https://leetcode-cn.com/problems/decode-ways-ii/)|[解码方法 II](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0639_DecodeWaysII.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0639_DecodeWaysII.cpp)|动态规划|困难
[600](https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/)|[不含连续1的非负整数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0600_Non-negativeIntegersWithoutConsecutiveOnes.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0600_Non-negativeIntegersWithoutConsecutiveOnes.cpp)|动态规划|困难
[583](https://leetcode-cn.com/problems/delete-operation-for-two-strings/)|[两个字符串的删除操作](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0583_DeleteOperationForTwoStrings.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0583_DeleteOperationForTwoStrings.cpp)|最长公共子序列、动态规划|中等
[575](https://leetcode-cn.com/problems/distribute-candies/)|[分糖果](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0575_DistributeCandies.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0575_DistributeCandies.cpp)|贪心|简单
[524](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)|[通过删除字母匹配到字典里最长单词](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0524_LongestWordInDictionaryThroughDeleting.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0524_LongestWordInDictionaryThroughDeleting.cpp)|双指针|中等
[517](https://leetcode-cn.com/problems/super-washing-machines/)|[超级洗衣机](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0517_SuperWashingMachines.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0517_SuperWashingMachines.cpp)|贪心|困难
[502](https://leetcode-cn.com/problems/ipo/)|[IPO](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0502_IPO.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0502_IPO.cpp)|贪心、最大堆|困难
[482](https://leetcode-cn.com/problems/license-key-formatting/)|[密钥格式化](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0482_LicenseKeyFormatting.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0482_LicenseKeyFormatting.cpp)|数学|简单
[470](https://leetcode-cn.com/problems/implement-rand10-using-rand7/)|[用 Rand7() 实现 Rand10()](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0470_ImplementRand10UsingRand7.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0470_ImplementRand10UsingRand7.cpp)|拒绝采样|中等
[447](https://leetcode-cn.com/problems/number-of-boomerangs/)|[回旋镖的数量](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0447_NumberOfBoomerangs.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0447_NumberOfBoomerangs.cpp)|枚举、哈希表|中等
[437](https://leetcode-cn.com/problems/path-sum-iii/)|[路径总和 III](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0437_PathSumIII.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0437_PathSumIII.cpp)|深度优先搜索、前缀和|中等
[434](https://leetcode-cn.com/problems/number-of-segments-in-a-string/)|[字符串中的单词数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0434_NumberOfSegmentsInAString.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0434_NumberOfSegmentsInAString.cpp)|遍历字符串|简单
[430](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)|[扁平化多级双向链表](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0430_FlattenAMultilevelDoublyLinkedList.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0430_FlattenAMultilevelDoublyLinkedList.cpp)|深度优先搜索、栈|中等
[414](https://leetcode-cn.com/problems/third-maximum-number/)|[第三大的数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0414_ThirdMaximumNumber.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0414_ThirdMaximumNumber.cpp)|有序元素不重复集合|简单
[326](https://leetcode-cn.com/problems/power-of-three/)|[3的幂](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0326_PowerOfThree.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0326_PowerOfThree.cpp)|试除法、约数|简单
[405](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/)|[数字转换为十六进制数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0405_ConvertANumberToHexadecimal.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0405_ConvertANumberToHexadecimal.cpp)|位运算|简单
[292](https://leetcode-cn.com/problems/nim-game/)|[Nim 游戏](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0292_NimGame.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0292_NimGame.cpp)|数学推理|简单
[284](https://leetcode-cn.com/problems/peeking-iterator/)|[窥探迭代器](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0284_PeekingIterator.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0284_PeekingIterator.cpp)|迭代器|中等
[223](https://leetcode-cn.com/problems/rectangle-area/)|[矩形面积](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0223_RectangleArea.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0223_RectangleArea.cpp)|坐标系|中等
[212](https://leetcode-cn.com/problems/word-search-ii/)|[单词搜索 II](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0212_WordSearchII.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0212_WordSearchII.cpp)|回溯、字典树(前缀树)|困难
[187](https://leetcode-cn.com/problems/repeated-dna-sequences/)|[重复的DNA序列](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0187_RepeatedDNASequences.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0187_RepeatedDNASequences.cpp)|哈希表、滑动窗口、位运算|中等
[166](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)|[分数到小数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0166_FractionToRecurringDecimal.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0166_FractionToRecurringDecimal.cpp)|长除法、哈希表|中等
[165](https://leetcode-cn.com/problems/compare-version-numbers)|[比较版本号](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0165_CompareVersionNumbers.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0165_CompareVersionNumbers.cpp)|字符串切割、双指针|中等
[162](https://leetcode-cn.com/problems/find-peak-element/)|[寻找峰值](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0162_FindPeakElement.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0162_FindPeakElement.cpp)|二分查找|中等
[68](https://leetcode-cn.com/problems/text-justification)|[文本左右对齐](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0068_TextJustification.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0068_TextJustification.cpp)|贪心、模拟|困难
[58](https://leetcode-cn.com/problems/length-of-last-word/)|[最后一个单词的长度](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0058_LengthOfLastWord.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0058_LengthOfLastWord.cpp)|反向查找字符|简单
[36](https://leetcode-cn.com/problems/valid-sudoku/)|[有效的数独](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0036_ValidSudoku.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0036_ValidSudoku.cpp)|暴力遍历一次|中等
[27](https://leetcode-cn.com/problems/remove-element/)|[移除元素](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0027_RemoveElement.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0027_RemoveElement.cpp)|双指针|简单
[1](https://leetcode-cn.com/problems/two-sum/)|[两数之和](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcode/0001_TwoSum.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0001_TwoSum.cpp)|哈希表|简单

## LeetCode 中的剑指offer

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[22](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)|[链表中倒数第k个节点](https://github.com/hujingbo98/notes/blob/master/algorithm/jianzhioffer/22_TheKthNodeFromTheBottomInTheLinkedList.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/jianzhioffer/22_TheKthNodeFromTheBottomInTheLinkedList.cpp)|双指针-快慢指针|简单
[10- I](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)|[斐波那契数列](https://github.com/hujingbo98/notes/blob/master/algorithm/jianzhioffer/10-I_FibonacciSequence.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/jianzhioffer/10-I_FibonacciSequence.cpp)|动态规划、滚动数组、矩阵快速幂|简单

## LeetCode 中的面试题

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[17.14](https://leetcode-cn.com/problems/smallest-k-lcci/)|[最小K个数](https://github.com/hujingbo98/notes/blob/master/algorithm/leetcodeInterviewProblem/17_14_SmallestKNumbers.md) / [source](https://github.com/hujingbo98/notes/blob/master/code/source/leetcodeInterviewProblem/17_14_SmallestKNumbers.cpp)|最大堆、快速排序|中等
