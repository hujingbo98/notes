/**
 * Source : https://leetcode-cn.com/problems/distribute-candies/
 * Author : Hu Jingbo
 * Date   : 2021-11-01
 * 
 * 575. 分糖果
 * 
 * Alice 有 n 枚糖，其中第 i 枚糖的类型为 candyType[i]。Alice 注意到她的体重正在增
 * 长，所以前去拜访了一位医生。
 * 
 * 医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 n / 2 即可（n 是一个偶数）。Alice 
 * 非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。
 * 
 * 给你一个长度为 n 的整数数组 candyType，返回： Alice 在仅吃掉 n / 2 枚糖的情况下，
 * 可以吃到糖的最多种类数。
 * 
 * 示例 1：
 * 输入：candyType = [1,1,2,2,3,3]
 * 输出：3
 * 解释：Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
 * 
 * 示例 2：
 * 输入：candyType = [1,1,2,3]
 * 输出：2
 * 解释：Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，
 * 她只能吃到两种不同类的糖。
 * 
 * 示例 3：
 * 输入：candyType = [6,6,6,6]
 * 输出：1
 * 解释：Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
 * 
 * 提示：
 * n == candyType.length
 * 2 <= n <= 10^4
 * n 是一个偶数
 * -10^5 <= candyType[i] <= 10^5
 */

#include <vector>
#include <algorithm>
#include <unordered_set>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：贪心
     * 
     * 设糖果的总数为 n，糖果的总种类数为 m，由于 Alice 最多吃 n / 2 个糖，所以取 m
     * 和 n / 2 较小的一个即为答案。
     * 
     * 时间复杂度是 O(n)。使用哈希表获取 m， 需要 O(n) 的时间。
     * 空间复杂度是 O(n)。哈希表需要 O(n)的空间。
     */
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};

TEST(Solution, distributeCandies) {
    Solution s;

    vector<int> v1 = {1, 1, 2, 2, 3, 3};
    EXPECT_EQ(3, s.distributeCandies(v1));

    vector<int> v2 = {1, 1, 2, 3};
    EXPECT_EQ(2, s.distributeCandies(v2));

    vector<int> v3 = {6, 6, 6, 6};
    EXPECT_EQ(1, s.distributeCandies(v3));
}