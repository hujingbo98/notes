/**
 * Source : https://leetcode-cn.com/problems/ipo/
 * Author : Hu Jingbo
 * Date   : 2021-09-08
 * 
 * 502. IPO
 * 
 * 假设 力扣（LeetCode）即将开始 IPO。为了以更高的价格将股票卖给风险投资公司，力扣
 * 希望在 IPO 之前开展一些项目以增加其资本。由于资源有限，它只能在 IPO 之前完成最多
 * k 个不同的项目。帮助力扣设计完成最多 k 个不同项目后得到最大总资本的方式。
 * 给你 n 个项目。对于每个项目 i，它都有一个纯利润 profits[i]，和启动该项目需要的
 * 最小资本 capital[i]。最初，你的资本为 w。当你完成一个项目时，你将获得纯利润，且
 * 利润将被添加到你的总资本中。总而言之，从给定项目中选择最多 k 个不同项目的列表，
 * 以最大化最终资本，并输出最终可获得的最多资本。答案保证在 32 位有符号整数范围内。
 * 
 * 示例 1：
 * 输入：k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
 * 输出：4
 * 解释：
 * 由于你的初始资本为 0，你仅可以从 0 号项目开始。
 * 在完成后，你将获得 1 的利润，你的总资本将变为 1。
 * 此时你可以选择开始 1 号或 2 号项目。
 * 由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
 * 因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
 * 
 * 示例 2：
 * 输入：k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
 * 输出：6
 *  
 * 提示：
 * 1 <= k <= 10^5
 * 0 <= w <= 10^9
 * n == profits.length
 * n == capital.length
 * 1 <= n <= 10^5
 * 0 <= profits[i] <= 10^4
 * 0 <= capital[i] <= 10^9
 */

#include <vector>
#include <queue>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 贪心 + 堆
     * 
     * 思路：
     * 由题意知，在每次选择项目时，最佳选择是选取总资本大于或等于启动资本的项目中
     * 纯利润最高的项目，则可以保证最大化最终资本。
     * 由于资本是只增不减的，我们可以维护一个最大堆，来保存总资本大于等于启动资金的
     * 项目，最大堆中元素的键值是项目的纯利润，这样我们在选择项目时，直接取堆顶元素
     * 就可以保证最佳选择。由于资本是增加的，即我们可选取的项目是逐渐增多的，我们可
     * 以先将项目以启动资金为键排序后，再将启动资本小于或等于总资本的项目添加到最大
     * 堆，这样当资本增加后，我们可以利用之前的索引更新可选项目到最大堆。
     * 注意：当选择完一个项目时，要从最大堆中将其弹出。
     * 
     * 时间复杂度分析：
     * 数组的建立为 O(n)，排序为 O(nlog n)，最大堆的建立为 O(nlog n)，最大堆的弹出
     * 为 O(klog n)，所以总的时间复杂度为以上加起来，即 O((n + k)log n)，其中 n 是
     * 项目的个数。
     * 空间复杂度为 O(n)，其中 n 是项目的个数。空间复杂度主要用于创建数组和最大堆。
     */
    int findMaximizedCapital(int k, int w, vector<int>& profits, 
        vector<int>& capital) {
            std::pair<int, int> pa;
            priority_queue<int> q;
            vector<std::pair<int, int>> arr;
            int len = profits.size();
            for (int i = 0; i < len; ++i) {
                arr.push_back({capital[i], profits[i]});
            }
            std::sort(arr.begin(), arr.end());
            int j = 0;
            for (int i = 0; i < k; ++i) {
                while (j < len && arr[j].first <= w) {
                    q.push(arr[j++].second);
                }
                if (q.empty())
                    break;
                w += q.top();
                q.pop();
            }
        return w;
    }
};

TEST(Solution, findMaximizedCapital) {
    Solution s;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    EXPECT_EQ(4, s.findMaximizedCapital(2, 0, profits, capital));
    profits = {1, 2, 3};
    capital = {0, 1, 2};
    EXPECT_EQ(6, s.findMaximizedCapital(3, 0, profits, capital));
    profits = {1, 2, 3};
    capital = {1, 1, 2};
    EXPECT_EQ(0, s.findMaximizedCapital(1, 0, profits, capital));
}