/**
 * Source : https://leetcode-cn.com/problems/number-of-boomerangs/
 * Author : Hu Jingbo
 * Date   : 2021-09-13
 * 
 * 447. 回旋镖的数量
 * 
 * 给定平面上 n 对 互不相同 的点 points ，其中 points[i] = [xi, yi] 。回旋镖 是由点 
 * (i, j, k) 表示的元组 ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元
 * 组的顺序）。
 * 
 * 返回平面上所有回旋镖的数量。
 *  
 * 示例 1：
 * 输入：points = [[0,0],[1,0],[2,0]]
 * 输出：2
 * 解释：两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 示例 2：
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：2
 * 
 * 示例 3：
 * 输入：points = [[1,1]]
 * 输出：0
 *  
 * 提示：
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * 所有点都 互不相同
 */

#include <vector>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 枚举 + 哈希表
     * 
     * 设 points 中有 m 个点到 points[i] 的距离均相等，我们需要从这 m 点中选出 2 个
     * 点当作回旋镖的 2 个端点，由于题目要求考虑元组的顺序，因此方案数即为在 m 个元素
     * 中选出 2 个不同元素的排列数，即：
     *                  A = m*(m-1)
     * 据此，我们可以遍历 points，计算并统计所有点到 points[i] 的距离，将每个距离的
     * 出现次数记录在哈希表中，然后遍历哈希表，并用上述公式计算并累加回旋镖的个数。
     * 
     * 在代码实现时，我们可以直接保存距离的平方，避免复杂的开方运算。
     * 
     * 时间复杂度为 O(n^2)，其中 n 为 points 的长度。
     * 空间复杂度为 O(n)。
     */
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (const auto& it : points) {
            unordered_map<int/*distant*/, int/*count*/> m;
            for (const auto& itt : points) {
                int distance = (it[0] - itt[0]) * (it[0] - itt[0])
                    + (it[1] - itt[1]) * (it[1] - itt[1]);
                ++m[distance];
            }
            for (const auto &[_, cnt]: m) {
                ans += cnt * (cnt - 1);
            }
        }
        return ans;
    }
};

TEST(Solution, numberOfBoomerangs) {
    Solution s;
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    vector<vector<int>> points_2 = {{1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> points_3 = {{1, 1}};
    EXPECT_EQ(2, s.numberOfBoomerangs(points));
    EXPECT_EQ(2, s.numberOfBoomerangs(points_2));
    EXPECT_EQ(0, s.numberOfBoomerangs(points_3));
}