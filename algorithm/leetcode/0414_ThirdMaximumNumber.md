<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-06
-->

Problem Source : <https://leetcode-cn.com/problems/third-maximum-number/>

Solution Source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0414_ThirdMaximumNumber.cpp>

## 414、第三大的数

给你一个非空数组，返回此数组中 第三大的数。如果不存在，则返回数组中最大的数。

示例 1：

```txt
输入：[3, 2, 1]
输出：1
解释：第三大的数是 1。
```

示例 2：

```txt
输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2。
```

示例 3：

```txt
输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1。
```

提示：

```txt
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
```

## 方法一：有序元素不重复集合

我们可以遍历数组，同时用一个有序元素不重复集合 s 来维护数组中前三大不同的数。

具体做法是每遍历一个数 num，就将 num 插入到 s 中，若 s 的大小超过 3，就删除 s 中最小的元素。

遍历结束后，若 s 的大小小于 3，则返回 s 中的最大元素，否则返回 s 中的最小元素。

时间复杂度是 O(n)，其中 n 是数组的大小。在遍历过程中，s 的最大大小是 4，因此插入和删除的时间复杂度可视作 O(1)，因此时间复杂度是 O(n)。

空间复杂度是 O(1)。在遍历过程中，s 的最大大小是 4。

```c++
int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int num : nums) {
        s.insert(num);
        if (s.size() > 3)
            s.erase(s.begin());
    }
    return s.size() < 3 ? *s.rbegin() : *s.begin();
}
```
