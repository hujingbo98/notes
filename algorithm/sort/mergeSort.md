<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-10-06
-->

Source : <https://github.com/hujingbo98/notes/blob/master/code/source/algorithm/sort/mergeSort.cpp>

## 排序问题

```txt
输入：n 个数的一个序列 {a[0], a[1], ... , a[n-1]}。
输出：输出序列的一个排列 {a[0]', a[1]', ... , a[n-1]'}，其中 
a[0]' <= a[1]' <= ... <= a[n-1]'。
```

## 归并排序 (Merge Sort)

归并排序算法是采用分治法(Divide and Conquer)的一个非常典型的应用。

分解：分解待排序的 n 个元素的序列成各具有 n/2 个元素的两个子序列。
解决：使用归并排序递归地排序两个子序列。
合并：合并两个已排序的子序列以产生已排序好的序列。

当待排序的序列长度为 1 时，递归开始回升，在这种情况下不需要做任何工作，因为长度为 1 的序列都已排好序。

时间复杂度是 O(nlogn)，其中 n 是序列的大小。归并排序的时间复杂度与输入的数据无关，最好和最坏情况都是 O(nlogn)。

空间复杂度是 O(n)，需要额外的 O(n) 空间来存储已排序好的子序列。

```c++
class MergeSort {
public:
    /**
     * 递归版
     */
    vector<int> mergeSort_recursive(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans = nums;
        mergeSort_recursive(nums, ans, 0, n - 1);
        return ans;
    }

    void mergeSort_recursive(vector<int>& nums, vector<int>& ans, int l, int r)
    {
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        mergeSort_recursive(nums, ans, l, mid);
        mergeSort_recursive(nums, ans, mid + 1, r);

        // merge sorted sequence
        int il = l;
        int ir = mid + 1;
        int i = l;
        while (il <= mid && ir <= r)
            ans[i++] = nums[il] <= nums[ir] ? nums[il++] : nums[ir++];
        while (il <= mid)
            ans[i++] = nums[il++];
        while (ir <= r)
            ans[i++] = nums[ir++];
        for (i = l; i <= r; ++i)
            nums[i] = ans[i];
    }

    /**
     * 迭代版
     */
    vector<int> mergeSort_iterative(vector<int>& nums)
    {
        vector<int> ans = nums;
        int n = nums.size();
        for (int seg = 1; seg < n; seg *= 2) {
            for (int l = 0; l < n; l += 2 * seg) {
                int mid = min(l + seg, n);
                int r = min(l + 2 * seg, n);
                int il = l;
                int ir = mid;
                int k = l;
                while (il < mid && ir < r)
                    ans[k++] = nums[il] <= nums[ir] ? nums[il++] : nums[ir++];
                while (il < mid)
                    ans[k++] = nums[il++];
                while (ir < r)
                    ans[k++] = nums[ir++];
            }
            swap(nums, ans);
        }
        return ans;
    }
};
```
