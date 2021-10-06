<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-06
-->

Source : <https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/quickSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 
a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 快速排序 (Quick Sort)

快速排序使用了分治思想。下面是对一个数组 a[l..r] 进行快速排序的分治过程：

分解：从数列中挑出一个元素，称为基准(pivot)。然后数组被划分为两个（可能为空）的子数组 a[l..p-1] 和 a[p+1, r]，使得前面的一个数组中元素都小于等于基准，后面的一个数组中的元素都大于等于基准，而 a[p] 就是基准。

解决：递归的调用快速排序，对两个子数组进行排序。

在本示例中，我们每次的基准都取子数组中的最后一个元素。

平均时间复杂度是 O(nlogn)，其中 n 是数组的大小。

最优情况时间复杂度是 O(nlogn)，其中 n 是数组的大小。快速排序的最优情况是每次取出的基准都将数组划分为长度相等的两个子数组，此时

```txt
第一次递归：T(n) = 2T(n/2) + n
第二次递归：T(n) = 2{2T(n/4) + n/2} + n = 2^2T(n/(2^2)) + 2n
...
第logn次（最后一次）递归：T(n) = (2^logn)T(1) + nlogn = n + nlogn = nlogn
```

最坏情况的时间复杂度是 O(n^2)，其中 n 是数组的大小。快速排序的最快情况是每次取出的基准都是数组中最大或最小的，这种情况其实就是冒泡排序了（每次都排好一个元素）。这种情况的时间复杂度是 O(n^2)。

空间复杂度是 O(n)，其中 n 是数组的大小。我们使用的是就地排序，排序本身占用常数级的空间，但递归调用消耗的平均空间复杂度是 O(logn)，最坏情况的空间复杂度是 O(n)。

快速排序在划分时，会改变原数组中大小相等的元素的顺序，因此快速排序是不稳定的。

```c++
class QuickSort {
public:
    vector<int> quickSort(vector<int>& nums)
    {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
private:
    void quickSort(vector<int>& nums, int l, int r)
    {
        if (l < r) {
            int p = partition(nums, l, r);
            quickSort(nums, l, p-1);
            quickSort(nums, p+1, r);
        }
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int i = l;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
```
