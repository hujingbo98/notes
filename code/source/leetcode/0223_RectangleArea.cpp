/**
 * Source : https://leetcode-cn.com/problems/rectangle-area/
 * Author : Hu Jingbo
 * Date   : 2021-09-30
 * 
 * 223. 矩形面积
 * 
 * 给你二维平面上两个由直线构成的矩形，请你计算并返回两个矩形覆盖的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示：
 * 
 * 第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
 * 第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 * 
 * 示例 1：
 * 输入：
 *      ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, 
 *      bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
 * 输出：45
 * 
 * 示例 2：
 * 输入：
 *      ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2,
 *      bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
 * 输出：16
 * 
 * 提示：
 * -10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
 */

#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /**
     * 方法一：计算重叠面积
     * 
     * 两个矩形覆盖的总面积等于两个矩形的面积之和减去两个矩形重叠部分的面积。由于两个
     * 矩形的左下顶点和右上顶点已知，因此两个矩形的面积可以直接计算。如果两个矩形重叠，
     * 则两个矩形的重叠部分也是矩形，重叠部分的面积可以根据重叠部分的边界计算。
     * 
     * 两个矩形的水平边投影的 x 轴上的线段分别为 [ax1, ax2] 和 [bx1, bx2]，数值边投
     * 影到 y 轴上的线段分别为 [ay1, ay2] 和 [by1, by2]。如果两个矩形重叠，则重叠部
     * 分的水平边投影到 x 轴上的线段为 m = [max(ax1, bx1), min(ax2, bx2)]，竖直边
     * 投影到 y 轴上的线段为 n = [max(ay1, by1), min(ay2, by2)]，根据 m 和 n 的长
     * 度可以计算重叠部分的面积。只有当 m 和 n 的长度都大于 0 时，两个矩形才有重叠部
     * 分。
     * 
     * 时间复杂度是 O(1)。
     * 
     * 空间复杂度是 O(1)。
     */
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        int overlapHeight = min(ay2, by2) - max(ay1, by1);
        int overlapArea = max(overlapWidth, 0) * max(overlapHeight, 0);
        return area1 + area2 - overlapArea;
    }
};

TEST(Solution, computeArea) {
    Solution s;

    EXPECT_EQ(45, s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
    EXPECT_EQ(16, s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2));
}