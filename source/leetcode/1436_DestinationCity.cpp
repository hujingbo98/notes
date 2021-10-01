/**
 * Source : https://leetcode-cn.com/problems/destination-city/
 * Author : Hu Jingbo
 * Date   : 2021-10-01
 * 
 * 1436. 旅行终点站
 * 
 * 给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = 
 * [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi。请你找出这次旅行的
 * 终点站，即没有任何可以通往其他城市的线路的城市。
 * 
 * 题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。
 * 
 * 示例 1：
 * 输入：
 *      paths = [["London","New York"],
 *               ["New York","Lima"],
 *               ["Lima","Sao Paulo"]]
 * 输出："Sao Paulo" 
 * 解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。
 * 本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。
 * 
 * 示例 2：
 * 输入：paths = [["B","C"],["D","B"],["C","A"]]
 * 输出："A"
 * 解释：所有可能的线路是：
 * "D" -> "B" -> "C" -> "A". 
 * "B" -> "C" -> "A". 
 * "C" -> "A". 
 * "A". 
 * 显然，旅行终点站是 "A" 。
 * 
 * 示例 3：
 * 输入：paths = [["A","Z"]]
 * 输出："Z"
 *  
 * 提示：
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * 所有字符串均由大小写英文字母和空格字符组成。
 */

#include <string>
#include <vector>
#include <unordered_set>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    /**
     * 方法一：哈希表
     * 
     * 旅行的终点站，即没有任何可以通往其他城市的线路的城市。也就是说，我们在 paths
     * 的出发城市中找不到该城市，在 paths 的到达城市能找到该城市，就可以认定该城市
     * 是旅行的终点站。
     * 
     * 我们可以使用哈希表以出发城市为键保存 paths，然后枚举所有到达城市，在哈希表中
     * 查找该城市，如果没找到，则说明该城市就是旅行的终点站。
     * 
     * 时间复杂度是 O(mn)，其中 n 是 paths 的长度，m 是城市名称的最大长度。
     * 
     * 空间复杂度是 O(mn)。主要是建立哈希所占用的空间。
     */
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> CitiesASet;
        for (const auto& path : paths) {
            CitiesASet.insert(path[0]);
        }
        for (const auto& path : paths) {
            if (CitiesASet.find(path[1]) == CitiesASet.end()) {
                return path[1];
            }
        }
        return "";
    }
};

TEST(Solution, destCity) {
    Solution s;

    vector<vector<string>> paths = {{"London","New York"},
                                    {"New York","Lima"},
                                    {"Lima","Sao Paulo"}};
    EXPECT_EQ("Sao Paulo", s.destCity(paths));

    vector<vector<string>> paths_v2 = {{"B","C"},
                                       {"D","B"},
                                       {"C","A"}};
    EXPECT_EQ("A", s.destCity(paths_v2));
}