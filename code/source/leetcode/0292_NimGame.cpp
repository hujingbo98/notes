/**
 * Source : https://leetcode-cn.com/problems/nim-game/
 * Author : Hu Jingbo
 * Date   : 2021-09-18
 * 
 * 292. Nim 游戏
 * 
 * 你和你的朋友，两个人一起玩 Nim 游戏：
 * - 桌子上有一堆石头。
 * - 你们轮流进行自己的回合，你作为先手。
 * - 每一回合，轮到的人拿掉 1 - 3 块石头。
 * - 拿掉最后一块石头的人就是获胜者。
 * - 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 
 *   的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
 *  
 * 示例 1：
 * 输入：n = 4
 * 输出：false 
 * 解释：如果堆中有 4 块石头，那么你永远不会赢得比赛；
 *      因为无论你拿走 1 块、2 块还是 3 块石头，最后一块石头总是会被你的朋友拿走。
 * 
 * 示例 2：
 * 输入：n = 1
 * 输出：true
 * 
 * 示例 3：
 * 输入：n = 2
 * 输出：true
 * 
 * 提示：
 * 1 <= n <= 231 - 1
 */

#include "gtest/gtest.h"

class Solution {
public:
    /**
     * 方法一：数学推理
     * 
     * 根据游戏规则，当在你的回合，堆中有大于零小于三块石头是，你可以把全部石头拿走，
     * 从而在游戏中取胜。
     * 
     * 如果堆中有 4 块石头，那么你永远不会赢得比赛；因为无论你拿走 1 块、2 块还是 3
     * 块石头，最后一块石头总是会被你的朋友拿走。
     * 
     * 因此，我们只需每次拿完石头后，堆中剩余的石头是 4 的倍数，就可保证赢得比赛。
     * 因为如果对方回合堆中剩余石头是 4 的倍数，无论对方拿走几个石头，我们都可以保
     * 证，对方下个回合还是 4 的倍数，直到堆中剩余 4 个石头，那么对方就输定了。
     * 
     * 所以当我们作为先手，如果开局堆中石头不是 4 的倍数就稳赢。
     * 
     * 时间复杂度为 O(1)。
     * 空间复杂度为 O(1)。
     */
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

TEST(Solution, canWinNim) {
    Solution s;
    EXPECT_EQ(false, s.canWinNim(4));
    EXPECT_EQ(true, s.canWinNim(1));
    EXPECT_EQ(true, s.canWinNim(2));
}