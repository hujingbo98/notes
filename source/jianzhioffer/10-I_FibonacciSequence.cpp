/**
 * Source : https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
 * Author : Hu Jingbo
 * Date   : 2021-09-04
 * 
 * 剑指 Offer 10- I. 斐波那契数列
 * 
 * 写一个函数，输入 n，求斐波那契(Fibonacci)数列的第 n 项(即F(N))。
 * 斐波那契数列的定义如下：
 * F(0) = 0, F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 * 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
 * 答案需要取模 1e9+7(1000000007)，如计算初始结果为：1000000008，请返回 1。
 * 
 * 示例 1：
 * 输入：n = 2
 * 输出：1
 * 
 * 示例 2：
 * 输入：n = 5
 * 输出：5
 * 
 * 提示：
 * 0 <= n <= 100
 * 通过次数243,093提交次数680,358
 */

#include "gtest/gtest.h"
#include "vector"

using namespace std;

class Solution {
public:
    /**
     * 递归
     * 
     * 斐波那契的边界是 F(0) = 0, F(1) = 1。当 n > 1 时，每一项的和都等于前两项的
     * 和，因此，有如下递推关系：
     *              F(n) = F(n - 1) + F(n - 2)
     * 因此，可直接使用递归求取 F(n)。
     * 注意：计算过程中，答案需取模 le9 + 7。
     * 
     * 时间复杂度为 O(2^n)，空间复杂度为 O(n)。
     */
    int fib(int n) {
        if (n < 2) return n;
        int MOD = 1000000007;
        return (fib(n - 1) + fib(n - 2)) % MOD;
    }

    /**
     * 动态规划
     * 
     * 斐波那契的边界是 F(0) = 0, F(1) = 1。当 n > 1 时，每一项的和都等于前两项的
     * 和，因此，有如下递推关系：
     *              F(n) = F(n - 1) + F(n - 2)
     * 由于斐波那契有递推关系，因此可以使用动态规划求解。动态规划的状态转移方程即为
     * 上述的递推关系，边界条件为 F(0) 和 F(1)。
     * 根据状态转移方程和边界条件，可以得到时间复杂度和空间复杂度都是 O(n) 的实现。
     * 由于 F(n) 只和 F(n - 1) 与 F(n - 2) 有关，因此可以使用滚动数组思想把空间
     * 复杂度优化为 O(1)。
     * 注意：计算过程中，答案需取模 le9 + 7。
     * 
     * 时间复杂度为 O(n)，空间复杂度为 O(1)。
     */
    int fib_V2(int n) {
        if (n < 2) return n;
        int MOD = 1000000007;
        int array[3] = {0, 1};
        for (int i = 2; i <= n; ++i) {
            array[2] = (array[0] + array[1]) % MOD;
            array[0] = array[1];
            array[1] = array[2];
        }
        return array[2];
    }

    /**
     * 矩阵快速幂
     * 
     * 使用矩阵快速幂的方法可以降低时间复杂度。
     * 首先我们可以构造这样一种递推关系：
     *               {{1, 1}, {1, 0}} * {F(n), F(n-1)} 
     *               = {F(n) + F(n-1), F(n)}
     *               = {F(n+1), F(n)}
     * 因此 {F(n+1), F(n)} = {{1, 1}, {1, 0}}^n * {F(1), F(0)}
     * 令 M = {{1, 1}, {1, 0}}
     * 因此只要能快速的计算矩阵 M 的 n 次幂，就可以得到 F(n) 的值。如果直接求取
     * M^n，时间复杂度为 O(n)，可以定义矩阵乘法，然后用快速幂算法来加速 M^n 的求取。
     * 注意：计算过程中，答案需取模 le9 + 7。
     * 
     * 时间复杂度为 O(log n)，空间复杂度为 O(1);
     */
    int fib_V3(int n) {
        if (n < 2) return n;
        Matrix q{{1, 1}, {1, 0}};
        Matrix res = fastpow(q, n-1);
        return res[0][0];
        return 0;
    }
private:
    using Matrix = vector<vector<long>>;
    const int MOD = 1000000007;
    Matrix fastpow(const Matrix& a, int n) {
        Matrix ret = {{1, 0}, {0, 1}};
        Matrix t = a;
        while (n > 0) {
            if (n & 1) {
                ret = multiply(ret, t);
            }
            n >>= 1;
            t = multiply(t, t);
        }
        return ret;
    }

    Matrix multiply(const Matrix& a, const Matrix& b) {
        Matrix res = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                res[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
            }
        }
        return res;
    }
};

TEST(Solution, fib) {
    Solution s;
    for (int i = 0; i < 1; ++i) {
        EXPECT_EQ(0, s.fib(0));
        EXPECT_EQ(1, s.fib(1));
        EXPECT_EQ(1, s.fib(2));
        EXPECT_EQ(2, s.fib(3));
        EXPECT_EQ(3, s.fib(4));
        EXPECT_EQ(5, s.fib(5));
        // EXPECT_EQ(586268941, s.fib(50));
        // EXPECT_EQ(687995182, s.fib(100));
    }
}

TEST(Solution, fib_V2) {
    Solution s;
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(0, s.fib_V2(0));
        EXPECT_EQ(1, s.fib_V2(1));
        EXPECT_EQ(1, s.fib_V2(2));
        EXPECT_EQ(2, s.fib_V2(3));
        EXPECT_EQ(3, s.fib_V2(4));
        EXPECT_EQ(5, s.fib_V2(5));
        EXPECT_EQ(586268941, s.fib_V3(50));
        EXPECT_EQ(687995182, s.fib_V2(100));
    }
}

TEST(Solution, fib_V3) {
    Solution s;
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(0, s.fib_V3(0));
        EXPECT_EQ(1, s.fib_V3(1));
        EXPECT_EQ(1, s.fib_V3(2));
        EXPECT_EQ(2, s.fib_V3(3));
        EXPECT_EQ(3, s.fib_V3(4));
        EXPECT_EQ(5, s.fib_V3(5));
        EXPECT_EQ(586268941, s.fib_V3(50));
        EXPECT_EQ(687995182, s.fib_V3(100));
    }
}