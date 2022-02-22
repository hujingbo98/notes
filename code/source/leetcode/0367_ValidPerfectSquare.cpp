/**
 * Source : https://leetcode-cn.com/problems/valid-perfect-square/
 * Author : Hu Jingbo
 * Date   : 2021-11-04
 * 
 * 367. 有效的完全平方数
 * 
 * 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否
 * 则返回 false 。
 * 
 * 进阶：不要 使用任何内置的库函数，如  sqrt 。
 * 
 * 示例 1：
 * 输入：num = 16
 * 输出：true
 * 
 * 示例 2：
 * 输入：num = 14
 * 输出：false
 * 
 * 提示：
 * 1 <= num <= 2^31 - 1
 */

#include <climits>

#include "gtest/gtest.h"

class Solution {
public:
    /**
     * 方法一：二分法
     */
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long square = (long long)mid * mid;
            if (square == num) {
                return true;
            } else if (square < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

TEST(Solution, isPerfectSquare) {
    Solution s;

    EXPECT_TRUE(s.isPerfectSquare(0));
    EXPECT_TRUE(s.isPerfectSquare(1));
    EXPECT_TRUE(s.isPerfectSquare(16));
    EXPECT_FALSE(s.isPerfectSquare(14));
    EXPECT_FALSE(s.isPerfectSquare(INT_MAX));
    EXPECT_FALSE(s.isPerfectSquare(INT_MIN));
}