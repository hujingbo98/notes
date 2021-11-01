<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-20
-->

Source : <https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/bubbleSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 冒泡排序 (Bubble Sort)

冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。

具体做法是，按顺序遍历 [a[0], a[n])。在遍历 a[i] 的过程中，比较 a[i] 和 a[i+1]，如果 a[i] 大于 a[i+1]，就交换它们两个。当遍历完成后，最大的元素就会冒到数列的最后。然后我们将遍历的范围缩小到 [a[0], a[n-1])。继续遍历，直至遍历的范围长度缩小到 1，则排序完成。

时间复杂度为 O(n^2)，其中 n 为数组的长度。

空间复杂度为 O(1)。

```c++
vector<int> bubbleSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
            }
        }
    }
    return nums;
}
```

## flag 优化的冒泡排序

在一趟序列遍历中元素没有发生交换，则证明该序列已经有序。

在实现中我们可以立一个 flag，当一趟遍历没有交换时，直接退出即可。

这样做的好处是，将最好情况的时间降低为 O(n)。

时间复杂度为 O(n^2)。最好情况下的时间复杂度为 O(n)，其中 n 为数列的长度。

空间复杂度为 O(1)。

```c++
vector<int> bubbleSort_V2(vector<int>& nums)
{
    int n = nums.size();
    bool flag;
    for (int i = 0; i < n - 1; ++i) {
        flag = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j+1]) {
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
        if (!flag)
            return nums;
    }
    return nums;
}
```
