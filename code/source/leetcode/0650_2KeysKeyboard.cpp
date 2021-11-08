/**
 * Source : https://leetcode-cn.com/problems/2-keys-keyboard/
 * Author : Hu Jingbo
 * Date   : 2021-09-19
 * 
 * 650. 只有两个键的键盘
 * 
 * 最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：
 * 
 * Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
 * Paste（粘贴）：粘贴 上一次 复制的字符。
 * 给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A'。返回能
 * 够打印出 n 个 'A' 的最少操作次数。
 * 
 * 示例 1：
 * 输入：3
 * 输出：3
 * 解释：
 * 最初, 只有一个字符 'A'。
 * 第 1 步, 使用 Copy All 操作。
 * 第 2 步, 使用 Paste 操作来获得 'AA'。
 * 第 3 步, 使用 Paste 操作来获得 'AAA'。
 * 
 * 示例 2：
 * 输入：n = 1
 * 输出：0
 * 
 * 提示：
 * 1 <= n <= 1000
 */

#include <vector>
#include <limits>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：动态规划
     * 
     * 设 f(i) 表示打印出 i 个 A 的最少操作次数。由于我们只能使用复制全部和粘贴两种
     * 操作，那么要想得到 i 个 A，我们必须先拥有 j 个 A，使用一次复制全部操作，和若
     * 干次粘贴操作得到 i 个 A。
     * 
     * 因此，这里的 j 必须是 i 的因数，即 i mod j = 0，复制全部操作的使用次数是 1 
     * 次，粘贴操作的使用次数是 i/j - 1 次。我们可以枚举 j 进行状态转移，这样就可以
     * 得到状态转移方程：
     *          f(i) = min(f(j) + i/j)，(i mod j = 0)
     * 动态规划的边界条件为 f(1) = 0，最终的答案为 f(n)。
     * 
     * 细节：
     * 在枚举 i 的因数 j 时，我们可以在 O(i) 的时间内枚举 [1, i)。
     * 由于 i 肯定同时拥有因数 j 和 i/j，二者必有一个小于 sqrt(i) (sqrt 表示开平方
     * 根)，因此，一种时间复杂度更低的方法是，我们只需要在 [1, sqrt(i)] 的范围内枚
     * 举 j，并用 j 和 i/j 分别作为因数进行状态转移，时间复杂度为 O(sqrt(i))。
     * 
     * 时间复杂度为 O(n*sqrt(n))。
     * 空间复杂度为 O(n)。存储所有状态需要的空间为 O(n)。
     */
    int minSteps(int n) {
        vector<int> f(n+1);
        f[1] = 0;
        for (int i = 2; i <= n; ++i) {
            f[i] = std::numeric_limits<int>::max();
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i/j);
                    f[i] = min(f[i], f[i/j] + j);
                }
            }
        }
        return f[n];
    }

    /**
     * 方法二：分解质因数
     * 
     * 观察方法一中的状态转换方程：
     *      f(n) = min(f[i], f[j] + i/j), (i mod j = 0)
     * 可以转写成等价的形式：
     *      f(n) = min(f[i]，f[i/j] + j)，(i mod j = 0)
     * 此时状态转移方程就有了直观上的表述，即 f(n) 表示：
     * 给定初始值 n，我们希望经过若干次操作将其变为 1。每次操作我们选择 n 的一个大于
     * 1 的因数 j，耗费 j 的代价将 n 减少为 n/j。在所有可行的操作序列中，总代价的最
     * 小值即为 f(n)。
     * 我们选择的所有因数的乘积必然为 n。因此我们将 n 拆分成若干个大于 1 的整数的乘
     * 积，即
     *      n = a1 * a2 * ... * ak  , (k < n)
     * 那么总代价为 a1 + a2 + ... + ak。
     * 如果 ai 为素数，那么无法继续进行拆分；如果 ai 为合数，那么对于任意一种将 ai 
     * 拆分成两个大于 1 的整数的方式：
     *      ai = m * n
     * 拆分前的代价为 m * n，拆分后的代价为 m + n。由于 m, n 均大于 1，因此：
     *      m + n <= m * n
     * 恒成立。也就是说，在达到最小的总代价时，我们将 n 拆分成了若干个素数的乘积。
     * 因此我们只需对 n 进行质因数分解，统计所有质因数的和，即为最终答案。
     * 
     * 证明 m + n <= m * n, 其中 m, n 均大于 1。
     *      m * n - (m + n) = (m - 1) * (n - 1) - 1 >= 0
     * 得证。
     * 
     * 时间复杂度为 O(sqrt(n))。
     * 空间复杂度为 O(1)。
     */
    int minSteps_V2(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        if (n > 1)
            ans += n;
        return ans;
    }
};

TEST(Solution, minSteps) {
    Solution s;
    EXPECT_EQ(0, s.minSteps(1));
    EXPECT_EQ(2, s.minSteps(2));
    EXPECT_EQ(3, s.minSteps(3));
    EXPECT_EQ(4, s.minSteps(4));
    EXPECT_EQ(14, s.minSteps(100));
    EXPECT_EQ(21, s.minSteps(1000));

    EXPECT_EQ(0, s.minSteps_V2(1));
    EXPECT_EQ(2, s.minSteps_V2(2));
    EXPECT_EQ(3, s.minSteps_V2(3));
    EXPECT_EQ(4, s.minSteps_V2(4));
    EXPECT_EQ(14, s.minSteps_V2(100));
    EXPECT_EQ(21, s.minSteps_V2(1000));
}