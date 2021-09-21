/**
 * Source : https://leetcode-cn.com/problems/length-of-last-word/
 * Author : Hu Jingbo
 * Date   : 2021-09-21
 * 
 * 58. 最后一个单词的长度
 * 给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一
 * 个单词的长度。单词是指仅由字母组成、不包含任何空格字符的最大子字符串。
 * 
 * 示例 1：
 * 输入：s = "Hello World"
 * 输出：5
 * 
 * 示例 2：
 * 输入：s = "   fly me   to   the moon  "
 * 输出：4
 * 
 * 示例 3：
 * 输入：s = "luffy is still joyboy"
 * 输出：6
 * 
 * 提示：
 * 1 <= s.length <= 10^4
 * s 仅有英文字母和空格 ' ' 组成
 * s 中至少存在一个单词
 */

#include <string>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：反向遍历查找字符
     * 
     * 先从后往前找到第一个非空格字符 s[i]，根据提示，s 中至少存在一个单词，因此非
     * 空格字符必然存在，然后从字符 s[i] 的前一个位置往前找第一个空格字符 s[j]；
     * 如果没找到，则从 s 的开头 s[0] 至 s[i] 就是最后一个单词，即答案为 i + 1；
     * 如果找到了，则从字符 s[j] 的下一个字符开始至字符 s[i] 就是最后一个单词，因此
     * 答案为 i - j。
     * 
     * 时间复杂度是 O(n)，其中 n 为 s 的长度。
     * 
     * 空间复杂度为 O(1)。
     */
    int lengthOfLastWord(string s) {
        auto i = s.find_last_not_of(' ');
        auto j = s.find_last_of(' ', i);
        if (j == string::npos)
            return i + 1;
        return i - j;
    }
};

TEST(Solution, lengthOfLaseWord) {
    Solution s;
    EXPECT_EQ(5, s.lengthOfLastWord("Hello World"));
    EXPECT_EQ(4, s.lengthOfLastWord("   fly me   to   the moon  "));
    EXPECT_EQ(6, s.lengthOfLastWord("luffy is still joyboy"));
    EXPECT_EQ(1, s.lengthOfLastWord("a"));
}