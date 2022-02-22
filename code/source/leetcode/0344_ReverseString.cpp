/**
 * Source : https://leetcode-cn.com/problems/reverse-string/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 344. 反转字符串
 * 
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决
 * 这一问题。
 * 
 * 示例 1：
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 示例 2：
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 * 提示：
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
 */

#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size() - 1;
        for (int i = 0; i < n; ++i, --n) {
            char temp = s[i];
            s[i] = s[n];
            s[n] = temp;
        }
    }
};

TEST(Solution, 0344_ReverseString) {
    Solution so;

    vector<char> s = {'h','e','l','l','o'};
    vector<char> ans = {'o','l','l','e','h'};
    so.reverseString(s);
    EXPECT_EQ(ans, s);

    vector<char> s_2 = {'H','a','n','n','a','h'};
    vector<char> ans_2 = {'h','a','n','n','a','H'};
    so.reverseString(s_2);
    EXPECT_EQ(ans_2, s_2);
}