/**
 * Source : https://leetcode-cn.com/problems/super-washing-machines/
 * Author : Hu Jingbo
 * Date   : 2021-09-29
 * 
 * 517. 超级洗衣机
 * 
 * 假设有 n 台超级洗衣机放在同一排上。开始的时候，每台洗衣机内可能有一定量的衣服，也可
 * 能是空的。
 * 
 * 在每一步操作中，你可以选择任意 m (1 <= m <= n) 台洗衣机，与此同时将每台洗衣机的一
 * 件衣服送到相邻的一台洗衣机。
 * 
 * 给定一个整数数组 machines 代表从左至右每台洗衣机中的衣物数量，请给出能让所有洗衣机
 * 中剩下的衣物的数量相等的最少的操作步数。如果不能使每台洗衣机中衣物的数量相等，则返
 * 回 -1 。
 * 
 * 示例 1：
 * 
 * 输入：machines = [1,0,5]
 * 输出：3
 * 解释：
 * 第一步:    1     0 <-- 5    =>    1     1     4
 * 第二步:    1 <-- 1 <-- 4    =>    2     1     3    
 * 第三步:    2     1 <-- 3    =>    2     2     2   
 * 
 * 示例 2：
 * 
 * 输入：machines = [0,3,0]
 * 输出：2
 * 解释：
 * 第一步:    0 <-- 3     0    =>    1     2     0    
 * 第二步:    1     2 --> 0    =>    1     1     1     
 * 
 * 示例 3：
 * 
 * 输入：machines = [0,2,0]
 * 输出：-1
 * 解释：
 * 不可能让所有三个洗衣机同时剩下相同数量的衣物。
 * 
 * 提示：
 * 
 * n == machines.length
 * 1 <= n <= 10^4
 * 0 <= machines[i] <= 10^5
 */

#include <vector>
#include <numeric>
#include <algorithm>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：贪心
     * 
     * 我们可以累加每台洗衣机的衣物数，得到衣物总数 tot。要使最终每台洗衣机中衣物的数
     * 量相等，那么 tot 必须是 n 的倍数，否则可以直接返回 -1。
     * 
     * 记 avg = tot / n，定义 machines[i]' = machines[i] - avg，若 machines[i]'
     * 为正则说明要移出 machines[i]' 件衣物，为负则说明要移入 -machines[i]' 件衣物。
     * 
     * 将前 i 台洗衣机看成一组，记作 A，其余洗衣机看成另一组，记作 B。
     * 设 sum[i] = sigma[j=0, i](machines[i]')，若 sum[i] 为正则说明需要从 A 向 B
     * 移入 sum[i] 件衣物，为负则说明需要从 B 向 A 移入 -sum[i] 件衣物。
     * 
     * 我们分两种情况来考虑操作步数：
     *  1. A 与 B 两组之间的衣物，最多需要 max[i=0, n-1](|sum[i]|) 次衣物移动。
     *  2. 组内的某一台洗衣机的衣物数量过多，需要向左右两侧移出衣物，这最多需要
     *     max[i=0, n-1](machines[i]') 次衣物移动。
     * 取两者最大值即为答案。
     * 
     * 时间复杂度是 O(n)，其中 n 是洗衣机的数量。
     * 
     * 空间复杂度为 O(1)。
     */
    int findMinMoves(vector<int>& machines) {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (tot % n)
            return -1;
        
        int avg = tot / n;
        int ans = 0, sum = 0;
        for (int num : machines) {
            num -= avg;
            sum += num;
            ans = max(ans, max(abs(sum), num));
        }

        return ans;
    }
};

TEST(Solution, findMinMoves) {
    Solution s;

    vector<int> machines = {1, 0, 5};
    EXPECT_EQ(3, s.findMinMoves(machines));

    vector<int> machines_2 = {0, 3, 0};
    EXPECT_EQ(2, s.findMinMoves(machines_2));
}