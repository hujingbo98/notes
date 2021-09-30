# Algorithm

Algorithm learning source code and comment.

## Sort

排序方法/源地址|平均时间复杂度|最坏时间复杂度|最好时间复杂度|空间复杂度|稳定性
:-:|:-:|:-:|:-:|:-:|:-:
[冒泡排序](https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/bubbleSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定
[选择排序](https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/selectionSort.cpp)|O(n^2)|O(n^2)|O(n^2)|O(1)|不稳定
[插入排序](https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/insertionSort.cpp)|O(n^2)|O(n^2)|O(n)|O(1)|稳定

其中 n 表示数列的长度。稳定表示排序后 2 个相等键值的顺序和排序之前它们的顺序相同，反之，则不稳定。

## LeetCode

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[1894](https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk)|[找到需要补充粉笔的学生编号](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1894_FindTheStudentThatWillReplaceTheChalk.cpp)|模拟、前缀和、二分查找|中等
[1704](https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/)|[判断字符串的两半是否相似](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp)|哈希直接定址|简单
[1221](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/)|[分割平衡字符串](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1704_DetermineifStringHalvesAreAlike.cpp)|贪心|简单
[1143](https://leetcode-cn.com/problems/longest-common-subsequence/)|[最长公共子序列](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/1143_LongestCommonSubsequence.cpp)|动态规划|中等
[725](https://leetcode-cn.com/problems/split-linked-list-in-parts/)|[分隔链表](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0725_SplitLinkedListInParts.cpp)|分隔链表|中等
[704](https://leetcode-cn.com/problems/binary-search/)|[二分查找](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0704_BinarySearch.cpp)|二分查找|简单
[678](https://leetcode-cn.com/problems/valid-parenthesis-string/)|[有效的括号字符串](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0678_ValidParenthesisString.cpp)|栈、贪心|中等
[673](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)|[最长递增子序列的个数](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0673_NumberofLongestIncreasingSubsequence.cpp)|动态规划、贪心、前缀和、二分查找|中等
[650](https://leetcode-cn.com/problems/2-keys-keyboard/)|[只有两个键的键盘](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0650_2KeysKeyboard.cpp)|动态规划、分解质因数|中等
[600](https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/)|[不含连续1的非负整数](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0600_Non-negativeIntegersWithoutConsecutiveOnes.cpp)|动态规划|困难
[524](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)|[通过删除字母匹配到字典里最长单词](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0524_LongestWordInDictionaryThroughDeleting.cpp)|双指针|中等
[502](https://leetcode-cn.com/problems/ipo/)|[IPO](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0502_IPO.cpp)|贪心、最大堆|困难
[470](https://leetcode-cn.com/problems/implement-rand10-using-rand7/)|[用 Rand7() 实现 Rand10()](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0470_ImplementRand10UsingRand7.cpp)|拒绝采样|中等
[447](https://leetcode-cn.com/problems/number-of-boomerangs/)|[回旋镖的数量](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0447_NumberOfBoomerangs.cpp)|枚举、哈希表|中等
[430](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)|[扁平化多级双向链表](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0430_FlattenAMultilevelDoublyLinkedList.cpp)|深度优先搜索、栈|中等
[326](https://leetcode-cn.com/problems/power-of-three/)|[3的幂](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0326_PowerOfThree.cpp)|试除法、约数|简单
[292](https://leetcode-cn.com/problems/nim-game/)|[Nim 游戏](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0292_NimGame.cpp)|数学推理|简单
[223](https://leetcode-cn.com/problems/rectangle-area/)|[矩形面积](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0223_RectangleArea.cpp)|坐标系|中等
[212](https://leetcode-cn.com/problems/word-search-ii/)|[单词搜索 II](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0212_WordSearchII.cpp)|回溯、字典树(前缀树)|困难
[165](https://leetcode-cn.com/problems/compare-version-numbers)|[比较版本号](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0165_CompareVersionNumbers.cpp)|字符串切割、双指针|中等
[162](https://leetcode-cn.com/problems/find-peak-element/)|[寻找峰值](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0162_FindPeakElement.cpp)|二分查找|中等
[68](https://leetcode-cn.com/problems/text-justification)|[文本左右对齐](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0068_TextJustification.cpp)|贪心、模拟|困难
[58](https://leetcode-cn.com/problems/length-of-last-word/)|[最后一个单词的长度](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0058_LengthOfLastWord.cpp)|反向查找字符|简单
[36](https://leetcode-cn.com/problems/valid-sudoku/)|[有效的数独](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0036_ValidSudoku.cpp)|暴力遍历一次|中等
[1](https://leetcode-cn.com/problems/two-sum/)|[两数之和](https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0001_TwoSum.cpp)|哈希表|简单

## LeetCode 中的剑指offer

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[22](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)|[链表中倒数第k个节点](https://github.com/hujingbo98/algorithm/blob/master/source/jianzhioffer/22_TheKthNodeFromTheBottomInTheLinkedList.cpp)|双指针-快慢指针|简单
[10- I](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)|[斐波那契数列](https://github.com/hujingbo98/algorithm/blob/master/source/jianzhioffer/10-I_FibonacciSequence.cpp)|动态规划、滚动数组、矩阵快速幂|简单

## LeetCode 中的面试题

编号/源地址|题目/解决方案|标签|难度
:-:|:-|:-|-|
[17.14](https://leetcode-cn.com/problems/smallest-k-lcci/)|[最小K个数](https://github.com/hujingbo98/algorithm/blob/master/source/leetcodeInterviewProblem/17_14_SmallestKNumbers.cpp)|最大堆、快速排序|中等
