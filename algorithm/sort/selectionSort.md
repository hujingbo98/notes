<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-21
-->

Source : <https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/selectionSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 选择排序 (Selection Sort)

在未排序序列中重复查找最小元素（升序），将其放在开头来对数组进行排序。该算法在给定数组中维护两个子数组：

1. 已排序的子数组。
2. 剩余的未排序的子数组。

在选择排序的每次迭代中，从未排序的子数组中选取最小元素并将其移动到已排序的子数组。

时间复杂度是 O(n^2)，其中 n 是序列的长度。

空间复杂度是 O(1)。

选择排序是不稳定的，在交换的过程相同键值的次序可能会改变。例如：{7, 7, 1}，在第一次交换时将两个 7 的次序改变了。

以下示例解释了上述步骤：

```txt
nums[] = 64 25 12 22 11

找到 nums[0...4] 中的最小元素并将其放在开头
11 25 12 22 64

找到 nums[1...4] 中的最小元素并将其放在 nums[1...4] 的开头
11 12 25 22 64

找到 nums[2...4] 中的最小元素并将其放在 nums[2...4] 的开头
11 12 22 25 64

找到 nums[3...4] 中的最小元素并将其放在 nums[3...4] 的开头
11 12 22 25 64
```

```c++
vector<int> selectionSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
    return nums;
}
```
