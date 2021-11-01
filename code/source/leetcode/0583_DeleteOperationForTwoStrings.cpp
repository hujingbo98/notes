/**
 * Source : https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 * Author : Hu Jingbo
 * Date   : 2021-09-25
 * 
 * 583. 两个字符串的删除操作
 * 
 * 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可
 * 以删除任意一个字符串中的一个字符。
 * 
 * 示例：
 * 输入: "sea", "eat"
 * 输出: 2
 * 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 *  
 * 提示：
 * 给定单词的长度不超过500。
 * 给定单词中的字符只含有小写字母。
 */

#include <string>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /**
     * 方法一：最长公共子序列 - 动态规划
     * 
     * 我们可以计算出 word1 和 word2 的最长公共子序列 lcs，则最少操作次数为：
     *                    m - lcs + n - lcs
     * 
     * 使用动态规划计算最长公共子序列：
     * 
     * 假设 word1 和 word2 的长度为 m 和 n，创建 m+1 行 n+1 列的二维数组 dp，其中
     * dp[i][j] 表示 word1[0:i] 和 word2[0:j] 的最长公共子序列的长度。
     * 
     * 上述表示中，word1[0:i] 表示 word1 的长度为 i 的前缀，word2[0:j] 表示 word2
     * 的长度为 j 的前缀。
     * 
     * 考虑动态规划的边界情况：
     *  - 当 i = 0 时，word1[0:i] 为空，空字符串和任意字符串的最长公共子序列的长度
     *    都是 0，因此，对于任意 0 <= j <= n，有 dp[0][j] = 0。
     *  - 当 j = 0 时，word2[0:j] 为空，同理可得，对任意 0 <= i <= m，有
     *    dp[i][0] = 0。
     * 因此动态规划的边界是：当 i = 0 或 j = 0 时，有 dp[i][j] = 0。
     * 
     * 当 i > 0 且 j > 0 时，考虑 dp[i][j] 的计算：
     *  - 当 word1[i-1] 等于 word2[j-1] 时，将这两个相同的字符称为公共字符，考虑
     *    word1[0:i-1] 和 word2[0:j-1] 的最长公共子序列，再增加一个字符（即公共字
     *    符）即可得到 word1[0:i] 和 word2[0:j] 的最长公共子序列，因此
     *    dp[i][j] = dp[i-1][j-1] + 1。
     *  - 当 word1[i-1] 不等于 word2[j-1] 时，dp[i][j] 应取 dp[i-1][j] 和 
     *    dp[i][j-1] 中较大的一项。
     * 因此，可得到状态转移方程：
     *             0                            i = 0 或 j = 0
     *  dp[i][j] = dp[i-1][j-1] + 1             word1[i-1] = word2[j-1]
     *             max(dp[i-1][j], dp[i][j-1])  word1[i-1] != word2[j-1]
     * 
     * 最终计算得到 dp[m][n] 即为 word1 和 word2 的最长公共子序列的长度。
     * 
     * 时间复杂度是 O(mn)，其中 m、n 分别是字符串 word1 和 word2 的长度。二维数组 dp
     * 有 m + 1 行，n + 1 列，需要对 dp 中每个元素进行计算。
     * 
     * 空间复杂度是 O(mn)，其中 m、n 分别是字符串 word1 和 word2 的长度。创建了 m+1
     * 行，n+1 列的二维数组 dp。
     */
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            char c1 = word1[i-1];
            for (int j = 1; j <= n; ++j) {
                char c2 = word2[j-1];
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
    /**
     * 方法二：动态规划
     * 
     * 可以直接使用动态规划计算最少删除操作次数，不需要计算最长公共子序列。
     * 
     * 假设 word1 和 word2 的长度分别是 m 和 n，创建 m + 1 行 n + 1 列的二维数组 dp，
     * 其中 dp[i][j]表示使 word1[0:i] 和 word2[0:j] 相同的最少删除操作次数。
     * 
     * 上述表示中，word1[0:i] 表示 word1 的长度为 i 的前缀，word2[0:j] 表示 word2 
     * 的长度为 j 的前缀。
     * 
     * 动态规划的边界情况：
     *  - 当 i = 0 时，word1[0:i] 为空，空字符串与任何字符串要变成相同，只需将另一个
     *    字符串全部删除，因此对任意 0 <= j <= n，有 dp[0][j] = j。
     *  - 当 j = 0 时，word2[0:j] 为空，同理可得，对任意 0 <= i <= n，有
     *    dp[i, 0] = i;
     * 当 i > 0 且 j > 0 时，考虑计算 dp[i][j]。
     *  - 当 word1[i] = word2[j] 时，将这两个相同的字符称为公共字符，考虑使 
     *    word1[0:i-1] 和 word2[0:j-1] 相同的最少删除操作次数，增加一个公共字符后，
     *    最少删除操作次数不变，因此 dp[i][j] = dp[i-1][j-1]。
     *  - 当 word1[i] != word2[j] 时，考虑一下两项：
     *    * 使 word1[0:i-1] 和 word2[0:j] 相同的最少删除操作次数，加上删除 word1[i]
     *      的 1 次操作。
     *    * 使 word1[0:i] 和 word2[0:j-1] 相同的最少删除操作次数，加上删除 word2[j]
     *      的 1 次操作。
     *    要得到使 word1[0:i] 和 word2[0:j] 相同的最少删除操作次数，应去两项中较小的
     *    一项，因此
     *    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
     * 因此可得到状态转移方程：
     *             j                                i = 0
     *  dp[i][j] = i                                j = 0
     *             dp[i-1][j-1]                     i > 0 and j > 0 and word1[i] = word2[j]
     *             min(dp[i-1][j], dp[i][j-1]) + 1  i > 0 and j > 0 and word1[i] != word2[j]
     * 最终计算得到的 dp[m][n] 即为使 word1 和 word2 相同的最少删除操作次数。
     * 
     * 时间复杂度是 O(mn)，其中 m 和 n 分别是 word1 和 word2 的长度。二维数组 dp 有
     * m+1 行 n+1 列，需要对 dp 中的每一个元素进行计算。
     * 
     * 空间复杂度是 O(mn)，其中 m 和 n 分别是 word1 和 word2 的长度。创建了 m + 1 行
     * n + 1 列的二维数组 dp。
     */
    int minDistance_V2(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            char c1 = word1[i-1];
            for (int j = 1; j <= n; ++j) {
                char c2 = word2[j-1];
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

TEST(Solution, minDistance) {
    Solution s;

    EXPECT_EQ(2, s.minDistance("sea", "eat"));

    EXPECT_EQ(2, s.minDistance_V2("sea", "eat"));
}
