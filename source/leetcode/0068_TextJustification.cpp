/**
 * Source : https://leetcode-cn.com/problems/text-justification
 * Author : Hu Jingbo
 * Date   : 2021-09-09
 * 
 * 68. 文本左右对齐
 * 
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 
 * 个字符，且左右两端对齐的文本。你应该使用“贪心算法”来放置给定的单词；也就是说，尽
 * 可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字
 * 符。要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左
 * 侧放置的空格数要多于右侧的空格数。文本的最后一行应为左对齐，且单词之间不插入额外
 * 的空格。
 * 
 * 说明:
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 示例:
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * 
 * 示例 2:
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 *   "What   must   be",
 *   "acknowledgment  ",
 *   "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 *      因为最后一行应为左对齐，而不是左右两端对齐。       
 *      第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 示例 3:
 * 输入:
 * words = ["Science","is","what","we","understand","well","enough","to",
 *          "explain","to","a","computer.","Art","is","everything","else",
 *          "we","do"]
 * maxWidth = 20
 * 输出:
 * [
 *   "Science  is  what we",
 *   "understand      well",
 *   "enough to explain to",
 *   "a  computer.  Art is",
 *   "everything  else  we",
 *   "do                  "
 * ]
 */

#include <vector>
#include <string>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    /**
     * 首先我们应该遍历给定的单词数组，然后逐行插入。
     * 
     * 题目要求在每一行中尽可能多的插入，并且除最后一行，其余行的空格应均匀分布，并
     * 且总是左边的空格多于右边的空格，所以我们应该提前得出每行最多可以插入 m 个单
     * 词，和每个单词之间的空格数量，然后再插入到行。
     * 
     * 每行插入最多单词数量可以维护一个变量 n 来累加的该行单词的长度，m 来累加该行
     * 单词的数量，注意除第一个单词其余单词前需至少一个空格，所以当遍历到一个单词 
     * w 时，如果此单词是该行的第一个单词，由于题目给出的每个单词的长度大于 0，小于
     * maxWidth，则我们可以直接将此单词插入该行，然后令 n = w.length，m = 1。
     * 如果此单词非第一个单词，我们应先判断 n + w.length + 1 + (m - 1)，是否小于
     * 或等于 maxWidth，其中第一个 m - 1 是已累加的非第一个单词前的至少一个空格。
     * 如果是，则 n 加 w.length，m 加 1，否则得到该行的最多可以插入 m 个单词。
     * 
     * 此时我们需要计算在非第一个单词前插入的空格数量，即在 m - 1 处插入空格，在每
     * 处插入的空格数量有两种情况：
     *  1. 最后一个单词已经累加到了该行，或者该行最多只能插入一个单词，即 m = 1。
     *     这种情况只需在非第一个单词前插入一个空格，并在最后补全空格即可。
     *  2. 第二种情况是需均匀分配，分为两部分，左侧和右侧
     *     左侧共有 l = (maxWidth - n) mod (m - 1) 处添加空格
     *     右侧共有 r = m - l - 1 处添加空格。
     *     左侧每处添加的空格数量为 nl = (maxWidth - n) / (m - 1) + 1
     *     右侧每处添加的空格数量为 nr = nl - 1
     * 注意：第二种情况中有 m - 1 作为除数，m = 1 即 m - 1 = 0 的情况已经在第一种
     * 情况中包括了，这里可以放心使用。
     * 
     * 时间复杂度为 O(m)，其中 m 是数组 words 中所有字符串的长度之和。
     * 空间复杂度为 O(m)。
     */
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int nlen = words.size();
        int i = 0;
        int n, m;
        string s;
        while (i < nlen) {
            s.clear();
            s += words[i];
            n = words[i].length();
            m = 1;
            ++i;
            while (i < nlen && 
                   static_cast<int>(n + words[i].length() + m) <= maxWidth) {
                n += words[i++].length();
                ++m;
            }
            if (i == nlen || m == 1) {
                for (int j = i - m + 1; j < i; ++j) {
                    s += " " + words[j];
                }
                int nspace = maxWidth - s.size();
                s.append(nspace, ' ');
            } else {
                int l = (maxWidth - n) % (m - 1);
                int nl = (maxWidth - n) / (m - 1) + 1;
                int j = i - m + 1;
                for (; j < i - m + 1 + l; ++j) {
                    s.append(nl, ' ');
                    s += words[j];
                }
                int nr = nl - 1;
                for (; j < i; ++j) {
                    s.append(nr, ' ');
                    s += words[j];
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};

TEST(Solution, fullJustify) {
    Solution s;

    vector<string> words = {"This", "is", "an", "example", "of", "text", 
        "justification."};
    vector<string> ans = s.fullJustify(words, 16);
    vector<string> stdAns = {"This    is    an", "example  of text",
        "justification.  "};
    ASSERT_EQ(stdAns.size(), ans.size());
    int nStdAns = stdAns.size();   
    for (int i = 0; i < nStdAns; ++i) {
        EXPECT_EQ(stdAns[i], ans[i]);
    }

    vector<string> words_2 = {"What","must","be","acknowledgment","shall","be"};
    vector<string> ans_2 = s.fullJustify(words_2, 16);
    vector<string> stdAns_2 = { "What   must   be",
                                "acknowledgment  ",
                                "shall be        "};
    ASSERT_EQ(stdAns_2.size(), ans_2.size());
    int nStdAns_2 = stdAns_2.size();   
    for (int i = 0; i < nStdAns_2; ++i) {
        EXPECT_EQ(stdAns_2[i], ans_2[i]);
    }
    
    vector<string> words_3 = {"Science","is","what","we","understand","well",
        "enough","to","explain","to","a","computer.","Art","is","everything",
        "else","we","do"};
    vector<string> ans_3 = s.fullJustify(words_3, 20);
    vector<string> stdAns_3 = { "Science  is  what we",
                                "understand      well",
                                "enough to explain to",
                                "a  computer.  Art is",
                                "everything  else  we",
                                "do                  "};
    ASSERT_EQ(stdAns_3.size(), ans_3.size());
    int nStdAns_3 = stdAns_3.size();   
    for (int i = 0; i < nStdAns_3; ++i) {
        EXPECT_EQ(stdAns_3[i], ans_3[i]);
    }
}