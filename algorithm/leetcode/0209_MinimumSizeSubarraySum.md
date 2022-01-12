<!--
 * @Author : Hu Jingbo
 * @Date   : 2022-01-12
-->

Problem Source : <https://leetcode-cn.com/problems/minimum-size-subarray-sum/>

Solution Source: <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0209_MinimumSizeSubarraySum.cpp>

## 209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 target。

找出该数组中满足其和 ≥ target 的长度最小的连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]，并返回其长度。如果不存在符合条件的子数组，返回 0。

示例 1：

```txt
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

示例 2：

```txt
输入：target = 4, nums = [1,4,4]
输出：1
```

示例 3：

```txt
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

提示：

```txt
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
```

进阶：如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

## 方法一：滑动窗口

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0, ans = INT_MAX, n = nums.size();
    int left = 0, right = 0;
    for (; right < n; ++right) {
        sum += nums[right];
        while (sum >= target) {
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
```