/**
 * Source : https://leetcode-cn.com/problems/trapping-rain-water-ii
 * Author : Hu Jingbo
 * Date   : 2021-11-03
 * 
 * 407. 接雨水 II
 * 给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算
 * 图中形状最多能接多少体积的雨水。
 * 
 * 示例 1:
 * 输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
 * 输出: 4
 * 解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
 * 
 * 示例 2:
 * 输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],
 *                    [3,2,2,2,3],[3,3,3,3,3]]
 * 输出: 10
 * 
 * 提示:
 * m == heightMap.length
 * n == heightMap[i].length
 * 1 <= m, n <= 200
 * 0 <= heightMap[i][j] <= 2 * 10^4
 */

#include <vector>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    using PAIR = pair<int, int>;
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            if (!visit[i][0]) {
                pq.push({heightMap[i][0], i * n});
                visit[i][0] = true;
            }
            if (!visit[i][n - 1]) {
                pq.push({heightMap[i][n - 1], i * n + n - 1});
                visit[i][n - 1] = true;
            }
        }
        for (int j = 1; j < n - 1; ++j) {
            if (!visit[0][j]) {
                pq.push({heightMap[0][j], j});
                visit[0][j] = true;
            }
            if (!visit[m - 1][j]) {
                pq.push({heightMap[m - 1][j], (m - 1) * n + j});
                visit[m - 1][j] = true;
            }
        }

        int ans = 0;
        vector<int> dirs = {-1, 1, -n, n};
        while (!pq.empty()) {
            PAIR cur = pq.top();
            pq.pop();
            for (int dir : dirs) {
                int pos = cur.second + dir;
                int x = pos / n;
                int y = pos % n;
                if (x >= 0 && x < m && y >= 0 && y < n && !visit[x][y]) {
                    if (cur.first > heightMap[x][y]) {
                        ans += cur.first - heightMap[x][y];
                    }
                    visit[x][y] = true;
                    pq.push({max(cur.first, heightMap[x][y]), pos});
                }
            }
        }
        return ans;
    }
};

TEST(Solution, trapRainWater) {
    Solution s;

    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    s.trapRainWater(heightMap);
}