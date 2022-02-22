/**
 * Source : https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 剑指 Offer 05. 替换空格
 * 
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * 
 * 示例 1：
 * 输入：s = "We are happy."
 * 输出："We%20are%20happy."
 * 
 * 限制：
 * 0 <= s 的长度 <= 10000
 */

#include <string>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int spaceCount = count(s.begin(), s.end(), ' ');
        int n = s.size();
        int ansN = n + spaceCount * 2;
        s.resize(ansN);
        int left = n - 1, right = ansN - 1;
        while (left < right) {
            if (s[left] == ' ') {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
            } else {
                s[right--] = s[left];
            }
            --left;
        }
        return s;
    }
};

TEST(Solution, 05_ReplaceSpace) {
    Solution so;

    string s = "We are happy.";
    string ans = "We%20are%20happy.";
    EXPECT_EQ(ans, so.replaceSpace(s));
}