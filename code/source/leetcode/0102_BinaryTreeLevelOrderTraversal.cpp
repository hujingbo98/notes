/**
 * Source : https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 102. 二叉树的层序遍历
 * 
 * 给你二叉树的根节点 root，返回其节点值的层序遍历。（即逐层地，从左到右访问所有节
 * 点）。
 * 
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 示例 2：
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 示例 3：
 * 输入：root = []
 * 输出：[]
 * 
 * 提示：
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 */

#include <vector>
#include <queue>

#include "gtest/gtest.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                temp.emplace_back(node->val);
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            ans.emplace_back(move(temp));
        }
        return ans;
    }
};

static TreeNode* constructBinaryTreeByString(const string& s) {
    int n = s.length() - 1;
    if (s[0] != '[' || s[n] != ']')
        return nullptr;
    vector<TreeNode*> vec;
    int x = 0;
    int symbol = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '-') {
            symbol = -1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            x *= 10;
            x += s[i] - '0';
        }
        if (s[i] == ',' || i == n - 1) {
            vec.emplace_back(new TreeNode(x * symbol));
            x = 0;
            symbol = 1;
        } 
        if (s.compare(i, 5, "null,") == 0) {
            vec.emplace_back(nullptr);
            i += 4;
        }
    }
    int nSize = vec.size();
    for (int i = 0; i * 2 + 1 < nSize; ++i) {
        if (vec[i]) {
            vec[i]->left = vec[i * 2 + 1];
            if (i * 2 + 2 < nSize)
                vec[i]->right = vec[i * 2 + 2];
        }
    }
    return vec[0];
}

TEST(Solution, 0102_BinaryTreeLevelOrderTraversal) {
    Solution s;

    vector<int> v = {3,9,20,-1,-1,15,7};
    // TreeNode* root = constructBinaryTreeByVector(v);
    TreeNode* root = constructBinaryTreeByString("[3,9,20,null,null,15,7]");
    vector<vector<int>> ans = {{3},{9,20},{15,7}};
    EXPECT_EQ(ans, s.levelOrder(root));
}