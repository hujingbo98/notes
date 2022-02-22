/**
 * Source : https://leetcode-cn.com/problems/zuma-game/
 * Author : Hu Jingbo
 * Date   : 2021-11-09
 */

#include <string>
#include <unordered_map>
#include <functional>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> hash;
        for (char c : hand) {
            ++hash[c];
        }
        int useNumMin = 6;
        function<void(int)> backtrack = [&](int useNum){
            if (board.empty()) {
                useNumMin = min(useNumMin, useNum);
                return;
            }
            int n = board.length();
            for (int i = 0; i < n; ++i) {
                for (auto& h : hash) {
                    if (h.second <= 0)
                        continue;
                    if (i == 0 && h.first != board[i])
                        continue;
                    if (i > 0 && h.first == board[i - 1] && h.first == board[i])
                        continue;
                    if (i > 0 && h.first != board[i - 1] && h.first != board[i] && board[i - 1] != board[i])
                        continue;

                    string temp = board;

                    board.insert(i, 1, h.first);
                    ++useNum;
                    --h.second;

                    int l = i;
                    while (true) {
                        n = board.length();
                        if (l >= n)
                            break;
                        char cc = board[l];
                        int cnt = 1;
                        int r = l + 1;
                        --l;
                        while (l >= 0 && l < n && board[l] == cc) {
                            ++cnt;
                            --l;
                        }
                        ++l;
                        while (r >= 0 && r < n && board[r] == cc) {
                            ++cnt;
                            ++r;
                        }
                        if (cnt >= 3) {
                            board.erase(l, cnt);
                        } else {
                            break;
                        }
                    }

                    backtrack(useNum);
                    board = temp;
                    ++h.second;
                    --useNum;
                }
            }
        };

        backtrack(0);
        return useNumMin == 6 ? -1 : useNumMin;
    }
};

TEST(Solution, findMinStep) {
    Solution s;

    string board = "G";
    string hand = "GGGGG";
    EXPECT_EQ(2, s.findMinStep(board, hand));

    string board1 = "WRRBBW";
    string hand1 = "RB";
    EXPECT_EQ(-1, s.findMinStep(board1, hand1));

    string board2 = "WWRRBBWW";
    string hand2 = "WRBRW";
    EXPECT_EQ(2, s.findMinStep(board2, hand2));

    string board3 = "RBYYBBRRB";
    string hand3 = "YRBGB";
    EXPECT_EQ(3, s.findMinStep(board3, hand3));

    string board4 = "RRWWRRBBRR";
    string hand4 = "WB";
    EXPECT_EQ(2, s.findMinStep(board4, hand4));

    string board5 = "RRYGGYYRRYGGYYRR";
    string hand5 = "GGBBB";
    EXPECT_EQ(5, s.findMinStep(board5, hand5));
}