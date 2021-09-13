<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-09
-->
Problem source : <https://leetcode-cn.com/problems/two-sum>
Solution source : <https://github.com/hujingbo98/algorithm/blob/master/source/leetcode/0001_TwoSum.cpp>

1、两数之和

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值target 的那两个整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：

```txt
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

示例 2：

```txt
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

示例 3：

```txt
输入：nums = [3,3], target = 6
输出：[0,1]
```

提示：

* `2 <= nums.length <= 104`
* `-109 <= nums[i] <= 109`
* `-109 <= target <= 109`
* 只会存在一个有效答案

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

方法一：暴力枚举

枚举数组中的每一个数 x，寻找数组中是否存在另一个数 y，使得 x + y = target，即寻找 y = target - x。
当我们遍历数组寻找 y 时，因为 x 已经和位于 x 之前的元素都匹配过了，所以不需要再和 x 之前的元素进行匹配。
又因为每一个元素不能被使用两次，所以我们只需要在 x 后面的元素寻找 y。

时间复杂度为 O(n^2)，其中 n 是数组的元素数量。最坏情况下是数组中任意两个数都要匹配一次。
空间复杂度为 O(1)。

```c++
vector<int> twoSum_V1(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; 
}
```

方法二：哈希表

在暴力枚举方法中，时间复杂度较高的原因是查找 target - x 的过程。因此，需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。
如果 target - x 存在，我们需要找出它的索引。使用哈希表，可以将寻找 target - x 的时间复杂度降低到 O(1)。
具体实现是创建一个哈希表，对于每一个 x，首先在哈希表中查找是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。

时间复杂度为 O(n)，其中 n 是数组中的元素数量。对于每一个元素 x，可以 O(1) 地寻找 target - x。
空间复杂度为 O(n)，其中 n 是数组中元素的数量，主要为哈希表的开销。

```c++
vector<int> twoSum_V2(vector<int>& nums, int target) {
    unordered_map<int, int> hashTable;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        auto it = hashTable.find(target - nums[i]);
        if (it != hashTable.end())
            return {it->second, i};
        hashTable[nums[i]] = i;
    }
    return {};
}
```
