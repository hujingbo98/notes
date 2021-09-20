<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-21
-->

Source : <https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/insertionSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 插入排序 (Insertion Sort)

插入排序是一种简单的排序算法，其工作方式像排序一手扑克牌。该数组实际上分为已排序和未排序部分。未排序部分的一个元素被拾取并放在已排序部分中的正确位置。

按顺序遍历该数组，在遍历 x = a[i] 的过程中，比较 x 和 a[i-1]；如果 x 大于 a[i-1]，则将 x 插入到 a[i-1] 的下一个位置 a[i]；如果 a[i] 小于 a[i-1]，则将 a[i-1] 移动到下标为 i 的位置，为插入 x 腾出空间，然后与之前的元素进行比较。

时间复杂度是 O(n^2)。其中 n 是数组的长度。最好情况下的时间复杂度是 O(n)，当输入的数组已排序好时，遍历过程中不需要向前迭代。

空间复杂度是 O(1)。

插入排序算法是稳定的排序算法。

插入排序算法示例排序步骤：

```txt
原数组：12, 11, 13, 5, 6

开始
第一次：11, 12, 13, 5, 6
第二次：11, 12, 13, 5, 6
第三次：5, 11, 12, 13, 6
第四次：5, 6, 11, 12, 13
结束
```

```c++
vector<int> insertionSort(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int x = nums[i];
        int j = i;
        while (j > 0 && nums[j-1] > x) {
            nums[j] = nums[j-1];
            --j;
        }
        nums[j] = x;
    }
    return nums;
}
```
