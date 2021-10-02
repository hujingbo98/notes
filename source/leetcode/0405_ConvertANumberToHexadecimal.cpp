/**
 * Source : https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/
 * Author : Hu Jingbo
 * Date   : 2021-10-02
 * 
 * 405. 数字转换为十六进制数
 * 
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用补码运
 * 算方法。
 * 
 * 注意:
 * 十六进制中所有字母(a-f)都必须是小写。
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；
 * 对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 * 
 * 示例 1：
 * 输入:
 * 26
 * 输出:
 * "1a"
 * 
 * 示例 2：
 * 输入:
 * -1
 * 输出:
 * "ffffffff"
 */

#include <string>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /**
     * 方法一：位运算
     * 
     * 题目要求将给定的整数 num 转换为十六进制数，负整数使用补码运算方法。
     * 
     * 在补码运算中，最高位表示符号位，符号位是 0 表示正整数和零，符号位是 1 表示负整
     * 数。32 未有符号整数的二进制数是 32 位，由于一位十六进制数对应四位二进制数，因此
     * 32 位有符号整数的十六进制有 8 位。
     * 
     * 将 num 的二进制数按照四位一组分成 8 组，依次将每一组转换为对应的十六进制数，即
     * 可得到 num 的十六进制数。
     * 
     * 假设二进制数的 8 组从低位到高位依次是第 0 组到第 7 组，则对于第 i 组，可以通过
     * (num >> (4*i)) & 0xf 的到该组的值，其取值范围是 0 到 15（即十六进制的 f）。
     * 将每一组的值转换为十六进制数的做法如下：
     *  - 对于 0 到 9，数字本身就是十六进制数。
     *  - 对于 10 到 15，将其转换为 a 到 f 中对应的字母。
     * 
     * 对于负整数，由于最高位一定不是 0，因此不会出现前导零。对于零和正整数，可能出现
     * 前导零。避免签到零的做法如下：
     *  - 如果 num = 0，则直接返回 0。
     *  - 如果 num > 0，则在遍历每一组的值时，从第一个不是 0 的值开始十六进制数。
     * 
     */
    string toHex(int num) {
        if (0 == num)
            return "0";

        string ans;
        for (int i = 7; i >= 0; --i) {
            int nbit = (num >> (i * 4)) & 0xf;
            if (ans.length() > 0 || nbit > 0) {
                char bit = nbit < 10 ? ('0' + nbit) : ('a' + nbit - 10);
                ans.push_back(bit);
            }
        }
        return ans;
    }
};

TEST(Solution, toHex) {
    Solution s;

    EXPECT_EQ("0", s.toHex(0));
    EXPECT_EQ("1a", s.toHex(26));
    EXPECT_EQ("ffffffff", s.toHex(-1));
}