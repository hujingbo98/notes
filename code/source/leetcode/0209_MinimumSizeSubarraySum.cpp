/**
 * Source : https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * Author : Hu Jingbo
 * Date   : 2022-01-10
 * 
 * 209. 长度最小的子数组
 * 
 * 给定一个含有 n 个正整数的数组和一个正整数 target。
 * 
 * 找出该数组中满足其和 ≥ target 的长度最小的连续子数组 [numsl, numsl+1, ..., 
 * numsr-1, numsr]，并返回其长度。如果不存在符合条件的子数组，返回 0。
 * 
 * 示例 1：
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 示例 2：
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 
 * 示例 3：
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 * 提示：
 * 1 <= target <= 109
 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 105
 * 
 * 进阶：
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 */

#include <vector>
#include <climits>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：滑动窗口
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, ans = INT_MAX, n = nums.size();
        int left = 0, right = 0;
        for (; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

TEST(Solution, 0209_MinimumSizeSubarraySum) {
    Solution s;

    vector<int> nums = {2,3,1,2,4,3};
    EXPECT_EQ(2, s.minSubArrayLen(7, nums));

    vector<int> nums_2 = {1,4,4};
    EXPECT_EQ(1, s.minSubArrayLen(4, nums_2));

    vector<int> nums_3 = {1,1,1,1,1,1,1,1};
    EXPECT_EQ(0, s.minSubArrayLen(11, nums_3));
}