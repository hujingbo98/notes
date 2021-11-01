/**
 * Source : https://leetcode-cn.com/problems/valid-parenthesis-string/
 * Author : Hu Jingbo
 * Date   : 2021-09-12
 * 
 * 678. 有效的括号字符串
 * 
 * 给定一个只包含三种字符的字符串：'('，')' 和 '*'，写一个函数来检验这个字符串是否
 * 为有效字符串。有效字符串具有如下规则：
 * 
 * 任何左括号 ( 必须有相应的右括号 )。
 * 任何右括号 ) 必须有相应的左括号 ( 。
 * 左括号 ( 必须在对应的右括号之前 )。
 * * 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
 * 一个空字符串也被视为有效字符串。
 * 
 * 示例 1:
 * 输入: "()"
 * 输出: True
 * 
 * 示例 2:
 * 输入: "(*)"
 * 输出: True
 * 
 * 示例 3:
 * 输入: "(*))"
 * 输出: True
 * 
 * 注意:
 * 字符串大小将在 [1，100] 范围内。
 */

#include <string>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 方法一：栈
     * 
     * 可以用栈的思想，我们初始化两个栈 ls (left stack) 和 as (asterisk stack)，
     * 前者用来保存 '(' 在字符串中的下标，后者保存 '*' 在字符串中的下标。
     * 
     * '*' 可以被视为 '('、')' 和空，因此我们可以保留 '*'，即遇到 ')' 先出栈 '('，
     * 再出栈 '*'。因此我们执行下面策略来匹配掉 ')'：
     *  1. 遇到 '(' 压栈 ls。
     *  2. 遇到 '*' 压栈 as。
     *  3. 遇到 ')' 优先弹栈 ls, 如果 ls 为空，则弹栈 as，如果 as 也为空，则说明
     *     此 ')' 无匹配的左括号，返回 false。
     * 
     * 最后再匹配 '(' 和 '*'，我们还是按照栈的思想匹配，取出 ls 栈顶的 '('，去匹配
     * as 栈顶的 '*'，如果 as 栈为空，则匹配失败，返回 false。如果 '(' 在 '*' 的
     * 左侧，则匹配成功，弹出 ls 和 as。否则，弹出 as，继续匹配。直到 ls 中的 '(' 
     * 全部匹配完，则说明此字符串是有效的括号字符串。具体如下：
     *  1. 如果 ls 为空，返回 true，否则，取 ls 的栈顶元素 l。
     *  2. 如果 as 为空，返回 false，否则，取 as 的栈顶元素 a，如果 l < a，则说明
     *     l 在 a 的左侧，匹配成功，弹栈 ls 和 as，否则，弹栈 as 继续执行第 2 步。
     *  3. 继续执行第 1 步。
     * 
     * 时间复杂度为 O(n)，n 为字符串的长度。
     * 空间复杂度为 O(n)，主要为两个栈的开销。
     */
    bool checkValidString(string s) {
        stack<int> ls; // left stack
        stack<int> as; // asterisk stack
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ls.push(i);
            } else if (s[i] == '*') {
                as.push(i);
            } else if (s[i] == ')') {
                if (!ls.empty()) {
                    ls.pop();
                } else if (!as.empty()) {
                    as.pop();
                } else {
                    return false;
                }
            }
        }
        int lsLen = ls.size();
        bool found;
        for (int i = 0; i < lsLen; ++i) {
            found = false;
            while (!as.empty()) {
                if (as.top() > ls.top()) {
                    ls.pop();
                    as.pop();
                    found = true;
                    break;
                } else {
                    as.pop();
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    /**
     * 方法二：贪心
     * 
     * 使用贪心的思想，可以将空间复杂度降到 O(1)。
     * 从左到右遍历字符串，遍历过程中，未匹配的左括号数量可能会出现如下变化：
     *  - 如果遇到左括号，则未匹配的左括号数量加 1；
     *  - 如果遇到右括号，则需要一个左括号和右括号匹配，因此未匹配的左括号的数量减
     *    1；
     *  - 如果遇到星号，由于星号可以被视为左括号、右括号和空字符串，因此未匹配的左
     *    括号数量可能加 1，减 1 或不变。
     * 基于上述结论，可以在遍历过程中维护未匹配的左括号数量可能的最小值和最大值，根
     * 据遍历到的字符，更新最小值和最大值。
     *  - 如果遇到左括号，则将最小值和最大值分别加 1；
     *  - 如果遇到右括号，则将最小值和最大值分别减 1；
     *  - 如果遇到星号，则将最小值减 1，将最大值加 1；
     * 任何情况下，未匹配的左括号数量必须非负，因此当最大值变成负数时，说明没有左括
     * 号可以和右括号匹配，返回 false。当最小值为 0 时，不应将最小值减小，以确保最
     * 小值非负。遍历结束时，所有的左括号都应和右括号匹配，因此只有当最小值为 0 时，
     * 字符串 s 才是有效的括号字符串。
     * 
     * 时间复杂度为 O(n)，其中 n 为给定字符串的长度。
     * 空间复杂度为 O(1)。
     */
    bool checkValidString_V2(string s) {
        int min = 0;
        int max = 0;
        for (const auto& it : s) {
            if (it == '(') {
                ++min;
                ++max;
            } else if (it == ')') {
                if (min > 0) {
                    --min;
                }
                if (max > 0) {
                    --max;
                } else {
                    return false;
                }
            } else if (it == '*') {
                if (min > 0) {
                    --min;
                }
                ++max;
            }
        }
        if (0 == min)
            return true;
        return false;
    }
};

TEST(Solution, checkValidString) {
    Solution s;
    EXPECT_EQ(true, s.checkValidString(""));
    EXPECT_EQ(true, s.checkValidString("()"));
    EXPECT_EQ(true, s.checkValidString("(*)"));
    EXPECT_EQ(true, s.checkValidString("(*))"));
    EXPECT_EQ(true, s.checkValidString("((*)"));
    EXPECT_EQ(false, s.checkValidString("(((((*(()((((*((**(((()()*)()()()*(("
        "((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));

    EXPECT_EQ(true, s.checkValidString_V2(""));
    EXPECT_EQ(true, s.checkValidString_V2("()"));
    EXPECT_EQ(true, s.checkValidString_V2("(*)"));
    EXPECT_EQ(true, s.checkValidString_V2("(*))"));
    EXPECT_EQ(true, s.checkValidString_V2("((*)"));
    EXPECT_EQ(false, s.checkValidString_V2("(((((*(()((((*((**(((()()*)()()()*"
        "((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));
}