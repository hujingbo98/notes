<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-06
-->

Source : <https://github.com/hujingbo98/algorithm/blob/master/source/algorithm/sort/shellSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 
a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 希尔排序 (Shell Sort)

1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。希尔排序（Shell Sort）又称缩小增量排序（Diminishing Increment Sort）。

希尔排序是按照不同步长对元素进行插入排序。在排序前，选择一个步长序列，也叫增量序列 t1, t2, ... , tk，其中 ti > tj (i < j), tk = 1。

按增量序列，对序列进行 k 趟步长为 ti 的插入排序。当最后一趟排序 tk = 1 时，序列进行一次步长为 1 的插入排序后，排序完成。

在此我们选择增量 gap=length/2 ，缩小增量继续以 gap = gap/2 的方式，这种增量选择我们可以用一个序列来表示，{n/2, (n/2)/2, ..., 1}，称为增量序列。我们选择的这个增量序列是比较常用的，也是 Shell 建议的增量，称为希尔增量，但其实这个增量序列不是最优的。此处我们做示例使用希尔增量。

```txt
第一次比较次数，每组两个元素：1 * n/2
第二次比较次数，每组四个元素：最坏是 (1 + 2 + 3) * n/4
第三次比较次数，每组 8 个元素：最坏是 (1 + 2 + ... + 7) * n/8
...
```

累加求极限得到的算法复杂度小于 O(n^2)。详见：<https://blog.csdn.net/ginnosx/article/details/12263619>

时间复杂度是 O(nlogn)，其中 n 数组的大小。使用希尔增量的最坏时间复杂度是 O(n^2)，最好的时间复杂度是 O(n)。一些经过优化的增量序列经过复杂证明可使得最坏时间复杂度为 O(n^1.3)。

空间复杂度是 O(1)。

根据增量分组后，两个大小相同的元素被分到不同组中时，有可能改变它们之间的顺序。因此希尔排序是不稳定的排序算法。

```c++
vector<int> shellSort(vector<int>& nums)
{
    int n = nums.size();
    int step = n;
    while ((step >>= 1) > 0) {
        for (int i = step; i < n; i += step) {
            int x = nums[i];
            int j = i;
            while (j - step >= 0 && nums[j-step] > x) {
                nums[j] = nums[j-step];
                j -= step;
            }
            nums[j] = x;
        }
    }
    return nums;
}
```
