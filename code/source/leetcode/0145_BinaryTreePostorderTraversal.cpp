/**
 * Source : https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * Author : Hu Jingbo
 * Date   : 2022-01-11
 * 
 * 145. 二叉树的后序遍历
 * 
 * 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
 * 
 * 示例 1：
 * 输入：root = [1,null,2,3]
 * 输出：[3,2,1]
 * 
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 * 
 * 示例 3：
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 提示：
 * 树中节点的数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 * 
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 */

#include <vector>
#include <stack>

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
    /**
     * 方法一：递归
     */
    vector<int> postorderTraversal_Recursion(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> recursion = [&recursion, &ans](
            TreeNode* node) {
            if (!node)
                return;
            recursion(node->left);
            recursion(node->right);
            ans.emplace_back(node->val);
        };
        recursion(root);
        return ans;
    }

    /**
     * 方法二：计数法迭代
     */
    vector<int> postorderTraversal_Iteration(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, int>> s;
        while (root || !s.empty()) {
            while (root) {
                s.emplace(make_pair(root, 1));
                root = root->left;
            }
            if (!s.empty()) {
                auto [node, cnt] = s.top();
                s.pop();
                if (cnt == 1) {
                    s.emplace(make_pair(node, 2));
                    root = node->right;
                } else if (cnt == 2) {
                    ans.emplace_back(node->val);
                }
            }
        }
        return ans;
    }

    /**
     * 方法三：标记法迭代：可以统一前序、中序、后序的写法
     */
    vector<int> postorderTraversal_IterationByMarkMethod(TreeNode *root) {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node) {
                s.emplace(node);
                s.emplace(nullptr);
                if (node->right) s.emplace(node->right);
                if (node->left) s.emplace(node->left);
            } else {
                node = s.top();
                s.pop();
                ans.emplace_back(node->val);
            }
        }
        return ans;
    }
};

static TreeNode* constructBinaryTreeByVector(const vector<int>& v) {
    if (v.empty())
        return nullptr;
    int n = v.size();
    vector<TreeNode*> vec(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (v[i] != -1) {
            vec[i] = new TreeNode(v[i]);
        }
    }
    for (int i = 0; i * 2 + 1 < n; ++i) {
        if (vec[i]) {
            vec[i]->left = vec[i * 2 + 1];
            if (i * 2 + 2 < n)
                vec[i]->right = vec[i * 2 + 2];
        }
    }
    return vec[0];
}

TEST(Solution, 0145_BinaryTreePostorderTraversal) {
    Solution s;
    
    vector<int> v = {1,-1,2,-1,-1,3};
    TreeNode* root = constructBinaryTreeByVector(v);
    vector<int> ans = {3,2,1};
    EXPECT_EQ(ans, s.postorderTraversal_Recursion(root));
    EXPECT_EQ(ans, s.postorderTraversal_Iteration(root));
    EXPECT_EQ(ans, s.postorderTraversal_IterationByMarkMethod(root));
}