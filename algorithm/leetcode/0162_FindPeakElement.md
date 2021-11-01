<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-15
-->

Problem Source : <https://leetcode-cn.com/problems/find-peak-element/>

Solution Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0162_FindPeakElement.cpp>

## 162、寻找峰值

峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。
你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

示例 1：

```txt
输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
```

示例 2：

```txt
输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；或者返回索引 5，其峰值元素为 6。
```

提示：

```txt
1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]
```

## 方法一：暴力

我们需要遍历给定数组 nums，当遍历到 num[i] 时，分别比较其左右相邻的元素，如果该元素均大于其左右相邻的元素，即该元素为峰值元素，返回其下标即可。

时间复杂度为 O(n)，其中 n 为 nums 的长度。
空间复杂度为 O(1)。

```c++
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if ((i == 0 || nums[i] > nums[i-1]) &&
            (i == n-1 || nums[i] > nums[i+1]))
            return i;
    }
    return -1;
}
```

## 方法二：二分查找

如果我们取 nums 中间的元素 nums[i]，与两边元素进行比较，会出现以下四种情况：

1. 如果 nums[i - 1] < nums[i] > nums[i + 1]，那么 i 就是峰值位置，直接返回 i 作为答案即可。
2. 如果 nums[i - 1] < nums[i] < nums[i + 1]，那么 i 往右走，一定可以找到峰值，即 i = i + 1。
为什么一定可以找到峰值呢？因为 i 往右走，只要碰到 nums[i] > nums[i+1]，那么 i 就是峰值位置，如果一直到数组末尾都小于的，由于 num[n] 等于负无穷，因此最后一个元素肯定是峰值。
3. 如果 nums[i - 1] > num[i] > nums[i + 1]，那么 i 往左走，一定可以找到峰值。
4. 如果 nums[i - 1] > num[i] < nums[i + 1]，那么 i 往任意方向走，都一定可以找到峰值。

总结：

- 如果 nums[i] < nums[i + 1]，那么往右走。
- 如果 nums[i] > nums[i + 1]，那么往左走。

设计算法如下：

1. 对于当前可行的下标范围 [l, r]，我们取其中间 i = (l + r) / 2;
2. 如果 nums[i] 是峰值，返回 i 即可。
3. 如果 nums[i] < nums[i + 1]，l = i + 1，然后继续执行步骤 1；
4. 如果 nums[i] > nums[i + 1]，r = i - 1，然后继续执行步骤 1；

时间复杂度为 O(log n)，其中 n 为 nums 的长度。
空间复杂度为 O(1)。

```c++
int findPeakElement_V2(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int r = nums.size() - 1;
    int i = 0;
    while (l <= r) {
        i = (l + r) / 2;
        if ((i == 0 || nums[i] > nums[i - 1]) &&
            (i == n - 1 || nums[i] > nums[i + 1])) {
            return i;
        }
        if (nums[i] < nums[i + 1])
            l = i + 1;
        else if (nums[i] > nums[i + 1])
            r = i - 1;
    }
    return -1;
}
```
