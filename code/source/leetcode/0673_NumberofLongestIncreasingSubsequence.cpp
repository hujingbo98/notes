/**
 * Source : https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
 * Author : Hu Jingbo
 * Date   : 2021-09-20
 * 
 * 673. 最长递增子序列的个数
 * 
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 示例 2:
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 */

#include <vector>
#include <algorithm>
#include <iterator>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：动态规划
     * 
     * 定义 dp[i] 表示以 nums[i] 为结尾的最长上升子序列的长度，cnt[i] 表示以 
     * nums[i] 为结尾的最长上升子序列的个数。设 nums 的最长上升子序列的长度为
     * maxLen 那么答案为所满足的 dp[i] = maxLen 的 i 所对应的 cnt[i] 之和。
     * 
     * 在计算 dp[i] 时，我们需要在 dp[j] 的最长上升子序列后面再加一个 nums[i]，其中
     * 0 <= j < i，只有 nums[i] 大于 nums[j] 时，才能将 nums[i] 放在 nums[j] 后面
     * 以形成更长的上升子序列。我们从小到大计算 dp 数组的值，在计算 dp[i] 之前，我们
     * 已经计算出 dp[0] 至 dp[i-1] 的值，因此，状态转移方程为：
     *      dp[i] = max(dp[j]) + 1, 其中 0 <= j < i 且 nums[j] < nums[i]
     * 
     * 对于 cnt[i]，其等于所有满足 dp[i] = max(dp[j]) + 1 的 cnt[i] 之和。
     * 在代码实现中，我们可以在计算 dp[i] 的同时统计 cnt[i] 的值，并同时维护总的
     * maxLen 和答案。
     * 
     * 时间复杂度为 o(n^2)。其中 n 为 nums 的大小，我们需要遍历 nums 来统计以 
     * nums[i] 为结尾的最长上升子序列的长度，在每次统计 nums[i] 时，需要枚举 i 之前
     * 的 nums[j] 和 dp [j] (0 <= j < i) 进行比较和统计。
     * 
     * 空间复杂度为 O(n)。dp 数组使用 O(n) 的空间，cnt 数组使用 O(n) 的空间。
     */
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size);
        vector<int> cnt(size);
        dp[0] = 1;
        cnt[0] = 1;
        int maxLen = 1;
        int ans = 1;
        for (int i = 1; i < size; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i];
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }

    /**
     * 方法二：贪心 + 前缀和 + 二分查找
     * 
     * 我们维护一个二维数组 d[i][]，d[i] 数组保存所有能成为长度为 i 的最长上升子序
     * 列的末尾元素的值。
     * 
     * 我们可以注意到 d[i] 数组中的最小值是关于 i 单调递增的。因为如果
     * d[j] >= d[i] 且 j < i，我们考虑从长度为 i 的最长上升子序列的末尾删除 i - j
     * 个元素，那么这个序列的长度变为 j，且第 j 个元素 x(末尾元素) 必然小于 d[i]，
     * 也就小于 d[j]。那么我们的就找到了一个长度为 j 的最长上升子序列，并且末尾元素
     * 比 d[j] 数组中的最小值小，从而产生了矛盾。因此 d[i] 数组中的最小值的单调性得
     * 证。
     * 
     * 我们依次遍历数组 nums 中的每个元素，在每次遍历元素 n 的过程中，我们使用二
     * 分查找在 min(d[0]) 至 min(d[len-1]) 找到首个不小于 n 的下标 i，并将 n 添加
     * 到 d[i] 数组中。如果没找到就说明我们找到了以 n 结尾的更长的最长上升子序列，
     * 将只有一个元素 n 的数组，插入到二维数组 d 的末尾。
     * 
     * 同时，我们可以注意到 d[i] 数组是递减的，因为只有当 n 小于 min(d[i]) 时，才
     * 会被添加到数组 d[i] 中。
     * 
     * 类似的，我们也可以维护一个二维数组 cnt，其中 cnt[i][j] 记录以 d[i][j] 为结
     * 尾的最长上升子序列的个数。为了计算 cnt[i][j]，我们可以考察 d[i-1] 和 
     * cnt[i-1]，将所有满足 d[i-1][k] < d[i][j] 的 cnt[i-1][k]，累加到 cnt[i][j]，
     * 这样最终答案就是数组 cnt[maxLen] 的所有元素之和。
     * 
     * 在代码实现中，由于数组 d[i] 是有序的，可以使用二分查找得到最小满足 d[i-1][k]
     * < d[i][j] 的下标 k。
     * 
     * 另一处优化是将 cnt 改为前缀和，并在开头填上 0，此时 d[i][j] 对应的最长上升
     * 子序列的个数就是 cnt[i-1][len-1] - cnt[i-1][k]。
     * 
     * 时间复杂度为 O(nlog n)。其中 n 为 nums 的长度。对于 nums 中的每个元素，我们
     * 至多两次二分查找，每次耗时 O(log n)，因此时间复杂度为 O(nlog n)。
     * 
     * 空间复杂度为 O(n)。主要是数组 d 和 cnt 所用的空间。
     */
    int findNumberOfLIS_V2(vector<int>& nums) {
        vector<vector<int>> d, cnt;
        for (int n : nums) {
            auto dIt = lower_bound(d.begin(), d.end(), n, [](
                const vector<int>& element, int value) {
                    return element.back() < value;
                });
            int nCnt = 1;
            if (dIt != d.begin()) {
                auto dItPre = dIt - 1;
                auto i = distance(d.begin(), dItPre);
                auto dItPreIt = upper_bound(dItPre->begin(), dItPre->end(),
                    n, [](int value, int element) {
                        return element < value;
                    });
                auto k = distance(dItPre->begin(), dItPreIt);
                nCnt = cnt[i].back() - cnt[i][k];
            }
            if (dIt != d.end()) {
                auto i = distance(d.begin(), dIt);
                dIt->push_back(n);
                cnt[i].push_back(cnt[i].back() + nCnt);
            } else {
                d.push_back({n});
                cnt.push_back({0, nCnt});
            }
        }
        return cnt.back().back();
    }
};

TEST(Solution, findNumberOfLIS) {
    Solution s;

    vector<int> nums = {1, 3, 5, 4, 7};
    EXPECT_EQ(2, s.findNumberOfLIS(nums));
    EXPECT_EQ(2, s.findNumberOfLIS_V2(nums));

    vector<int> nums_2 = {2, 2, 2, 2, 2};
    EXPECT_EQ(5, s.findNumberOfLIS(nums_2));
    EXPECT_EQ(5, s.findNumberOfLIS_V2(nums_2));

    vector<int> nums_3 = {1,1,1,2,2,2,3,3,3};
    EXPECT_EQ(27, s.findNumberOfLIS_V2(nums_3));
}