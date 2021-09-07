/**
 * Source : https://leetcode-cn.com/problems/smallest-k-lcci/
 * Author : Hu Jingbo
 * Date   : 2021-09-07
 * 
 * 面试题 17.14. 最小K个数
 * 
 * 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
 * 
 * 示例：
 * 输入：arr = [1,3,5,7,2,4,6,8], k = 4
 * 输出：[1,2,3,4]
 * 
 * 提示：
 * 0 <= len(arr) <= 100000
 * 0 <= k <= min(100000, len(arr))
 */

#include <vector>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 最大堆
     * 
     * 使用一个最大堆实时维护数组的前 k 小值。首先，先将数组的前 k 个数插入到最大堆
     * 中，随后开始从数组的第 k + 1 个数遍历，如果遍历的数比最大堆的堆顶的数小，就将
     * 堆顶的数弹出，再将遍历的数插入最大堆。最后将最大堆里的数存入数组返回即可。
     * 
     * 时间复杂度分析：
     *  1. 将数组的前 k 个数插入到最大堆的时间是 O(k(log k))
     *  2. 从 k + 1，开始遍历，最坏情况是都需要插入到最大堆，此时，时间复杂度是
     *     O((n-k)(log k))
     *  3. 将最大堆里的数存入数组的时间复杂度是 O(k(log k))
     * 所以，时间复杂度是 O((n + k)(log k))，其中 n 是数组的长度。
     * 空间复杂度是 O(k)，最大堆里最多存 k 个数。
     */
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        if (k <= 0) return ans;
        priority_queue<int> q;
        int len = arr.size();
        int i = 0;
        for (; i < k && i < len; ++i) {
            q.push(arr[i]);
        }
        for (; i < len; ++i) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }

    /**
     * 快速排序思想
     * 
     * 可以借鉴快速排序思想中的划分函数。划分函数可以将一个数组分为两个部分，小于等于分
     * 界值 pivot 的元素都会被放到数组的左边，大于的都会被放到数组的右边，然后返回
     * 分界值的下标。
     * 与快速排序不同的是，快速排序会根据分界值的下标递归处理两侧，而我们只需要处理
     * 一侧。
     * 此时可以划分为三种情况：
     *  1. 如果分界值的下标等于 k - 1 或 k，则说明数组的第 k 小数是 pivot 或第 k+1
     *     小数是 pivot，此时可以确定，前 k 个数就是数组的前 k 小值，将其保存到新数
     *     组中返回即可。
     *  2. 如果分界值的下标小于 k - 1，则说明数组的第 k 小数在分界值的右侧，此时需
     *     要递归划分分界值右侧的数组。
     *  3. 如果分界值的下标大于 k，则说明数组的第 k 小数在分界值的左侧，此时需
     *     要递归划分分界值左侧的数组。
     * 实现中定义 partition(arr, l, r, k) 递归函数，递归完成后取数组的前 k 个数放
     * 到新数组中返回即可。
     */
    vector<int> smallestK_V2(vector<int>& arr, int k) {
        if (arr.empty())
            return {};
        int l = 0;
        int r = arr.size() - 1;
        partition(arr, l, r, k);
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    void partition(vector<int>& arr, int l, int r, int k) {
        int i = l - 1;
        int x = arr[r];
        for (int j = l; j < r; ++j) {
            if (arr[j] <= x) {
                ++i;
                std::swap(arr[j], arr[i]);
            }
        }
        std::swap(arr[i + 1], arr[r]);
        if (i + 1 == k || i + 1 == k - 1)
            return;
        else if (i + 1 < k - 1)
            partition(arr, i + 2, r, k);
        else if (i + 1 > k)
            partition(arr, l, i, k);
    }

};

TEST(Solution, smallestK) {
    Solution s;
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    vector<int> ans = s.smallestK(arr, 4);
    int len = ans.size();
    ASSERT_EQ(4, len);
    for (int i = 4; i <= 1; --i) {
        EXPECT_EQ(i, ans[i]);
    }
}

TEST(Solution, smallestK_V2) {
    Solution s;
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    vector<int> ans = s.smallestK_V2(arr, 4);
    int len = ans.size();
    ASSERT_EQ(4, len);
    for (int i = 4; i <= 1; --i) {
        EXPECT_LE(4, ans[i]);
    }
}