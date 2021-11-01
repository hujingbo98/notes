<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-09-16
-->

Problem Source : <https://leetcode-cn.com/problems/word-search-ii/>

Soluton Source : <https://github.com/hujingbo98/notes/blob/master/code/source/leetcode/0212_WordSearchII.cpp>

212、单词搜索 II

给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例 1：

```txt
输入：
     board = [["o","a","a","n"],
              ["e","t","a","e"],
              ["i","h","k","r"],
              ["i","f","l","v"]], 
     words = ["oath","pea","eat","rain"]
输出：["eat","oath"]
```

示例 2：

```txt
输入：
     board = [["a","b"],
              ["c","d"]], 
     words = ["abcb"]
输出：[]
```

提示：

```txt
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] 是一个小写英文字母
1 <= words.length <= 3 * 10^4
1 <= words[i].length <= 10
words[i] 由小写英文字母组成
words 中的所有字符串互不相同
```

```c++
class Solution {
public:
    /**
     * 方法一：回溯 + 字典树（前缀树）+ 删除被匹配的单词
     * 
     * 根据题意，我们需要逐个遍历二维网格中的每一个单元格，然后搜索从该单元格出发
     * 的所有路径，找到其中对应 words 中的单词路径。因为这是一个回溯的过程，所以
     * 我们有如下算法：
     *  - 遍历二维网格中的所有单元格
     *  - 深度优先搜索所有从当前正在遍历的单元格出发的、由相邻的且不重复的单元格组
     *    成的路径。因为题目要求同一个单元格内的字母在一个单词中不允许被重复使用，
     *    所以，我们在深度优先搜索的过程中，每经过一个单元格，都将该单元格的字母修
     *    改为特殊字符（例如 '#'），以避免再次经过该单元格。
     *  - 如果当前路径是 words 中的单词，就将该单词添加到结果集；如果当前路径是 
     *    words 中任意单词的前缀，则继续搜索；反之，如果当前路径不是 words 中任意
     *    单词的前缀，则剪枝。我们可以将 words 中的单词先添加到前缀树中，然后用
     *    O(max(s.length)) 的时间复杂度查询当前路径是否为 words 中的单词或任意单
     *    词的前缀。
     * 注意：
     *  - 在具体实现中，因为同一个单词可能在不同的路径中出现，所以我们需要使用哈希
     *    集合对结果集去重。
     *  - 在回溯过程中，我们不需要每一步都判断完整的当前路径是否是 words 中任意一个
     *    单词的前缀。而是可以记录下路径中每个单元格所对应的前缀树结点，每次只需判
     *    断新增单元格的字母是否是上一个单元格对应的前缀树的子节点即可。
     * 
     * 优化：删除被匹配的单词
     *     考虑以下情况。假设给定一个所有单元格都是 a 的二维字符网格和单词列表 
     *     ["a", "aa", "aaa", "aaaa"]。当我们使用方法一来找出所有同时在二维网格和
     *     单词列表中出现的单词时，我们需要遍历每一个单元格的所有路径，会找到大量重
     *     复的单词。
     *     为了缓解这种情况，我们可以将匹配到的单词从前缀树中移除，来避免重复寻找相
     *     同的单词。因为这种方法可以保证每个单词只能被匹配一次；所以我们也不需要再
     *     对结果集去重了。
     * 
     * 时间复杂度为 O( m * n * 3^(l-1) )，其中 m 是二维网格的高度，n 是二维网格的
     * 宽度，l 是最长单词的长度。我们需要遍历 m * n 个单元格，每个单元格最多需要遍
     * 历 4 * 3^(l-1) 条路径。
     * 空间复杂度为 O(k * l)，其中 k 是 words 的长度，l 是最长单词的长度。最坏情况
     * 下，我们需要 O(k * l) 用于存储前缀树。
     */
    struct TrieElement {
        string word = "";
        unordered_map<char, TrieElement *> children;
    };

    class Trie {
    public:
        Trie()
        {
            m_Root = new TrieElement();
        }
        ~Trie()
        {
            destroyTrie(m_Root);
        }

        void insert(const string& word)
        {
            TrieElement *node = m_Root;
            for (auto it : word) {
                if (node->children.find(it) == node->children.end()) {
                    node->children[it] = new TrieElement();
                }
                node = node->children[it];
            }
            node->word = word;
        }

        static void destroyTrie(TrieElement* node)
        {
            for (auto& it : node->children) {
                destroyTrie(it.second);
            }
            delete node;
        }

        TrieElement* getRoot() { return m_Root; }
    private:
        TrieElement*                    m_Root;
    };

    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>>& board, int i, int j, TrieElement* node, 
        set<string>& ss)
    {
        char c = board[i][j];
        if (node->children.find(c) == node->children.end())
            return;
        node = node->children[c];
        if (!node->word.empty()) {
            ss.insert(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        int rowSize = board.size();
        int colSize = board[0].size();
        for (int m = 0; m < 4; ++m) {
            int ii = i + dirs[m][0];
            int jj = j + dirs[m][1];
            if (ii >= 0 && ii < rowSize
                && jj >= 0 && jj < colSize) 
            {
                if (board[ii][jj] != '#')
                    dfs(board, ii, jj, node, ss);
            }
        }
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, 
        vector<string>& words) 
    {
        Trie trie;
        for (const auto& it : words) {
            trie.insert(it);
        }
        set<string> ss;
        int rowSize = board.size();
        for (int i = 0; i < rowSize; ++i) {
            int colSize = board[0].size();
            for (int j = 0; j < colSize; ++j) {
                dfs(board, i, j, trie.getRoot(), ss);
            }
        }
        vector<string> ans;
        for (auto& it : ss) {
            ans.push_back(it);
        }
        return ans;
    }
};
```