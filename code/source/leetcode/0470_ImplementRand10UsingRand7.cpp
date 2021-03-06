/**
 * Source : https://leetcode-cn.com/problems/implement-rand10-using-rand7/
 * Author : Hu Jingbo
 * Date   : 2021-09-05
 * 
 * 470. 用 Rand7() 实现 Rand10()
 * 
 * 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 
 * 到 10 范围内的均匀随机整数。不要使用系统的 Math.random() 方法。
 *  
 * 示例 1:
 * 输入: 1
 * 输出: [7]
 * 
 * 示例 2:
 * 输入: 2
 * 输出: [8,4]
 * 
 * 示例 3:
 * 输入: 3
 * 输出: [8,1,10]
 * 
 * 提示:
 * rand7 已定义。
 * 传入参数: n 表示 rand10 的调用次数。
 *  
 * 进阶:
 * rand7()调用次数的 期望值 是多少 ?
 * 你能否尽量少调用 rand7() ?
 */

#include <random>

#include "gtest/gtest.h"

class Solution {
public:
    // The rand7() API is already defined for you.
    // int rand7();
    // @return a random integer in the range 1 to 7
    // 模拟 rand7()
    int rand7() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 7);
        return dis(gen);
    }
    /**
     * 方法一：拒绝采样
     * 
     * 可以使用拒绝采样的方法实现 rand10()。在拒绝采样中，如果生成的随机数满足要求，
     * 那么就返回该随机数，否则会不断生成，直到生成一个满足要求的随机数为止。
     * 我们只需要能够满足等概率生成 10 个不同的数即可，具体生成的方法有很多种，比如
     * 我们可以利用两个 rand7() 相乘，或利用两个 rand7() 组成一个两位的 8 进制数，
     * 只需取其中等概率的 10 个不同的数的组合即可。
     * 在这里我们使用两个 rand7() 数 a、b 组成一个 8 进制数 ab，即生成 49 个
     * 数的集合为 [1, 49]，其中每个数的概率为 1/49，我们只用前 40 个来实现 
     * rand10()，而拒绝剩下的 9 个数。当前 40 个数转化为 [1, 10] 时，
     * 这 10 个数中每个数的生成概率为 4/49。
     * 
     * 期望时间复杂度为 O(1)，但最坏情况下会达到 O(∞) (一直被拒绝)。
     * 空间复杂度为 O(1)。
     * 
     * 循环 10000 次的测试结果：
     * [ RUN      ] Solution.rand10
     * [       OK ] Solution.rand10 (497 ms)
     */
    int rand10() {
        int n;
        do {
            n = (rand7() - 1) * 7 + rand7();
        } while (n > 40);
        return (n - 1) % 10 + 1;
    }

    /**
     * 方法二：优化拒绝采样
     * 
     * 在方法一中，函数调用次数的期望：
     * 分析这种方法在平均情况下需要调用 rand7() 的次数。称连续调用两次 rand7() 为
     * 一轮，在第一轮中，有 40/49 的概率被接受，有 9/49 的概率被拒绝，进入第二轮随
     * 机。第二轮有 (9/49)^2 的概率被拒绝，以此类推，可以得到第 n 轮被拒绝的概率为
     * (9/49)^n。因此，调用 rand7() 的次数期望为：
     *      E(#call) = 2 + 2 * (9/49)^2 + 2 * (9/49)^3 + ...
     *                   ∞
     *               = 2 ∑ (9/49)^n
     *                  n=0
     *               = 2 * (1 / (1 - 9/49))
     *               = 2.45
     * 如何减少 rand7() 的调用次数：如果可以减少随机被拒绝的概率，从而就可以减少
     * rand7() 的调用次数期望，即可减少 rand7() 的平均调用次数。
     * 我们可以通过使用被拒绝的采样来优化方法一。在方法一，第一轮生成的 [1, 49] 的
     * 随机数，若生成的随机数 x 在 [41, 49]中，则拒绝 x。在 x 被拒绝的情况下，可以
     * 得到一个 [1, 9] 的随机数，如果再调用一次 rand7()，那么就可以生成 [1, 63] 的
     * 随机数。与方法一类似，保留 [1, 60] 拒绝 [61, 63]。若 x 在 [61, 63] 中，则
     * 继续调用 rand7()，生成 [1, 21] 的随机数，保留 [1, 20]，拒绝 21，此时 21 
     * 已经没有任何用处。若出现了拒绝 21 的情况，就重新开始生成 [1, 49] 的随机数。
     * 如此方法，调用 rand7() 的次数期望为：
     *      E(#call) 
     *      = 2 + 1 * 9/49 + 1 * 9/49 * 3 / 63 + 2 * 9/49 * 3/63 * 1/21 + ...
     *      = 2.19333
     * 
     * 循环 10000 次的测试结果：
     * [ RUN      ] Solution.rand10_V2
     * [       OK ] Solution.rand10_V2 (426 ms)
     */
    int rand10_V2() {
        int n;
        while (true) {
            n = (rand7() - 1) * 7 + rand7();
            if (n <= 40)
                return (n - 1) % 10 + 1;
            n -= 40;
            n = (n - 1) * 7 + rand7();
            if (n <= 60)
                return (n - 1) % 10 + 1;
            n -= 60;
            n = (n - 1) * 7 + rand7();
            if (n <= 20)
                return (n - 1) % 10 + 1;
        }
    }

    /**
     * 方法二(优化拒绝采样)的第二种实现。
     * 
     * 循环 10000 次的测试结果：
     * [ RUN      ] Solution.rand10_V2_2
     * [       OK ] Solution.rand10_V2_2 (450 ms)
     */
    int rand10_V2_2() {
        int n;
        int arr[3] = {40, 60, 20};
        int i;
        while (true) {
            n = rand7();
            for (i = 0; i < 3; ++i) {
                n = (n - 1) * 7 + rand7();
                if (n <= arr[i])
                    return (n - 1) % 10 + 1;
                else
                    n -= arr[i];
            }
        }
    }
};

TEST(Solution, rand10) {
    Solution s;
    int n;
    for (int i = 0; i < 10; ++i) {
        n = s.rand10();
        ASSERT_GE(10, n);
        ASSERT_LE(1, n);
    }
}

TEST(Solution, rand10_V2) {
    Solution s;
    int n;
    for (int i = 0; i < 10; ++i) {
        n = s.rand10_V2();
        ASSERT_GE(10, n);
        ASSERT_LE(1, n);
    }
}

TEST(Solution, rand10_V2_2) {
    Solution s;
    int n;
    for (int i = 0; i < 10; ++i) {
        n = s.rand10_V2_2();
        ASSERT_GE(10, n);
        ASSERT_LE(1, n);
    }
}