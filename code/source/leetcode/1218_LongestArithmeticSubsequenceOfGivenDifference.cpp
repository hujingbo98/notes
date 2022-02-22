/**
 * Source : https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
 * Author : Hu Jingbo
 * Date   : 2021-11-05
 * 
 * 1218. 最长定差子序列
 * 
 * 给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序
 * 列的长度，该子序列中相邻元素之间的差等于 difference 。
 * 
 * 子序列是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr
 * 派生出来的序列。
 * 
 * 示例 1：
 * 输入：arr = [1,2,3,4], difference = 1
 * 输出：4
 * 解释：最长的等差子序列是 [1,2,3,4]。
 * 
 * 示例 2：
 * 输入：arr = [1,3,5,7], difference = 1
 * 输出：1
 * 解释：最长的等差子序列是任意单个元素。
 * 
 * 示例 3：
 * 输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
 * 输出：4
 * 解释：最长的等差子序列是 [7,5,3,1]。
 * 
 * 提示：
 * 1 <= arr.length <= 10^5
 * -10^4 <= arr[i], difference <= 10^4
 */

#include <vector>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> hash;
        int ans = 1;
        for (int num : arr) {
            hash[num] = hash[num - difference] + 1;
            ans = max(ans, hash[num]);
        }
        return ans;
    }
};

TEST(Solution, longestSubsequence) {
    Solution s;

    vector<int> v = {1, 2, 3, 4};
    EXPECT_EQ(4, s.longestSubsequence(v, 1));

    vector<int> v1 = {1, 3, 5, 7};
    EXPECT_EQ(1, s.longestSubsequence(v1, 1));

    vector<int> v2 = {1,5,7,8,5,3,4,2,1};
    EXPECT_EQ(4, s.longestSubsequence(v2, -2));
}